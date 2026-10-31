#include "Main/Unknown/code_020f11f0.h"

u32 func_020f11f0(u32 param_1, u32 param_2) {
    u16 uVar1;
    int iVar2;
    uVar1 = ((u32) func_02061f90());
    if (((u32) uVar1 < data_021759c0->mUnk_3d0) &&
        (iVar2 = func_020f1258((int) param_1, (int) uVar1, (int) 0, (int) param_2), iVar2 != 0)) {
        return 1;
    }
    return 0;
}
