#include "Main/Unknown/code_020b3260.h"

#pragma thumb on

int func_020b3260(int param_1) {
    if (param_1 < 0) {
        return 0;
    }
    if (param_1 < 2) {
        return ((int) 0x00001000u);
    }
    return param_1 << 0xb;
}

#pragma thumb off
