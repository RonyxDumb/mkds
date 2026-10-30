#include "Main/Unknown/code_0202b888.h"

#pragma thumb on

u32 func_0202b8c0(void) {
    if (data_02174e3c->mUnk_040 == 0) {
        return 1;
    }
    return 0;
}

u32 func_0202b888(void) {
    u32 uVar5;
    int iVar4;
    int iVar3;
    int iVar2;
    uVar5 = 1;
    iVar4 = 0;
    if (0 < data_02174e3c->mUnk_048) {
        iVar3 = 0;
        do {
            iVar2 = ((u32) func_02029930());
            uVar5 = uVar5 & *(u32 *) (iVar2 + iVar3 + 0x14);
            iVar3 = iVar3 + 0x18;
            iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *) (*(int *) &data_02174e3c + 0x48));
    }
    return uVar5;
}

#pragma thumb off
