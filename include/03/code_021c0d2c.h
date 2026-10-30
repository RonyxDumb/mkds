#pragma once

#include "types.h"
#include "03/unk_021da000.h"

// 8-byte object returned by func_ov003_021d1c18: bits 0-7 and bits 16-24 of the word at 0x00 are two coordinates.
typedef struct Unk021d1c18 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021d1c18;

// Stack object of func_ov003_021c0d2c.
typedef struct Unk021c0d2c {
    /* 00 */ u16 mUnk_00[4];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c[2];
} Unk021c0d2c;

void func_ov003_021c0d2c(void);
