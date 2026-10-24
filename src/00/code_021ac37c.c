#include "00/code_021ac37c.h"

void func_ov000_021ac37c(u8 *param_1, u32 *param_2, u32 param_3) {
    u32 uVar1;
    u32 uVar2;
    u8 *puVar3;
    uVar2 = 0;
    if (uVar2 < param_3 >> 2) {
        do {
            uVar1 = *param_2;
            param_2 = param_2 + 1;
            *param_1 = (s8) ((u32) uVar1 >> 0x18);
            param_1[1] = (s8) ((u32) uVar1 >> 0x10);
            param_1[2] = (s8) ((u32) uVar1 >> 8);
            puVar3 = param_1 + 3;
            param_1 = param_1 + 4;
            *puVar3 = (s8) uVar1;
            uVar2 = uVar2 + 1;
        } while (uVar2 < param_3 >> 2);
    }
    return;
}
