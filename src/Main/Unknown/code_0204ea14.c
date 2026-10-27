#include "Main/Unknown/code_0204ea14.h"

#pragma thumb on

u32 func_0204ea3c(void) {
    u32 uVar1;
    int iVar2;
    u32 uVar3;
    uVar3 = 0;
    uVar1 = func_02008880((int) (0));
    if (((u32) 0x00010000u) <= uVar1) {
        iVar2 = func_02008570((u8 *) (0), (int) (*(u32 *) ((*(int *) &data_0217aa00) + ((int) 0x00001658u))),
                              (u32) (*(u32 *) ((*(int *) &data_0217aa00) + ((int) 0x0000168cu))));
        if ((iVar2 != 0) && (iVar2 = func_02008310((int) (((u32) &data_0215472c)),
                                                   (int) (*(u32 *) ((*(int *) &data_0217aa00) + ((int) 0x00001658u)))),
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
    uVar2 = ((int) func_020b3f7c((void *) (param_1), (s32) (0)));
    uVar3 = ((int) func_020b3f7c((void *) (param_1), (s32) (1)));
    iVar1 = ((int) (u32) ((unsigned char *) &data_0215472c));
    *(u32 *) (((int) (u32) ((unsigned char *) &data_0215472c)) + 4) = uVar2;
    *(u32 *) (iVar1 + 8) = uVar3;
    return;
}

#pragma thumb off
