#include "00/code_02181df8.h"

void func_ov000_02181df8(void) {
    u32 uVar1;
    uVar1 = ((int) func_0204799c((const char *) &data_ov000_021b0af4));
    *(u32 *) ((int) data_ov000_021b4c6c + 0x2c) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) &data_ov000_021b0b0c));
    *(u32 *) ((int) data_ov000_021b4c6c + 0x30) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) &data_ov000_021b0b24));
    func_020b49bc(&data_ov000_021b4c6c->mUnk_24, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) &data_ov000_021b0b40));
    func_020b48b4(&data_ov000_021b4c6c->mUnk_20, (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) &data_ov000_021b0b5c));
    func_020b4a44(&data_ov000_021b4c6c->mUnk_28, (void *) (uVar1));
    ((u32) func_02016468((u32) (0x23), (u32) (0),
                         (void *) (*(u32 *) ((int) data_ov000_021b4c6c->mUnk_24 + 0x14)),
                         (u32) (*(u32 *) ((int) data_ov000_021b4c6c->mUnk_24 + 0x10))));
    ((u32) func_02016468((u32) (0x1e), (u32) (0),
                         (void *) (*(u32 *) ((int) data_ov000_021b4c6c->mUnk_28 + 0xc)),
                         (u32) (*(u32 *) ((int) data_ov000_021b4c6c->mUnk_28 + 8))));
    return;
}
