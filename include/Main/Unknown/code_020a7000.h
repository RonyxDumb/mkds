#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0

// 0x48-byte entries from 0xb0 of Unk020a7f18; func_020a8098 writes the first mUnk_1d0 of them.
typedef struct Unk020a7f18_0b0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x28];
    /* 40 */ s32 mUnk_40;
    /* 44 */ u8 mUnk_44[4];
} Unk020a7f18_0b0;

// Object passed to func_020a7f18 and func_020a7fc4 as their first argument and on to func_020a8098: the shared
// Unk020e71a0 part, words at 0xa4 to 0xac, four 0x48-byte entries with their count at 0x1d0, and a word at 0x1fc.
typedef struct Unk020a7f18 {
    /* 000 */ Unk020e71a0 mUnk_000;
    /* 0a0 */ u8 mUnk_0a0[4];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ Unk020a7f18_0b0 mUnk_0b0[4];
    /* 1d0 */ u16 mUnk_1d0;
    /* 1d2 */ u8 mUnk_1d2[0x2a];
    /* 1fc */ s32 mUnk_1fc;
} Unk020a7f18;

// Declared here until the code that defines them is decompiled.
void func_020a71c8(void);
void func_020a7270(u16 a);
s32 func_020a72c8(u16 a, u16 b);
u8 func_020a7f18(Unk020a7f18 *p, Unk0206bcb0 *a, u8 *b, u8 *c);
u8 func_020a7fc4(Unk020a7f18 *p, Unk0206bcb0 *a, u8 *b, u8 *c);
void func_020a8098(Unk020a7f18 *p);
