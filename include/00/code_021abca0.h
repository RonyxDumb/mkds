#pragma once

#include "types.h"

typedef struct Hash20Context {
    /* 00 */ u32 mStateA;
    /* 04 */ u32 mStateB;
    /* 08 */ u32 mStateC;
    /* 0c */ u32 mStateD;
    /* 10 */ u32 mStateE;
    /* 14 */ u32 mBitCountHigh;
    /* 18 */ u32 mBitCountLow;
    /* 1c */ u8 mBuffer[0x40];
} Hash20Context;

void CPSi_sha1_calc(void *rawContext, const u8 *input, u32 inputLength);
