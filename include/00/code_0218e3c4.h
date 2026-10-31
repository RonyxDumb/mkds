#pragma once

#include "types.h"

// 8 bytes, moved one byte at a time.
typedef struct Unk0218e3c4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[6];
} Unk0218e3c4;

s32 func_ov000_0218e3c4(s32 param_1, s32 param_2, s32 param_3, void *param_4, s32 *param_5);
s32 func_ov000_0218e3e4(s32 param_1, void *param_2, s32 param_3, s32 param_4, void *param_5, s32 param_6);
s32 func_ov000_0218e420(s32 param_1, void *param_2, s32 param_3, s32 param_4);
s32 func_ov000_0218e438(s32 param_1, void *param_2, s32 param_3, s32 param_4, void *param_5, s32 *param_6);
s32 func_ov000_0218e460(s32 param_1, void *param_2, s32 param_3, s32 param_4);
s32 func_ov000_0218e478(s32 param_1, void *param_2, s32 *param_3);
