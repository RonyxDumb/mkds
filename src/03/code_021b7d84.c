#include "03/code_021b7d84.h"

void func_ov003_021b7d90(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value3 = (value0) + (0u);
    value0 = (value1) + (0u);
    value1 = (value3) + (0u);
    value3 = (u32) &func_0214d1fc;
    func_0214d1fc((const void *) value0, (void *) value1, (u32) value2);
    return;
}

void func_ov003_021b7d84(void *arg0, s32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value1 = (value1 << 24);
    value1 = (value1 >> 24);
    value3 = (u32) &func_0214d168;
    func_0214d168((void *) value0, (u8) value1, (u32) value2);
    return;
}
