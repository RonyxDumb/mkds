#include "00/code_0218a24c.h"

u32 func_ov000_0218a24c(u32 param_1) {
    u32 uVar1;
    u32 uVar2;
    int iVar3;
    uVar1 = func_ov000_02188584((u32) (1));
    uVar2 = func_ov000_02188584((u32) (4));
    func_ov000_0218a064((u32 *) ((u32 *) (u32) (uVar1)), (int) (param_1), (int) (uVar2));
    *(u32 *) &data_ov000_021b5f98 = 4;
    iVar3 = func_ov000_021a8c94((void *) (uVar2));
    if (iVar3 != 0) {
        func_ov000_02188508((u32) (2));
        return 0x11;
    }
    return 0xc;
}
