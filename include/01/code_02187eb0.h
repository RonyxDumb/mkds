#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_0206bcb0.h"

// One entry of the table returned by func_02042044.
typedef struct Unk02042044 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[2];
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
} Unk02042044;

void func_ov001_02187eb0(Unk02188950 *param_1);
Unk02042044 *func_ov001_02187ee8(Unk02188950 *param_1);
s32 func_ov001_02187f38(Unk02188950 *param_1);
s32 func_ov001_02187f7c(Unk02188950 *param_1);
Unk02042044 *func_ov001_02187fc0(Unk02188950 *param_1);
Unk0206bcb0 *func_ov001_02188000(Unk02188950 *param_1, s32 param_2, s32 param_3);
Unk0206bcb0 *func_ov001_02188084(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4);
Unk0206bcb0 *func_ov001_02188104(Unk02188950 *param_1, s32 param_2, s32 param_3);
