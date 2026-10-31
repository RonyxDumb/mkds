#pragma once

#include "types.h"
#include "03/code_021d1d88.h"
#include "code_02021f9c.h"
#include "code_02022aa8.h"

typedef struct Unk021d2490 {
    /* 000 */ Unk02022aa8 mUnk_000[2];
    /* 018 */ u8 mUnk_018[0x770];
    /* 788 */ Unk021d1d88 *mUnk_788;
    /* 78c */ Unk02021f9c *mUnk_78c[2];
    /* 794 */ u8 mUnk_794[4];
} Unk021d2490;

void func_ov003_021d2490(void);
