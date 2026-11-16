#include "00/Lib/CPS/md5_begin.h"
#include "digest_stream_hash.h"

void MD5Init(DGTHash1Context *context) {
    DGT_Hash1Reset(context);
}
