#include "Main/Unknown/code_0211f61c.h"

#pragma thumb on

void func_0211f61c(void) {
    u32 uVar1;
    int local_10;
    int local_c[1];
    local_10 = 0;
    local_c[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e128))));
    func_020b48b4(&data_0217d380->mUnk_00, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e134))));
    func_020b49bc((Unk020b4934 **) (&local_10), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e130))));
    func_020b4a44((Unk020b4a44 **) local_c, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e124))));
    *(u32 *) ((int) data_0217d380 + 4) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e12c))));
    *(u32 *) ((int) data_0217d380 + 0xc) = uVar1;
    ((u32) func_02016468((u32) 0x23, (u32) 0, (void *) (*(u32 *) (local_10 + 0x14)),
                         (u32) (*(u32 *) (local_10 + 0x10))));
    ((u32) func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) (local_c[0] + 0xc)),
                         (u32) (*(u32 *) (local_c[0] + 8))));
}

#pragma thumb off
