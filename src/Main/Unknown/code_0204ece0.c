#include "Main/Unknown/code_0204ece0.h"

#pragma thumb on

void func_0204ece0(u16 param_1) {
    int iVar1;
    iVar1 = func_020501b0(param_1);
    if (iVar1 != 0) {
        *(u8 *) ((*(int *) &data_0217aa00) + ((int) 0x00001e45u)) = param_1;
    }
    return;
}

#pragma thumb off
