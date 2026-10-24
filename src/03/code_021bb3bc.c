#include "03/code_021bb3bc.h"

void func_ov003_021bb3bc(int param_1, int param_2, u32 param_3) {
    int uVar1;
    uVar1 = 0;
    if (uVar1 < param_3) {
        do {
            *(u8 *) (param_1 + uVar1) = *(u8 *) (param_2 + uVar1);
            uVar1 = uVar1 + 1;
        } while (uVar1 < param_3);
    }
    return;
}
