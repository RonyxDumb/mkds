#include "01/code_02188de0.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

void func_ov001_02188de0(Unk02188950 *param_1, s32 param_2, s32 param_3, Vec3 *param_4, UnkFunc *param_5) {
    UnkFunc *cb;

    param_1->mUnk_1f8 = param_2;
    param_1->mUnk_1fc = param_3;
    if (param_4 != 0) {
        param_1->mUnk_200 = *param_4;
    }
    cb = param_5;
    if (cb == 0) {
        cb = func_ov001_02188e88;
    }
    param_1->mUnk_20c = cb;
}
