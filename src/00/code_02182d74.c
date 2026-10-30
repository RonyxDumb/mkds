#include "00/code_02182d74.h"

void func_ov000_02182d74(void) {
    if (func_02036d08() != 0) {
        func_02037288(10);
    }
    if (func_02036c5c() != 0) {
        if (func_02122ae4() != 0) {
            data_ov000_021b4c70->mUnk_04 = 1;
            func_02126638(func_020b3f7c(data_ov000_021b4c70->mUnk_1058, 0x1b), 0, 0, 1, 0, 0, 0);
            func_02122ab0();
            func_0211fe44();
            return;
        }
        data_ov000_021b4c70->mUnk_04 = 2;
        func_ov000_02182de8();
        func_0211fe44();
    }
}
