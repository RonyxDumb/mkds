#pragma once

#include "types.h"
#include "Main/Unknown/code_02025ebc.h"

// Object behind data_02174e18.
typedef struct Unk02174e18 {
    /* 00 */ u8 mUnk_00[0x94];
    /* 94 */ s32 mUnk_94;
    /* 98 */ u8 mUnk_98[0x54];
    /* ec */ Unk02025ebc mUnk_ec;
    /* fc */ u8 mUnk_fc[8];
    /* 104 */ s32 mUnk_104;
} Unk02174e18;

void func_02027e78(void);
void func_02027f1c(u32 a, u32 b, u32 c, u32 d);
