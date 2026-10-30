#include "Main/Unknown/code_02116888.h"

#pragma thumb on

void func_02116888(void) {
    int *piVar1;
    u32 uVar2;
    int iVar3;
    int local_18;
    int local_14;
    int local_10[2];
    local_18 = 0;
    local_14 = 0;
    local_10[0] = 0;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d20c))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d350))), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d200))));
    func_020b48b4(&data_0217d350->mUnk_04, (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d1f4))));
    *(u32 *) ((*(int *) &data_0217d350) + 8) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d22c))));
    *(u32 *) ((*(int *) &data_0217d350) + 0xc) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d238))));
    *(u32 *) ((*(int *) &data_0217d350) + 0x18) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d1fc))));
    *(u32 *) ((*(int *) &data_0217d350) + 0x1c) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d208))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d350) + 0x28)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d210))));
    func_020b48b4(&data_0217d350->mUnk_2c, (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f0))));
    *(u32 *) ((*(int *) &data_0217d350) + 0x30) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3fc))));
    *(u32 *) ((*(int *) &data_0217d350) + 0x34) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f8))));
    piVar1 = (&(*(int *) &data_0217d350));
    *(u32 *) ((*(int *) &data_0217d350) + 0x38) = uVar2;
    uVar2 = ((u32) func_02036bec((void *) (*(u32 *) (*piVar1 + 0x50)), (u32) (((u32) 0x00000800u))));
    *(u32 *) ((*(int *) &data_0217d350) + 0x4c) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f4))));
    func_020b4934((Unk020b4934 **) (&local_18), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d400))));
    func_020b47d8((Unk020b47d8 **) (local_10), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d404))));
    func_020b4a44((Unk020b4a44 **) (&local_14), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d228))));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((*(int *) &data_0217d350) + 0x10)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d214))));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((*(int *) &data_0217d350) + 0x20)), (void *) (uVar2));
    iVar3 = ((u32) func_02077f00());
    ((u32) func_02016468((u32) (0x17), (u32) (0), (void *) (*(u32 *) (local_18 + 0x14)),
                         (u32) (*(u32 *) (local_18 + 0x10))));
    ((u32) func_02016468((u32) (0x1b), (u32) (0), (void *) (local_10[0] + 0xc), (u32) (*(u32 *) (local_10[0] + 8))));
    ((u32) func_02016468((u32) (0x1b), (u32) (((u32) 0x00000800u)),
                         (void *) data_0217d350->mUnk_4c, (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) (0x1f), (u32) (0), (void *) (*(u32 *) (local_14 + 0xc)), (u32) (0x40)));
    ((u32) func_02016468((u32) (0xe), (u32) (0x40), (void *) (*(u32 *) (iVar3 + 0xc)), (u32) (0x20)));
    return;
}

#pragma thumb off
