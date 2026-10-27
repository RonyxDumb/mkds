#pragma once

#include "types.h"

typedef struct Unk021b565c {
    /* 00 */ u8 pad_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 pad_08[0x2c];
    /* 34 */ s32 mUnk_34;
} Unk021b565c;

extern Unk021b565c *data_ov000_021b565c;

void func_ov000_0219c93c(void);
