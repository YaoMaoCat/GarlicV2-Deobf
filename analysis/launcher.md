# Analysis: Launcher

`unpacked_GarlicNELauncherV2.exe` (the Themida-unpacked launcher that ships
with the GarlicV2 distribution) is a thin shell over `data/GarlicInjector.exe`.
It does not contain any proxy logic itself; its only purpose is to:

1. **Require a license key** ("`dasuan666`", i.e. `大蒜666`).
2. **Ask the user** for the path of `GarlicInjector.exe` (defaults to
   `data/GarlicInjector.exe`) and `GarlicProxy.pkg` (defaults to
   `data/GarlicProxy.pkg`).
3. **Build the per-session auth-nonce / auth-token** (see `auth.md`).
4. **`CreateProcessW` the injector** with the auth block, wait for it to
   finish, and propagate its exit code.

The launcher ships in the repository as `proxy/launcher.ps1` (a newer
PowerShell-only version). The `unpacked_GarlicNELauncherV2.exe` binary is
the legacy Windows GUI shell that wraps the same logic.

## 1. Imports

```
kernel32  LocalFree, DeleteCriticalSection, EnterCriticalSection,
           LeaveCriticalSection, FlsAlloc/Free/GetValue/SetValue,
           InitializeCriticalSectionEx, GetStringTypeW
```

That is **all**. No `WinHttp`, no `WinInet`, no `WSA*`, no `WinSock`,
no `IPHLPAPI`, no `DbgHelp`, no anti-debugger APIs (`IsDebuggerPresent`,
`CheckRemoteDebuggerPresent`, `NtQueryInformationProcess`), no
`NtQuerySystemInformation`. The launcher does not talk to the network and
does not attempt to detect a debugger. Themida VM provides some runtime
tamper resistance at the binary level, but the launcher source itself
is straight C++ over the CRT.

## 2. Themida layout

The launcher is **Themida-protected**: a Themida VM unpacking stub runs
on every entry point. The PE carries the canonical Themida section
names that show up on the Section table:

| Section | RVA | Size | Role |
|---------|-----|------|------|
| `.text` | 0x1000 | 102 400 | Main code; some of it runs inside the Themida VM. |
| (unnamed) | 0x1A000 | 49 152 | Strings / data. |
| `.themida` | 0x2F000 | 6 348 800 | Themida VM bytecode + obfuscated code. |
| `.boot` | 0x63D000 | 3 928 064 | Themida VM unpacker stub (jitted on first call). |
| `.SCY` | 0x9FC000 | 4 096 | Themida security cookie / anti-tamper magic. |
| `.extern` | 0x9FD000 | 864 | Extern data referenced by the VM. |
| `.synthetic_builtins` | 0x9FD360 | 48 | Synthetic intrinsic stubs. |

The binary supplied to this repo (`unpacked_GarlicNELauncherV2.exe`)
has had the Themida VM **partially stripped** so that the entry point
jumps straight into the deobfuscated original code. The remaining
`.themida`/`.boot`/`.SCY` sections are still in the file but are
referenced only by the security cookie (`__security_check_cookie` reads
`data_140049080` and `data_140026000`).

After Themida stripping, the launcher exhibits the standard C++
runtime layout with VCRUNTIME140 / ucrtbase / MSVCP140 imports.

## 3. Top-level call graph (post-Themida)

```
_start  (0x140003190)
└── main  (0x14000b6c0, 4318 bytes, complexity 84)
    ├── [print banner]
    │   └── sub_140001740 × N   (printf-style wstring writer)
    ├── parse CLI flags
    │   ├── --nowait / --wait         → flag in `r13`
    │   ├── --injector <path>         → path of GarlicInjector.exe
    │   ├── --package <path>          → path of GarlicProxy.pkg
    │   └── --dll / --help / -h / -?
    ├── build the auth block (see auth.md)
    │   ├── QueryPerformanceCounter
    │   ├── GetTickCount64
    │   ├── GetCurrentProcessId
    │   └── FNV-1a("GarlicBridge-V2-20260809") → bridge_seed
    ├── require license key                ← STEP 1/3 of the launcher UI
    │   └── sub_1400078e0  (prompt + strcmp "dasuan666")
    │       sub_140006140 prints "1 / 3 "
    │       returns 1 on success, 0 after 3 wrong attempts
    ├── verify the two files exist          ← STEP 2/3
    │   └── sub_14000ceb0  (GetFileAttributesExW)
    │       sub_140006140 prints "2 / 3 "
    ├── spawn the injector                  ← STEP 3/3
    │   └── sub_140006a30  (builds command line, CreateProcessW, waits)
    │       sub_140006140 prints "3 / 3 "
    └── print exit code / cleanup
```

So the launcher is **three console steps** that the user has to clear
before the actual proxy gets started: password, file-existence,
spawn-child. The middle step's check is actually per-file (`0xa000000c`
/ `0xa0000003` are Win32 `STATUS_DELETE_PENDING` / `FILE_NOT_FOUND` /
`PATH_NOT_FOUND` etc.); the launcher differentiates "permission denied"
from "not found" and prints slightly different text for each.

## 4. The license-key prompt

```
sub_1400078e0(hConsole)
{
    print "1 / 3 ";
    print prompt text from data_140034b38;
    do
        read_line (sub_140006550 reads into var_68);
        if (strcmp(input, L"dasuan666") == 0)
            print green "OK";
            return 1;
        else
            print red "wrong" / "wrong again";
            attempts++;
    while (attempts < 3);
    return 0;
}
```

The wide string literal `L"dasuan666"` is plain ASCII (`dasuan` = 拼音
"大蒜" / garlic) and is preserved in the `.rdata` for the launcher
only — it is not in the injector. There is **no cryptographic check**;
`dasuan666` is just `strcmp()`-ed against the user's input.

This is the only anti-piracy mechanism in the launcher. It is bypassed
by either:

* typing `dasuan666` (a freely distributed public string), or
* replacing `unpacked_GarlicNELauncherV2.exe` with a stub launcher
  that skips the prompt, or
* driving the injector directly (it has no UI of its own).

For the purposes of interop analysis this key check is irrelevant:
the injector only needs the right auth-nonce/auth-token pair, which
can be derived by anyone from the FNV-1a construction documented in
`auth.md`.

## 5. Summary

| Property | Value |
|----------|-------|
| Talks to the network? | No. |
| Anti-debug? | No (Themida VM provides some VM-level tamper resistance only). |
| Cryptographic protection of the proxy DLL? | None in this binary — encryption is performed inside `data/GarlicInjector.exe` (see `injector.md`). |
| Anti-tamper for itself? | License-key `strcmp` (`dasuan666`), with 3 attempts. |
| Useful logic? | Just UI, CLI parsing, child-process spawning. |

This is essentially the same logic as `proxy/launcher.ps1`, with the
license-key prompt added on top and the child-process launcher
(`sub_140006a30`) calling `CreateProcessW` instead of `& $Injector`.