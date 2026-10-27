#include "Main/Unknown/code_020581f4.h"

#pragma thumb on

void func_020581f4(void) {
    int iVar1;
    if ((int *) (*(int *) &data_0217aa00) == (int *) 0x0) {
        iVar1 = 0;
    } else {
        iVar1 = *(int *) (*(int *) &data_0217aa00);
    }
    if (iVar1 == 1) {
        func_020518c8((u32) (1));
    }
    return;
}

#pragma thumb off
