#pragma once

#include "types.h"

// Object of func_020dd950: words at 0x00 to 0x10, a vector at 0x14, a word at 0x20, a vector at 0x34, and two
// arrays of vectors at 0x44 and 0x48 with one element per unit of the word at 0x20.
typedef struct Unk020dd950 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ Vec3 mUnk_14;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s64 mUnk_2c;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ s32 mUnk_40;
    /* 44 */ Vec3 *mUnk_44;
    /* 48 */ Vec3 *mUnk_48;
} Unk020dd950;

extern const Vec3 data_021583c8;

void func_020dd950(Unk020dd950 *d, Vec3 *a, Vec3 *b, s32 c, s32 n, s32 e, Vec3 *f);
void func_020dd8b0(Unk020dd950 *d, Vec3 *a, Vec3 *b);
