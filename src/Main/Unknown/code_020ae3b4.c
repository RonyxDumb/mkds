#include "Main/Unknown/code_020ae3b4.h"
#include "Main/Unknown/code_02045874.h"

#pragma thumb on

u32 func_020ae3b4(u32 param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_020ae3f4());
    if (iVar1 == 0) {
        uVar2 = (u32) func_0204aa60();
    } else {
        uVar2 = ((int) func_020ae3d8());
    }
    return func_02046524((Unk020f41c4_B *) uVar2, param_1);
}

#pragma thumb off
