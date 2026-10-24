#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

void func_020ac2c4(int param_1, int param_2, int param_3) {
    int iVar4;
    int iVar3;
    int iVar2;
    int iVar1;
    iVar1 = _s32_div_f(param_3 * param_3, 2);
    iVar4 = 0;
    if (0 < iVar1) {
        iVar3 = 1;
        iVar2 = 0;
        do {
            *(u8 *) (param_2 + iVar4) = *(u8 *) (param_1 + iVar2) | *(unsigned char *) (param_1 + iVar3) << 4;
            iVar3 = iVar3 + 2;
            iVar2 = iVar2 + 2;
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
    }
    return;
}

#pragma thumb off
