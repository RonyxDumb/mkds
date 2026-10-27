#pragma once

#include "types.h"
#include "Main/Unknown/code_020e43a8.h"

// 0x10-byte request built on the stack here.
typedef struct Unk020e4e08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 mUnk_04;
} Unk020e4e08;

void func_020e4e08(u32 param_1, Unk020e43a8 *p, u32 param_3, u32 param_4);
