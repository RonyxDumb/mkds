#pragma once

#include "types.h"

// Row of the 0x34-byte table addressed by data_0217c654.
typedef struct {
    /* 00 */ s16 mUnk_00[4][2];
    /* 10 */ s16 mUnk_10[4][2];
    /* 20 */ s16 mUnk_20[2];
    /* 24 */ void *mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
} Unk021035ac;

void func_021035ac(int b2);
void func_0210366c(Unk021035ac *p);
