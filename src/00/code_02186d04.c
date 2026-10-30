#include "00/code_02186d04.h"

void func_ov000_02186d04(Unk021868d0 *param_1) {
    if (param_1 != 0) {
        if (param_1->mUnk_00c == 0) {
            func_ov000_02186a10(param_1, &param_1->mUnk_938);
        }
        func_ov000_02186a10(param_1, &param_1->mUnk_928);
        if (param_1->mUnk_91c != 0) {
            param_1->mUnk_018(data_ov000_021b1320, param_1->mUnk_91c, 0);
            param_1->mUnk_91c = 0;
        }
        if (param_1->mUnk_920 != 0) {
            param_1->mUnk_018(data_ov000_021b1334, param_1->mUnk_920, 0);
            param_1->mUnk_920 = 0;
        }
        func_0214d168(param_1, 0, 0x1a60);
    }
    return;
}
