#pragma once

#include "types.h"
#include "03/code_021d1d88.h"
#include "03/code_021d34e4.h"

typedef struct Unk021d34c8 {
    /* 00 */ Unk021d1d88 *mUnk_00;
    /* 04 */ u16 *mResource;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021d34e4 mUnk_0c;
    /* 20 */ Unk021d34e4 mUnk_20;
    /* 34 */ s32 mUnk_34;
    /* 38 */ Unk021d34e4 *mUnk_38;
} Unk021d34c8;

void func_ov003_021d34c8(u32 index, u32 value);
