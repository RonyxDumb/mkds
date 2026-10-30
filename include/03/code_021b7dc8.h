#pragma once

#include "types.h"

typedef struct Unk021d6810 {
    /* 00 */ u8 pad_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk021d6810;

extern Unk021d6810 data_ov003_021d6810;

s32 func_ov003_021b7dc8(void);
s32 func_ov003_021b7df4(u32 a, u32 b, u32 c);
