#include "Main/Unknown/code_02079988.h"

#pragma thumb on

void func_02079988(int param_1, u32 param_2) {
    u16 extraout_r1;
    extraout_r1 = (int) (param_2) % (int) (3);
    *(u16 *) (param_1 + 0x68) = extraout_r1;
    return;
}

#pragma thumb off
