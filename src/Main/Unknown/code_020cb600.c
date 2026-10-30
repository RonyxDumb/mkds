#include "Main/Unknown/code_020cb600.h"

void func_020cb600(int *param_1) {
    u32 uVar1;
    uVar1 = *(u32 *) ((u32) param_1);
    if ((int) uVar1 < 0x7fffffff) {
        *param_1 = uVar1 + 1;
    }
}
