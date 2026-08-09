# Analysis

Reverse-engineering notes for the two binaries that ship with the
GarlicV2 distribution:

* `unpacked_GarlicNELauncherV2.exe` — the launcher (Themida wrapper).
* `data/GarlicInjector.exe` — the reflector / pkg-decryptor.

Plus an analysis of the DLL that comes out of decrypting
`data/GarlicProxy.pkg` (`artifacts/GarlicProxy.dll`).

| File | Covers |
|------|--------|
| `decryption.md` | Format of `GarlicProxy.pkg`, PBKDF2 parameters, AES-GCM layout, session auth nonce/token. |
| `launcher.md`    | `unpacked_GarlicNELauncherV2.exe` — Themida layout, imports, license-key prompt, child-process spawn. |
| `injector.md`    | `data/GarlicInjector.exe` — auth verify, EnumWindows PID hunt, reflective DLL injection, SeDebugPrivilege. |
| `proxy.md`       | The decrypted DLL — HookBridge trampolines, `ClassFileLoadHook` bytecode splice into `net.minecraft.network.Connection`, RelayHandler, B-side Netty server on port 25565. |
| `auth.md`        | The `auth-nonce` / `auth-token` construction used by the launcher, and why it's not a security boundary. |

All of these files are reverse-engineering notes; they describe what
the binaries do, not how to use the binaries. No source code from the
SakuraTools project is reproduced here.

For the package format and a working decryption tool, see
[`artifacts/decrypt_pkg.py`](../artifacts/decrypt_pkg.py) and
[`README.md` §1](../README.md#1-restoring-garlicproxydll-from-garlicproxypkg).