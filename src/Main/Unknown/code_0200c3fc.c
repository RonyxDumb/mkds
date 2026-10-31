#include "Main/Unknown/code_0200c3fc.h"

#pragma thumb on

void func_0200c3fc(s32 param_1) {
    s32 i;

    if ((int) data_0216fdf4 != 0) {
        i = param_1 - 1;
        func_0214d168((void *) ((int) data_0216fdf4 + i * 0x20), 0, 0x1e);
        *(u32 *) ((int) data_0216fdf4 + i * 4 + 0x1e0) = 0;
    }
}

#pragma thumb off
