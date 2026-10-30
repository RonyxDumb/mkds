#include "00/code_021a71a4.h"

u8 *func_ov000_021a71a4(u8 *param_1, Unk021a71a4 *param_2, s32 param_3) {
    u8 *iVar1;
    iVar1 = param_1;
    if (param_3 == 0) {
        iVar1 = 0;
    }
    param_2->mUnk_04 = iVar1;
    param_2->mUnk_00 = param_3;
    return param_1 + func_ov000_021a8a54(param_3);
}
