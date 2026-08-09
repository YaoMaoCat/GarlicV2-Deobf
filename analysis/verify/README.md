# Verify the DLL really came from `native/`

This directory holds a build-and-compare recipe. The point is to
provide hard evidence that:

* the source files in `../native/` are the **only** source the binary
  in `../artifacts/GarlicProxy.dll` could have come from; and
* the binary in `../artifacts/GarlicProxy.dll` is **byte-identical** to
  a fresh build of `MinecraftProxy_msvc`.

This is the single most decisive test for the "套壳 vs 原创" question.

## 1. Files

* `build_and_verify.ps1` — PowerShell script that:
  1. configures MSVC's `vcvars64.bat`,
  2. builds `MinecraftProxy_msvc` with CMake into `build/`,
  3. prints the SHA-256 of the resulting DLL,
  4. compares it to the SHA-256 of `../artifacts/GarlicProxy.dll`.
* `expected.sha256` — the SHA-256 of the file shipped in
  `../artifacts/GarlicProxy.dll`. If a fresh build matches this hash
  exactly, the binary is unambiguously the compiled output of
  `../native/`.

## 2. How to run

From this directory (`analysis/verify/`), in PowerShell 5+:

```powershell
.\build_and_verify.ps1
```

This will:

1. Configure `vcvars64.bat` from
   `C:\Program Files\Microsoft Visual Studio\18\Insiders\VC\Auxiliary\Build\`.
2. Run `cmake -S ../.. -B build -G "Visual Studio 17 2022" -A x64`
   (or fall back to Ninja if VS 17 not present).
3. Build `MinecraftProxy_msvc` in Release.
4. Hash `build/Release/MinecraftProxy_msvc.dll` with SHA-256.
5. Hash `../artifacts/GarlicProxy.dll` with SHA-256.
6. Print both hashes and report MATCH / MISMATCH.

## 3. What a match proves

The CMakeLists in the parent defines `MinecraftProxy_msvc` as
the union of **exactly** the files in `native/`:

```
add_library(MinecraftProxy_msvc SHARED
    native/ReflectiveLoader.c
    native/loader.cpp
    native/env.cpp
    native/random_name.cpp
    native/classfile.cpp
    native/class_edit.cpp
    native/trampolines.cpp
    native/relay_handler.cpp
    native/connection_hook.cpp
    native/world_cache.cpp
    native/b_server.cpp
)
```

with the compile definitions `REFLECTIVEDLLINJECTION_CUSTOM_DLLMAIN`,
`WIN_X64`, `WIN32_LEAN_AND_MEAN`, `NOMINMAX`, `_CRT_SECURE_NO_WARNINGS`.

A SHA-256 match between this build and `artifacts/GarlicProxy.dll`
therefore means **the bytecode-level semantics of every line in
`native/` is exactly what the binary shipped to users contains.**
Anything that does not appear in `native/` does not appear in the
binary. Conversely, anything that *does* appear in the binary but not
in `native/` would be visible in the build diff (likely as different
hash).

## 4. What a mismatch does NOT disprove

* The build may produce a non-deterministic PDB (Microsoft no longer
  ships deterministic-build switches for STL types by default).
  Only the **DLL text / data sections** are hashed, never the PDB.
* Anti-virus software on the build host may patch in-line. If the
  hash differs, try a clean VM.
* The compiler version matters: the original build used the version
  of MSVC available in late 2026 (`Microsoft (R) C/C++ Optimizing
  Compiler Version 19.51.36252` per the dump). Newer toolchains may
  emit slightly different code. The script reports the compiler
  version in use so you can decide whether to chase exact match.

## 5. Caveats

* The expected SHA-256 in `expected.sha256` is **the hash of the
  decrypted payload**, i.e. what `artifacts/decrypt_pkg.py`
  produces. The shipped `data/GarlicProxy.pkg` carries the same
  payload encrypted; running `artifacts/decrypt_pkg.py` against it
  must produce a file with the same hash.
* The build pulls in `native/include/jni.h` and `native/include/jvmti.h`,
  which are unmodified Sun / Oracle headers. They are **not** part of
  the upstream SakuraTools project (SakuraTools expects a JDK
  install); they are included in this repo only for offline
  compilation. They have no effect on the resulting DLL binary
  (no compiled code from them).
* This verification does **not** cover the injector or the launcher.
  Both are Themida-stripped binaries; building them from scratch would
  require reconstructing the pre-Themida state, which is outside the
  scope of this repo.