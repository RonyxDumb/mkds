#include "Main/Unknown/code_021144c0.h"

#pragma thumb on

void func_021144c0(void *param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x10)));
    *(int *) &data_0217d34c = iVar1;
    uVar2 = ((u32) func_02036bec((void *) (param_1), (u32) (0x78)));
    *(u32 *) ((*(int *) &data_0217d34c) + 4) = uVar2;
    uVar2 = (u32) func_0205eda0((void *) (param_1));
    *(u32 *) ((*(int *) &data_0217d34c) + 8) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) &data_0216d3e4));
    *(u32 *) ((*(int *) &data_0217d34c) + 0xc) = uVar2;
    return;
}

#pragma thumb off
