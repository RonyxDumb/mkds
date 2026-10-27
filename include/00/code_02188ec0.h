#pragma once

#include "types.h"

typedef struct Unk02188ec0 {
    /* 000 */ u8 pad_00[0xd0b];
    /* d0b */ u8 mUnk_d0b : 2;
} Unk02188ec0;

u32 func_ov000_02188ec0(Unk02188ec0 *object);
