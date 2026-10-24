#include "Main/Unknown/code_020ce6ec.h"

#pragma thumb on

void func_020ce6ec(void) {
    int iVar1;
    iVar1 = ((u32) func_020cccc0());
    if (iVar1 != 0) {
        iVar1 = func_020ce778();
        if (iVar1 == 0) {
            func_020ce760((int) (0x19));
            func_02148950((u16) (1), (u32) (0), (int) (0));
            func_020ce744((int) (0x1e));
            func_02148934((u32) (0));
        } else {
            func_020ce760((int) (0x18));
            func_02148950((u16) (1), (u32) (0), (int) (0));
            func_020ce744((int) (0x12));
            func_02148934((u32) (0));
        }
    }
    func_0211e4e8();
    return;
}

#pragma thumb off
