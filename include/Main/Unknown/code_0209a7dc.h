#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0

// Block of eight words at 0xb0 and 0xd0 of Unk0209a7dc: the u16 at 0x00 grows by 0x18 each step, 0x14 and 0x1c move
// 0x10 and 0x18 towards zero.
typedef struct Unk0209a7dc_b0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0209a7dc_b0;

// Object of func_0209a7dc, one state per value of mUnk_114.
typedef struct Unk0209a7dc {
    /* 000 */ Unk020e71a0 mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u16 mUnk_0a2;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ Unk0209a7dc_b0 mUnk_0b0;
    /* 0d0 */ Unk0209a7dc_b0 mUnk_0d0;
    /* 0f0 */ Unk020e0144 mUnk_0f0;
    /* 114 */ s32 mUnk_114;
} Unk0209a7dc;

// Declared here until the code that defines them is decompiled.
s32 func_0209af64(s32 a, s32 b);
s16 func_0209af80(s32 a);

void func_0209a7dc(void *param_1, Unk0209a7dc *param_2);
