#pragma once

#include "types.h"
#include "00/code_021aa000.h"
#include "00/code_021ab000.h"
#include "00/code_021ad000.h"
#include "00/unk_021b6000.h"
#include "03/code_021b94b8.h"

// Object at 0x0c of the argument of func_ov000_021a998c.
typedef struct Unk021a998c_0c {
    /* 000 */ u8 mUnk_000[0x1a0];
    /* 1a0 */ u8 mUnk_1a0[8];
    /* 1a8 */ u8 mUnk_1a8[0x118];
    /* 2c0 */ u8 mUnk_2c0[0x5c];
    /* 31c */ u8 mUnk_31c[0x5c];
    /* 378 */ u8 mUnk_378[0x58];
    /* 3d0 */ u8 mUnk_3d0[0x58];
    /* 428 */ u8 mUnk_428;
    /* 429 */ u8 mUnk_429;
} Unk021a998c_0c;

// Argument of func_ov000_021a998c.
typedef struct Unk021a998c {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ Unk021a998c_0c *mUnk_0c;
} Unk021a998c;

void func_ov000_021a998c(Unk021a998c *param_1);
