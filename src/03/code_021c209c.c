#include "03/code_021c209c.h"

u32 func_ov003_021c20a8(u32 param_1) {
    if ((*((u32 *) ((u32) (&data_ov003_021da178))) >> 4 & param_1) != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021c209c(void) {
    *((u8 *) ((u32) (&data_ov003_021da170))) = 1;
    return;
}
