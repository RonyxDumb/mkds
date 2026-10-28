#pragma once

#include "types.h"

// 8-byte object at index i of Unk021d1770.mUnk_08: func_ov003_021d1770 reads bits 16-24 and bits 0-7 of its word
// at 0x00.
typedef struct Unk021d1770_08 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk021d1770_08;

// Object passed to func_ov003_021d1770: a pointer at 0x08 to Unk021d1770_08 objects, indexed by its second
// argument.
typedef struct Unk021d1770 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk021d1770_08 *mUnk_08;
} Unk021d1770;

void func_ov003_021d1770(Unk021d1770 *param_1, int param_2, u32 *param_3, s32 *param_4);
