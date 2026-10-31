#include "Main/Unknown/code_0204ea14.h"

#pragma thumb on

u32 func_0204ea3c(void) {
    u32 uVar1;
    int iVar2;
    u32 uVar3;
    uVar3 = 0;
    uVar1 = func_02008880((int) 0);
    if (((u32) 0x00010000u) <= uVar1) {
        iVar2 = func_02008570((u8 *) 0, (int) (*(u32 *) ((*(int *) &data_0217aa00) + 0x1658)),
                              (u32) (*(u32 *) ((*(int *) &data_0217aa00) + 0x168c)));
        if ((iVar2 != 0) && (iVar2 = func_02008310(data_0215472c,
                                                   (Unk02008188 *) (*(u32 *) ((*(int *) &data_0217aa00) + 0x1658))),
                             iVar2 != 0)) {
            uVar3 = 1;
        }
    }
    return uVar3;
}

void func_0204ea14(u32 param_1) {
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    uVar2 = ((int) func_020b3f7c((void *) param_1, (s32) 0));
    uVar3 = ((int) func_020b3f7c((void *) param_1, (s32) 1));
    iVar1 = ((int) (u32) ((u8 *) &data_0215472c));
    *(u32 *) (((int) (u32) ((u8 *) &data_0215472c)) + 4) = uVar2;
    *(u32 *) (iVar1 + 8) = uVar3;
}

#pragma thumb off
