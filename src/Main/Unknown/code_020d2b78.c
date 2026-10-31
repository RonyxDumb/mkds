#include "Main/Unknown/code_020d2b78.h"

#pragma thumb on

u32 func_020d2c20(void) {
    return ((u32) *(const u32 *) ((u8 *) (u32) (((u32) (&data_0217b4ec))) + 0));
}

u32 func_020d2be8(void) {
    int iVar1;
    if ((*(int *) &data_0217b4d8) != 0) {
        return *(u32 *) ((*(int *) &data_0217b4d8) + 4);
    }
    iVar1 = *(int *) &data_0217b4e4;
    if ((iVar1 != 0) && (*(int *) (iVar1 + 0x170) != 0)) {
        return *(u32 *) (iVar1 + 0x174);
    }
    return 0;
}

u32 func_020d2bb0(void) {
    int iVar1;
    if ((*(int *) &data_0217b4d8) != 0) {
        return *(u32 *) ((*(int *) &data_0217b4d8) + 8);
    }
    iVar1 = *(int *) &data_0217b4e4;
    if ((iVar1 != 0) && (*(int *) (iVar1 + 0x170) != 0)) {
        return *(u32 *) (iVar1 + 0x178);
    }
    return 0;
}

u32 func_020d2b78(void) {
    int iVar1;
    if ((*(int *) &data_0217b4d8) != 0) {
        return *(u32 *) ((*(int *) &data_0217b4d8) + 0xc);
    }
    iVar1 = *(int *) &data_0217b4e4;
    if ((iVar1 != 0) && (*(int *) (iVar1 + 0x170) != 0)) {
        return *(u32 *) (iVar1 + 0x17c);
    }
    return 0;
}

#pragma thumb off
