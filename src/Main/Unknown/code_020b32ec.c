#include "Main/Unknown/code_020b32ec.h"

#pragma thumb on

Unk020b4a44 *func_020b33c4(void) {
    return ((Unk020b4a44 *) *(
        const u32 *) ((u8 *) (u32) (((u32) *(
                                   const u32 *) ((u8 *) (u32) (((u32) (&data_0217b354))) +
                                                          0))) +
                               0 + (0x16cu)));
}

Unk020b4934 *func_020b3374(void) {
    int iVar1;
    iVar1 = func_020b2d04();
    if (iVar1 == 1) {
        *(u32 *) (*(int *) ((int) data_0217b354 + 0x170) + 0x14) =
            *(u32 *) ((int) data_0217b354 + 0x174);
    } else {
        iVar1 = func_020b2d04();
        if (iVar1 == 2) {
            *(u32 *) (*(int *) ((int) data_0217b354 + 0x170) + 0x14) =
                *(u32 *) ((int) data_0217b354 + 0x178);
        }
    }
    return *(Unk020b4934 **) ((int) data_0217b354 + 0x170);
}

void *func_020b32f8(void) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = func_020b2d04();
    if (iVar1 == 0) {
        if (*(int *) ((int) data_0217b354 + 0x17c) != 0) {
            iVar2 = *(int *) ((int) data_0217b354 + 0x17c) + 0xc;
        }
    } else if (iVar1 == 1) {
        if (*(int *) ((int) data_0217b354 + 0x180) != 0) {
            iVar2 = *(int *) ((int) data_0217b354 + 0x180) + 0xc;
        }
    } else if (iVar1 == 2) {
        if (*(int *) ((int) data_0217b354 + 0x184) != 0) {
            iVar2 = *(int *) ((int) data_0217b354 + 0x184) + 0xc;
        }
    } else if ((iVar1 == 3) && (*(int *) ((int) data_0217b354 + 0x188) != 0)) {
        iVar2 = *(int *) ((int) data_0217b354 + 0x188) + 0xc;
    }
    return (void *) iVar2;
}

u32 func_020b32ec(void) {
    return ((u32) *(
        const u32 *) ((u8 *) (u32) (((u32) *(
                                   const u32 *) ((u8 *) (u32) (((u32) (&data_0217b354))) +
                                                          0))) +
                               12));
}

#pragma thumb off
