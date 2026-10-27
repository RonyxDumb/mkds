#pragma once

#include "types.h"

typedef struct Unk021d1d88 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ void *mUnk_04[1];
} Unk021d1d88;

Unk021d1d88 *func_ov003_021d1d88(u32 count);
