#include "Main/Unknown/code_020589ec.h"

#pragma thumb on

void func_020589ec(void) {
    int iVar1;
    iVar1 = func_0205955c();
    if (iVar1 == 1) {
        iVar1 = (*(int *) &data_0217aa00) + ((int) 0x00001608u);
        *(u16 *) (iVar1 + 0x10) = 4;
        *(u16 *) (iVar1 + 0x12) = 1;
    }
    return;
}

#pragma thumb off
