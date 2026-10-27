#pragma once

#include "types.h"
#include "Main/Unknown/code_02042fc4.h"

// One entry of the table returned by func_02042044.
typedef struct Unk02042044 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[2];
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
} Unk02042044;

Unk02042044 *func_02042044(u32 arg0, u32 arg1);
