#pragma once

#include "types.h"

typedef struct Unk02010804 {
    /* 00 */ u8 mUnk_00[0x2c];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u16 mUnk_30; // size in units of 8 bytes
    /* 32 */ u16 mUnk_32; // bit 0 set by func_02010804
    /* 34 */ u8 mUnk_34[4];
    /* 38 */ u32 mUnk_38; // byte offset from this struct
} Unk02010804;

void func_02010804(Unk02010804 *a, int b);
void func_02010870(Unk02010804 *a, u32 b);
