#pragma once

#include "types.h"
#include "Main/Unknown/code_020d849c.h"

// Object at 0x1d8 of Unk020dc474: a word at 0xa8.
typedef struct Unk020dc474_1d8 {
    /* 00 */ u8 mUnk_00[0xa8];
    /* a8 */ s32 mUnk_a8;
} Unk020dc474_1d8;

// Three vectors and a fourth: at 0x28 of Unk020dc474, and on the stack of func_020dd6c8.
typedef struct Unk020dc474_28 {
    /* 00 */ Vec3 mUnk_00[3];
    /* 24 */ Vec3 mUnk_24;
} Unk020dc474_28;

// Object of func_020dc474, func_020dc608 and the functions after it up to func_020dd860: vectors at 0x04, 0x10 and 0xa0, ring of four
// vector pointers at 0x160, words at 0xe8, 0xec, 0xf0 and 0x1fc.
typedef struct Unk020dc474 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ Unk020dc474_28 mUnk_28;
    /* 58 */ u8 mUnk_58[0x18];
    /* 70 */ s32 mUnk_70;
    /* 74 */ u8 mUnk_74[4];
    /* 78 */ u32 mUnk_78;
    /* 7c */ u8 mUnk_7c[4];
    /* 80 */ u8 mUnk_80[4];
    /* 84 */ u32 mUnk_84;
    /* 88 */ u8 mUnk_88[6];
    /* 8e */ u16 mUnk_8e;
    /* 90 */ u16 mUnk_90;
    /* 92 */ u16 mUnk_92;
    /* 94 */ u8 mUnk_94[0xc];
    /* a0 */ Vec3 mUnk_a0;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ u8 mUnk_b4[0x10];
    /* c4 */ u8 mUnk_c4[0x10];
    /* d4 */ u8 mUnk_d4[0x10];
    /* e4 */ s32 mUnk_e4;
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mUnk_fc;
    /* 100 */ Unk020d849c mUnk_100;
    /* 160 */ Vec3 *mUnk_160[4];
    /* 170 */ u8 mUnk_170[0x30];
    /* 1a0 */ Unk020d84e4 mUnk_1a0;
    /* 1d8 */ Unk020dc474_1d8 *mUnk_1d8;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ Vec3 mUnk_1e0;
    /* 1ec */ s32 mUnk_1ec;
    /* 1f0 */ Vec3 *mUnk_1f0;
    /* 1f4 */ Vec3 *mUnk_1f4;
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ u8 mUnk_1fa[2];
    /* 1fc */ s32 mUnk_1fc;
} Unk020dc474;

void func_020dc474(Unk020dc474 *p);
