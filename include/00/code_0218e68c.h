#pragma once

#include "types.h"

// 8 bytes: descriptor, requested events and returned events.
typedef struct Unk0218e68c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk0218e68c;

s32 func_ov000_0218e68c(s32 param_1, u32 *param_2, u32 *param_3, u32 *param_4);
s32 func_ov000_0218e74c(s32 param_1);
s32 func_ov000_0218e77c(s32 param_1);
s32 func_ov000_0218e7ac(s32 param_1, u32 param_2);
s32 func_ov000_0218e7dc(s32 param_1, u32 param_2);
