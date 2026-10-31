#include "Main/Unknown/code_0205928c.h"

#pragma thumb on

void func_020592d4(void) {
    int iVar1;
    iVar1 = func_02058dc0(func_0205933c);
    if (iVar1 == 1) {
        iVar1 = (*(int *) &data_0217aa00) + 0x1608;
        *(u16 *) (iVar1 + 0x10) = 0x14;
        *(u16 *) (iVar1 + 0x12) = 1;
    }
}

void func_020592ac(void) {
    int iVar1;
    if ((int *) (*(int *) &data_0217aa00) == (int *) 0x0) {
        iVar1 = 0;
    } else {
        iVar1 = *(int *) (*(int *) &data_0217aa00);
    }
    if (iVar1 == 1) {
        func_020518c8((u32) 1);
    }
}

void func_0205928c(void) {
    int iVar1;
    if (*(int *) ((*(int *) &data_0217aa00) + 0x10) == 0) {
        iVar1 = (*(int *) &data_0217aa00) + 0x1608;
        *(u16 *) (iVar1 + 0x10) = 0xf;
        *(u16 *) (iVar1 + 0x12) = 1;
    }
}

#pragma thumb off
