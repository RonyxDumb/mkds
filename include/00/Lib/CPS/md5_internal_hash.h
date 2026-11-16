#pragma once

#include "types.h"

typedef struct CPSMd5Ctx {
    /* 00 */ u32 mStateA;
    /* 04 */ u32 mStateB;
    /* 08 */ u32 mStateC;
    /* 0c */ u32 mStateD;
    /* 10 */ u32 mBitCountLow;
    /* 14 */ u32 mBitCountHigh;
    /* 18 */ u8 mBuffer[0x40];
} CPSMd5Ctx;

typedef struct CPSMd5Ctx CPSMd5Ctx;

void CPSi_md5_result(CPSMd5Ctx *context, u8 *digest);
void CPSi_md5_calc(void *rawContext, const u8 *input, u32 inputLength);
void CPSi_md5_init(CPSMd5Ctx *context);
void CPSi_md5_block(CPSMd5Ctx *context, const u8 *block);
