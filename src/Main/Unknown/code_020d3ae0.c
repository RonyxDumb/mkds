#include "Main/Unknown/code_020d3ae0.h"

#pragma thumb on

void func_020d3ae0(int param_1, int param_2) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((int) 0x00002710u);
    if (((int) 0x00002710u) <= param_1) {
        *(u16 *) (param_2 + 2) = *(u16 *) (param_2 + 2) | *((u16 *) ((u32) (&data_021568e8)));
        param_1 = (param_1 - iVar1) * 0x10000 >> 0x10;
    }
    uVar2 = func_020d2178((u32) (param_1));
    *(u32 *) (param_2 + 0x74) = uVar2;
    return;
}

#pragma thumb off
