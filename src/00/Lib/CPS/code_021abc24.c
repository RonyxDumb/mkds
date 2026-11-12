#include "00/Lib/CPS/code_021abc24.h"
#include "00/Lib/CPS/code_021abca0.h"
#include "00/Lib/CPS/code_021ac37c.h"
#include "00/unk_021b4000.h"

// The zero padding is byte 1 on.
u8 gSha1PaddingBytes[0x40] = {0x80};

void CPSi_sha1_result(Hash20Context *context, u8 *digest) {
    int bufferIndex;
    int paddingLength;
    char_from_long(digest, &context->mBitCountHigh, 8);
    bufferIndex = context->mBitCountLow >> 3 & 0x3f;
    if (bufferIndex < 0x38) {
        paddingLength = 0x38 - bufferIndex;
    } else {
        paddingLength = 0x78 - bufferIndex;
    }
    CPSi_sha1_calc(context, gSha1PaddingBytes, paddingLength);
    CPSi_sha1_calc(context, digest, 8);
    char_from_long(digest, &context->mStateA, 0x14);
}

void CPSi_sha1_result_prng(Hash20Context *context, u8 *digest) {
    CPSi_sha1_calc(context, gSha1PaddingBytes + 1, 0x2c);
    char_from_long(digest, &context->mStateA, 0x14);
}
