#pragma once

#include "types.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/unk_0217b000.h"

// Entry func_0208ec64 takes from the list at 0x0c of data_0217b08c.
typedef struct Unk0208ec64 {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0208ec64;

s32 func_0208ec64(u32 param_1);
