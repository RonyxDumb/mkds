#pragma once

#include "types.h"

// Bit fields of the word at 0x04 (bits 7-9, 10-11) are read and written by func_0213c94c.
typedef struct Unk0213c94c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04_0 : 7;
    /* 04 */ u32 mUnk_04_7 : 3;
    /* 04 */ u32 mUnk_04_10 : 2;
    /* 04 */ u32 mUnk_04_12 : 20;
} Unk0213c94c;

int func_0213c94c(Unk0213c94c *a, int b);
u16 *func_0213c9c0(const u16 *s, int c, u32 n);
