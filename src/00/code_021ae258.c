#include "00/code_021ae258.h"

void func_ov000_021ae2d8(void) {
    int iVar1;
    iVar1 = *(int *) (*(int *) (((int) (u32) ((unsigned char *) &data_0216ff5c)) + 4) + 0xa4);
    if (iVar1 != 0) {
        *(u8 *) (iVar1 + 8) = 10;
        *(u32 *) (iVar1 + 0x44) = 0;
    }
    return;
}

void func_ov000_021ae290(int param_1, u16 param_2, int param_3) {
    u16 uVar1;
    int iVar2;
    iVar2 = *(int *) (*(int *) (((int) (u32) ((unsigned char *) &data_0216ff5c)) + 4) + 0xa4);
    if (iVar2 != 0) {
        if (param_3 == ((int) 0x7f000001u)) {
            param_3 = *((int *) ((u32) (&data_ov000_021b63b4)));
        }
        *(u16 *) (iVar2 + 0x1a) = param_2;
        *(u16 *) (iVar2 + 0x18) = *(u16 *) (iVar2 + 0x1a);
        *(int *) (iVar2 + 0x20) = param_3;
        *(u32 *) (iVar2 + 0x1c) = *(u32 *) (iVar2 + 0x20);
        if (param_1 == 0) {
            uVar1 = func_ov000_021ae340();
            *(u16 *) (iVar2 + 10) = uVar1;
            return;
        }
        *(short *) (iVar2 + 10) = (short) param_1;
    }
    return;
}

void func_ov000_021ae270(void) {
    int *piVar1;
    piVar1 = *(int **) (*(int *) (((int) (u32) ((unsigned char *) &data_0216ff5c)) + 4) + 0xa4);
    if (piVar1 != (int *) 0x0) {
        *piVar1 = *(int *) (((int) (u32) ((unsigned char *) &data_0216ff5c)) + 4);
        *(u8 *) (piVar1 + 2) = 0;
        piVar1[0x11] = 0;
        piVar1[0x18] = 0;
        piVar1[0xe] = 0;
    }
    return;
}

void func_ov000_021ae258(void) {
    u32 *puVar1;
    puVar1 = *(u32 **) (*(int *) (((int) (u32) ((unsigned char *) &data_0216ff5c)) + 4) + 0xa4);
    if (puVar1 != (u32 *) 0x0) {
        *puVar1 = 0;
    }
    return;
}
