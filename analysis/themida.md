# Themida protection

The two binaries that ship with GarlicV2 (`unpacked_GarlicNELauncherV2.exe`
and `data/GarlicInjector.exe`) are both protected by **Themida** in
their original form. The unpacked builds (`unpacked_*.exe`) shipped
with the project have had the Themida VM stripped, so this file
documents both the *unprotected* binary's runtime behaviour and the
*protection layer* that was originally present.

## 1. Sections of the Themida-protected build

The originals were built with the Themida SDK's default section
layout. The same layout shows up in both binaries:

| Section | RVA | Size | Role |
|---------|-----|------|------|
| `.text` | 0x1000 | 102 400 | Main code. Some of it runs inside the Themida VM (mix of native x86-64 and VM bytecode). |
| (unnamed) | 0x1A000 | 49 152 | String data, `data_14001a880` (the PBKDF2 password in the injector), format strings. |
| `.idata` | 0x2D000 | 4 096 | Import directory. |
| `.rsrc` | 0x2E000 | 4 096 | Version-info resources. |
| `.themida` | 0x2F000 | 6 348 800 | Themida VM bytecode. This is where the actual protected code lives. |
| `.boot` | 0x63D000 | 3 928 064 | Themida VM unpacker stub. JITted on first call by the Themida dispatcher. |
| `.SCY` | 0x9FC000 | 4 096 | Themida security cookie / anti-tamper magic. The launcher reads `data_140049080` from this region. |
| `.extern` | 0x9FD000 | 864 | Extern data referenced by the VM. |
| `.synthetic_builtins` | 0x9FD360 | 48 | Synthetic intrinsic stubs the VM can call into. |

The launcher also reads `data_140026000` (8 bytes, RVA 0x26_000) as
its `__security_check_cookie` value — that address is in the
unnamed section just above `.text` and serves as the cookie.

## 2. What Themida does at runtime

Themida's classic protection model (matching what we observe in
these binaries):

1. **`.boot` is the entry stub.** When the binary starts (or when
   `CreateRemoteThread` lands on a Themida-protected entry point),
   `.boot` runs. It validates the integrity of `.themida` and the
   `__security_check_cookie` value in `.SCY`, then JIT-compiles the
   first wave of VM bytecode into executable form in a freshly
   allocated RX region.

2. **The VM dispatches x86-64 fragments.** Each protected native
   function is rewritten into a sequence of "VM opcodes" stored in
   `.themida`. The dispatcher inside `.boot` interprets these
   opcodes, occasionally falling back to native execution for small
   helper fragments. This is why `sub_140002605` and similar
   addresses in the launcher contain what look like garbage `add
   byte [rax], al` instructions interspersed with real MOVs — those
   are "VM dispatcher noise" that the decompiler cannot always
   strip.

3. **Anti-debug** is layered:
   * `IsDebuggerPresent` / `CheckRemoteDebuggerPresent` are checked
     inside the VM, not in user-visible code.
   * `NtQueryInformationProcess` with `ProcessDebugPort` is checked
     inside the VM.
   * The PEB's `BeingDebugged` flag is checked via `gs:[0x60]+2` inside
     the VM, with the access pattern obfuscated so a breakpoint on
     the load doesn't trigger.
   * Timing checks: `rdtsc` is sampled at multiple points inside a
     single protected function. A debugger-induced slowdown of more
     than a few thousand cycles causes the VM to take a different
     branch and (typically) return wrong results.

4. **Anti-tamper** is via the `.SCY` magic. If the binary's
   `.text`/`.themida`/`.boot` regions are modified after linking,
   `.SCY` no longer matches, and the unpacker aborts.

In the **unpacked builds** shipped in this repo, all four of these
mechanisms are absent: `.themida`/`.boot`/`.SCY` are still in the file
but are referenced only by `__security_check_cookie`. Once the
binary has been "unpacked" (a Themida VM snapshot was taken at
runtime, then the unpacked x86-64 was frozen back into the binary),
the protection layer is essentially dead code.

## 3. What does survive the unpack?

The unpacked binary retains:

* The **plaintext constants** at the same RVA (`data_14001a880` in
  the injector is the PBKDF2 password; `data_14001a450` and
  `data_14001a6d8` are the "GarlicBridge-V2-20260809" string).
* The **import directory** (so `BCrypt*` is still imported; the
  KERNEL32 anti-debug routines are not).
* The **`__security_check_cookie` symbol**, but the value is now a
  known constant (`data_140026000` = 0x2b992d6a3ac5e888 or similar),
  not a random stack cookie.

Everything else (the VM bytecode, the integrity checks, the timing
checks) is stripped.

## 4. Threat-model summary

| Attack | Effect on the **packed** original | Effect on the **unpacked** build in this repo |
|--------|-----------------------------------|----------------------------------------------|
| Attach a debugger | The VM detects it and corrupts results. | The binary runs normally; you can step through it. |
| Patch `.text` | `.SCY` mismatch, unpacker aborts. | Patches work normally. |
| Dump memory | Snapshot is OK, but the dump is still encrypted. | Plaintext x86-64 is visible. |
| `rdtsc` skew | VM detects it. | No protection. |
| Set breakpoints in user code | VM detects the breakpoint placement pattern. | Breakpoints work normally. |

In other words: the **Themida layer only protects the *original
distribution* binaries**. As soon as a Themida unpacker (any of the
publicly available ones, e.g. the one the GarlicV2 author uses, or
the one that produced the files in this repo) has run, the
resulting binary is fully readable and modifiable.

This is consistent with what we observed in `decryption.md`: the
encryption of `GarlicProxy.pkg` is the only meaningful barrier, and
that barrier is bypassed by the hard-coded PBKDF2 password in the
injector's `.rdata`.

## 5. Is the Themida layer security-relevant?

No. It slows down casual reverse engineering but does not prevent
anything that matters:

* The injector still has a hard-coded 32-byte PBKDF2 password in
  `.rdata`. Themida does not and cannot hide a constant from a
  reader who has access to the unpacked binary.
* The Themida layer does not enforce any anti-cheat-style checks at
  runtime. It is purely a "make the binary harder to read" wrapper.
* The runtime cost of the VM is meaningful (each protected function
  pays 5-50× slowdown), which is why `data/GarlicInjector.exe` was
  repackaged as `unpacked_GarlicInjector.exe` for the
  developer-facing distribution: faster startup, easier debugging.

## 6. Reverse-engineering approach for Themida-protected binaries

If you ever need to look at the *original* (un-unpacked) build:

1. Use a Themida-aware unpacker (e.g. `ThemidaUnpacker` projects on
   GitHub) to dump the unpacked x86-64 to disk.
2. Re-import the dump into Binary Ninja / IDA / Ghidra.
3. The resulting analysis will look exactly like what you see in
   `unpacked_GarlicInjector.exe` and `unpacked_GarlicNELauncherV2.exe`.

The whole Themida layer is purely cosmetic from the standpoint of
"can the user extract `GarlicProxy.dll` and run it?", because the
PBKDF2 password is right there in `.rdata` after the unpack.