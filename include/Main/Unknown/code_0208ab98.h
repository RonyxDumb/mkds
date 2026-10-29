#pragma once

#include "types.h"

// Nine halfwords: the word at 0x00, the three fields of it at 0x02, 0x04 and 0x06, their differences from a target
// at 0x08, 0x0a and 0x0c, a mask at 0x0e and a factor at 0x10.
typedef struct Unk0208ab98 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
} Unk0208ab98;

void func_0208ab98(void *a, u16 b, s32 c);
void func_0208ad74(void *a, u32 b);
void *func_0208adc8(void *a, u32 b);
