#pragma once

#include "types.h"

// 0xd8-byte object (data_0216eaa4): func_0212f5a0 calls mUnk_04(a, b, n, this) after mUnk_08 and before mUnk_10, which
// are called only when not null; func_0212f638 stores a number in mUnk_00 and a function in mUnk_04 and clears
// mUnk_18. mUnk_18 is read as 24 pairs of words by func_0212f1f8 and as two words by func_0212f3f8.
typedef struct Unk0212f1f8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ UnkFunc *mUnk_04;
    /* 08 */ UnkFunc *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ UnkFunc *mUnk_10;
    /* 14 */ u32 mUnk_14;
    union {
        struct {
            /* 00 */ s32 mUnk_00;
            /* 04 */ s32 mUnk_04;
        } p[24];
        /* 00 */ s32 w[2];
    } /* 18 */ mUnk_18;
} Unk0212f1f8;

void func_0212f1ac(s16 *a, s16 *b, u32 n);
void func_0212f1f8(s16 *a, s16 *b, u32 n, Unk0212f1f8 *d);
void func_0212f3f8(s16 *a, s16 *b, u32 n, Unk0212f1f8 *d);
void func_0212f59c(void);
void func_0212f5a0(void *a, void *b, u32 n, u32 d, Unk0212f1f8 *s);
void func_0212f638(s32 a);
void func_0212f730(void *a, u32 b, s32 c);
