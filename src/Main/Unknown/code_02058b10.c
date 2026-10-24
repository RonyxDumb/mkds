#include "Main/Unknown/code_02058b10.h"

#pragma thumb on

void func_02058b10(void) {
    int iVar1;
    func_020562e8();
    iVar1 = *((int *) ((u32) (&data_0217aa00))) + ((int) 0x00001608u);
    *(u16 *) (iVar1 + 0x10) = 0xf;
    *(u16 *) (iVar1 + 0x12) = 1;
    return;
}

#pragma thumb off
