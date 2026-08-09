# Package format and decryption

This file documents the on-disk format of `GarlicProxy.pkg` and the
algorithm used by `data/GarlicInjector.exe` to decrypt it. For a
runnable decoder, see [`artifacts/decrypt_pkg.py`](../artifacts/decrypt_pkg.py).

The structure here is the same as `README.md §1`, expanded with the
reverse-engineering reasoning that landed on each field.

## 1. Identification

The launcher drops these strings as identifiers in the binary:

* `data_14001a450` (RVA `0x14001a450`, file offset `0x19880`):
  `"GarlicBridge-V2-20260809"` (24 bytes). This is the **shared
  secret / version identifier** for the 2026-08-09 build of the
  proxy.
* `data_14001ac18` (file offset `0x19c18`):
  `"GNP2PKG!"` (8 bytes). This is the **file magic** for the
  encrypted package.

Both strings are referenced from inside `sub_1400021e0` (the
decryption function). They are the only two human-readable strings
sitting in the `.rdata` segment of the injector (Themida stripped).

## 2. Header layout (100 bytes, little-endian)

| Offset | Size | Meaning |
|--------|------|---------|
| 0x00   | 8    | Magic ASCII `"GNP2PKG!"` |
| 0x08   | 4    | Format version (must be `2`) |
| 0x0C   | 4    | Header size (must be `0x64` = 100) |
| 0x10   | 8    | Ciphertext length N (LE) |
| 0x18   | 16   | PBKDF2 salt |
| 0x28   | 12   | AES-GCM nonce |
| 0x34   | 32   | Reserved / auxiliary header fields (covered by AAD) |
| 0x54   | 16   | AES-GCM tag |
| 0x64   | N    | AES-GCM ciphertext (plaintext = Windows x64 PE DLL) |

The injector validates:

```
file_size == N + 100
b"GNP2PKG!" == header[0:8]
2            == *(uint32_t*)&header[0x08]
0x64         == *(uint32_t*)&header[0x0C]
N            == *(uint64_t*)&header[0x10]
N > 0
```

The `memcmp` against `"GNP2PKG!"` is at `sub_1400021e0:0x1400024cb`
(see `xrefs_to 0x14001ac18`). The version / header-size /
payload-length checks live in the same function.

The version and header-size checks together (`zmm6:8:4 == 2`,
`rcx_12 == 0x64`) imply that this format is **fixed at 100 bytes**:
the launcher / injector would refuse any package with a different
header layout, so the salt / nonce / tag offsets above are stable.

## 3. PBKDF2 password

The injector derives the AES-GCM key with a single hard-coded
password that lives in `.rdata` of the unpacked injector:

* Address: `data_14001a880` (RVA, file offset `0x19880` in
  `unpacked_GarlicInjector.exe`).
* Length: 32 bytes (passed as the `cbPassword` argument to
  `BCryptDeriveKeyPBKDF2`).
* Hex bytes:

  ```
  4d 8a 16 c3 57 91 e2 2f 6b d4 09 7e a5 38 f1 64
  b2 0c 73 de 41 9f 25 88 fa 56 1b c9 34 67 ad 02
  ```

The reference to this constant is the second positional argument
of the `BCryptDeriveKeyPBKDF2` call inside `sub_1400021e0` (the
MLIL disassembly shows `rcx_15, 0x14001a880, 0x20, ...`).

## 4. PBKDF2 parameters

The call:

```
BCryptOpenAlgorithmProvider(&alg, "SHA256", nullptr,
                            BCRYPT_ALG_HANDLE_HMAC_FLAG);
BCryptDeriveKeyPBKDF2(
    alg,
    password = 0x14001a880, cbPassword = 0x20,
    salt     = &header[0x18] (16 bytes), cbSalt = 0x10,
    cIterations = 0x124F8 = 75 000,
    pbDerivedKey = &var_b8, cbDerivedKey = 0x20,
    dwFlags = 0);
```

So the key is

```
key = PBKDF2-HMAC-SHA256(
        password = the 32-byte constant above,
        salt     = header[0x18:0x28],     # 16 bytes from the package
        c        = 75 000,                 # 0x124F8
        dkLen    = 32);
```

The injector runs **75 000 iterations** of HMAC-SHA256 to produce the
32-byte AES-256 key. There is no salt evolution, no counter
overrides — a textbook PBKDF2.

## 5. AES-GCM decrypt

After deriving the key, the injector:

```
BCryptOpenAlgorithmProvider(&alg, "AES", nullptr, 0);
BCryptSetProperty(alg, "ChainingMode", "ChainingModeGCM", 32, 0);
BCryptGetProperty(alg, "ObjectLength", &obj_len, 4, ...);
key_obj = HeapAlloc(...);
BCryptGenerateSymmetricKey(alg, &hKey, key_obj, obj_len,
                          &var_b8, 0x20, 0);  // var_b8 is the PBKDF2 output

out_buf = HeapAlloc(..., payload_size);
BCryptDecrypt(
    hKey,
    pbInput       = &header[0x64],
    cbInput       = payload_size,
    pPaddingInfo  = &{
        cbSize        = 0x58,
        dwInfoVersion = 1,
        pbNonce       = &header[0x28], cbNonce = 12,
        pbAuthData    = &header[0x00], cbAuthData = 0x54,
        pbTag         = &header[0x54], cbTag = 16,
    },
    pbIV = nullptr, cbIV = 0,
    pbOutput = out_buf, cbOutput = payload_size,
    pcbResult, dwFlags = 0);
```

The GCM parameters were derived from the MLIL disassembly of the
`BCryptDecrypt` call in `sub_1400021e0`. The relevant MLIL:

```
r8_9 = var_118:0.d                              # payload size
pbInput = zx.q(var_128:0xc.d) + lpMem           # ciphertext start = lpMem + 0x64
paddingInfo:8.q = &var_108:8                    # pbNonce = lpMem + 0x28
var_178:0.d = 0xc                               # cbNonce  = 12
var_168:0.d = 0x54                              # cbAuthData = 84 (covers header[0..83])
var_168:8.q = &var_d8:4                         # pbAuthData = lpMem + 0x54
var_158:0.d = 0x10                              # cbTag    = 16
rax_32 = 0x140002caf(...)                        # BCryptDecrypt
```

That is:

* `pbNonce = lpMem + 0x28`, 12 bytes — **header bytes 40..51**.
* `pbAuthData = lpMem + 0x00`, 84 bytes — **header bytes 0..83**.
* `pbTag = lpMem + 0x54`, 16 bytes — **header bytes 84..99**.
* `pbInput = lpMem + 0x64`, payload_size bytes — the rest of the file.

In particular, the AAD covers the magic, version, header-size,
payload-size, salt and nonce fields (84 bytes total). The tag
sits at the end of the header (the last 16 bytes before the
ciphertext).

## 6. Post-decrypt integrity checks

After `BCryptDecrypt` returns, the injector runs:

```
1) SHA-256 of plaintext -> hash (sub_140001e80)
2) memcmp(hash, &header[0x34], 0x20)              # 32-byte compare
3) plaintext[0:2] == "MZ"
```

The SHA-256 expected hash is stored in the header at offsets
`0x34..0x53` (32 bytes — inside the AAD range). The MZ check
ensures the decrypted blob is a PE file.

If either check fails the decryptor reports an error and the
launcher exits non-zero.

## 7. Reference decoder (Python)

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

The cryptography library's `AESGCM.decrypt(nonce, ciphertext + tag, aad)`
matches the BCrypt contract: `nonce` is the 12-byte IV, the input is
the AES-GCM input concatenated with the 16-byte tag, and `aad` is the
authenticated-but-not-encrypted data.

## 8. Why the format is what it is

Looking at the choices the injector made, several are forced by the
constraints, not arbitrary:

* **Header size `0x64 = 100`** comes out of "magic + version + size
  + payload-size + salt + nonce + tag = 100 bytes". The version
  field (`2`) seems to be a future-proofing slot (current code
  hard-rejects anything that is not exactly `2`).
* **AES-GCM nonce length = 12** is the standard GCM IV size; the
  spec recommends 12 bytes and warns against longer IVs.
* **AES-GCM tag length = 16** is the standard 128-bit GCM tag.
* **PBKDF2 iterations = 75 000** is on the lower side of "good
  practice" (OWASP 2023 recommends 600 000 for SHA-256). The low
  count is consistent with this being a *gating* / *cosmetic*
  measure, not a real attempt to make brute force expensive.

## 9. What the format protects against

* Casual copying of the .pkg file: yes (the file is opaque without
  the injector; it is not "plaintext DLL in a zip").
* Tampering of the package: yes — both GCM tag integrity and the
  in-header SHA-256 hash detect any modification.
* Brute-force recovery of the plaintext without the PBKDF2 password:
  **no** — the password is hard-coded in the injector, so brute
  force is not even required.
* Anyone holding the PBKDF2 password (which is everyone, since it
  ships in plain text in `data/GarlicInjector.exe`): **no
  protection at all.** This is the situation we are in.