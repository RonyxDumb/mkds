#pragma once

#include "types.h"

typedef struct Unk021b566c {
    /* 00 */ int *mUnk_00;
    /* 04 */ u8 mUnk_04[9];
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[7];
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17[3];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ void *mUnk_1c;
    /* 20 */ u8 mUnk_20[4];
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x7c];
    /* a4 */ u16 mUnk_a4;
    /* a6 */ u8 mUnk_a6[0xf2];
    /* 198 */ s32 mUnk_198;
    /* 19c */ u8 mUnk_19c[2];
    /* 19e */ u8 mUnk_19e;
    /* 19f */ u8 mUnk_19f[0x4d];
    /* 1ec */ u32 mUnk_1ec;
} Unk021b566c;

extern Unk021b566c *data_ov000_021b566c;

void func_ov000_0219de4c(void *value, u16 index);
