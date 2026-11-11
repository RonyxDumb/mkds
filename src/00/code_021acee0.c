#include "00/code_021acee0.h"
#include "code_02150228.h"

void MD5Final(u8 *digest, DGTHash1Context *ctx) {
    DGT_Hash1GetDigest_R(digest, ctx);
}
