#include "00/code_021a8bb0.h"

void func_ov000_021a8bb0(u32 param_1, u8 *param_2) {
    *param_2 = (s8) (param_1 >> 0x18);
    param_2[1] = (s8) (param_1 >> 0x10);
    param_2[2] = (s8) (param_1 >> 8);
    param_2[3] = (s8) param_1;
    return;
}
