#include "03/code_021bca90.h"

void func_ov003_021bca90(u8 *param_1, u8 *param_2, u8 *param_3) {
    *param_3 = *param_1 ^ *param_2;
    param_3[1] = param_1[1] ^ param_2[1];
    param_3[2] = param_1[2] ^ param_2[2];
    param_3[3] = param_1[3] ^ param_2[3];
    param_3[4] = param_1[4] ^ param_2[4];
    param_3[5] = param_1[5] ^ param_2[5];
    param_3[6] = param_1[6] ^ param_2[6];
    param_3[7] = param_1[7] ^ param_2[7];
    return;
}
