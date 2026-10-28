#include "Main/Unknown/code_020b2e34.h"

#pragma thumb on

void func_020b2e64(u32 param_1) {
    int iVar1;
    int iVar2;
    iVar1 = ((u32) func_020b2ec0());
    iVar2 = func_020b29c4();
    if (iVar2 != 0) {
        func_020b2f88((int) (param_1));
    }
    iVar2 = ((u32) func_020b2ec0());
    if ((iVar1 == 0) && (iVar2 != 0)) {
        func_02105d70();
    }
    return;
}

unsigned int func_020b2e58(void) {
    return ((unsigned int) *(
        const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                   const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b354))) +
                                                          0))) +
                               4));
}

int func_020b2e34(void) {
    int iVar1;
    int iVar2;
    iVar2 = *(int *) ((*(int *) &data_0217b354) + 0x24);
    if ((iVar2 == 2) && (iVar1 = func_020c3db4(), iVar1 != 0)) {
        iVar2 = 7;
    }
    return iVar2;
}

#pragma thumb off
