#include "Main/Unknown/code_020ada7c.h"

void func_020ada7c(int *param_1) {
    u32 uVar1;
    uVar1 = *(u32 *) ((u32) param_1);
    if ((int) uVar1 < 0x7fffffff) {
        *param_1 = uVar1 + 1;
    }
}
