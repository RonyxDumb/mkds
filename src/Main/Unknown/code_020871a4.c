#include "Main/Unknown/code_020871a4.h"

#pragma thumb on

void func_020871c0(int param_1, u32 param_2) {
    u16 uVar1;
    u16 *puVar2;
    u32 uVar3;
    uVar3 = *(u32 *) &data_0217aec4;
    puVar2 = (u16 *) (*(u32 *) &data_0217aec8);
    *puVar2 = (short) ((u32) 0x00007c00u);
    uVar1 = func_020873e4((int) (param_2));
    puVar2[1] = uVar1;
    puVar2[2] = 0;
    puVar2[3] = 0x1f;
    func_0200ee74((u32) ((u32) (u32) (puVar2)), (int) (8));
    func_0214d168((void *) ((u32 *) (u32) (uVar3)), (u8) (0), (u32) (*(u32 *) (param_1 + 4)));
    func_020adddc((u32) (param_2), (u32) (uVar3), (u32) (1), (u32) (2));
    func_0200ee74((u32) (uVar3), (int) (((u32) 0x00000100u)));
    *(u32 *) (param_1 + 0xc) = uVar3;
    *(u16 **) (param_1 + 0x10) = puVar2;
    return;
}

void func_020871a4(int param_1, u32 param_2) {
    u16 uVar1;
    int iVar2;
    iVar2 = *(int *) (param_1 + 0x10);
    uVar1 = func_020873e4((int) (param_2));
    *(u16 *) (iVar2 + 2) = uVar1;
    func_0200ee74((u32) (iVar2), (int) (8));
    return;
}

#pragma thumb off
