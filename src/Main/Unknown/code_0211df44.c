#include "Main/Unknown/code_0211df44.h"

#pragma thumb on

void func_0211e074(void) {
    u32 uVar1;
    Unk020b4934 *local_10;
    u32 local_c;
    Unk020b4a44 *local_8[1];
    local_10 = 0;
    local_c = 0;
    local_8[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded4))));
    func_020b496c(&local_10, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded8))));
    func_020b48ec((Unk02021dc8 **) (&local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dec4))));
    func_020b4a7c(local_8, (void *) (uVar1));
    return;
}

void func_0211e024(void) {
    u32 uVar1;
    Unk020b4934 *local_10;
    u32 local_c;
    Unk020b4a44 *local_8[1];
    local_10 = 0;
    local_c = 0;
    local_8[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dedc))));
    func_020b496c(&local_10, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216decc))));
    func_020b48ec((Unk02021dc8 **) (&local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dee0))));
    func_020b4a7c(local_8, (void *) (uVar1));
    return;
}

void func_0211dfb4(u32 param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x10)));
    *(int *) &data_0217d370 = iVar1;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded4))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d370))), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded8))));
    func_020b48b4((Unk02021dc8 **) ((int *) (u32) ((*(int *) &data_0217d370) + 4)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dec4))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) ((*(int *) &data_0217d370) + 8)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dec8))));
    *(u32 *) ((*(int *) &data_0217d370) + 0xc) = uVar2;
    return;
}

void func_0211df44(void *param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x10)));
    *(int *) &data_0217d370 = iVar1;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dedc))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d370))), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216decc))));
    func_020b48b4((Unk02021dc8 **) ((int *) (u32) ((*(int *) &data_0217d370) + 4)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dee0))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) ((*(int *) &data_0217d370) + 8)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded0))));
    *(u32 *) ((*(int *) &data_0217d370) + 0xc) = uVar2;
    return;
}

#pragma thumb off
