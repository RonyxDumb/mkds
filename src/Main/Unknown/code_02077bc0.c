#include "Main/Unknown/code_02077bc0.h"
#include "code_020172d0.h"

#pragma thumb on

void func_02077bc0(void *param_1) {
    u32 uVar1;
    u32 uVar2;
    u32 uVar3;
    u32 uVar4;
    uVar1 = func_020170dc(0x20);
    uVar2 = func_020172d0(0x20);
    uVar3 = ((u32) func_02036bec(param_1, uVar1));
    uVar4 = ((u32) func_02036bec(param_1, uVar2));
    func_02017070((u32) 0x00040000u, (u32) 0x00020000u, (Unk020169a4 *) uVar3, uVar1, 1);
    func_02017274((u32) 0x00010000u, uVar4, uVar2, 1);
}

#pragma thumb off
