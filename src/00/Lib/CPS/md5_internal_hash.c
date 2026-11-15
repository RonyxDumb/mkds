#include "00/Lib/CPS/md5_internal_hash.h"

#include "00/Lib/CPS/md5_byte_copy.h"
#include "00/Lib/wifi_library_globals.h"
#include "cpu_copy_fill.h"

u8 gMd5PaddingBytes[64] = {
    0x80,
};

u8 gMd5WordIndexes[64] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x01, 0x06, 0x0b, 0x00, 0x05, 0x0a, 0x0f, 0x04, 0x09, 0x0e, 0x03, 0x08, 0x0d, 0x02, 0x07, 0x0c,
    0x05, 0x08, 0x0b, 0x0e, 0x01, 0x04, 0x07, 0x0a, 0x0d, 0x00, 0x03, 0x06, 0x09, 0x0c, 0x0f, 0x02,
    0x00, 0x07, 0x0e, 0x05, 0x0c, 0x03, 0x0a, 0x01, 0x08, 0x0f, 0x06, 0x0d, 0x04, 0x0b, 0x02, 0x09,
};

u32 gMd5StepConstants[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

void CPSi_md5_block(CPSMd5Ctx *context, const u8 *block) {
    u32 words[16];
    u32 stateA;
    u32 stateB;
    u32 stateC;
    u32 stateD;
    u32 tableIndex;
    s32 groupIndex;
    stateA = context->mStateA;
    stateB = context->mStateB;
    stateC = context->mStateC;
    stateD = context->mStateD;
    Md5BlockCopyBytes(words, block, 0x40);
    tableIndex = 0;
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateA += (stateD ^ (stateB & (stateC ^ stateD))) + words[gMd5WordIndexes[tableIndex]] +
                  gMd5StepConstants[tableIndex];
        stateA = stateB + ((stateA << 7) | (stateA >> 25));
        stateD += (stateC ^ (stateA & (stateB ^ stateC))) + words[gMd5WordIndexes[tableIndex + 1]] +
                  gMd5StepConstants[tableIndex + 1];
        stateD = stateA + ((stateD << 12) | (stateD >> 20));
        stateC += (stateB ^ (stateD & (stateA ^ stateB))) + words[gMd5WordIndexes[tableIndex + 2]] +
                  gMd5StepConstants[tableIndex + 2];
        stateC = stateD + ((stateC << 17) | (stateC >> 15));
        stateB += (stateA ^ (stateC & (stateD ^ stateA))) + words[gMd5WordIndexes[tableIndex + 3]] +
                  gMd5StepConstants[tableIndex + 3];
        stateB = stateC + ((stateB << 22) | (stateB >> 10));
        tableIndex += 4;
    }
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateA += ((stateB & stateD) | (stateC & ~stateD)) + words[gMd5WordIndexes[tableIndex]] +
                  gMd5StepConstants[tableIndex];
        stateA = stateB + ((stateA << 5) | (stateA >> 27));
        stateD += ((stateA & stateC) | (stateB & ~stateC)) + words[gMd5WordIndexes[tableIndex + 1]] +
                  gMd5StepConstants[tableIndex + 1];
        stateD = stateA + ((stateD << 9) | (stateD >> 23));
        stateC += ((stateD & stateB) | (stateA & ~stateB)) + words[gMd5WordIndexes[tableIndex + 2]] +
                  gMd5StepConstants[tableIndex + 2];
        stateC = stateD + ((stateC << 14) | (stateC >> 18));
        stateB += ((stateC & stateA) | (stateD & ~stateA)) + words[gMd5WordIndexes[tableIndex + 3]] +
                  gMd5StepConstants[tableIndex + 3];
        stateB = stateC + ((stateB << 20) | (stateB >> 12));
        tableIndex += 4;
    }
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateA += (stateD ^ (stateB ^ stateC)) + words[gMd5WordIndexes[tableIndex]] + gMd5StepConstants[tableIndex];
        stateA = stateB + ((stateA << 4) | (stateA >> 28));
        stateD +=
            (stateC ^ (stateA ^ stateB)) + words[gMd5WordIndexes[tableIndex + 1]] + gMd5StepConstants[tableIndex + 1];
        stateD = stateA + ((stateD << 11) | (stateD >> 21));
        stateC +=
            (stateB ^ (stateD ^ stateA)) + words[gMd5WordIndexes[tableIndex + 2]] + gMd5StepConstants[tableIndex + 2];
        stateC = stateD + ((stateC << 16) | (stateC >> 16));
        stateB +=
            (stateA ^ (stateC ^ stateD)) + words[gMd5WordIndexes[tableIndex + 3]] + gMd5StepConstants[tableIndex + 3];
        stateB = stateC + ((stateB << 23) | (stateB >> 9));
        tableIndex += 4;
    }
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateA += (stateC ^ (stateB | ~stateD)) + words[gMd5WordIndexes[tableIndex]] + gMd5StepConstants[tableIndex];
        stateA = stateB + ((stateA << 6) | (stateA >> 26));
        stateD +=
            (stateB ^ (stateA | ~stateC)) + words[gMd5WordIndexes[tableIndex + 1]] + gMd5StepConstants[tableIndex + 1];
        stateD = stateA + ((stateD << 10) | (stateD >> 22));
        stateC +=
            (stateA ^ (stateD | ~stateB)) + words[gMd5WordIndexes[tableIndex + 2]] + gMd5StepConstants[tableIndex + 2];
        stateC = stateD + ((stateC << 15) | (stateC >> 17));
        stateB +=
            (stateD ^ (stateC | ~stateA)) + words[gMd5WordIndexes[tableIndex + 3]] + gMd5StepConstants[tableIndex + 3];
        stateB = stateC + ((stateB << 21) | (stateB >> 11));
        tableIndex += 4;
    }
    context->mStateA += stateA;
    context->mStateB += stateB;
    context->mStateC += stateC;
    context->mStateD += stateD;
}

void CPSi_md5_init(CPSMd5Ctx *context) {
    MI_CpuFill8(context, 0, sizeof(CPSMd5Ctx));
    context->mStateA = (0x67452301u);
    context->mStateB = (0xefcdab89u);
    context->mStateC = (0x98badcfeu);
    context->mStateD = (0x10325476u);
}

void CPSi_md5_calc(void *rawContext, const u8 *input, u32 inputLength) {
    CPSMd5Ctx *context = rawContext;
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
        CPSi_md5_block(context, context->mBuffer);
        for (; inputOffset + 63 < inputLength; inputOffset += 64) {
            CPSi_md5_block(context, input + inputOffset);
        }
    } else {
        inputOffset = 0;
    }
    MI_CpuCopy8(input + inputOffset, &context->mBuffer[bufferIndex], inputLength - inputOffset);
}

void CPSi_md5_result(CPSMd5Ctx *context, u8 *digest) {
    int bufferIndex;
    int paddingLength;
    Md5ResultCopyBytes((u32) digest, (u32) &context->mBitCountLow, 8);
    bufferIndex = context->mBitCountLow >> 3 & 0x3f;
    if (bufferIndex < 0x38) {
        paddingLength = 0x38 - bufferIndex;
    } else {
        paddingLength = 0x78 - bufferIndex;
    }
    CPSi_md5_calc(context, gMd5PaddingBytes, paddingLength);
    CPSi_md5_calc(context, digest, 8);
    Md5ResultCopyBytes((u32) digest, (u32) context, 0x10);
}
