#include "03/code_021b7d84.h"

void func_ov003_021b7d90(void *arg0, const void *arg1, u32 arg2) {
    func_0214d1fc(arg1, arg0, arg2);
}

void func_ov003_021b7d84(void *arg0, s32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = arg2;
    u32 value3;
    value1 = (value1 << 24);
    value1 = (value1 >> 24);
    value3 = (u32) &func_0214d168;
    func_0214d168((void *) value0, (u8) value1, value2);
    return;
}
