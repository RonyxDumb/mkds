#pragma once

#include "types.h"

// Object behind data_ov000_021b4c8c; mUnk_00 selects the handler run by func_ov000_021857e0.
typedef struct Unk021b4c8c {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
} Unk021b4c8c;

extern Unk021b4c8c *data_ov000_021b4c8c;

void func_ov000_021857e0(void);
