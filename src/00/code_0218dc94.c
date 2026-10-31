#include "00/code_0218dc94.h"

void *func_ov000_0218dc94(s32 param_1, s32 param_2, void (*param_3)(void *)) {
    Unk0218dc94 *a = func_ov000_021a3690(0x18);
    if (a == 0) {
        func_0213442c(data_ov000_021b2334, data_ov000_021b22dc, 0, 0x52);
    }
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b233c, data_ov000_021b22dc, 0, 0x53);
    }
    if (param_2 == 0) {
        param_2 = 8;
    }
    a->mUnk_00 = 0;
    a->mUnk_04 = param_2;
    a->mUnk_08 = param_1;
    a->mUnk_0c = param_2;
    a->mUnk_10 = param_3;
    if (a->mUnk_04 != 0) {
        a->mUnk_14 = func_ov000_021a3690(a->mUnk_04 * a->mUnk_08);
        if (a->mUnk_14 == 0) {
            func_0213442c(data_ov000_021b2348, data_ov000_021b22dc, 0, 0x5e);
        }
    } else {
        a->mUnk_14 = 0;
    }
    return a;
}
