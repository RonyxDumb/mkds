#include "Main/Unknown/code_020d7db4.h"

#pragma thumb on

void func_020d7db4(int *param_1, u16 param_2, int param_3) {
    *(u16 *) (param_1 + 2) = param_2;
    func_020d7e44((u32) ((u32) * (u16 *) (param_1 + 2)),
                  (int) (*(int *) ((*(int *) &data_02175620) + 8) + (u32) * (u16 *) (param_1 + 2) * 4));
    *param_1 = (*(int *) &data_0217b670) + (u32) * (u16 *) (param_1 + 2) * 0xc;
    param_1[1] = param_3;
    func_020d90a8((Unk020e0144 *) param_1, 0, 1);
}

#pragma thumb off
