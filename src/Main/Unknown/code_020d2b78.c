#include "Main/Unknown/code_020d2b78.h"

#pragma thumb on

unsigned int func_020d2c20(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b4ec))) + 0));
}

u32 func_020d2be8(void) {
    int iVar1;
    if ((*(int *) &data_0217b4d8) != 0) {
        return *(u32 *) ((*(int *) &data_0217b4d8) + 4);
    }
    iVar1 = *(int *) &data_0217b4e4;
    if ((iVar1 != 0) && (*(int *) (iVar1 + ((int) 0x00000170u)) != 0)) {
        return *(u32 *) (iVar1 + ((int) 0x00000174u));
    }
    return 0;
}

u32 func_020d2bb0(void) {
    int iVar1;
    if ((*(int *) &data_0217b4d8) != 0) {
        return *(u32 *) ((*(int *) &data_0217b4d8) + 8);
    }
    iVar1 = *(int *) &data_0217b4e4;
    if ((iVar1 != 0) && (*(int *) (iVar1 + ((int) 0x00000170u)) != 0)) {
        return *(u32 *) (iVar1 + ((int) 0x00000178u));
    }
    return 0;
}

u32 func_020d2b78(void) {
    int iVar1;
    if ((*(int *) &data_0217b4d8) != 0) {
        return *(u32 *) ((*(int *) &data_0217b4d8) + 0xc);
    }
    iVar1 = *(int *) &data_0217b4e4;
    if ((iVar1 != 0) && (*(int *) (iVar1 + ((int) 0x00000170u)) != 0)) {
        return *(u32 *) (iVar1 + ((int) 0x0000017cu));
    }
    return 0;
}

#pragma thumb off
