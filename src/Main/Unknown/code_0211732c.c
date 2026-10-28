#include "Main/Unknown/code_0211732c.h"

#pragma thumb on

void func_02117388(void) {
    u32 uVar1;
    int iVar3;
    u32 *puVar2;
    Unk020b4934 *local_20;
    u32 local_1c;
    Unk020b4a44 *local_18[2];
    local_20 = 0;
    local_1c = 0;
    local_18[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d534))));
    func_020b496c(&local_20, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d538))));
    func_020b48ec((void **) (&local_1c), (void *) (uVar1));
    iVar3 = 0;
    puVar2 = (u32 *) &data_0216d53c;
    do {
        uVar1 = ((int) func_0204799c((const char *) (*puVar2)));
        func_020b4a7c(local_18, (void *) (uVar1));
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    return;
}

void func_0211732c(void) {
    u32 uVar1;
    int iVar3;
    u32 *puVar2;
    Unk020b4934 *local_20;
    u32 local_1c;
    Unk020b4a44 *local_18[2];
    local_20 = 0;
    local_1c = 0;
    local_18[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d524))));
    func_020b496c(&local_20, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d528))));
    func_020b48ec((void **) (&local_1c), (void *) (uVar1));
    iVar3 = 0;
    puVar2 = (u32 *) &data_0216d548;
    do {
        uVar1 = ((int) func_0204799c((const char *) (*puVar2)));
        func_020b4a7c(local_18, (void *) (uVar1));
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    return;
}

#pragma thumb off
