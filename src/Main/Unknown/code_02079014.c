#include "Main/Unknown/code_02079014.h"

#pragma thumb on

void func_02079078(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    u32 uVar1;
    u32 uVar2;
    uVar1 = func_02084d3c(param_2, param_4, param_5);
    func_020849c0(param_2, 3);
    func_0207a14c((u32) (uVar1), (u32) (1));
    func_0208823c(0, param_3, param_2, 1, param_1, 0);
    uVar1 = func_02013a30((u32) (param_6));
    uVar1 = func_02013a4c((int) (uVar1), (int) (0));
    uVar2 = func_0207b8dc((int) (2));
    func_020881b0((int) (param_3), (int) (0), (u32) (uVar1), (u32) (uVar2), (int) (param_1));
    func_02087f84((int) (param_3), (int) (0));
    return;
}

void func_02079038(u32 param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = func_02084d3c();
    func_020849c0(param_1, 3);
    func_0207a14c((u32) (iVar1), (u32) (1));
    uVar2 = func_02013754((int) (iVar1 + *(int *) (iVar1 + 8) + 4), (u32) (((u32) ((u32) (&data_02155098)))));
    func_02013468((int) (iVar1), (int) (uVar2), (int) (0));
    return;
}

void func_02079014(u32 param_1) {
    u32 uVar1;
    uVar1 = func_02084d3c();
    func_020849c0(param_1, 3);
    func_0207a14c((u32) (uVar1), (u32) (1));
    return;
}

#pragma thumb off
