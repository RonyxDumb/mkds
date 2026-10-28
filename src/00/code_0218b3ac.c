#include "00/code_0218b3ac.h"

void func_ov000_0218b3c8(void) {
    int iVar1;
    if (((*(int *) &data_ov000_021b4d18) != 0) && (iVar1 = func_ov000_0218df5c(), iVar1 == 0)) {
        func_ov000_0218dfb4((int *) ((int *) (u32) ((*(int *) &data_ov000_021b4d18))));
        *(int *) &data_ov000_021b4d18 = 0;
    }
    return;
}

void func_ov000_0218b3ac(int *param_1) {
    int iVar1;
    iVar1 = *param_1;
    func_ov000_0218dfb4((int *) ((int *) (u32) (*(u32 *) (iVar1 + 0x18))));
    *(u32 *) (iVar1 + 0x18) = 0;
    func_ov000_021a3668((void *) (iVar1));
    return;
}
