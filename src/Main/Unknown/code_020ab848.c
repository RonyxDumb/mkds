#include "Main/Unknown/code_020ab848.h"

#pragma thumb on

void func_020ab848(s32 *param_1, s32 *param_2, s32 *param_3, s32 *param_4) {
    s32 value;
    func_020ab11c(param_1, param_2, param_3, param_4);
    *param_1 = *param_1 - data_0217b334->mUnk_50;
    *param_2 = *param_2 - data_0217b334->mUnk_54;
    *param_3 = *param_3 - data_0217b334->mUnk_50;
    *param_4 = *param_4 - data_0217b334->mUnk_54;
    value = *param_1;
    if (value < 0) {
        value += 0x100;
    }
    *param_1 = value;
    value = *param_2;
    if (value < 0) {
        value += 0x100;
    }
    *param_2 = value;
    value = *param_3;
    if (value < 0) {
        value += 0x100;
    }
    *param_3 = value;
    value = *param_4;
    if (value < 0) {
        value += 0x100;
    }
    *param_4 = value;
}

#pragma thumb off
