#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "00/unk_021b6000.h"

typedef struct Unk021a8c94 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ void *(*mUnk_04)(u32 a, u32 b);
    /* 08 */ void (*mUnk_08)(u32 a, void *b, u32 c);
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[8];
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
} Unk021a8c94;

extern Unk021b5f94 data_ov000_021b6040;
extern void *(*data_ov000_021b6014)(u32 a, u32 b);

s32 func_ov000_021a8c94(void *param_1);
