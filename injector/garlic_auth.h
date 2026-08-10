/* garlic_auth.h — FNV-1a-64 auth verifier + hex decoder.
 * Added by the GarlicV2 maintainer on top of SakuraTools injector/.
 * The same code appears in the launcher, the injector, and the
 * proxy DLL — three copies of the same FNV-1a chain. */

#pragma once
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GARLIC_AUTH_BLOCK_SIZE 24
#define GARLIC_MAGIC UINT64_C(0x4741524c49434155) /* "GARLICAU" LE */

/* GarlicInternalVerify — same as sub_140001000 (injector),
 * sub_140001ac0 (DLL), and the launcher's main verifying path.
 *
 * authBlock layout (24 bytes):
 *   [0] magic       (8B, must be GARLIC_MAGIC)
 *   [1] nonce       (8B, session seed)
 *   [2] token       (8B, expected FNV-1a output)
 *
 * Returns 1 if token matches the FNV-1a derivation of nonce. */
int GarlicAuth_Verify(const uint64_t authBlock[3]);

/* Decode a 16-char hex string (no "0x" prefix) into a uint64.
 * Returns 0 on success, non-zero if the string is not valid hex
 * or the wrong length. Only uppercase hex (A-F) is accepted;
 * if lowercase is needed, upcase before calling. */
int GarlicAuth_HexDecode(const char *hex16, uint64_t *out);

/* Build the 24-byte auth block from decoded nonce + token.
 * authBlock[0] = GARLIC_MAGIC, authBlock[1] = nonce,
 * authBlock[2] = token. */
void GarlicAuth_BuildBlock(uint64_t authBlock[3], uint64_t nonce,
                           uint64_t token);

#ifdef __cplusplus
}
#endif