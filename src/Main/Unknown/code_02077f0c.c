#include "Main/Unknown/code_02077f0c.h"

#pragma thumb on

void func_02077f48(unsigned int p0) {
    *(unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                           const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217ad08))) + 0))) +
                       0 + (0x1d8u)) = (unsigned int) (p0);
}

void func_02077f0c(u16 *param_1, int param_2, u32 param_3) {
    u16 uVar1;
    int sVar2;
    int iVar3;
    uVar1 = *param_1;
    iVar3 = param_2 - (u32) uVar1;
    if (iVar3 < 0) {
        iVar3 = ((int) 0x0000ffffu) - iVar3;
    }
    sVar2 = func_021488e8((int) (iVar3), (int) (param_3));
    *param_1 = *param_1 + sVar2;
    if ((int) ((*param_1 + 100) - param_2) < 0) {
        *param_1 = (u16) (*param_1 + 100);
        return;
    }
    *param_1 = uVar1;
    return;
}

#pragma thumb off
