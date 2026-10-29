#include "Main/Unknown/code_02025df4.h"

#pragma thumb on

int func_02025df4(int param_1, u32 param_2) {
    int iVar4;
    int iVar3;
    int iVar2;
    u32 uVar1;
    iVar4 = 0;
    iVar3 = 0;
    do {
        uVar1 = func_02025e28(iVar3);
        iVar2 = func_0205fd2c((Unk0205fd2c *) param_1, param_2, uVar1);
        if (iVar2 != 0) {
            iVar4 = iVar4 + 1;
        }
        iVar3 = iVar3 + 1;
    } while (iVar3 < 0x24);
    return iVar4;
}

#pragma thumb off
