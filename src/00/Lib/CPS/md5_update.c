#include "00/Lib/CPS/md5_update.h"
#include "digest_stream_hash.h"

void MD5Update(DGTHash1Context *ctx, const u8 *src, u32 count) {
    DGT_Hash1SetSource(ctx, src, count);
}
