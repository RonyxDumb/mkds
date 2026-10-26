#include "00/code_021935bc.h"

u32 func_ov000_021935bc(u32 param_1, u32 param_2, u32 *param_3, u32 *param_4, u32 *param_5) {
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    uVar2 = (int) param_2 >> 0x18 & 0xff;
    uVar3 = (int) param_2 >> 0x10 & 0xff;
    param_2 = param_2 & ((u32) 0x0000ffffu);
    iVar1 = func_ov000_02193634((int) (uVar2), (int) (uVar3), (int) (param_2));
    if (iVar1 == 0) {
        func_0213442c(data_ov000_021b323c, data_ov000_021b31f8, 0, 0xb7);
    }
    iVar1 = func_ov000_02193634((int) (uVar2), (int) (uVar3), (int) (param_2));
    if (iVar1 == 0) {
        func_ov000_02196590((u32 *) (u32) (param_1), ((u32) ((u32) (&data_ov000_021b3254))));
        return 2;
    }
    *param_3 = uVar2;
    *param_4 = uVar3;
    *param_5 = param_2;
    return 0;
}
