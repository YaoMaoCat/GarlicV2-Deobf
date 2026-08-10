# Auth-nonce / Auth-token

The launcher builds two 16-hex-character arguments (`--auth-nonce` and
`--auth-token`) for every injector invocation, and the injector
re-derives `token` from `nonce` and verifies it before decrypting the
package. This file documents the construction and why it does not
actually gate decryption.

## 1. Layout

The injector is called as:

```
GarlicInjector.exe <pkg-path> --auth-nonce <hex16> --auth-token <hex16>
```

where each `<hex16>` is exactly **8 bytes / 16 lowercase hex chars**.
Inside the injector those hex strings are decoded with
`sub_14000a880` (the C-runtime `_wcstol_l` wrapper) and stored as a
24-byte "auth block" passed to `sub_140001750`:

```
offset  size  meaning
0x00    8     0x4741524c49434155     "GARLICAU"   (constant; reversed ASCII)
0x08    8     raw nonce bytes (little-endian)
0x10    8     raw token bytes (little-endian)
```

`sub_140001750` checks `arg3[0] == 0x4741524c49434155` and computes
`token'` from `arg3[1]` using the same FNV-1a chain the launcher
uses. If `token' == arg3[2]` it returns from the auth gate and calls
`sub_1400021e0` (the decryptor).

## 2. Construction (in the launcher)

`unpacked_GarlicNELauncherV2.exe` builds the auth block at the start
of `main`:

```
rsi_4 = QueryPerformanceCounter()
        ^ (GetTickCount64()           << 0x11)
        ^ (GetCurrentProcessId()      << 0x20)
        ^ &QueryPerformanceCounter;

rdi_1 = 0x14650fb0739d0383;       // FNV-1a offset basis (64-bit)
for i in 0..24:
    rdi_1 = (rdi_1 ^ "GarlicBridge-V2-20260809"[i]) * 0x100000001b3;

strncpy(auth_block, "UACILRAG", 8);    // "UACILRAG" reversed = "GARLICAU"
*((uint64_t*)(auth_block + 8)) = rsi_4;  // the nonce (8 bytes)

token_seed = FNV-1a-64(rsi_4, rdi_1);     // derive the token from the nonce
token      = (token_seed * 0x100000001b3) ^ 0x4741524c49434155;
token      = token * 0x100000001b3;

auth_nonce_hex = "%016llX" (rsi_4);
auth_token_hex = "%016llX" (token);
```

The launcher escapes both the auth-nonce and auth-token with a
backslash-encoder (`sub_140006290`) before concatenating them into the
child-process command line.

The injection command line ultimately passed to `CreateProcessW` is:

```
"<data>\GarlicInjector.exe" "<data>\GarlicProxy.pkg" --auth-nonce <hex16> --auth-token <hex16>
```

(`<data>` is the relative `data\` directory the launcher reads at
startup; defaults to `data`.)

## 3. Verification (in the injector)

`sub_140001000` (FNV-1a verification, called both by the launcher's
auth-block-build step and by the injector's auth-block-check step)
implements the chain:

```
fnv64_bridge = FNV-1a-64("GarlicBridge-V2-20260809",
                          offset_basis=0x14650fb0739d0383);

fnv64_nonce = FNV-1a-64(nonce_bytes, offset_basis=fnv64_bridge);
                // The 8-byte nonce is fed through the chain one
                // byte at a time with FNV-1a's prime 0x100000001b3.

token_recomputed = ((fnv64_nonce * 0x100000001b3) ^ 0x4741524c49434155)
                  * 0x100000001b3;
```

`sub_140001000` returns this `token_recomputed`. The injector compares
it against `arg3[2]`. They match ⇒ proceed.

## 4. Does this gate decryption? No.

The PBKDF2 password used by `sub_1400021e0` to derive the AES-GCM
key is **the hard-coded 32-byte constant** at file offset
`0x19_880` inside `data/GarlicInjector.exe`:

```
4d 8a 16 c3 57 91 e2 2f 6b d4 09 7e a5 38 f1 64
b2 0c 73 de 41 9f 25 88 fa 56 1b c9 34 67 ad 02
```

This is **not derived** from `auth_block`; the auth block is
discarded the moment `sub_1400021e0` starts working. In other words:

> The `--auth-nonce` / `--auth-token` arguments are an **anti-tamper
> gate**, not a key. They cause `sub_140001750` to bail out without
> calling the decryptor if the launcher side of the FNV-1a chain is
> tampered with, but anyone holding the PBKDF2 password can run the
> decryptor directly without ever touching the auth-block.

That is exactly what `artifacts/decrypt_pkg.py` does.

## 5. The DLL side also gates on `0x4741524c49434155`

The decrypted DLL (`artifacts/GarlicProxy.dll`) sees the auth block
written into its first argument (`lpParameter` of the remote thread
that the injector creates with `CreateRemoteThread`). The DLL's own
`ReflectiveLoader` body eventually forwards the auth block to
`sub_180001740.c` (`ProxyInitWorker`), which contains:

```
if (data_180046030 != 0)        // HookBridge already installed
    ...
```

The DLL verifies the auth block **twice**:

1. **In DllMain** (`sub_180001ba0`), on `PROCESS_ATTACH`, it calls
   `sub_180001ac0` — **a complete FNV-1a re-derivation**, NOT just a
   constant check:

   ```c
   // V2 DLL verifier sub_180001ac0 ("GarlicInternalVerify", added by 大蒜)
   if (arg1 && *arg1 == 0x4741524c49434155) {           // magic
       rax = 0x14650fb0739d0383;
       for (rcx = 0; rcx < 0x18; rcx++)                // 24 bytes
           rax = (rax ^ "GarlicBridge-V2-20260809"[rcx]) * 0x100000001b3;
       for (r8 = 0; r8 < 8; r8++)                      // nonce, 8 bytes
           rax = (rax ^ ((arg1[1] >> (r8 * 8)) & 0xff)) * 0x100000001b3;
       result = ((rax ^ 0x4741524c49434155) * 0x100000001b3);  // magic mix
   }
   ok = (arg1 && *arg1 == 0x4741524c49434155 && arg1[2] == result);
   ```

   The computation matches the launcher/injector **exactly** (24-byte
   bridge-string hash → 8-byte nonce hash → magic mix), so the DLL
   really does re-derive and compare the FNV-1a token. If it fails,
   `DllMain` returns 0 and the DLL is not attached.

2. In `ProxyInitWorker` (`sub_180001740`), the leading `"GARLICAU"`
   bytes are checked again before the proxy initialises.

So the auth block **does** gate the DLL's operation: the FNV-1a token
is re-derived inside the DLL itself, not only in the injector. (The
gate is still trivially reproducible by anyone with the construction,
and the PBKDF2 password, but it is not a dummy check.)

## 6. Sample captured auth block

Captured on 2026-08-09 with the launcher bundled in this repo:

```
auth-nonce  = 000050782AF4FFF2
auth-token  = E4DC3F010E766F5D
```

Decoded LE:

```
nonce bytes = F2 FF F4 2A 78 50 00 00
token bytes = 5D 6F 76 0E 01 3F DC E4
```

The nonce was the value of `QueryPerformanceCounter() ^ tick ^ pid ^
&QueryPerformanceCounter` at the moment the launcher built the
auth block. The token was the FNV-1a derivation of that nonce.

## 7. Summary

| Question | Answer |
|----------|--------|
| Is the PBKDF2 key derivable from `auth-nonce` + `auth-token`? | **No.** The key is the hard-coded 32-byte constant. |
| Can the auth block be regenerated without the launcher? | **Yes.** Anyone who knows the FNV-1a construction can re-derive the token from the nonce. |
| Does the injector's auth gate prevent `sub_1400021e0` from running? | **Only by short-circuiting `sub_140001750` before the decryptor call.** If the gate fails, `sub_1400021e0` is never called and the DLL is never injected. |
| Does the DLL's auth gate (the `"GARLICAU"` constant) prevent the proxy from running? | **Yes — through a full FNV-1a re-derivation.** V2 DLL `DllMain`→`sub_180001ac0` recomputes the token (bridge-string hash → nonce hash → magic mix) and rejects the attach if it mismatches. It is a real check, though trivially reproducible. |
| Effective security boundary | **None for the proxy DLL itself; only the launcher-side license-key `strcmp("dasuan666")` provides any user-facing access control.** |