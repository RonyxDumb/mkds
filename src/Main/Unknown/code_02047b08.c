#include "Main/Unknown/code_02047b08.h"

#pragma thumb on

void *func_02047b08(const char *param_1) {
    int iVar1;
    iVar1 = func_02047b30((u32) (*(u32 *) (((u32) (u32) ((unsigned char *) &data_02164e04)) + 0x0)),
                          param_1);
    if (iVar1 == 0) {
        iVar1 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((unsigned char *) &data_02164e04)) + 0x48)),
                              param_1);
    }
    return (void *) iVar1;
}

#pragma thumb off
