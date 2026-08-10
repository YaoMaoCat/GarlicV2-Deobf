# DLL vs `native/`: definitive diff

This file answers the question "**did 大蒜 (GarlicV2 maintainer) add
any code to the proxy DLL that is NOT in the `native/` source tree?**"
The answer is **yes**, and it is documented below.

## 1. Method

1. Extract every double-quoted C string literal from `native/*` (`*.c`,
   `*.cpp`, `*.h`).
2. Extract every double-quoted C string literal from
   `artifacts/pseudo_dump/*.c` (one file per function, decompiler
   output of the decrypted DLL).
3. Take the set difference. Anything that survives as a "real"
   (non-SSA, non-decompiler-noise) string in the DLL but not in
   `native/` is **evidence of code added by 大蒜**.

The script that produces the comparison is
[`analysis/compare_definitive.py`](../compare_definitive.py).

## 2. Result

| Set | Count |
|-----|-------|
| Strings unique to `native/` (not in DLL) | 283 |
| Strings unique to DLL dump (not in `native/`) | 70 |

Of the **70 strings that appear in the DLL dump but not in
`native/`**:

* **67 are truncated halves of longer strings** that DO appear in
  `native/`. The PseudoC decompiler splits each `"… — …"` (em-dash
  `U+2014`) string at the dash, and only the first half is captured
  in the dump's string literals. Examples:

  | `native/` (full string) | DLL dump (truncated half) |
  |---|---|
  | `"Attach: addFirst ALSO threw — giving up"` | `"Attach: addFirst ALSO threw "` |
  | `"BServer: B gone; mid-session — leaving A's connection intact, A resumes control"` | `"BServer: B gone; mid-session "` |
  | `"BServer: intention — %s"` | `"BServer: intention "` |
  | `"BServer: BundlerInfo not found (bundle attr not set — may cause issues on modern servers)"` | `"BServer: BundlerInfo not found (bundle attr not set "` |
  | `"mid-session: captured A's live Connection + attached relay (A already in-game)"` | `"mid-session: captured A's live Connection + attached relay (A already "` |
  | `"login: B in PLAY (empty world); released A's Render thread — mid-session"` | `"login: B in PLAY (empty world); released A's Render thread "` |
  | `"ProxyInitWorker: mid-session — A already in-game; live connection captured, gate skipped"` | `"ProxyInitWorker: mid-session "` |
  | `"Attach: addFirst ALSO threw — giving up"` | `"Attach: addFirst ALSO threw "` |

  This is a decompiler artefact, not a code change. The strings are
  present in `native/` verbatim, including the em-dashes; the
  PseudoC dump just can't represent them as a single literal.

* **3 are genuinely new strings added by 大蒜**:

  ```
  "[auth] GarlicProxy internal verification failed"
  "[auth] GarlicProxy internal verification passed"
  "D:\\.minecraft\\proxy.log"    (note: this one *does* exist in
                                   native/loader.cpp as the
                                   RawWriteFile target, but the
                                   DLL also embeds the literal
                                   constant in sub_1800019f0; not
                                   a duplicate)
  ```

  Of these, the `[auth]` pair is the smoking gun: those strings are
  emitted by **new code in the DLL's `DllMain`** that performs an
  **internal authentication check** before normal `DllMain`
  processing begins.

## 3. The added code: `sub_180001ac0` + the modified `sub_180001ba0`

### 3.1 `sub_180001ba0` (modified `DllMain`)

```
int64_t sub_180001ba0(HMODULE arg1, int32_t arg2, int64_t* arg3)
{
    if (arg2 == 1)                              // DLL_PROCESS_ATTACH
    {
        if (!sub_180001ac0(arg3))               // <-- NEW CHECK
        {
            sub_1800019f0("[auth] GarlicProxy internal verification failed");
            return 0;                            // <-- refuse to load
        }
        sub_1800019f0("[auth] GarlicProxy internal verification passed");

        // original native/ DllMain flow follows
        sub_1800019f0("[raw] DllMain entry");
        DisableThreadLibraryCalls(arg1);
        sub_1800019f0("[raw] DisableThreadLibraryCalls done");
        HANDLE hObject = CreateThread(nullptr, 0, sub_1800014d0, nullptr,
            THREAD_CREATE_RUN_IMMEDIATELY, nullptr);
        if (hObject) CloseHandle(hObject);
        sub_1800023a0("=== DllMain PROCESS_ATTACH ===",
                       sub_1800019f0("[raw] CreateThread done"));
        sub_1800019f0("[raw] first LogTo returned");
    }
    return 1;
}
```

For comparison, the unmodified `native/loader.cpp:151`:

```
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        RawWriteFile("[raw] DllMain entry");
        DisableThreadLibraryCalls(hModule);
        RawWriteFile("[raw] DisableThreadLibraryCalls done");
        HANDLE h = CreateThread(nullptr, 0, BootstrapThread, nullptr, 0, nullptr);
        if (h) CloseHandle(h);
        RawWriteFile("[raw] CreateThread done");

        LogTo("=== DllMain PROCESS_ATTACH ===");
        RawWriteFile("[raw] first LogTo returned");
    }
    return TRUE;
}
```

**The diff**: 大蒜 wrapped the entire body in `if (sub_180001ac0(arg3))`,
and returns `0` (load failed) if the check fails. The two `[auth]…`
log strings are unique to the DLL.

### 3.2 `sub_180001ac0` — the new internal verifier

```
int64_t sub_180001ac0(int64_t* arg1)
{
    int64_t rax;
    if (arg1 && *arg1 == 0x4741524c49434155)        // magic: "GARLICAU"
    {
        rax = 0x14650fb0739d0383;                    // FNV-1a offset basis

        // FNV-1a hash of the "GarlicBridge-V2-20260809" bridge string,
        // 25-byte loop (rdx_1 < 0x19):
        for (int rcx = 0; rcx + 1 < 0x19; ++rcx)
        {
            int64_t rax_1 = rax ^ data_180030488[rcx];
            rax = rax_1 * 0x100000001b3;              // FNV-1a prime
        }

        // FNV-1a chain over the 8-byte nonce at arg1[1]:
        for (int r8_1 = 0; r8_1 < 8; ++r8_1)
        {
            int64_t rax_2 = rax ^ (arg1[1] >> (r8_1 << 3));
            rax = rax_2 * 0x100000001b3;
        }

        // Final XOR + FNV-1a round:
        int64_t rax_3 = rax ^ 0x4741524c49434155;
        result = rax_3 * 0x100000001b3;
    }

    // Compare against the supplied token at arg1[2]:
    if (!arg1 || *arg1 != 0x4741524c49434155 || arg1[2] != result)
        result = 0;
    else
        result = 1;
    return result;
}
```

The constants `0x4741524c49434155` ("GARLICAU"),
`0x14650fb0739d0383` (FNV-1a 64-bit offset basis), and
`0x100000001b3` (FNV-1a 64-bit prime) are **identical** to those
used in:

* `unpacked_GarlicNELauncherV2.exe::sub_140001000` (launcher-side
  verifier), and
* `unpacked_GarlicInjector.exe::sub_140001000` (injector-side
  verifier, see [`analysis/injector.md`](injector.md) and
  [`analysis/auth.md`](auth.md)).

And the `data_180030488` array is the 25-byte
`"GarlicBridge-V2-20260809"` constant (the same shared-secret
string the launcher uses). The loop bounds `0x19 = 25` and the
8-byte chain over `arg1[1]` match exactly.

So `sub_180001ac0` is **byte-for-byte the same FNV-1a
authentication scheme used in the launcher / injector**, just
**duplicated inside the DLL**.

### 3.3 What this means

Without the right 24-byte auth block in `arg3`, the DLL's
`DllMain` returns `0` and **does not load**. This means:

* Reflective-injecting the DLL with a hand-crafted `lpParameter`
  (e.g. just `NULL`) will not work — the DLL refuses to load.
* The injector **must** write the 24-byte
  `("GARLICAU", nonce, token)` auth block into the target before
  `CreateRemoteThread` lands on the DLL's `ReflectiveLoader`, just
  as the documented flow already does.
* If the auth block is wrong (e.g. computed with a tampered
  FNV-1a), the DLL exits silently with the "verification failed"
  message written to `D:\.minecraft\proxy.log`.

This is a **defensive hardening on top of the upstream SakuraTools
source**. 大蒜 did not modify any of the existing code; they
**added one function (`sub_180001ac0`) and wrapped `DllMain`
around it**. The wrapper is ~10 lines of code; the verifier is
~25 lines. The total new code is roughly **35 lines of x86-64**
in a binary of 835 functions.

## 4. Where the auth block comes from

The 24-byte auth block written into the target's memory by the
injector (`sub_140001bf0` in `data/GarlicInjector.exe`) is
populated by `data_140046048` (random class name) + `data_140046058`
(random class name) + nonce + token. The auth block's first 8
bytes are the constant `0x4741524c49434155` ("GARLICAU").

Looking at the DLL's `sub_180001ba0`, the auth block is
**also** the third argument (`arg3`, `lpReserved`): the same
memory the launcher / injector put there. So `sub_180001ac0`
verifies the same 24 bytes that `sub_140001000` in the launcher /
injector verifies — three independent checks of the same value,
in three different binaries, all using the same FNV-1a chain.

## 5. Conclusion

> **大蒜** modified `native/` by:
>
> 1. Adding a 24-byte FNV-1a verifier (`sub_180001ac0` in the DLL)
>    at the very start of `DllMain`, with two new log strings:
>    `[auth] GarlicProxy internal verification passed` /
>    `[auth] GarlicProxy internal verification failed`.
> 2. Wrapping the original `DllMain` body in a conditional on that
>    verifier, returning `0` (load failure) if the auth check
>    fails.
> 3. Otherwise leaving `native/` byte-for-byte equivalent to the
>    DLL.

No other source-level additions were detected in
`native/*.cpp`/`*.c`/`*.h`. Every other difference between the
native/* string set and the DLL dump's string set is a
decompiler artefact (truncated em-dash strings, SSA variables,
CRT wrapper functions, etc.).

The total amount of new code is small (~35 lines x86-64),
behaviour-wise equivalent to "load only when the launcher asked
you to". It is in line with the GarlicV2 distribution's anti-piracy
position (the launcher requires the licence key `dasuan666`),
but it lives **entirely inside the proxy DLL**, not in `native/`,
which is the part of this repository that is verbatim from
SakuraTools.

## 6. How to verify

* Open `analysis/compare_definitive.py`. It walks `native/` and
  `artifacts/pseudo_dump/`, pulls every string literal, and reports
  the difference. The output lists exactly the 3 strings above as
  "unmatched" (everything else matches after accounting for
  em-dash truncation).
* Open `artifacts/pseudo_dump/sub_180001ba0.c`. This is the
  modified DllMain. The first conditional
  `if (!sub_180001ac0(arg3))` is the new wrapper.
* Open `artifacts/pseudo_dump/sub_180001ac0.c`. This is the new
  FNV-1a verifier. The constants
  `0x4741524c49434155`, `0x14650fb0739d0383`, `0x100000001b3` are
  identical to the launcher / injector.
* Compare `native/loader.cpp:151` (the unmodified `DllMain`) to
  `sub_180001ba0.c` (the DLL's actual `DllMain`). The two
  `[auth]…` log strings and the `if (!sub_180001ac0(arg3))` guard
  are the additions.