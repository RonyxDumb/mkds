#include "03/code_021bf2d0.h"

void func_ov003_021bf310(s8 param_1) {
    *(u8 *) ((int) data_ov003_021da108 + 0x16) = param_1;
}

u32 func_ov003_021bf2f0(void) {
    if ((int) data_ov003_021da108 == 0) {
        return 1;
    }
    if (*(u8 *) ((int) data_ov003_021da108 + 0x19) == 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021bf2e0(void) {
    *(u8 *) ((int) data_ov003_021da108 + 0x18) = 0;
}

void func_ov003_021bf2d0(void) {
    *(u8 *) ((int) data_ov003_021da108 + 0x18) = 1;
}
