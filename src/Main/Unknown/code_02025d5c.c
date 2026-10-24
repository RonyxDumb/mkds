#include "Main/Unknown/code_02025d5c.h"

#pragma thumb on

int func_02025d74(int param_1) {
    int iVar1;
    iVar1 = ((int *) &data_021533fc)[param_1];
    if (iVar1 != -1) {
        iVar1 = iVar1 + -0x1a;
    }
    return iVar1;
}

int func_02025d5c(int param_1) {
    int iVar1;
    iVar1 = ((int *) &data_021533fc)[param_1];
    if (iVar1 != -1) {
        iVar1 = iVar1 + 4;
    }
    return iVar1;
}

#pragma thumb off
