#pragma once

#include "types.h"

// Halfword at 0x00 and the halfword at 0x02 derived from it by func_02089e68, word at 0x08.
typedef struct Unk02089e68 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ s32 mUnk_08;
} Unk02089e68;

void func_02089e68(Unk02089e68 *a);
void func_02089e10(int a);
