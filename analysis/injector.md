# Analysis: Injector

`data/GarlicInjector.exe` is the binary that:

1. Reads `GarlicProxy.pkg` from disk.
2. **Decrypts** it using PBKDF2-HMAC-SHA256 + AES-256-GCM with a
   hard-coded 32-byte password.
3. Reflective-injects the resulting DLL into a target Minecraft Java
   process.

The decryption format is documented in detail in `decryption.md`; this
file focuses on the injector's control flow, anti-tamper gate, and
remote thread injection.

## 1. Imports

```
bcrypt
    BCryptOpenAlgorithmProvider
    BCryptGetProperty
    BCryptSetProperty
    BCryptCloseAlgorithmProvider
    BCryptGenerateSymmetricKey
    BCryptDecrypt
    BCryptDestroyKey
    BCryptCreateHash
    BCryptHashData
    BCryptFinishHash
    BCryptDestroyHash
    BCryptDeriveKeyPBKDF2
kernel32
    CreateToolhelp32Snapshot
    Process32First
    Process32Next
    FlsAlloc / Free / GetValue / SetValue
    InitializeCriticalSectionEx
```

There are **no networking APIs and no anti-debug APIs** imported by
the injector either. The bcrypt import set is exactly the set needed
for the PBKDF2 + AES-GCM + SHA-256 computation.

## 2. Themida layout

Identical to the launcher's:

| Section | RVA | Size | Role |
|---------|-----|------|------|
| `.text` | 0x1000 | 102 400 | Visible C++ code (post-unpack). |
| (unnamed) | 0x1A000 | 49 152 | Strings / `data_14001a880` (the PBKDF2 password) and other constants. |
| `.themida` | 0x2F000 | 6 348 800 | Themida VM bytecode (mostly inert in the unpacked build). |
| `.boot` | 0x63D000 | 3 928 064 | Themida unpacker stub. |
| `.SCY` | 0x9FC000 | 4 096 | Themida security cookie. |
| `.extern` | 0x9FD000 | 864 | Extern data referenced by the VM. |
| `.synthetic_builtins` | 0x9FD360 | 48 | Intrinsic stubs. |

The injected build (`unpacked_GarlicInjector.exe`) has had the VM
stripped, so entry points jump straight into the original code.

## 3. Top-level call graph

```
main (0x140001310, complexity 27)
└── argv parsing
    ├── strcmp(argv[3], "--auth-nonce")   ← must be argv[3]
    ├── strcmp(argv[4], "--auth-token")   ← must be argv[4]
    ├── hex-decode argv[3] into 8 bytes   (sub_14000a880)
    ├── hex-decode argv[4] into 8 bytes   (sub_14000a880)
    ├── FNV-1a(auth_nonce) = derived_token (sub_140001000)
    │     ↑ both use the bridge hash
    │       FNV-1a("GarlicBridge-V2-20260809", seed=0x14650fb0739d0383)
    └── if derived_token != auth_token:
            print "[-] %s"  ← data_14001a610 ("Auth-nonce / auth-token mismatch")
            exit 3
        else:
            hwnd = EnumWindows(find_pid_by_window_title, &pid)
                EnumWindows callback (sub_1400010e0) uses:
                  IsWindowVisible
                  GetWindowTextW
                  GetWindowThreadProcessId
                  CreateToolhelp32Snapshot
                  Process32First / Next
                  GetProcessTimes
                  strcmp("java.exe") / strcmp("javaw.exe")
                  title contains "U+5E03 U+5409 U+5C9B" (布吉岛)
                keeps the **latest** matching java/javaw PID
            if pid == 0: poll every 50ms until found
            decrypt_and_inject(pid, pkg_path, auth_block_24b, out_buf, 0x400)
                sub_140001750 (this file, §4)
```

The injector is **single-purpose**: take a hard-coded password, a
session auth token pair, and a pkg path, find the right Java PID, and
do the reflective injection. There is no logging beyond a small
"[+] %s" / "[-] %s" wrapper.

## 4. `sub_140001750` — main injection driver

```
sub_140001750(target_pid, pkg_path, auth_block_24b, log_buf, log_size)
{
    log_prefix = "[-] " (data_14001a6f8 default);
    if (arg3 != 0 && *arg3 == 0x4741524c49434155)         // "GARLICAU"
        recompute_derived_token = FNV-1a(arg3[1]);       // sub_140001000 path
        if (arg3[2] != (recompute * 0x100000001b3 ^ 0x4741524c49434155) * 0x100000001b3)
            log "[-] %s" with data_14001a6f8;             // auth failed
            return 0;
    if (decrypt_pkg(pkg_path, &out_ptr, &out_size, log_buf, log_size) == 0)   // sub_1400021e0
        log "[-] %s";
        return 0;
    // We have a decrypted DLL in (out_ptr, out_size)
    //
    // 1) Acquire SeDebugPrivilege so we can OpenProcess on the
    //    target java PID even when run by a non-admin user.
    OpenProcessToken(GetCurrentProcess(), 0x28, &hToken);
    LookupPrivilegeValueA(NULL, "SeDebugPrivilege", &tk);
    AdjustTokenPrivileges(hToken, FALSE, &tk, ...);
    //
    // 2) OpenProcess with PROCESS_ALL_ACCESS (0x43a) on the PID.
    hProc = OpenProcess(0x43a, FALSE, target_pid);
    //
    // 3) VirtualAllocEx + WriteProcessMemory 24-byte auth block
    //    into the target. This is the auth_block_24b; the target's
    //    ReflectiveLoader will read it back as the first few bytes
    //    of the buffer it sees, and use it as its session "key".
    pAuthBuf = VirtualAllocEx(hProc, NULL, 0x18, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    WriteProcessMemory(hProc, pAuthBuf, auth_block_24b, 0x18, &nWritten);
    //
    // 4) sub_140001bf0 — reflective-DLL inject the decrypted DLL.
    //    Writes the full DLL image into a fresh RX region in the
    //    target, then CreateRemoteThread(hProc, NULL, 1<<20,
    //    dll_base + export("ReflectiveLoader"), pAuthBuf, ...).
    //    The 1 MiB reserved stack is the same trick Stephen Fewer
    //    uses in ReflectiveDLLInjection.
    hThread = sub_140001bf0(hProc, out_ptr, out_size, pAuthBuf);
    WaitForSingleObject(hThread, INFINITE);
    GetExitCodeThread(hThread, &exitCode);
    if (exitCode == 0)
        log "[-] remote ReflectiveLoader returned 0";
        return 0;
    log "[+] injected into PID %u" with target_pid;
    VirtualFreeEx(hProc, pAuthBuf, 0, MEM_RELEASE);
    return 1;
}
```

### 4.1 The auth-block write

The 24-byte auth block is written into the target **before** the DLL
is mapped. The decrypted DLL's own ReflectiveLoader then reads it as
the first argument to `ReflectiveLoader(lpParameter)`. So the auth
block lives at the same address as the thread parameter, and the DLL
gets to verify it (the `*arg3 == 0x4741524c49434155` check happens in
the DLL's own `sub_180001740.c → ProxyInitWorker`, not in the
injector). The injector just hands the bytes through.

In other words: the auth gate at the **injector** side (re-deriving
the FNV-1a token from the nonce and comparing to the user-supplied
token) is purely cosmetic — it does **not** prevent the injection if
it fails; it just makes `sub_140001750` return 0 without doing the
actual inject. The DLL side does its own auth check, and **that** check
ultimately gates whether the proxy ends up running. As long as the
auth block's first 8 bytes are `"GARLICAU"`, the DLL's check passes
(it only validates that the bytes are aligned correctly; the rest of
the auth comes from the PBKDF2 password baked into the DLL).

### 4.2 `sub_140001bf0` — reflective DLL loader

Standard Stephen Fewer ReflectiveDLLInjection:

```
if (dos_header->e_magic == IMAGE_DOS_SIGNATURE)
    nt = (PIMAGE_NT_HEADERS)(dos + dos->e_lfanew);
    if (nt->OptionalHeader.Magic == PE32+ (0x20b))
        export_dir = &nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
        foreach (export)
            if (strcmp((char*)dll + names[i], "ReflectiveLoader") == 0)
                function_rva = functions[ordinals[i]];
                remote_base = VirtualAllocEx(hProc, NULL, dll_size,
                                             MEM_COMMIT|MEM_RESERVE,
                                             PAGE_EXECUTE_READWRITE);
                WriteProcessMemory(hProc, remote_base, dll, dll_size, NULL);
                thread = CreateRemoteThread(hProc, NULL, 1<<20,
                                            remote_base + function_rva,
                                            auth_buf, 0, &tid);
                return thread;
```

There is no relocation fixup, no import resolution, no TLS callback
execution at the injector side — all of that is the responsibility of
the DLL's own `ReflectiveLoader`. The injector is just a thin shim
that copies the bytes into the target and jumps to the export.

## 5. What the injector does **not** do

* It does not verify the SHA-256 of the decrypted DLL (this is done
  inside `sub_1400021e0` itself, but only as an integrity check
  against a hash stored inside the package header; it is not a
  package-signature check).
* It does not check whether the package's salt / nonce / tag are
  "fresh" — every launch the launcher regenerates these from the
  per-session nonce. The package can be replayed as long as the
  embedded salt and nonce are unchanged.
* It does not check the origin of the target process beyond
  "java.exe / javaw.exe with window title containing `布吉岛`".
  Any process spoofing those strings will be injected into.

## 6. Summary

The injector is a one-shot tool:

```
argv → hex-decode → FNV-1a-verify → EnumWindows → find Java PID →
OpenProcess + SeDebugPrivilege → VirtualAllocEx(auth_block) →
reflective-inject(DLL, auth_block) → WaitForSingleObject.
```

The reflective injection is the standard Stephen Fewer pattern; the
only GarlicV2-specific additions are the AES-GCM decryption step and
the FNV-1a auth gate. Anyone with the PBKDF2 password can decrypt the
package and reflective-inject the DLL into any Java process whose
window title contains `布吉岛`, without ever running the launcher or
the injector.