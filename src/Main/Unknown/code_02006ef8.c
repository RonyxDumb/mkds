#include "Main/Unknown/code_02006ef8.h"

#pragma thumb on

int func_02006ef8(void) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    for (iVar1 = ((u32) func_02007040()); iVar1 != 0; iVar1 = *(int *) (iVar1 + 0x28)) {
        iVar2 = iVar2 + 1;
    }
    return iVar2;
}

#pragma thumb off
