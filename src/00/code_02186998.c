#include "00/code_02186998.h"

u32 func_ov000_02186998(int param_1, int *param_2, int param_3) {
    int iVar1;
    if (param_3 <= 0) {
        return 0;
    }
    iVar1 = (**(UnkWordFunc **) (param_1 + 0x14))(0, param_2[3] + param_3);
    if (iVar1 == 0) {
        return 0;
    }
    func_0214d1fc((const void *) ((u16 *) (u32) (*param_2)), (void *) ((u32 *) (u32) (iVar1)), (u32) (param_2[3]));
    (**(UnkWordFunc **) (param_1 + 0x18))(0, *param_2, 0);
    if (iVar1 == 0) {
        return 0;
    }
    param_2[1] = param_2[1] + (iVar1 - *param_2);
    param_2[3] = param_2[3] + param_3;
    *param_2 = iVar1;
    param_2[2] = iVar1 + param_2[3];
    return 1;
}
