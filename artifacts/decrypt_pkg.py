#!/usr/bin/env python3
"""Final decryptor with exact layout from MLIL."""
import hashlib
from pathlib import Path
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
from cryptography.exceptions import InvalidTag

PBKDF2_PASSWORD = bytes.fromhex("4d8a16c35791e22f6bd4097ea538f164b20c73de419f2588fa561bc93467ad02")
PKG = Path(r"D:\Minecraft\Dev\GarlicNELauncherV2\data\GarlicProxy.pkg")
OUT = Path(r"D:\Minecraft\Dev\GarlicNELauncherV2\decrypted_GarlicProxy.dll")

data = PKG.read_bytes()
assert data[:8] == b"GNP2PKG!"
payload_size = int.from_bytes(data[0x10:0x18], "little")
assert len(data) == 100 + payload_size, f"size {len(data)} vs {100+payload_size}"

# Header layout from MLIL
salt  = data[0x18:0x18+16]
nonce = data[0x28:0x28+12]
aad   = data[0x00:0x54]            # 84 bytes
tag   = data[0x54:0x54+16]
ct    = data[0x64:0x64+payload_size]

print(f"File size: {len(data)}, payload: {payload_size}")
print(f"Salt  ({len(salt)}): {salt.hex()}")
print(f"Nonce ({len(nonce)}): {nonce.hex()}")
print(f"AAD   ({len(aad)}): first 32 = {aad[:32].hex()}, last 16 = {aad[-16:].hex()}")
print(f"Tag   ({len(tag)}): {tag.hex()}")
print(f"CT    ({len(ct)}): first 16 = {ct[:16].hex()}")

key = hashlib.pbkdf2_hmac("sha256", PBKDF2_PASSWORD, salt, 75000, dklen=32)
print(f"\nDerived key: {key.hex()}")

try:
    pt = AESGCM(key).decrypt(nonce, ct + tag, aad)
    print(f"\n*** SUCCESS! Plaintext length: {len(pt)} ***")
    print(f"First 16 bytes: {pt[:16].hex()}")
    if pt[:2] == b"MZ":
        print(f"PE file confirmed!")
    OUT.write_bytes(pt)
    print(f"Saved to: {OUT}")
except InvalidTag:
    print("\n*** InvalidTag - decryption failed ***")
except Exception as e:
    print(f"\n*** Error: {type(e).__name__}: {e} ***")
