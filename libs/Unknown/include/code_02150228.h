#pragma once

#include "types.h"

// 0x58 bytes: four words at 0x00, a 64-bit count at 0x10 and a 0x40-byte buffer at 0x18 whose last two words are
// also written as mUnk_50 and mUnk_54.
typedef struct Unk02150610 {
    /* 00 */ u32 mUnk_00[4];
    /* 10 */ u64 mUnk_10;
    /* 18 */ u8 mUnk_18[0x38];
    /* 50 */ u32 mUnk_50;
    /* 54 */ u32 mUnk_54;
} Unk02150610;

extern u32 data_0216f0ac[48];
extern u32 data_0216f16c[64];

void func_02150228(Unk02150610 *q);
void func_02150610(u8 *out, Unk02150610 *ctx);
void func_021506d4(Unk02150610 *ctx, const u8 *src, u32 n);
