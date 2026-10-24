#include "Main/Unknown/code_020d7d80.h"

#pragma thumb on

void func_020d7d80(u32 *param_1) {
    int *piVar5;
    int iVar4;
    int iVar3;
    int iVar2;
    int iVar1;
    piVar5 = (int *) *param_1;
    iVar3 = piVar5[1];
    iVar4 = 0;
    if (0 < iVar3) {
        iVar2 = 0;
        do {
            iVar1 = *piVar5 + iVar2;
            *(u32 *) (iVar1 + 0x30) = *(u32 *) (iVar1 + 0x40);
            *(u32 *) (iVar1 + 0x34) = *(u32 *) (iVar1 + 0x44);
            iVar2 = iVar2 + 0x54;
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
    }
    return;
}

#pragma thumb off
