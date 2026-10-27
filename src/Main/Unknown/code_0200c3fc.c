#include "Main/Unknown/code_0200c3fc.h"

#pragma thumb on

void func_0200c3fc(short param_1) {
    if ((*(int *) &data_0216fdf4) != 0) {
        func_0214d168((void *) ((u32 *) (u32) ((*(int *) &data_0216fdf4) + (param_1 + -1) * 0x20)), (u8) (0),
                      (u32) (0x1e));
        *(u32 *) ((*(int *) &data_0216fdf4) + (param_1 + -1) * 4 + ((int) 0x000001e0u)) = 0;
    }
    return;
}

#pragma thumb off
