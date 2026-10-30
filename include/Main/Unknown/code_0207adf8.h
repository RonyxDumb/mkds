#pragma once

#include "types.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/unk_02155000.h"

// Object func_0207adf8 works on.
typedef struct Unk0207adf8 {
    /* 00 */ u8 mUnk_00[0x54];
    /* 54 */ s32 mUnk_54;
    /* 58 */ u32 mUnk_58;
    /* 5c */ u8 mUnk_5c[0x10];
    /* 6c */ u16 mUnk_6c;
    /* 6e */ u16 mUnk_6e;
} Unk0207adf8;

void func_0207adf8(Unk0207adf8 *param_1, u32 param_2, u32 param_3);
