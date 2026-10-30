#pragma once

#include "types.h"
#include "00/code_021aa000.h"
#include "00/code_021ab000.h"
#include "00/unk_021b6000.h"
#include "03/code_021b94b8.h"

// Object behind mUnk_000 of Unk021a998c_0c.
typedef struct Unk021a998c_0c_00 {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u8 mUnk_20[0x30];
    /* 50 */ u8 mUnk_50[4];
    /* 54 */ u32 mUnk_54;
    /* 58 */ u16 mUnk_58;
} Unk021a998c_0c_00;

// Object behind mUnk_7f4 of Unk021a998c_0c: a length and a pointer.
typedef struct Unk021a998c_0c_7f4 {
    /* 0 */ u32 mUnk_0;
    /* 4 */ u8 *mUnk_4;
} Unk021a998c_0c_7f4;

// Object at 0x0c of the argument of func_ov000_021a998c.
typedef struct Unk021a998c_0c {
    /* 000 */ Unk021a998c_0c_00 *mUnk_000;
    /* 004 */ u8 mUnk_004;
    /* 005 */ u8 mUnk_005;
    /* 006 */ u16 mUnk_006;
    /* 008 */ u8 mUnk_008[0x20];
    /* 028 */ u8 mUnk_028[0x20];
    /* 048 */ u8 mUnk_048[0x48];
    /* 090 */ u8 *mUnk_090;
    /* 094 */ u8 mUnk_094[8];
    /* 09c */ u8 mUnk_09c[0x104];
    /* 1a0 */ u8 mUnk_1a0[8];
    /* 1a8 */ u8 mUnk_1a8[0x110];
    /* 2b8 */ u8 mUnk_2b8[8];
    /* 2c0 */ u8 mUnk_2c0[0x5c];
    /* 31c */ u8 mUnk_31c[0x5c];
    /* 378 */ u8 mUnk_378[0x58];
    /* 3d0 */ u8 mUnk_3d0[0x58];
    /* 428 */ u8 mUnk_428;
    /* 429 */ u8 mUnk_429;
    /* 42a */ u8 mUnk_42a[0x3e];
    /* 468 */ u8 mUnk_468[0x100];
    /* 568 */ s32 mUnk_568;
    /* 56c */ u8 mUnk_56c[8];
    /* 574 */ s32 mUnk_574;
    /* 578 */ u8 mUnk_578[0x27c];
    /* 7f4 */ Unk021a998c_0c_7f4 *mUnk_7f4;
    /* 7f8 */ u8 *mUnk_7f8;
    /* 7fc */ u32 mUnk_7fc;
    /* 800 */ u32 mUnk_800;
} Unk021a998c_0c;

// Argument of func_ov000_021a998c.
typedef struct Unk021a998c {
    /* 00 */ struct Unk0200db5c *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ Unk021a998c_0c *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u8 mUnk_38[8];
    /* 40 */ u8 *mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u8 mUnk_48[0x14];
    /* 5c */ u8 *mUnk_5c;
    /* 60 */ u32 mUnk_60;
} Unk021a998c;

void func_ov000_021a998c(Unk021a998c *param_1);
