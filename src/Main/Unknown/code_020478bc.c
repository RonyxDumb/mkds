#include "Main/Unknown/code_020478bc.h"

#pragma thumb on

void *func_02047974(const char *param_1) {
    int iVar1;
    iVar1 = func_02047b30((u32) (*(u32 *) (((u32) (u32) ((unsigned char *) &data_02164e04)) + 0xc)),
                          param_1);
    if (iVar1 == 0) {
        iVar1 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((unsigned char *) &data_02164e04)) + 0x34)),
                              param_1);
    }
    return (void *) iVar1;
}

void *func_02047950(const char *param_1) {
    int iVar1;
    iVar1 = func_0205e0a0();
    if (iVar1 == 3) {
        return (void *) func_020478bc((u32) param_1);
    }
    return (void *) func_02047780((s8 *) param_1);
}

int func_020478bc(u32 param_1) {
    int iVar1;
    int iVar2;
    iVar2 = 0;
    iVar1 = func_0205e0a0();
    if (((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 0xc)) {
        iVar2 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((unsigned char *) &data_02164e04)) + 0x28)),
                              (const char *) param_1);
    } else {
        if (*(int *) ((*(int *) &data_021759c8) + ((int) 0x00000308u)) != 0) {
            iVar2 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((unsigned char *) &data_02164e04)) + 0x18)),
                                  (const char *) param_1);
        }
        if ((iVar2 == 0) && (*(int *) ((*(int *) &data_021759c8) + ((int) 0x00000378u)) != 0)) {
            iVar2 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((unsigned char *) &data_02164e04)) + 0x1c)),
                                  (const char *) param_1);
        }
        if ((iVar2 == 0) && (*(int *) ((*(int *) &data_021759c8) + ((int) 0x000003e8u)) != 0)) {
            iVar2 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((unsigned char *) &data_02164e04)) + 0x20)),
                                  (const char *) param_1);
        }
    }
    return iVar2;
}

#pragma thumb off
