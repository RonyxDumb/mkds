#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a740c.h"
#include "00/code_021a8c94.h"

typedef struct Unk021a8e18 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021a8e18;

void *func_ov000_021a8db8(u32 a);
s32 func_ov000_021a8dd8(Unk021a6fa8 *a, s32 b, u32 c);
s32 func_ov000_021a8e18(Unk021a6fa8 *a, Unk021a8e18 *b, s32 param_3);
