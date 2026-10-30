#include "Main/Unknown/code_02078ee0.h"

#pragma thumb on

void func_02078f78(Unk020136f0 *param_1) {
    u32 uVar1;
    uVar1 = (u32) func_020136f0((Unk020136f0 *) param_1);
    *(u32 *) ((*(int *) &data_0217ad08) + ((int) 0x000001d4u)) = uVar1;
    func_02012cbc((Unk020136f0 *) (param_1));
    return;
}

void func_02078f18(void *param_1, int param_2) {
    u32 uVar1;
    func_02079a3c((u32 *) ((u32 *) (u32) (param_2)));
    *(u32 *) (param_2 + 0xb0) = (u32) data_021759d0->mUnk_00;
    *(u32 *) (param_2 + 0xb4) = 0;
    uVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x6c)));
    *(u32 *) (param_2 + 0x10) = uVar1;
    uVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x6c)));
    *(u32 *) (param_2 + 0x14) = uVar1;
    uVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x6c)));
    *(u32 *) (param_2 + 0x18) = uVar1;
    uVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x74)));
    *(u32 *) (param_2 + 0x1c) = uVar1;
    uVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x38)));
    *(u32 *) (param_2 + 8) = uVar1;
    return;
}

void func_02078ee0(u32 *param_1, int param_2) {
    u32 uVar1;
    uVar1 = 0;
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
    param_1[2] = ((u32) 0x00001000u);
    *(unsigned short *) ((int) param_1 + 0x16) = (short) ((u32) 0x0000eaabu);
    *(u16 *) (param_1 + 5) = *(u16 *) ((int) param_1 + 0x16);
    *(u16 *) (param_1 + 6) = 0;
    param_1[3] = 0;
    param_1[4] = 0xffffff88;
    if (param_2 != 0) {
        uVar1 = 0xffffff06;
    }
    param_1[0xb] = uVar1;
    param_1[0xc] = 0;
    return;
}

#pragma thumb off
