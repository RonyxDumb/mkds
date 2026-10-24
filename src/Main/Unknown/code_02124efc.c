#include "Main/Unknown/code_02124efc.h"

#pragma thumb on

void func_02124efc(u32 *param_1, int param_2) {
    int iVar1;
    iVar1 = 0;
    if (0 < param_2) {
        do {
            *param_1 = 1;
            *(u16 *) (param_1 + 1) = 0;
            *(u16 *) ((int) param_1 + 6) = 0;
            param_1[2] = 0;
            *(u16 *) (param_1 + 3) = 0;
            *(u16 *) ((int) param_1 + 0xe) = 0;
            param_1[4] = 0;
            func_02146c98((u32 *) (param_1 + 5));
            func_02146c98((u32 *) (param_1 + 9));
            param_1[0xd] = 1;
            param_1[0xe] = 0xffffffff;
            param_1[0xf] = 0;
            param_1 = param_1 + 0x10;
            iVar1 = iVar1 + 1;
        } while (iVar1 < param_2);
    }
    return;
}

#pragma thumb off
