#pragma once

#include "types.h"

// Entry of the list at data_ov000_021b52c4, 0x40 bytes.
typedef struct Unk0219b1d4 {
    /* 00 */ s32 mDescriptor;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14[3];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32;
    /* 33 */ u8 mUnk_33;
    /* 34 */ void (*mUnk_34)(s32 a, void *b);
    /* 38 */ void (*mUnk_38)(s32 a, s32 b, void *c, void *d);
    /* 3c */ void *mUnk_3c;
} Unk0219b1d4;

void func_ov000_0219b1d4(Unk0219b1d4 *object);
