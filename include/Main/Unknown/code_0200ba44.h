#pragma once

#include "types.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

// Object behind data_0216fde8; the members are the ones the code reads.
typedef struct Unk0216fde8 {
    /* 0000 */ u8 mUnk_0000[0x20];
    /* 0020 */ u8 mUnk_0020[0x480];
    /* 04a0 */ u8 mUnk_04a0[0x20];
    /* 04c0 */ u8 mUnk_04c0[0xe0];
    /* 05a0 */ u8 mUnk_05a0[0x24];
    /* 05c4 */ u8 mUnk_05c4[0x1c];
    /* 05e0 */ void (*mUnk_05e0)(u32, void *);
    /* 05e4 */ u8 mUnk_05e4[0x5efc - 0x5e4];
    /* 5efc */ u32 mUnk_5efc;
    /* 5f00 */ u8 mUnk_5f00[4];
    /* 5f04 */ u32 mUnk_5f04;
    /* 5f08 */ u32 mUnk_5f08;
    /* 5f0c */ u16 mUnk_5f0c;
    /* 5f0e */ u16 mUnk_5f0e;
} Unk0216fde8;

void func_0200ba44(u32 a, u32 b);
