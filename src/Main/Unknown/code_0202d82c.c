#include "Main/Unknown/code_0202d82c.h"

#pragma thumb on

void func_0202d82c(void) {
    u32 uVar1;
    u32 uVar2;
    uVar1 = ((int) func_020b3f7c((void *) data_02174e40->mUnk_0ac, (s32) (0xd)));
    uVar2 = ((int) func_020b3f7c((void *) data_02174e40->mUnk_0a8, (s32) (4)));
    *(u32 *) ((*(int *) &data_02174e40) + 0xb0) = 8;
    func_02126230((unsigned int) (uVar1), (unsigned int) (uVar2));
    return;
}

#pragma thumb off
