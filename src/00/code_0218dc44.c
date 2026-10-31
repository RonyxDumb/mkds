#include "00/code_0218dc44.h"

void func_ov000_0218dc48(void *param_1) {
    Unk0218dc94 *a = param_1;
    s32 b;
    if (a == 0) {
        func_0213442c(data_ov000_021b2334, data_ov000_021b22dc, 0, 0x69);
    }
    b = 0;
    if (0 < a->mUnk_00) {
        do {
            func_ov000_0218dd74(a, b);
            b = b + 1;
        } while (b < a->mUnk_00);
    }
    func_ov000_021a3668(a->mUnk_14);
    func_ov000_021a3668(a);
    return;
}

s32 func_ov000_0218dc44(void *param_1) {
    Unk0218dc94 *a = param_1;
    return a->mUnk_00;
}
