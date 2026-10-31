#include "Main/Unknown/code_020574c8.h"

#pragma thumb on

void func_02057514(void) {
    data_0217aa08->mUnk_28 = 1;
}

void func_02057504(void) {
    data_0217aa08->mUnk_28 = 0;
}

void func_020574c8(void) {
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    func_02057ca4(data_0217aa08->mUnk_00);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    func_02057504();
}

#pragma thumb off
