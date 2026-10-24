#include "Main/Unknown/code_020aca08.h"

#pragma thumb on

unsigned int func_020aca20(unsigned int p0) {
    return p0;
}

void func_020aca08(int param_1) {
    if (param_1 != 0) {
        *(u16 *) (param_1 + 4) = 0xb;
        func_02105e98();
    }
    return;
}

#pragma thumb off
