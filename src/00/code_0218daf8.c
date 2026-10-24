#include "00/code_0218daf8.h"

void func_ov000_0218daf8(u32 *param_1, u32 param_2, int param_3) {
    int iVar1;
    u32 uVar2;
    u8 auStack_18[8];
    if (param_3 == 0) {
        func_0213442c((u32) (((u32) ((u32) (&data_ov000_021b2308)))), (u32) (((u32) ((u32) (&data_ov000_021b22dc)))),
                      (u32) (0), (u32) (0xb7));
    }
    iVar1 = func_ov000_0218d818(param_2, param_1[5], *param_1, param_1[2], param_3, (u32 *) (void *) (auStack_18));
    uVar2 = _s32_div_f(iVar1 - param_1[5], param_1[2]);
    func_ov000_0218db48(param_1, param_2, uVar2);
    return;
}
