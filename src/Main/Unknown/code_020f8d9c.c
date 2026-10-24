#include "Main/Unknown/code_020f8d9c.h"

#pragma thumb on

void func_020f8d9c(int param_1, u32 param_2, int param_3) {
    *(u32 *) (param_1 + 0x48) = param_2;
    func_020e0650((u32 *) (u32) (param_1 + ((int) 0x00000104u)));
    func_02109110(param_1, *(u32 *) (*((int *) ((u32) (&data_0217bc34))) + param_3 * 0xa8 + 0xa0), param_1 + 0x50);
    func_02109054(param_1);
    return;
}

#pragma thumb off
