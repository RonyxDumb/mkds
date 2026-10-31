#include "00/code_0219bea8.h"

void func_ov000_0219bea8(u32 param_1, u32 param_2, void (*param_3)(s32 param_1), u32 param_4) {
    if (func_ov000_0219c39c() == 0) {
        if (data_ov000_021b54c8->mUnk_24 == 0) {
            data_ov000_021b54c8->mUnk_5c = param_3;
            data_ov000_021b54c8->mUnk_60 = param_4;
            data_ov000_021b54c8->mUnk_84.mUnk_10 = param_1;
            data_ov000_021b54c8->mUnk_84.mUnk_14 = param_2;
            if (func_ov000_021a3810() != 4) {
                func_ov000_0219c990(2, -60010);
                return;
            }
            func_ov000_0219b8a8(1);
            func_ov000_0218d6e4((const u8 *) data_ov000_021b54c8->mUnk_54);
        }
    }
}
