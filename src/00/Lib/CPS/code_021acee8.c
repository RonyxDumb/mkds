#include "00/Lib/CPS/code_021acee8.h"
#include "hash1.h"

void MD5Update(DGTHash1Context *ctx, const u8 *src, u32 count) {
    DGT_Hash1SetSource(ctx, src, count);
}
