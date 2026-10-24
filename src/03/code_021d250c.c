#include "03/code_021d250c.h"

void func_ov003_021d2544(u16 param_1, u16 param_2, u16 *param_3) {
    *param_3 = param_1;
    param_3[1] = param_2;
    return;
}

void func_ov003_021d2530(u16 param_1, u16 param_2, u16 param_3, u16 param_4, u16 *param_5) {
    *param_5 = param_1;
    param_5[1] = param_2;
    param_5[2] = param_3;
    param_5[3] = param_4;
    return;
}

void func_ov003_021d250c(u16 *param_1, u16 *param_2, short *param_3) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = *param_1 + *param_2;
    param_3[3] = param_1[1] + param_2[1];
    return;
}
