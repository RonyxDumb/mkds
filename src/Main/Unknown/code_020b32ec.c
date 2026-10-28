#include "Main/Unknown/code_020b32ec.h"

#pragma thumb on

unsigned int func_020b33c4(void) {
    return ((unsigned int) *(
        const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                   const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b354))) +
                                                          0))) +
                               0 + (0x16cu)));
}

u32 func_020b3374(void) {
    int iVar1;
    iVar1 = func_020b2d04();
    if (iVar1 == 1) {
        *(u32 *) (*(int *) ((*(int *) &data_0217b354) + ((int) 0x00000170u)) + 0x14) =
            *(u32 *) ((*(int *) &data_0217b354) + ((int) 0x00000174u));
    } else {
        iVar1 = func_020b2d04();
        if (iVar1 == 2) {
            *(u32 *) (*(int *) ((*(int *) &data_0217b354) + ((int) 0x00000170u)) + 0x14) =
                *(u32 *) ((*(int *) &data_0217b354) + ((int) 0x00000178u));
        }
    }
    return *(u32 *) ((*(int *) &data_0217b354) + ((int) 0x00000170u));
}

int func_020b32f8(void) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = func_020b2d04();
    if (iVar1 == 0) {
        if (*(int *) ((*(int *) &data_0217b354) + ((int) 0x0000017cu)) != 0) {
            iVar2 = *(int *) ((*(int *) &data_0217b354) + ((int) 0x0000017cu)) + 0xc;
        }
    } else if (iVar1 == 1) {
        if (*(int *) ((*(int *) &data_0217b354) + ((int) 0x00000180u)) != 0) {
            iVar2 = *(int *) ((*(int *) &data_0217b354) + ((int) 0x00000180u)) + 0xc;
        }
    } else if (iVar1 == 2) {
        if (*(int *) ((*(int *) &data_0217b354) + ((int) 0x00000184u)) != 0) {
            iVar2 = *(int *) ((*(int *) &data_0217b354) + ((int) 0x00000184u)) + 0xc;
        }
    } else if ((iVar1 == 3) && (*(int *) ((*(int *) &data_0217b354) + ((int) 0x00000188u)) != 0)) {
        iVar2 = *(int *) ((*(int *) &data_0217b354) + ((int) 0x00000188u)) + 0xc;
    }
    return iVar2;
}

unsigned int func_020b32ec(void) {
    return ((unsigned int) *(
        const unsigned int *) ((unsigned char *) (unsigned int) (((unsigned int) *(
                                   const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b354))) +
                                                          0))) +
                               12));
}

#pragma thumb off
