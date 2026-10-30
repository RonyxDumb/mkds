#include "00/code_02186a38.h"

u32 func_ov000_02186a38(Unk021868d0 *param_1, Unk02186998 *param_2, int param_3) {
    if (param_3 == 0) {
        return 0;
    }
    param_2->mUnk_00 = param_1->mUnk_014(data_ov000_021b1280, param_3);
    if (param_2->mUnk_00 == 0) {
        return 0;
    }
    param_2->mUnk_04 = param_2->mUnk_00;
    param_2->mUnk_0c = param_3;
    param_2->mUnk_08 = param_2->mUnk_00 + param_2->mUnk_0c;
    return 1;
}
