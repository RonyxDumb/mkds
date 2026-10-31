#include "00/code_021a4784.h"

void func_ov000_021a4784(u32 param_1, int param_2) {
    int iVar1;
    iVar1 = *(int *) (param_1 + 0x100);
    if (((iVar1 < 0xfe) && (1 <= param_2)) && (param_2 <= 254)) {
        *(int *) (param_1 + 0x100) = iVar1 + 1;
        *(s8 *) (param_1 + iVar1) = (s8) param_2;
    }
}
