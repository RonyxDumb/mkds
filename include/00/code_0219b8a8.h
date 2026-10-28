#pragma once

#include "types.h"

typedef struct Unk021b54c8 {
    /* 00 */ u8 pad_00[0x24];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d[0x27];
    /* 54 */ u32 mUnk_54;
    /* 58 */ u8 mUnk_58[4];
    /* 5c */ void (*mUnk_5c)(s32 param_1);
    /* 60 */ u32 mUnk_60;
    /* 64 */ u8 mUnk_64[0x30];
    /* 94 */ u32 mUnk_94;
    /* 98 */ u32 mUnk_98;
} Unk021b54c8;

extern Unk021b54c8 *data_ov000_021b54c8;

void func_ov000_0219b8a8(s32 value);
