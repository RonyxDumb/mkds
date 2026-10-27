#pragma once

#include "types.h"

typedef struct Unk021b5664 {
    /* 00 */ u8 pad_00[0x44];
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
} Unk021b5664;

extern Unk021b5664 *data_ov000_021b5664;

void func_ov000_0219d934(void *first, void *second);
