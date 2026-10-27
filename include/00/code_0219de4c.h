#pragma once

#include "types.h"

typedef struct Unk021b566c {
    /* 00 */ u8 pad_00[0x1a];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ void *mUnk_1c;
} Unk021b566c;

extern Unk021b566c *data_ov000_021b566c;

void func_ov000_0219de4c(void *value, u16 index);
