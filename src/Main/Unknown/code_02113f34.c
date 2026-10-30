#include "Main/Unknown/code_02113f34.h"

#pragma thumb on

void func_02113f34(void) {
    u32 uVar1;
    int iVar2;
    int iVar3;
    int local_20;
    int local_1c;
    int local_18;
    int local_14;
    int local_10;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d20c))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d348))), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d200))));
    func_020b48b4(&data_0217d348->mUnk_04, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d1f8))));
    func_020b4a44((Unk020b4a44 **) (&local_20), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d1f4))));
    *(u32 *) ((*(int *) &data_0217d348) + 8) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d22c))));
    *(u32 *) ((*(int *) &data_0217d348) + 0xc) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d238))));
    *(u32 *) ((*(int *) &data_0217d348) + 0x18) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d1fc))));
    *(u32 *) ((*(int *) &data_0217d348) + 0x1c) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d208))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_0217d348) + 0x28)), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d210))));
    func_020b48b4(&data_0217d348->mUnk_2c, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d218))));
    func_020b4a44((Unk020b4a44 **) (&local_10), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d204))));
    *(u32 *) ((*(int *) &data_0217d348) + 0x30) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d234))));
    *(u32 *) ((*(int *) &data_0217d348) + 0x34) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d21c))));
    *(u32 *) ((*(int *) &data_0217d348) + 0x38) = uVar1;
    iVar2 = ((u32) func_02077f00());
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d220))));
    func_020b4934((Unk020b4934 **) (&local_1c), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d230))));
    func_020b47d8((Unk020b47d8 **) (&local_18), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d228))));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((*(int *) &data_0217d348) + 0x10)), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d214))));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((*(int *) &data_0217d348) + 0x20)), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d224))));
    func_020b4a44((Unk020b4a44 **) (&local_14), (void *) uVar1);
    iVar3 = *(int *) (local_20 + 0xc);
    ((u32) func_02016468((u32) 0x13, (u32) 0, (void *) (*(u32 *) ((int) data_0217d348->mUnk_00 + 0x14)),
                         (u32) (*(u32 *) ((int) data_0217d348->mUnk_00 + 0x10))));
    ((u32) func_02016468((u32) 0xe, (u32) 0, (void *) (*(u32 *) (local_20 + 0xc)), (u32) (((u32) 0x000001a0u))));
    ((u32) func_02016468((u32) 0xe, (u32) 0x1c0, (void *) (iVar3 + 0x1c0),
                         (u32) 0x40));
    ((u32) func_02016468((u32) 0x23, (u32) 0,
                         (void *) (*(u32 *) ((int) data_0217d348->mUnk_28 + 0x14)),
                         (u32) (*(u32 *) ((int) data_0217d348->mUnk_28 + 0x10))));
    ((u32) func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) (local_10 + 0xc)),
                         (u32) (*(u32 *) (local_10 + 8))));
    ((u32) func_02016468((u32) 4, (u32) 0, (void *) (*(u32 *) (local_1c + 0x14)),
                         (u32) (*(u32 *) (local_1c + 0x10))));
    ((u32) func_02016468((u32) 8, (u32) 0, (void *) (local_18 + 0xc), (u32) (*(u32 *) (local_18 + 8))));
    ((u32) func_02016468((u32) 0xf, (u32) 0, (void *) (*(u32 *) (local_14 + 0xc)), (u32) 0x40));
    ((u32) func_02016468((u32) 0xe, (u32) 0x40, (void *) (*(u32 *) (iVar2 + 0xc)), (u32) 0x20));
}

#pragma thumb off
