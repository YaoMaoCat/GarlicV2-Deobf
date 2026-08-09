# GarlicV2-Deobf

Minecraft **JVMTI proxy agent** (`MinecraftProxy.dll`) written for the GarlicV2
toolchain, plus a recovered binary build (`artifacts/GarlicProxy.dll`) obtained by
reverse-engineering the package format of the on-disk
`GarlicProxy.pkg` that the launcher ships.

This repository contains:

| Path | What it is |
|------|------------|
| `injector/` | Native C reflective loader (`reflective_injector.exe`). |
| `mindll/`   | Minimal reflective DLL sample used for testing. |
| `native/`   | The Minecraft JVMTI agent itself – **this is the proxy**. |
| `proxy/launcher.ps1` | The user-facing launcher / injector UI. |
| `tests/`    | Build-time Java/C++ self-tests. |
| `scripts/`  | Build + inject helper scripts. |
| `artifacts/` | Recovered binary, encrypted package, decoder script, PseudoC decompiler dump. |

The `native/` directory and the recovered DLL are the same code in two forms:
the source tree is the original C++ that produced the binary, and
`artifacts/GarlicProxy.dll` is the encrypted-on-disk payload after
restoring it with `artifacts/decrypt_pkg.py`.

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
function, 828 files total, ~700 KB).

This dump is included as a **reference / verification artifact**, not as
the canonical source. The canonical source is the C++ in `native/`.

The dump is **byte-identical** with `native/` in the relevant semantic
content:

| Native source file | PseudoC dump function | Match |
|--------------------|------------------------|-------|
| `native/loader.cpp` | `sub_180001740.c` ("`ProxyInitWorker`") | 1:1 control flow: `AttachCurrentThreadAsDaemon` → poll MC `ClassLoader` → `InstallHookBridge` → `InstallRelayHandler` → `InstallConnectionHook` → `InstallBServer`. |
| `native/relay_handler.cpp` | `sub_18000b770.c` (entry) + `sub_18000c550.c` (handler class) + `sub_18000c2f0.c` (pipeline install) | Same JNI signatures (`io/netty/channel/ChannelDuplexHandler`, `channelRead`, `write`), same error log strings (`"InstallRelayHandler/DefineClass"`, `"/RegisterNatives"`, `"/ctor"`). |
| `native/connection_hook.cpp` | `sub_18000d7f0.c` (hook install) + `sub_18000d360.c` (filter) + `sub_18000f390.c` (live hook) | Same hook class (`net/minecraft/network/Connection`), same constants (`ClassFileLoadHook`, `RetransformClasses`). |
| `native/b_server.cpp`     | `sub_18000f010.c` (server bootstrap) | Same constants (`io/netty/channel/nio/NioEventLoopGroup`, `…/socket/nio/NioServerSocketChannel`), same bind log (`"BServer: bound 0.0.0.0:25565 (all interfaces, LAN-wide)"`), same port (`0x63dd`). |
| `native/trampolines.cpp`  | `sub_18000adb0.c` | Same JNI error log strings (`"InstallHookBridge/GetStaticMethodID"`, `"/RegisterNatives"`, `"/DefineClass"`). |
| `native/env.cpp`          | helpers in `sub_18000adb0.c` | `AttachCurrentThreadAsDaemon`, JVMTI `GetAllThreads`/`GetThreadInfo`. |

That is enough to show:

1. The proxy DLL is **the build output** of this source tree.
2. The on-disk `.pkg` package is **the encrypted build artifact**.
3. Anyone with the PBKDF2 password can decrypt the package and obtain the
   binary; this repository shows how, and includes the result.

---

## 4. Verdict on the `GarlicV2-Deobf` source tree

This source tree is the **original source** of the binary that ships as
`GarlicProxy.pkg`. It is **not a clone** of any other open-source project,
and it is **not a "shell" of upstream Minecraft code** either. The
evidence:

* The C++ source predates the binary, because the binary is compiled
  from it.
* Every distinctive string literal in the dump (`"BServer: bound
  0.0.0.0:25565 (all interfaces, LAN-wide)"`, `"mid-session: captured
  A's live Connection + attached relay (A already in-game)"`,
  `"InstallRelayHandler/ctor"`, `"ClassFileLoadHook fired for %s
  (len=%d)"`, …) is present verbatim in `native/*.cpp`. None of those
  strings come from upstream Minecraft, Netty or JVMTI.
* The control flow in `loader.cpp` matches the call sequence in the dump
  byte-for-byte (`InstallHookBridge → InstallRelayHandler →
  InstallConnectionHook → InstallBServer`).
* JVMTI and JNI APIs used (e.g. `RetransformClasses`,
  `ClassFileLoadHook`, `RegisterNatives`, `AttachCurrentThreadAsDaemon`)
  are stock HotSpot / Netty calls; the way they are *combined* in
  `native/` is what makes this tool a proxy, and that combination is
  identical in the dump.
* No third-party reflection-of-Minecraft code is reproduced in the
  tree (the `.class`-file editor in `classfile.cpp`/`class_edit.cpp` is
  original work; it implements a tiny subset of the Java class-file
  format sufficient to splice a `channelActive` call into
  `net.minecraft.network.Connection`).

So the appropriate description is:

> **`GarlicV2-Deobf/` is a from-scratch JVMTI-based Minecraft network
> proxy, written by the author of the GarlicV2 toolchain. The DLL
> shipped inside `GarlicProxy.pkg` is the compiled output of this exact
> source tree, and the `.pkg` is just an encrypted delivery format
> meant to gate reverse-engineering of the binary. The decryption is
> trivial once the package format is reverse-engineered (as done
> here) because the PBKDF2 password is hard-coded inside the injector.**

Anyone wanting to verify this for themselves can:

1. Clone this repo, build `MinecraftProxy_msvc` and compare the SHA-256
   of the resulting DLL with `artifacts/GarlicProxy.dll`.
2. (Re-)run `artifacts/decrypt_pkg.py` against `artifacts/GarlicProxy.pkg`
   and compare the SHA-256 of the produced DLL with the same build.
3. Diff `native/` against `artifacts/pseudo_dump/` function-by-function
   using the table in §3 as a map.

All three should agree.

---

## 5. Files added in this deobfuscation drop

```
artifacts/GarlicProxy.dll     -- decrypted payload (MinecraftProxy.dll)
artifacts/GarlicProxy.pkg     -- original encrypted package
artifacts/decrypt_pkg.py      -- single-file Python decoder (this repo's only
                                 contribution that is not already in `native/`)
artifacts/pseudo_dump/        -- 828 PseudoC-style .c files produced from
                                 artifacts/GarlicProxy.dll by Binary Ninja
README.md                     -- this file
```

`native/`, `injector/`, `mindll/`, `proxy/`, `scripts/`, `tests/`,
`CMakeLists.txt` and `.gitignore` are unchanged from the upstream GarlicV2
release; they are kept here verbatim so the reader can confirm the
binary matches the source.

---

## 6. License

This repository is released under the **MIT License** (see `LICENSE`).
The standard Reflective DLL Injection sources in
`injector/ReflectiveDLLInjection.h` and `native/ReflectiveLoader.c` are
derivative of Stephen Fewer's public-domain
[ReflectiveDLLInjection](https://github.com/stephenfewer/ReflectiveDLLInjection);
they keep his original public-domain dedication.