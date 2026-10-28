#include "Main/Unknown/code_020d3ae0.h"

#pragma thumb on

void func_020d3ae0(s32 param_1, Unk020e71a0 *param_2) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((int) 0x00002710u);
    if (((int) 0x00002710u) <= param_1) {
        param_2->mUnk_02 = param_2->mUnk_02 | (*(u16 *) &data_021568e8);
        param_1 = (param_1 - iVar1) * 0x10000 >> 0x10;
    }
    uVar2 = func_020d2178((u32) (param_1));
    param_2->mUnk_74 = uVar2;
    return;
}

#pragma thumb off
