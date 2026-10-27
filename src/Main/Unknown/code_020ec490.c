#include "Main/Unknown/code_020ec490.h"

#include "code_02147cd8.h"

void func_020ec490(Unk020ec490 *param_1) {
    if (param_1->mUnk_a8) {
        param_1->mUnk_ac = param_1->mUnk_ac + param_1->mUnk_ae;
    } else {
        param_1->mUnk_ac = param_1->mUnk_ac - param_1->mUnk_ae;
    }
    param_1->mUnk_10.y -= param_1->mUnk_a4;
    func_02148504(&param_1->mUnk_04, &param_1->mUnk_10, &param_1->mUnk_04);
    if (param_1->mUnk_04.y < param_1->mUnk_a0) {
        param_1->mUnk_90 = 2;
        param_1->mUnk_92 = 1;
    }
}
