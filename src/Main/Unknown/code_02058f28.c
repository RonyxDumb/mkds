#include "Main/Unknown/code_02058f28.h"

#pragma thumb on

void func_02058f28(void) {
    int iVar1;
    iVar1 = func_02058dc0((u32) &func_02058f58);
    if (iVar1 == 1) {
        iVar1 = (*(int *) &data_0217aa00) + ((int) 0x00001608u);
        *(u16 *) (iVar1 + 0x10) = 0xf;
        *(u16 *) (iVar1 + 0x12) = 1;
    }
    return;
}

#pragma thumb off
