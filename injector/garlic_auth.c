/* garlic_auth.c — FNV-1a-64 auth verifier + hex decoder.
 * Entry-for-byte identical to sub_140001000 (injector),
 * sub_140001ac0 (DLL), and the launcher's main path.
 * Added by the GarlicV2 maintainer. */

#include "garlic_auth.h"
#include <string.h>

/* "GarlicBridge-V2-20260809" — the shared secret version identifier.
 * 24 printable bytes + implicit null = 25-byte loop in the binary. */
static const char kBridgeSecret[] = "GarlicBridge-V2-20260809";

/* FNV-1a 64-bit constants used in all three binaries. */
#define FNV_OFFSET_BASIS UINT64_C(0x14650fb0739d0383)
#define FNV_PRIME       UINT64_C(0x00000100000001B3)

int GarlicAuth_Verify(const uint64_t authBlock[3])
{
    if (!authBlock || authBlock[0] != GARLIC_MAGIC)
        return 0;

    /* Step 1 — hash the bridge secret (25 bytes). */
    uint64_t h = FNV_OFFSET_BASIS;
    for (size_t i = 0; i < sizeof(kBridgeSecret); ++i)
        h = (h ^ (uint64_t)kBridgeSecret[i]) * FNV_PRIME;

    /* Step 2 — feed the nonce, byte-by-byte LE. */
    uint64_t nonce = authBlock[1];
    for (int b = 0; b < 8; ++b)
        h = (h ^ ((nonce >> (b << 3)) & 0xFFULL)) * FNV_PRIME;

    /* Step 3 — finish: (*prime) ^ GARLICAU *prime. */
    h = h * FNV_PRIME;
    h = h ^ GARLIC_MAGIC;
    uint64_t token = h * FNV_PRIME;

    return token == authBlock[2];
}

int GarlicAuth_HexDecode(const char *hex16, uint64_t *out)
{
    if (!hex16 || !out)
        return -1;
    if (strlen(hex16) != 16)
        return -2;

    *out = 0;
    for (int i = 0; i < 16; ++i) {
        char c = hex16[i];
        uint64_t nibble;
        if (c >= '0' && c <= '9')
            nibble = (uint64_t)(c - '0');
        else if (c >= 'A' && c <= 'F')
            nibble = (uint64_t)(c - 'A' + 10);
        else if (c >= 'a' && c <= 'f')
            nibble = (uint64_t)(c - 'a' + 10);
        else
            return -3;
        *out = (*out << 4) | nibble;
    }
    return 0;
}

void GarlicAuth_BuildBlock(uint64_t authBlock[3], uint64_t nonce,
                           uint64_t token)
{
    authBlock[0] = GARLIC_MAGIC;
    authBlock[1] = nonce;
    authBlock[2] = token;
}