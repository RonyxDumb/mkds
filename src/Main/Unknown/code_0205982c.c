#include "Main/Unknown/code_0205982c.h"

#pragma thumb on

void func_0205982c(void *param_1) {
    int iVar4;
    int iVar3;
    u32 uVar2;
    int *piVar1;
    uVar2 = (u32) func_02036b74(param_1, ((u32) 0x0000016cu), 0x20);
    piVar1 = (int *) &data_0217aa00;
    *(u32 *) ((int) data_0217aa00 + ((u32) 0x00001624u)) = uVar2;
    iVar4 = 0;
    iVar3 = 0;
    do {
        uVar2 = ((u32) func_02036bec(param_1, (u32) 0x12));
        *(u32 *) (*piVar1 + iVar3 + 0x162c) = uVar2;
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
}

#pragma thumb off
