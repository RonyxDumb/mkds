#include "03/code_021ccc08.h"

void func_ov003_021ccc08(int param_1) {
    u8 uVar1;
    *(s8 *) ((u8 *) data_ov003_021da268 + 0x1c) = (s8) param_1;
    if (param_1 == 2) {
        uVar1 = 4;
    } else {
        uVar1 = 6;
    }
    *(u8 *) ((u8 *) data_ov003_021da268 + 0x1d) = uVar1;
    return;
}
