#pragma once

#include "types.h"
#include "00/code_0219de4c.h"
#include "00/code_021a0958.h"

// Object func_ov000_0219db18 reads and writes through its last parameter.
typedef struct Unk0219db18 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 pad_02[6];
    /* 08 */ u32 mUnk_08;
} Unk0219db18;

u32 func_ov000_0219dabc(void);
void func_ov000_0219db18(s32 a, s32 b, s32 c, void *d);
