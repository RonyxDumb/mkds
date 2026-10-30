#include "Main/Unknown/code_02077bc0.h"
#include "code_020172d0.h"

#pragma thumb on

void func_02077bc0(void *param_1) {
    u32 uVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    uVar1 = func_020170dc((int) (0x20));
    uVar2 = func_020172d0((int) (0x20));
    uVar3 = ((u32) func_02036bec((void *) (param_1), (u32) (uVar1)));
    uVar4 = ((u32) func_02036bec((void *) (param_1), (u32) (uVar2)));
    func_02017070((u32) (0x00040000u), (u32) (0x00020000u), (Unk020169a4 *) (uVar3), (u32) (uVar1), (int) (1));
    func_02017274((u32) (0x00010000u), (u32) (uVar4), (u32) (uVar2), (int) (1));
    return;
}

#pragma thumb off
