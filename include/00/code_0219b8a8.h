#pragma once

#include "types.h"

typedef struct Unk021b54c8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[0x20];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u8 pad_2e[2];
    /* 30 */ u32 mUnk_30;
    /* 34 */ u8 pad_34[0x20];
    /* 54 */ u32 mUnk_54;
    /* 58 */ u8 mUnk_58[4];
    /* 5c */ void (*mUnk_5c)(s32 param_1);
    /* 60 */ u32 mUnk_60;
    /* 64 */ u8 pad_64[8];
    /* 6c */ void (*mUnk_6c)(u32 a, u32 b, void *c);
    /* 70 */ void *mUnk_70;
    /* 74 */ void (*mUnk_74)(u32 a, u32 b, u32 c, u32 d, u32 e, void *f);
    /* 78 */ void *mUnk_78;
    /* 7c */ void (*mUnk_7c)(s32 a, s32 b, s32 c, u32 d, u32 e, void *f);
    /* 80 */ void *mUnk_80;
    /* 84 */ u8 pad_84[0x10];
    /* 94 */ u32 mUnk_94;
    /* 98 */ u32 mUnk_98;
    /* 9c */ u8 pad_9c[0x349 - 0x9c];
    /* 349 */ u8 mUnk_349;
    /* 34a */ u8 pad_34a[2];
    /* 34c */ void *mUnk_34c;
    /* 350 */ u8 mUnk_350;
    /* 351 */ volatile u8 mUnk_351; // placeholder: every test of it loads the byte again
    /* 352 */ u8 mUnk_352;
    /* 353 */ u8 pad_353[0x430 - 0x353];
    /* 430 */ u32 mUnk_430[0x29];
    /* 4d4 */ u32 mUnk_4d4;
    /* 4d8 */ u8 pad_4d8[0x5f4 - 0x4d8];
    /* 5f4 */ u8 mUnk_5f4[0x20];
    /* 614 */ u32 mUnk_614;
} Unk021b54c8;

extern Unk021b54c8 *data_ov000_021b54c8;

void func_ov000_0219b8a8(s32 value);
