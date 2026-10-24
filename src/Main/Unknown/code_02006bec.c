#include "Main/Unknown/code_02006bec.h"

#pragma thumb on

void func_02006c0c(u32 param_1, u32 param_2, int param_3) {
    u32 uVar1;
    if (0 < param_3) {
        uVar1 = ((u32) func_020070b8());
        func_02005dac((int) (uVar1), (int) (param_1), (u32) (param_2), (int) (param_3));
    }
    return;
}

void func_02006bec(u32 param_1, u32 param_2) {
    u32 uVar1;
    uVar1 = ((u32) func_020070b8());
    func_02005dac((int) (uVar1), (int) (0), (u32) (param_1), (int) (param_2));
    return;
}

#pragma thumb off
