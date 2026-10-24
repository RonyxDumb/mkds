#include "00/code_0218b220.h"

void func_ov000_0218b224(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0x20) = param_2;
    return;
}

u32 func_ov000_0218b220(int param_1) {
    return *(u32 *) (param_1 + 0x20);
}
