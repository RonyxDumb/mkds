#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_02039860.h"

typedef struct Unk02185f04_1 {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ s32 mUnk_50;
    /* 54 */ u8 mUnk_54[0x4];
    /* 58 */ s32 mUnk_58;
} Unk02185f04_1;

typedef struct Unk02185fb0_1 {
    /* 00 */ u8 mUnk_00[0x80];
    /* 80 */ s32 mUnk_80;
    /* 84 */ u8 mUnk_84[0x4];
    /* 88 */ s32 mUnk_88;
} Unk02185fb0_1;

s32 func_ov001_021860cc(Unk02188950 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4);
s32 func_ov001_02185fb0(Unk02188950 *param_1, Unk02185fb0_1 *param_2, u8 *param_3, u8 *param_4);
s32 func_ov001_02185f04(Unk02188950 *param_1, Unk02185f04_1 *param_2, u8 *param_3, u8 *param_4);
