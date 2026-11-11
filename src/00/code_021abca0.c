#include "00/code_021abca0.h"
#include "00/code_021abc04.h"
#include "00/code_021abd68.h"
#include "code_0214d018.h"

void CPSi_sha1_calc(void *rawContext, const u8 *input, u32 inputLength) {
    Hash20Context *context = rawContext;
    u32 bufferIndex;
    u32 inputOffset;
    bufferIndex = (context->mBitCountLow >> 3) & 0x3f;
    context->mBitCountLow += inputLength << 3;
    if (context->mBitCountLow < (inputLength << 3)) {
        context->mBitCountHigh++;
    }
    context->mBitCountHigh += inputLength >> 29;
    inputOffset = 64 - bufferIndex;
    if (inputLength >= inputOffset) {
        MI_CpuCopy8(input, &context->mBuffer[bufferIndex], inputOffset);
        bufferIndex = 0;
        CPSi_sha1_block(context, context->mBuffer);
        for (; inputOffset + 63 < inputLength; inputOffset += 64) {
            CPSi_sha1_block(context, input + inputOffset);
        }
    } else {
        inputOffset = 0;
    }
    MI_CpuCopy8(input + inputOffset, &context->mBuffer[bufferIndex], inputLength - inputOffset);
}
