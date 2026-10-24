#include "Main/Unknown/code_02025f54.h"

#pragma thumb on

void func_02025f54(u32 *param_1, u32 param_2) {
    *param_1 = param_2;
    switch (*param_1) {
        case 0:
        case 3:
            param_1[1] = 0;
            return;
        case 1:
        case 2:
            param_1[1] = param_1[2];
    }
    return;
}

#pragma thumb off
