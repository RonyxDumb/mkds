#include "Main/Unknown/code_02116dd4.h"

#pragma thumb on

void func_02116e70(void) {
    u32 uVar1;
    u32 local_10;
    u32 local_c;
    u32 local_8[1];
    local_10 = 0;
    local_c = 0;
    local_8[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4c4))))));
    func_020b48ec(&local_10, uVar1);
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4bc))))));
    func_020b49f4(&local_c, uVar1);
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4c0))))));
    func_020b4a7c(local_8, uVar1);
    return;
}

// non-matching: 0x98 bytes, original 0x9c; 37 instructions differ; first at +0x0: original `push {r4, r5, r6, lr}`,
// ours `push {r4, r5, r6, r7, lr}`
void func_02116dd4(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, u32 param_6) {
    int *piVar1;
    int iVar2;
    u32 uVar3;
    iVar2 = ((u32) func_02036bec((void *) (param_1), (u32) (0x2c)));
    *((int *) ((u32) (&data_0217d354))) = iVar2;
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4c4))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_0217d354))))), (void *) (uVar3));
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4bc))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_0217d354))) + 4)), (void *) (uVar3));
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4c0))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_0217d354))) + 8)), (void *) (uVar3));
    uVar3 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216d4c8))))));
    piVar1 = ((int *) ((u32) (&data_0217d354)));
    *(u32 *) (*((int *) ((u32) (&data_0217d354))) + 0xc) = uVar3;
    *(u32 *) (*piVar1 + 0x10) = param_2;
    *(u32 *) (*piVar1 + 0x14) = param_3;
    *(u32 *) (*piVar1 + 0x18) = param_4;
    *(u16 *) (*piVar1 + 0x1c) = param_5;
    *(u32 *) (*piVar1 + 0x20) = param_6;
    *(u16 *) (*piVar1 + 0x24) = 2;
    *(u32 *) (*piVar1 + 0x28) = 3;
    return;
}

#pragma thumb off
