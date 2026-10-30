#pragma once

#include "types.h"

// Halfwords of Unk0203810c after the mode.
typedef struct Unk0203810c_04 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk0203810c_04;

// Argument of func_0203810c and func_020386d0.
typedef struct Unk0203810c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk0203810c_04 mUnk_04;
} Unk0203810c;

void func_0203810c(Unk0203810c *a, s32 b);
void func_020386d0(Unk0203810c *a, s32 b);
