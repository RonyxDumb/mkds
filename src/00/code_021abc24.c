#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021ac37c.h"
#include "00/unk_021b4000.h"

void CPSi_sha1_result(Hash20Context *context, u8 *digest) {
    int bufferIndex;
    int paddingLength;
    char_from_long(digest, &context->mUnk_14, 8);
    bufferIndex = context->mUnk_18 >> 3 & 0x3f;
    if (bufferIndex < 0x38) {
        paddingLength = 0x38 - bufferIndex;
    } else {
        paddingLength = 0x78 - bufferIndex;
    }
    CPSi_sha1_calc(context, gSha1PaddingBytes, paddingLength);
    CPSi_sha1_calc(context, digest, 8);
    char_from_long(digest, &context->mUnk_00, 0x14);
}

void CPSi_sha1_result_prng(Hash20Context *context, u8 *digest) {
    CPSi_sha1_calc(context, gSha1ZeroPaddingBytes, 0x2c);
    char_from_long(digest, &context->mUnk_00, 0x14);
}
