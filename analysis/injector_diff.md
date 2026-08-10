# Injector diff: SakuraTools `injector/` vs `data/GarlicInjector.exe`

The `injector/` directory contains a **plain reflective-DLL injector**
from SakuraTools. `data/GarlicInjector.exe` (the binary shipped with
GarlicV2) is 大蒜's **wrapper** around the same injection core, adding
an encrypted-package layer (PBKDF2 + AES-GCM), FNV-1a session
authentication, and a different CLI.

## 1. SakuraTools injector (in `injector/`)

All `.c` / `.h` files in `injector/` are **byte-for-byte identical**
(after whitespace normalisation) to the upstream SakuraTools repo
([GzSakura1338/SakuraTools/tree/main/injector](https://github.com/GzSakura1338/SakuraTools/tree/main/injector)).

| File | SHA-256** | Purpose |
|------|-----------|--------|
| `cli.c` | `86b7f5b2...` (ST) / same content | Main: `{dll-path}` → find "布吉岛" java PID → inject |
| `Inject.c` | `00664c03...` (ST) / same content | `DoInject()` — read DLL file, SeDebugPrivilege, `LoadRemoteLibraryR` |
| `LoadLibraryR.c` | `504f5154...` (ST) / same content | `GetReflectiveLoaderOffset()` + `LoadRemoteLibraryR()` — Stephen Fewer reflective loader |
| `GetProcAddressR.c` | `97721a9f...` (ST) / same content | `GetProcAddressR()` — walk export table without `kernel32!GetProcAddress` |
| `inject_ll.c` | `4bfcd87d...` (ST) / same content | Low-level inject variant: `LoadLibraryA` via remote thread |

** = SHA-256 reported by GitHub for the SakuraTools file. Our local
copies differ only in line endings (CRLF ↔ LF); content is identical.

The data flow of the SakuraTools injector is:

```
reflective_injector.exe <dll-path>
└── wait_for_buji_island_process()
│     EnumWindows → find visible java.exe/javaw.exe with
│     title containing "布吉岛" (U+5E03 U+5409 U+5C9B)
│     keep oldest-created matching process
├── DoInject(pid, dll_path, ...)
│     CreateFileA(read dll) → HeapAlloc → ReadFile
│     SeDebugPrivilege via OpenProcessToken + AdjustTokenPrivileges
│     OpenProcess(pid) → LoadRemoteLibraryR(process, dll_bytes, ...)
│         GetReflectiveLoaderOffset(dll_bytes)    // find export "ReflectiveLoader"
│         VirtualAllocEx(pid, RX)                 // alloc in target
│         WriteProcessMemory(pid, dll)            // copy DLL
│         CreateRemoteThread(pid, 1 MiB stack, ReflectiveLoader, lpParameter=NULL, ...)
│         WaitForSingleObject(thread, INFINITE)
└── wait_for_proxy_listener(pid)    // poll GetExtendedTcpTable for :25565 listener
```

## 2. GarlicInjector.exe (大蒜's wrapper)

`data/GarlicInjector.exe` takes a different CLI and adds three layers
on top of the same reflective-injection core:

```
GarlicInjector.exe <pkg-path> --auth-nonce <hex16> --auth-token <hex16>
```

### 2.1 Command-line scanning (new — not in SakuraTools)

```
main(argc=6, argv[])                                       ← sub_140001310
├── strcmp(argv[3], "--auth-nonce")   ← must be exactly 6 args
├── strcmp(argv[4], "--auth-token")
├── hex-decode argv[3] → uint64_t nonce         ← sub_14000a880 (new)
├── hex-decode argv[4] → uint64_t token         ← sub_14000a880 (new)
├── derive token' = FNV-1a(nonce, "GarlicBridge-V2-20260809")
│       if token' != token ⇒ error, exit 3             ← sub_140001000 (new)
├── GetFileAttributesA(pkg_path)                  ← same as SakuraTools cli.c check
├── EnumWindows(callback, &pid_chosen)           ← sub_1400010e0 (布吉岛 finder, same as cli.c)
│     callback: IsWindowVisible, GetWindowTextW,
│               GetWindowThreadProcessId,
│               strcmp("java.exe"/"javaw.exe"),
│               GetProcessTimes → keep newest
├── poll until pid non-zero (Sleep 50ms)
└── sub_140001750(pid, pkg_path, &auth_block_24b,
                  &log_buf, 0x400)
```

### 2.2 Encrypted-package layer (new — not in SakuraTools)

`sub_140001750` replaces SakuraTools' `DoInject()`:

```
sub_140001750(pid, pkg_path, &auth_block, &log_buf, 0x400)
├── OpenProcessToken + AdjustTokenPrivileges(SeDebugPrivilege)  ← same as Inject.c
├── OpenProcess(pid, PROCESS_ALL_ACCESS 0x43a)                   ← more permissive than Inject.c (uses 0x438)
├── sub_1400021e0(pkg_path, &out_ptr, &out_size, …)              ← NEW: decrypt pkg
│     CreateFileA(GENERIC_READ) → GetFileSize → HeapAlloc → ReadFile
│     PBKDF2-HMAC-SHA256(static_32_byte_password, salt, 75k, key)
│     AES-256-GCM(key, nonce, ciphertext+tag, AAD) → plaintext DLL
│     verify SHA-256(plaintext) matches header
│     verify plaintext[0:2] == "MZ"
├── VirtualAllocEx(pid, rx, dll_size)                             ← same as LoadLibraryR.c
├── WriteProcessMemory(pid, dll)                                  ← same
├── VirtualAllocEx(pid, rw, 0x18)                                 ← NEW: write 24-byte auth block
├── WriteProcessMemory(pid, auth_block)                           ← NEW
├── sub_140001bf0(pid, dll, size, auth_block_addr)
│     GetReflectiveLoaderOffset(dll)                              ← same as LoadLibraryR.c
│     CreateRemoteThread(pid, 1 MiB stack,
│                        base + ReflectiveLoader,
│                        auth_block_addr)
└── WaitForSingleObject(thread, INFINITE)
```

### 2.3 Auth block passed to the DLL (new — not in SakuraTools)

24 bytes written into the target at `pAuthBuf`:

```
offset  size  value
0x00    8     0x4741524c49434155   ("GARLICAU" magic)
0x08    8     nonce (raw, LE, as decoded from --auth-nonce hex)
0x10    8     token (raw, LE, as decoded from --auth-token hex)
```

This auth block is then read by `DllMain` in the proxy DLL (see
[`analysis/dll_vs_native.md`](dll_vs_native.md)). The DLL's
`GarlicInternalVerify()` re-checks it before loading.

### 2.4 FNV-1a verifier (new — not in SakuraTools)

`sub_140001000` is byte-for-byte identical to the DLL's
`GarlicInternalVerify()` and the launcher's `sub_140001000`:

```
fnv64_hash("GarlicBridge-V2-20260809", offset=0xA38B033F…)
    → fnv64_feed(nonce, 8 bytes)
    → (*prime) ^ 0x4741524c49434155 *prime
    → compare with token
```

The same code appears in **three** different executables:
`unpacked_GarlicNELauncherV2.exe` (launcher),
`data/GarlicInjector.exe` (injector), and
`artifacts/GarlicProxy.dll` (the proxy DLL).

### 2.5 Proxy-listener poll (present in both)

After injection succeeds, both injectors wait for the proxy to bind
port 25565:

```
for elapsed in 0..30000 ms step 50 ms:
    GetExtendedTcpTable(NULL, …, TCP_TABLE_OWNER_PID_LISTENER, …);
    scan rows for pid == target_pid AND local_port == 0x63DD;
    if found → return OK
```

This is identical in both. `cli.c::wait_for_proxy_listener()` and
`sub_140001310` (the loop near the end of main) use the same
`GetExtendedTcpTable` + `0x63DD` constant.

### 2.6 Themida protection (new — not in SakuraTools)

`data/GarlicInjector.exe` is Themida-protected in its original build
(same `.themida`/`.boot`/`.SCY` layout as the launcher). The
SakuraTools injector is not protected. See
[`analysis/themida.md`](themida.md) for details.

## 3. What the `injector/` **does not** cover

The files under `injector/` in this repository are SakuraTools'
**original** injector. They do NOT contain:

* The PBKDF2 + AES-GCM decryptor (`sub_1400021e0`)
* The FNV-1a verifier (`sub_140001000`)
* The hex-decoder (`sub_14000a880`)
* The `--auth-nonce` / `--auth-token` CLI
* The 24-byte auth-block construction and remote-memory write

These are the parts 大蒜 added when building `data/GarlicInjector.exe`.
They can be reconstructed from the MCP decompiler output in
[`analysis/injector.md`](injector.md) (the old-style `data/GarlicInjector.exe`
analysis) but are **not** present as source files anywhere in this
repository.

## 4. The `ori/` files (lost)

`ori/injector/` previously contained two additional files that are
now deleted and have no copy in this repo:

* `auto_inject.c` — likely 大蒜's original CLI wrapper (the
  pre-Themida source for what became `data/GarlicInjector.exe`).
* `smart_inject.c` — likely a smarter PID hunter or a variant of the
  `inject_ll.c` low-level injector.

Both files were listed in the initial `ori/` directory listing but
were removed before this analysis was written. Anyone wanting to
reconstruct them from scratch would need to reverse-engineer
`data/GarlicInjector.exe` using the decompilations in
[`analysis/injector.md`](injector.md) and this file.

## 5. Recommendation

For a complete picture of the GarlicV2 injector source code, the
following files would need to be (re-)created:

1. **`injector/garlic_main.c`** — new `main()` with:
   * hex-decoder for `--auth-nonce`/`--auth-token` args
   * FNV-1a verification (shared with `native/loader.cpp`)
   * 24-byte auth-block construction
   * call to `DoInject()` / `LoadRemoteLibraryR()` from the existing
     SakuraTools files
2. **`injector/pkg_decrypt.c`** — `sub_1400021e0` as a C translation:
   * `BCryptOpenAlgorithmProvider`, `BCryptDeriveKeyPBKDF2`,
     `BCryptGenerateSymmetricKey`, `BCryptDecrypt`
   * the `GNP2PKG!` header parser
   * SHA-256 verification of plaintext
3. **`injector/pkg_decrypt.h`** — header exposing `decrypt_pkg()`

These three files would make the entire injection flow buildable from
source without needing any Themida or BCrypt reverse-engineering at
the command level.

Given that the PBKDF2 password is a hard-coded static constant
already extracted in [`decryption.md`](decryption.md), and the
`GNP2PKG!` format is fully documented, option 2 is purely a
mechanical port of the decompiled x86-64 to C — no new reverse
engineering needed.