#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

void func_020ac2c4(const u8 *param_1, u8 *param_2, int param_3) {
    int i;
    int n = param_3 * param_3 / 2;
    for (i = 0; i < n; i++) {
        param_2[i] = param_1[i * 2] | (param_1[i * 2 + 1] << 4);
    }
}

#pragma thumb off

#pragma thumb off
