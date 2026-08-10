# GarlicV2-Deobf

> **中文版本: [README_CN.md](README_CN.md)**

> **This is not an original project.**
>
> Every C / C++ / PowerShell / CMake file in this tree (everything in
> `injector/`, `mindll/`, `native/`, `proxy/`, `scripts/`, `tests/`,
> `CMakeLists.txt`) is **source from**
> [GzSakura1338/SakuraTools](https://github.com/GzSakura1338/SakuraTools)
> (the "Garlic" / "GarlicV2" Minecraft JVMTI proxy toolchain).
> The only exception is `native/loader.cpp`, which has been modified to
> match the binary: GarlicV2's maintainer added an FNV-1a internal
> authentication check to `DllMain` (~35 lines; see
> [`analysis/dll_vs_native.md`](analysis/dll_vs_native.md)).
> Everything else is included here **only** so a reader can verify that
> the DLL recovered from `artifacts/GarlicProxy.pkg` matches the source
> it claims to come from.
>
> The only thing this repository actually contributes is:
>
> - `analysis/` — full reverse-engineering notes (launcher, injector, Themida, proxy DLL internals, BServer, auth, DLL vs native diff).
> - `artifacts/GarlicProxy.pkg` – the encrypted package as shipped.
> - `artifacts/GarlicProxy.dll` – the DLL obtained by decrypting it.
> - `artifacts/decrypt_pkg.py`  – the decryption script.
> - `artifacts/pseudo_dump/`    – a PseudoC decompiler dump of the DLL,
>   included as additional verification.
>
> **Do not treat this repository as original work.** All credit for the
> proxy, the launcher, the reflective injector and the build system
> belongs to the SakuraTools authors. The package format and decryption
> keys documented in §1 below were recovered from the publicly
> distributed `unpacked_GarlicNELauncherV2.exe` / `data/GarlicInjector.exe`
> binaries purely for interoperability analysis.

This repository contains:

| Path | What it is |
|------|------------|
| `injector/` | **SakuraTools core** + **大蒜's additions.**  `cli.c`, `Inject.c`, `LoadLibraryR.c`, `GetProcAddressR.c`, `inject_ll.c` are verbatim SakuraTools. `garlic_auth.c` (FNV-1a verifier + hex decode), `garlic_injector.c` (auth‑block CLI + remote injection) and `garlic_auth.h` were reconstructed from the binary. |
| `mindll/`   | Minimal reflective DLL sample used for testing. **(SakuraTools source, unchanged.)** |
| `native/`   | The Minecraft JVMTI agent itself. **(SakuraTools source; `loader.cpp` DllMain modified — FNV-1a verifier added to match the binary.)** |
| `proxy/launcher.ps1` | The user-facing launcher / injector UI. **(SakuraTools source, unchanged.)** |
| `tests/`    | Build-time Java/C++ self-tests. **(SakuraTools source, unchanged.)** |
| `scripts/`  | Build + inject helper scripts. **(SakuraTools source, unchanged.)** |
| `analysis/` | **New in this repo.** Full reverse-engineering notes (launcher, injector, Themida, proxy DLL internals, BServer, auth mechanism, DLL vs native diff). |
| `artifacts/` | **New in this repo.** Recovered binary, encrypted package, decoder script, PseudoC dump. |
| `artifacts/decrypt_pkg.py` | **Only new code.** Single-file Python decryptor; everything else is documentation / dumped artifacts. |

---

## 1. Restoring `GarlicProxy.dll` from `GarlicProxy.pkg`

The launcher (`data/GarlicInjector.exe`) reads `GarlicProxy.pkg`, decrypts it
into memory, and reflective-loads the resulting DLL into the target Java
process. The package format is undocumented and the decryption key is
hard-coded into the injector, so the package itself is opaque without
reversing the injector.

We recovered the format and re-implemented the decryptor in pure Python.
Reconstructing the DLL from `data/GarlicProxy.pkg`:

```
python artifacts/decrypt_pkg.py
# writes GarlicProxy.dll (301 056 bytes) in the current directory
```

Tested with the build of `data/GarlicProxy.pkg` shipped with
`unpacked_GarlicNELauncherV2.exe` (string `"GarlicBridge-V2-20260809"`).

### 1.1 Package header layout (100 bytes, little-endian)

```
Offset  Size  Meaning
0x00    8     Magic ASCII "GNP2PKG!"
0x08    4     Format version (must be 2)
0x0C    4     Header size (must be 0x64 == 100)
0x10    8     Ciphertext size N (LE)
0x18    16    PBKDF2 salt
0x28    12    AES-GCM nonce
0x34    32    Reserved/auxiliary header fields (covered by AAD)
0x54    16    AES-GCM tag
0x64    N     AES-GCM ciphertext (plaintext = a Windows x64 PE DLL)
```

Validation done by the injector:

```
file_size == N + 100
b"GNP2PKG!" == header[0:8]
2            == *(uint32_t*)&header[0x08]
0x64         == *(uint32_t*)&header[0x0C]
N            == *(uint64_t*)&header[0x10]
N > 0
```

### 1.2 Key derivation

The injector uses a single hard-coded PBKDF2 password (32 bytes,
file-relative offset `0x19_880` inside `unpacked_GarlicInjector.exe`):

```
4d 8a 16 c3 57 91 e2 2f 6b d4 09 7e a5 38 f1 64
b2 0c 73 de 41 9f 25 88 fa 56 1b c9 34 67 ad 02
```

Key derivation:

```
key = PBKDF2-HMAC-SHA256(
        password = above 32-byte constant,
        salt     = header[0x18 : 0x28],     # 16 bytes
        iter     = 75 000,                  # 0x124F8
        dklen    = 32)
```

Algorithm:

```
BCryptOpenAlgorithmProvider(&alg, "SHA256", nullptr, BCRYPT_ALG_HANDLE_HMAC_FLAG)
BCryptDeriveKeyPBKDF2(alg, password, 32, salt, 16, 75 000, key_out, 32, 0)
```

### 1.3 Payload decryption (AES-256-GCM)

```
BCryptOpenAlgorithmProvider(&alg, "AES", nullptr, 0)
BCryptSetProperty(alg, "ChainingMode", "ChainingModeGCM", 32, 0)
BCryptGenerateSymmetricKey(alg, &key, obj, obj_len, key, 32, 0)
BCryptDecrypt(
    key,
    plaintext      = header + 0x64,
    plaintext_len  = N,
    paddingInfo    = {
        cbSize        = 0x58,
        dwInfoVersion = 1,
        pbNonce       = header + 0x28, cbNonce = 12,
        pbAuthData    = header + 0x00, cbAuthData = 0x54,    # 84 bytes
        pbTag         = header + 0x54, cbTag    = 16,
    },
    IV  = nullptr, cbIV = 0,
    out  = heap(N), out_len = N,
    result_len, flags = 0)
```

`AAD` covers the first **84 bytes of the header** (magic + version + sizes +
salt + nonce). The GCM tag occupies the next 16 bytes. The first byte after
that is the ciphertext.

After decryption the injector sanity-checks:

* the GCM tag (handled by `BCryptDecrypt`),
* `memcmp(SHA-256(plaintext), header[0x34:0x54], 32) == 0`,
* the first two bytes of plaintext are `"MZ"`.

If any check fails, the package is rejected and the launcher exits with a
non-zero code.

### 1.4 `auth-nonce` / `auth-token` (session authentication)

`GarlicInjector.exe` is called as:

```
GarlicInjector.exe <pkg-path> --auth-nonce <16-hex-chars> --auth-token <16-hex-chars>
```

The launcher builds the nonce and token per session:

```
bridge_seed = FNV1a-64("GarlicBridge-V2-20260809", seed = 0x14650fb0739d0383)
nonce       = QueryPerformanceCounter()
                ^ (GetTickCount64() << 0x11)
                ^ (GetCurrentProcessId()  << 0x20)
                ^ &QueryPerformanceCounter
token       = FNV1a-64(nonce, seed = bridge_seed, finish = "GARLICAU" XOR)
```

The 24-byte "auth block" passed into the injector's working function is

```
arg3[0] = 0x4741524c49434155     // "GARLICAU"
arg3[1] = nonce (8 bytes LE)
arg3[2] = token (8 bytes LE)
```

The injector re-derives `token'` from `arg3[1]` using the same FNV-1a
algorithm and accepts the call only if `token' == arg3[2]`. After the auth
gate, **`sub_140001000`/`sub_140001750`/`sub_1400021e0` are the only
functions that touch the package, and none of them consume `arg3` for
key derivation** – the PBKDF2 password is the hard-coded 32-byte constant.
Therefore:

> **The session `auth-nonce` / `auth-token` are an anti-tamper gate only.
> They are NOT used in key derivation. Anyone holding the hard-coded
> PBKDF2 password can decrypt the package without going through the
> launcher.**

That is exactly what `artifacts/decrypt_pkg.py` does.

### 1.5 Reference decoder (Python)

```python
import hashlib
from cryptography.hazmat.primitives.ciphers.aead import AESGCM

PWD = bytes.fromhex(
    "4d8a16c35791e22f6bd4097ea538f164b20c73de419f2588fa561bc93467ad02")

def decrypt(pkg_path):
    d = open(pkg_path, "rb").read()
    assert d[:8] == b"GNP2PKG!"
    n        = int.from_bytes(d[0x10:0x18], "little")
    salt     = d[0x18:0x28]
    nonce    = d[0x28:0x34]
    aad      = d[0x00:0x54]
    tag      = d[0x54:0x64]
    ct       = d[0x64:0x64 + n]

    key = hashlib.pbkdf2_hmac("sha256", PWD, salt, 75_000, dklen=32)
    return AESGCM(key).decrypt(nonce, ct + tag, aad)
```

The full reference implementation is `artifacts/decrypt_pkg.py`.

---

## 2. Building the proxy from source

The proxy DLL is built from `native/` (CMake target `MinecraftProxy_msvc`).
`artifacts/GarlicProxy.dll` is the result of decrypting
`artifacts/GarlicProxy.pkg` – it is the same binary the source tree
compiles to.

```
cmake -S . -B build -G "Ninja"      # or "Visual Studio 17 2022"
cmake --build build --target MinecraftProxy_msvc --config Release
```

The reflective injector is built from `injector/`:

```
cmake --build build --target reflective_injector --config Release
```

The launcher is a PowerShell script (`proxy/launcher.ps1`); run it on the
build host and pick *"Inject proxy (auto-wait for MC window)"* once the
game is running.

---

## 3. About `artifacts/pseudo_dump/`

`artifacts/pseudo_dump/` is the output of running Binary Ninja's
PseudoC decompiler over `artifacts/GarlicProxy.dll` (one C file per
function, 828 files total, ~700 KB). It is included **only** so that
the match between the DLL and the SakuraTools source tree in `native/`
can be confirmed by anyone with a decompiler; it is not a substitute
for the real source and is not maintained.

Cross-reference between the SakuraTools source and the dump:

| SakuraTools source (in `native/`) | PseudoC dump function | What matches |
|--------------------|------------------------|-------|
| `native/loader.cpp` | `sub_180001740.c` ("`ProxyInitWorker`") | 1:1 control flow: `AttachCurrentThreadAsDaemon` → poll MC `ClassLoader` → `InstallHookBridge` → `InstallRelayHandler` → `InstallConnectionHook` → `InstallBServer`. |
| `native/relay_handler.cpp` | `sub_18000b770.c` (entry) + `sub_18000c550.c` (handler class) + `sub_18000c2f0.c` (pipeline install) | Same JNI signatures (`io/netty/channel/ChannelDuplexHandler`, `channelRead`, `write`), same error log strings (`"InstallRelayHandler/DefineClass"`, `"/RegisterNatives"`, `"/ctor"`). |
| `native/connection_hook.cpp` | `sub_18000d7f0.c` (hook install) + `sub_18000d360.c` (filter) + `sub_18000f390.c` (live hook) | Same hook class (`net/minecraft/network/Connection`), same constants (`ClassFileLoadHook`, `RetransformClasses`). |
| `native/b_server.cpp`     | `sub_18000f010.c` (server bootstrap) | Same constants (`io/netty/channel/nio/NioEventLoopGroup`, `…/socket/nio/NioServerSocketChannel`), same bind log (`"BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)"`), same port (`0x63dd`). |
| `native/trampolines.cpp`  | `sub_18000adb0.c` | Same JNI error log strings (`"InstallHookBridge/GetStaticMethodID"`, `"/RegisterNatives"`, `"/DefineClass"`). |
| `native/env.cpp`          | helpers in `sub_18000adb0.c` | `AttachCurrentThreadAsDaemon`, JVMTI `GetAllThreads`/`GetThreadInfo`. |

The match is consistent across every distinctive string literal in the
binary, which confirms the binary is compiled from the SakuraTools
source tree.

---

## 4. Provenance / attribution

The "Garlic" / "GarlicV2" Minecraft JVMTI proxy toolchain is the work
of the **SakuraTools** project:

* Repository: <https://github.com/GzSakura1338/SakuraTools>
* Author / maintainer: **GzSakura1338**

Everything in this tree under `injector/`, `mindll/`, `native/`,
`proxy/`, `scripts/`, `tests/`, `CMakeLists.txt` and the original
`.gitignore` is **verbatim source from SakuraTools**. No file has been
modified; no source has been written here. The presence of those
directories in this repo is **purely so a reader can confirm the DLL
under `artifacts/` matches what the SakuraTools source compiles to.**

What this repository adds on top is **only**:

* `artifacts/GarlicProxy.pkg`     — the encrypted package as shipped.
* `artifacts/GarlicProxy.dll`     — the DLL obtained by decrypting it
  with `artifacts/decrypt_pkg.py`.
* `artifacts/decrypt_pkg.py`      — a 60-line pure-Python decryptor
  (PBKDF2-HMAC-SHA256 + AES-256-GCM) that reproduces the decryption
  done by `data/GarlicInjector.exe`. This is the only piece of code in
  this repository that did not already exist in SakuraTools.
* `artifacts/pseudo_dump/`        — an 828-file PseudoC decompiler dump
  of the DLL, included as additional verification.
* `README.md`, `LICENSE`          — this document.

If you find value in the proxy, the launcher or the reflective
injector, please direct your support, bug reports and stars to the
original SakuraTools repository. This repository is **not** the place
to file issues against the proxy itself.

### 4.1 Why publish it at all, then?

Because the upstream package format is undocumented, and anyone trying
to:

* verify the contents of `data/GarlicProxy.pkg` without running the
  launcher,
* integrate with the launcher from a different OS / toolchain,
* audit what the injector actually does to `MinecraftProxy.dll`,

needs the format reverse-engineered. The reverse engineering is
non-trivial (Themida VM, AES-GCM with header AAD, FNV-1a-based
session authentication) and the result fits in a single Python file.
That file is `artifacts/decrypt_pkg.py`. Everything else in this
repository is documentation / verification.

The GarlicV2 maintainer ("大蒜" / Dev) has previously accused the
author of this repository of "spreading a virus" and removed them
from the project's chat for pointing out that the "GarlicV2"
toolchain is in fact derived from SakuraTools. This repository
does not redistribute any new binary, it just points to the public
binary that the launcher already ships and shows how to confirm it
matches the public source. Any complaints about redistribution
should be addressed to the GarlicV2 maintainer, not to this repo.

---

## 5. Files added in this drop

```
artifacts/GarlicProxy.dll     -- decrypted payload (MinecraftProxy.dll)
artifacts/GarlicProxy.pkg     -- original encrypted package as shipped
artifacts/decrypt_pkg.py      -- single-file Python decoder
                                 (the only piece of new code in this repo)
artifacts/pseudo_dump/        -- 828 PseudoC-style .c files produced from
                                 artifacts/GarlicProxy.dll by Binary Ninja
README.md                     -- this file (replaces the upstream "包转发"
                                 placeholder)
LICENSE                       -- MIT, with public-domain carve-outs for
                                 Reflective DLL Injection sources
```

`native/`, `injector/`, `mindll/`, `proxy/`, `scripts/`, `tests/`,
`CMakeLists.txt` and the original `.gitignore` are unchanged from the
SakuraTools release; they are kept here verbatim so a reader can
confirm the DLL matches the upstream source. They are not authored
here.

---

## 6. License

This repository is released under the **MIT License** (see `LICENSE`).
The C/C++ source in `injector/`, `mindll/`, `native/`, `proxy/`,
`scripts/` and `tests/` is the work of the SakuraTools authors and
remains under whatever license they ship it under; the MIT notice
above applies only to the small amount of **new** code in this
repository (the README, this LICENSE file and
`artifacts/decrypt_pkg.py`).

The standard Reflective DLL Injection sources in
`injector/ReflectiveDLLInjection.h` and `native/ReflectiveLoader.c`
are derivative of Stephen Fewer's public-domain
[ReflectiveDLLInjection](https://github.com/stephenfewer/ReflectiveDLLInjection);
they keep his original public-domain dedication.

The jni.h / jvmti.h headers in `native/include/` are Sun / Oracle
copyrighted header files (Oracle Binary Code License) and remain
under their original licenses; they are reproduced here unmodified
to allow the project to compile without a JDK install.

---

## 7. Reverse-engineering notes

Detailed notes on the launcher, injector and the decrypted proxy
DLL are in [`analysis/`](analysis/INDEX.md):

* [`analysis/decryption.md`](analysis/decryption.md) — the package format.
* [`analysis/auth.md`](analysis/auth.md) — `auth-nonce` / `auth-token`.
* [`analysis/launcher.md`](analysis/launcher.md) — `unpacked_GarlicNELauncherV2.exe`.
* [`analysis/injector.md`](analysis/injector.md) — `data/GarlicInjector.exe`.
* [`analysis/injector_diff.md`](analysis/injector_diff.md) — **diff between SakuraTools `injector/` and `data/GarlicInjector.exe`** (大蒜 added hex‑decode CLI, FNV-1a, PBKDF2+AES-GCM decrypt, auth block injection, Themida).
* [`analysis/injector_chain.md`](analysis/injector_chain.md) — **full auth chain: launcher → injector → DLL** (Mermaid sequence diagram + 5 connection points).
* [`analysis/themida.md`](analysis/themida.md) — Themida protection internals.
* [`analysis/proxy.md`](analysis/proxy.md) — the decrypted DLL.
* [`analysis/bserver.md`](analysis/bserver.md) — B-side Netty server.
* [`analysis/random_name.md`](analysis/random_name.md) — synthetic class names.
* [`analysis/threat_model.md`](analysis/threat_model.md) — what the tool does/doesn't do.
* [`analysis/verify/`](analysis/verify/) — build-and-SHA-256-compare script.
* [`analysis/dll_vs_native.md`](analysis/dll_vs_native.md) — **definitive diff between the DLL and `native/`**; finds that 大蒜 added an internal FNV-1a verifier at the start of `DllMain` (~35 lines of new code; the rest of `native/` is byte-for-byte equivalent).