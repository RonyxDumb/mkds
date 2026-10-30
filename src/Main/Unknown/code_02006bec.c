#include "Main/Unknown/code_02006bec.h"

#pragma thumb on

void func_02006c0c(u32 param_1, const u8 *param_2, int param_3) {
    if (0 < param_3) {
        func_02005dac(func_020070b8(), param_1, param_2, param_3);
    }
}

void func_02006bec(const u8 *param_1, u32 param_2) {
    func_02005dac(func_020070b8(), 0, param_1, param_2);
}

#pragma thumb off
