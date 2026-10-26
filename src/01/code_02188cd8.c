#include "01/code_02188cd8.h"
#include "01/code_0219b1c4.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

void func_ov001_02188d8c(Unk02188950 *param_1, Vec3 *param_2) {
    if (param_2 != 0) {
        param_1->mUnk_200 = *param_2;
    }
}

void func_ov001_02188d64(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    func_ov001_0219b208(param_1->mUnk_304, (u16) param_2, param_3, 0);
    param_1->mUnk_1d4 = 0;
}

void func_ov001_02188d30(Unk02188950 *param_1, s32 param_2, s32 param_3, UnkFunc *param_4) {
    func_ov001_0219b208(param_1->mUnk_304, (u16) param_2, param_3, 1);
    if (param_4 == 0) {
        param_4 = func_ov001_02188e88;
    }
    param_1->mUnk_1d4 = param_4;
}

void func_ov001_02188d1c(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_16c = param_2;
    param_1->mUnk_170 = param_3;
}

void func_ov001_02188d08(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_160 = param_2;
    param_1->mUnk_164 = param_3;
}

void func_ov001_02188cec(Unk02188950 *param_1, s32 param_2) {
    param_1->mUnk_174 = param_2;
    param_1->mUnk_178 = 0;
    param_1->mUnk_17c = 0;
}

void func_ov001_02188cd8(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_178 = param_2;
    param_1->mUnk_17c = param_3;
}
