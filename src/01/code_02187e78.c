#include "01/code_02187e78.h"

void func_ov001_02187e78(Unk02188950 *param_1) {
    int iVar1;

    if (param_1->mUnk_148 < data_02175620->mUnk_0c) {
        iVar1 = param_1->mUnk_14c + 1;
        if (iVar1 >= data_02175620->mUnk_08[(u16) param_1->mUnk_148].mUnk_02) {
            iVar1 = 0;
        }
        param_1->mUnk_14c = iVar1;
    }
}
