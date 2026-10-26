#include "01/code_02188e24.h"

void func_ov001_02188e74(Unk02188950 *param_1, s32 param_2, UnkFunc *param_3) {
    param_1->mUnk_1d8 = param_2;
    param_1->mUnk_1dc = param_3;
    return;
}

void func_ov001_02188e48(Unk02188950 *param_1, s32 param_2, void (*param_3)(Unk02188950 *), s32 param_4,
                         void (*param_5)(Unk02188950 *)) {
    param_1->mUnk_1e0 = param_2;
    param_1->mUnk_1e4 = param_3;
    param_1->mUnk_1e8 = param_4;
    param_1->mUnk_1ec = param_5;
    return;
}

void func_ov001_02188e24(Unk02188950 *param_1, s32 param_2, UnkFunc *param_3) {
    param_1->mUnk_1f0 = param_2;
    param_1->mUnk_0b0 = 0;
    if (param_3 == 0) {
        param_3 = (UnkFunc *) func_ov001_02188e88;
    }
    param_1->mUnk_1f4 = param_3;
    return;
}
