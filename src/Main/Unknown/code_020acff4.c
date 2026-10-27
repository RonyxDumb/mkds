#include "Main/Unknown/code_020acff4.h"

#pragma thumb on

void func_020acff4(void) {
    int iVar1;
    func_020ad028();
    iVar1 = *(int *) &data_0217b340;
    func_02124c30((void *) (*(u32 *) (iVar1 + 0x6c)), (void *) (*(u32 *) (iVar1 + 0xa8)),
                  (void *) (*(u32 *) (iVar1 + 0x74)), (void *) (iVar1 + ((int) 0x000004b4u)),
                  (void *) (*(u32 *) (iVar1 + 0x68)));
    return;
}

#pragma thumb off
