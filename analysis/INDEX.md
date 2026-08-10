# Analysis

Reverse-engineering notes for the two binaries that ship with the
GarlicV2 distribution:

* `unpacked_GarlicNELauncherV2.exe` — the launcher (Themida wrapper).
* `data/GarlicInjector.exe` — the reflector / pkg-decryptor.

Plus an analysis of the DLL that comes out of decrypting
`data/GarlicProxy.pkg` (`artifacts/GarlicProxy.dll`).

| File | Covers |
|------|--------|
| `decryption.md`  | Format of `GarlicProxy.pkg`, PBKDF2 parameters, AES-GCM layout, session auth nonce/token. |
| `auth.md`        | The `auth-nonce` / `auth-token` construction used by the launcher, and why it's not a security boundary. |
| `launcher.md`    | `unpacked_GarlicNELauncherV2.exe` — Themida layout, imports, license-key prompt, child-process spawn. |
| `injector.md`    | `data/GarlicInjector.exe` — auth verify, EnumWindows PID hunt, reflective DLL injection, SeDebugPrivilege. |
| `injector_diff.md` | **Definitive diff between SakuraTools `injector/` and `data/GarlicInjector.exe`.** 大蒜 added: hex‑decode CLI, FNV‑1a verifier, PBKDF2 + AES‑GCM decryption layer, 24‑byte auth block injection, Themida protection. The `injector/` files are verbatim SakuraTools; `GarlicInjector.exe` is a wrapper around them. |
| `themida.md`     | Themida protection internals: `.themida`/`.boot`/`.SCY` sections, anti-debug, anti-tamper. Why the protection layer is **not** security-relevant for this toolchain. |
| `proxy.md`       | The decrypted DLL — HookBridge trampolines, `ClassFileLoadHook` bytecode splice into `net.minecraft.network.Connection`, RelayHandler, B-side Netty server on port 25565. |
| `bserver.md`     | Full B-side Netty server lifecycle: bootstrap → `ChannelInitializer.initChannel` → per-channel setup → byte-relay handler. Mid-session attach via `Minecraft.execute(Runnable)`. |
| `random_name.md` | The 96-word vocabulary used to generate synthetic class names (`HookBridge`, `g_relay.dotName`, `g_b.dotName`). Seed entropy budget. |
| `threat_model.md`| What the tool actually does and doesn't do. Why the "散播病毒" accusation from the GarlicV2 maintainer is wrong. |
| `dll_vs_native.md` | **Definitive diff between the decrypted DLL and `native/`.** Result: **yes**, 大蒜 added an internal FNV-1a verifier at the start of `DllMain` (`sub_180001ac0` + the `[auth] GarlicProxy internal verification passed/failed` strings). About ~35 lines of new x86-64, the rest of `native/` is byte-for-byte equivalent. |
| `verify/`        | `build_and_verify.ps1` — compiles `native/` to `MinecraftProxy_msvc.dll` and SHA-256-compares it against `artifacts/GarlicProxy.dll`. The decisive test for the "套壳 vs 原创" question. |

All of these files are reverse-engineering notes; they describe what
the binaries do, not how to use the binaries. No source code from the
SakuraTools project is reproduced here.

For the package format and a working decryption tool, see
[`artifacts/decrypt_pkg.py`](../artifacts/decrypt_pkg.py) and
[`README.md` §1](../README.md#1-restoring-garlicproxydll-from-garlicproxypkg).