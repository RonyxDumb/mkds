#include "01/code_021a64a0.h"

void func_ov001_021a651c(void) {
    u32 uVar1;
    u32 local_10;
    u32 local_c;
    u32 local_8[1];
    local_10 = 0;
    local_c = 0;
    local_8[0] = 0;
    uVar1 = ((int) func_0204799c(data_ov001_021a993c));
    func_020b496c((void **) (&local_10), (void *) (uVar1));
    uVar1 = ((int) func_0204799c(data_ov001_021a9938));
    func_020b48ec((void **) (&local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c(data_ov001_021a9944));
    func_020b4a7c((void **) (local_8), (void *) (uVar1));
    return;
}

void func_ov001_021a64ac(u32 a) {
    data_ov001_021ca424 = func_02036bec((void *)a, 0x10);
    func_020b49bc(&data_ov001_021ca424->mUnk_00, func_0204799c(data_ov001_021a993c));
    func_020b48b4(&data_ov001_021ca424->mUnk_04, func_0204799c(data_ov001_021a9938));
    func_020b4a44((Unk020b4a44 **)&data_ov001_021ca424->mUnk_08, func_0204799c(data_ov001_021a9944));
    data_ov001_021ca424->mUnk_0c = func_0204799c(data_ov001_021a9940);
}

void func_ov001_021a64a0(void) {
    *(u32 *) &data_ov001_021ca424 = 0;
    return;
}
