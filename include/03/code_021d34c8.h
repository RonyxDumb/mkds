#pragma once

#include "types.h"

typedef struct Unk021d34c8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 *mResource;
    /* 08 */ u8 mUnk_08[0x34];
} Unk021d34c8;

void func_ov003_021d34c8(u32 index, u32 value);
