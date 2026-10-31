#include "00/code_021acc68.h"

void func_ov000_021acc68(u16 *param_1, u32 param_2, int param_3, int param_4) {
    u16 uVar1;
    u16 *puVar2;
    puVar2 = param_1 + param_3;
    for (; (param_2 != 0 && (param_3 < param_4)); param_3 = param_3 + 1) {
        uVar1 = *puVar2;
        *puVar2 = (u16) (param_2 + uVar1);
        param_2 = param_2 + uVar1 >> 0x10;
        puVar2 = puVar2 + 1;
    }
    return;
}
