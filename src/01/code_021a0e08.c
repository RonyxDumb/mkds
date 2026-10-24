#include "01/code_021a0e08.h"

void func_ov001_021a0e08(int param_1, int param_2) {
    u32 uVar1;
    uVar1 = ((int) func_02029608());
    func_02124fac((u32) (uVar1), (u16 *) (param_2));
    *(u16 *) (param_2 + 2) = 0x2d;
    func_02124fac((u32) (param_1 + 1), (u16 *) (param_2 + 4));
    *(u16 *) (param_2 + 6) = 0;
    return;
}
