#include "03/code_021cdb14.h"

int func_ov003_021cdb6c(void) {
    return (int) data_ov003_021da270 + 0x400;
}

void func_ov003_021cdb58(u32 param_1) {
    *(u8 *) ((int) data_ov003_021da270 + 0x4f5) = param_1;
}

void func_ov003_021cdb44(u32 param_1) {
    *(u8 *) ((int) data_ov003_021da270 + 0x4f6) = param_1;
}

void func_ov003_021cdb14(const u8 *param_1) {
    func_0214d1fc((const void *) ((u16 *) (u32) param_1),
                  (void *) ((u32 *) (u32) ((int) data_ov003_021da270 + 0x440)), (u32) 0x20);
    *(u8 *) ((int) data_ov003_021da270 + 0x4e7) = 0;
}
