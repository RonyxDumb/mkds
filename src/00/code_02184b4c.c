#include "00/code_02184b4c.h"

void func_ov000_02184b68(u32 param_1) {
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (8)));
    *((int *) ((u32) (&data_ov000_021b4c80))) = iVar1;
    *(u32 *) (iVar1 + 4) = param_1;
    func_ov000_02184b4c();
    uVar2 = ((u32) func_ov000_021804f4());
    uVar3 = ((int) func_ov000_021804e0());
    func_0202ab2c((u32) (param_1), (u32) (uVar2), (u32) (uVar3));
    func_0212a910((u32) (1), (u32) (1));
    return;
}

void func_ov000_02184b50(void) {
    func_0202a90c();
    *((u32 *) ((u32) (&data_ov000_021b4c80))) = 0;
    return;
}

void func_ov000_02184b4c(void) {
    return;
}
