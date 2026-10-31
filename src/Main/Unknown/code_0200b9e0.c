#include "Main/Unknown/code_0200b9e0.h"

#pragma thumb on

void func_0200b9e0(UnkFunc *param_1, u32 param_2) {
    int *piVar1;
    piVar1 = (int *) &data_0216fde8;
    *(u32 *) ((int) data_0216fde8 + 0x5dc) = (u32) param_1;
    *(u32 *) (*piVar1 + 0x5e4) = param_2;
    *(u16 *) (*piVar1 + 0x584) = 0;
    *(int *) (*piVar1 + 0x580) = *piVar1 + 0x4c0;
    *(u32 *) (*piVar1 + 0x5ef8) = 1;
    *(u32 *) (*piVar1 + 0x5f00) = 0;
    *(u16 *) (*piVar1 + 0x5ee) = 0;
    func_0200b934();
}

#pragma thumb off
