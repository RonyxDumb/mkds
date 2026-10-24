#include "Main/Unknown/code_02151f88.h"

#pragma thumb on

u32 func_02151f88(u32 param_1) {
    int iVar1;
    u8 auStack_20[24];
    iVar1 = func_02151fc4((u32 *) ((u32 *) (void *) (auStack_20)));
    if (iVar1 == 0) {
        return 0;
    }
    iVar1 = func_02151868((u32) ((u32) (u32) (auStack_20)), (int) (param_1));
    if (iVar1 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
