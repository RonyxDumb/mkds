#include "03/code_021d1770.h"

void func_ov003_021d1770(int param_1, int param_2, u32 *param_3, u32 *param_4) {
    int iVar1;
    iVar1 = *(int *) (param_1 + 8);
    *param_3 = (*(u32 *) (iVar1 + param_2 * 8) & ((u32) 0x01ff0000u)) >> 0x10;
    *param_4 = *(u32 *) (iVar1 + param_2 * 8) & 0xff;
    return;
}
