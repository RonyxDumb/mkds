#include "Main/Unknown/code_0200aeb4.h"

#pragma thumb on

void func_0200aeb4(u32 param_1) {
    u32 uVar1;
    int iVar2;
    uVar1 = ((s64) func_0200fca0());
    iVar2 = func_0200b018();
    if (iVar2 != 0) {
        func_0200aeec((u32 *) ((u32 *) (u32) ((*(int *) &data_0216fde0) + 0xc4)), (u32) (0), (u32) (param_1),
                      (u32) (0));
    }
    func_0200fcb4((u32) (uVar1));
    return;
}

#pragma thumb off
