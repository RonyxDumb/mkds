#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0210bcf4.h"

// The bytes from 0x450 of an Unk0206bcb0, which func_02024a88 and func_02024eec read and write.
typedef struct Unk02024eec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[3];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x1c];
    /* 44 */ s32 mUnk_44;
    /* 48 */ u8 mUnk_48[8];
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
} Unk02024eec;

s32 func_02024974(s32 a, s32 b, u32 c, u32 d);
void func_020249b8(Unk0206bcb0 *a, s32 b, s32 c);
void func_02024a28(Unk0210bfbc *p, u16 a, s32 b, s32 c);
void func_02024a88(Unk0206bcb0 *a);
s32 func_02024eec(Unk02024eec *a, s32 b, s32 c);
