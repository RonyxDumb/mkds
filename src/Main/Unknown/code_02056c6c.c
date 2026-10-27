#include "Main/Unknown/code_02056c6c.h"

#pragma thumb on

void func_02056c6c(u32 param_1, int param_2, u32 param_3) {
    int iVar1;
    iVar1 = func_0204684c();
    if (iVar1 != -1) {
        func_02056cac((u32 *) ((u32 *) (u32) (*(int *) ((*(int *) &data_0217aa08) + 0xc) + 4 +
                                              ((int) 0x00000380u) * param_2 + iVar1 * 0x1c)),
                      (u16 *) ((u16 *) (u32) (param_3)));
    }
    return;
}

#pragma thumb off
