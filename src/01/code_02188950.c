#include "01/code_02188950.h"

void func_ov001_02188c90(Unk02188950 *param_1) {
    param_1->mUnk_180 = 0;
    param_1->mUnk_194 = 0;
    param_1->mUnk_198 = 0;
    param_1->mUnk_19c = 0;
    param_1->mUnk_1a4 = 1;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = 0;
    param_1->mUnk_1c0 = 0;
}

void func_ov001_02188c48(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_180 = 2;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a4 = 1;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = 0;
    param_1->mUnk_1c0 = 0;
}

void func_ov001_02188c0c(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_180 = 2;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a4 = 2;
    param_1->mUnk_1bc = param_2;
    param_1->mUnk_1c0 = param_3;
}

void func_ov001_02188bc4(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_180 = 3;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a4 = 1;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = 0;
    param_1->mUnk_1c0 = 0;
}

void func_ov001_02188b78(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_180 = 0;
    param_1->mUnk_194 = 0;
    param_1->mUnk_198 = 0;
    param_1->mUnk_19c = 0;
    param_1->mUnk_1a4 = 3;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = param_2;
    param_1->mUnk_1c0 = param_3;
}

void func_ov001_02188b2c(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4) {
    param_1->mUnk_180 = 4;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a0 = param_4;
    param_1->mUnk_1a4 = 1;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = 0;
    param_1->mUnk_1c0 = 0;
}

void func_ov001_02188adc(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
    param_1->mUnk_180 = 2;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a4 = 4;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = param_4;
    param_1->mUnk_1c0 = param_5;
    param_1->mUnk_1c4 = param_6;
}

void func_ov001_02188a8c(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_180 = 5;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a0 = 0;
    param_1->mUnk_1a4 = 0;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = 0;
    param_1->mUnk_1c0 = 0;
}

void func_ov001_02188a30(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    s32 value;

    if (param_1->mUnk_180 == 7) {
        value = 7;
    } else if (param_1->mUnk_180 == 8) {
        value = 8;
    } else {
        value = 6;
    }
    param_1->mUnk_180 = value;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a0 = 0;
    param_1->mUnk_1a4 = 2;
    param_1->mUnk_1bc = param_4;
    param_1->mUnk_1c0 = param_5;
}

void func_ov001_021889ec(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    param_1->mUnk_180 = 2;
    param_1->mUnk_198 = param_2;
    param_1->mUnk_19c = param_3;
    param_1->mUnk_1a0 = 0;
    param_1->mUnk_1a4 = 2;
    param_1->mUnk_1bc = param_4;
    param_1->mUnk_1c0 = param_5;
}

void func_ov001_021889c8(Unk02188950 *param_1) {
    param_1->mUnk_1a4 = 0;
    param_1->mUnk_1b8 = 0;
    param_1->mUnk_1bc = 0;
    param_1->mUnk_1c0 = 0;
}

void func_ov001_02188998(Unk02188950 *param_1, Vec3 *param_2) {
    if (param_2 != 0) {
        param_1->mUnk_1ac = *param_2;
        param_1->mUnk_188 = *param_2;
    }
}

void func_ov001_02188980(Unk02188950 *param_1, Vec3 *param_2) {
    if (param_2 != 0) {
        param_1->mUnk_1ac = *param_2;
    }
}

void func_ov001_02188968(Unk02188950 *param_1, Vec3 *param_2) {
    if (param_2 != 0) {
        param_1->mUnk_188 = *param_2;
    }
}

void func_ov001_02188950(Unk02188950 *param_1, Vec3 *param_2) {
    if (param_2 != 0) {
        param_1->mUnk_1c8 = *param_2;
    }
}
