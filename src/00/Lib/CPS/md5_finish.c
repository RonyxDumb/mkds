#include "00/Lib/CPS/md5_finish.h"
#include "digest_stream_hash.h"

void MD5Final(u8 *digest, DGTHash1Context *ctx) {
    DGT_Hash1GetDigest_R(digest, ctx);
}
