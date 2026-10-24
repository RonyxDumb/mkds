#include "Main/Unknown/code_0203be48.h"

#pragma thumb on

void func_0203be6c(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    func_0203bea4();
    func_0203be88((u8 *) ((u8 *) (u32) (param_1)), (u32) (param_2), (u32) (param_4));
    return;
}

void func_0203be48(int param_1, int param_2, u32 *param_3, u32 *param_4) {
    if (param_3 != (u32 *) 0x0) {
        *param_3 = *(u32 *) (param_1 + param_2 * 4 + 4);
    }
    if (param_4 != (u32 *) 0x0) {
        *param_4 = *(u32 *) (param_1 + param_2 * 4 + 0x24);
    }
    return;
}

#pragma thumb off
