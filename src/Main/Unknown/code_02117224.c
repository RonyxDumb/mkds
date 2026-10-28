#include "Main/Unknown/code_02117224.h"

#pragma thumb on

void func_02117224(void *heap) {
    s32 i;

    data_0217d35c = func_02036bec(heap, 0x18);
    func_020b49bc(&data_0217d35c->mUnk_00, func_0204799c(data_0216d524));
    func_020b48b4(&data_0217d35c->mUnk_04, func_0204799c(data_0216d528));
    for (i = 0; i < 3; i++) {
        func_020b4a44(&data_0217d35c->mUnk_08[i], func_0204799c(data_0216d548[i]));
    }
    data_0217d35c->mUnk_14 = func_0204799c(data_0216d530);
}

#pragma thumb off
