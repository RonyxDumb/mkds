#include "Main/Unknown/code_0200635c.h"

#pragma thumb on

void func_0200635c(int param_1, u32 param_2) {
    int iVar1;
    *(int *) (param_1 + 0x10) = *(int *) (param_1 + 0x10) + 1;
    *(u32 *) (param_1 + 0xc) = param_2;
    iVar1 = ((int) param_2 >> 5) * 4;
    *(u32 *) (*(int *) (param_1 + 0x14) + iVar1) = *(u32 *) (*(int *) (param_1 + 0x14) + iVar1) | 1 << (param_2 & 0x1f);
    return;
}

#pragma thumb off
