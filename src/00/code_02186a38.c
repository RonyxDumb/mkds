#include "00/code_02186a38.h"

u32 func_ov000_02186a38(int param_1, int *param_2, int param_3) {
    int iVar1;
    if (param_3 == 0) {
        return 0;
    }
    iVar1 = (**(UnkWordFunc **) (param_1 + 0x14))((u32) &data_ov000_021b1280, param_3);
    *param_2 = iVar1;
    if (*param_2 == 0) {
        return 0;
    }
    param_2[1] = *param_2;
    param_2[3] = param_3;
    param_2[2] = *param_2 + param_2[3];
    return 1;
}
