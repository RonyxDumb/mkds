#include "Main/Unknown/code_02059388.h"

#pragma thumb on

void func_020593b4(void) {
    int iVar1;
    if ((int *) *((int *) ((u32) (&data_0217aa00))) == (int *) 0x0) {
        iVar1 = 0;
    } else {
        iVar1 = *(int *) *((int *) ((u32) (&data_0217aa00)));
    }
    if (iVar1 == 1) {
        func_020518c8((u32) (0));
    }
    return;
}

void func_02059388(void) {
    int iVar1;
    iVar1 = func_020593dc();
    if (iVar1 == 1) {
        iVar1 = *((int *) ((u32) (&data_0217aa00))) + ((int) 0x00001608u);
        *(u16 *) (iVar1 + 0x10) = 0x11;
        *(u16 *) (iVar1 + 0x12) = 1;
    }
    return;
}

#pragma thumb off
