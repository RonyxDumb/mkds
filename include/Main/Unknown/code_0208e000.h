#pragma once

#include "types.h"

// Object func_0208e490 returns: three words at 0x9c and a word at 0xb4.
typedef struct Unk0208e490 {
    /* 00 */ u8 mUnk_00[0x9c];
    /* 9c */ s32 mUnk_9c[3];
    /* a8 */ u8 mUnk_a8[0xc];
    /* b4 */ s32 mUnk_b4;
} Unk0208e490;

// Declared here until the code that defines them is decompiled.
void func_0208e99c(int param_1);
void *func_0208e490(u32 param_1, const Vec3 *param_2, int param_3);
