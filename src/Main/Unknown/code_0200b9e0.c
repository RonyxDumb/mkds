#include "Main/Unknown/code_0200b9e0.h"

#pragma thumb on

void func_0200b9e0(u32 param_1, u32 param_2) {
    int *piVar1;
    piVar1 = (int *) &data_0216fde8;
    *(u32 *) ((*(int *) &data_0216fde8) + ((int) 0x000005dcu)) = param_1;
    *(u32 *) (*piVar1 + ((int) 0x000005e4u)) = param_2;
    *(u16 *) (*piVar1 + ((int) 0x00000584u)) = 0;
    *(int *) (*piVar1 + ((int) 0x00000580u)) = *piVar1 + ((int) 0x000004c0u);
    *(u32 *) (*piVar1 + ((int) 0x00005ef8u)) = 1;
    *(u32 *) (*piVar1 + ((int) 0x00005f00u)) = 0;
    *(u16 *) (*piVar1 + ((int) 0x000005eeu)) = 0;
    func_0200b934();
    return;
}

#pragma thumb off
