#include "00/code_02180638.h"

s32 func_ov000_02180644(void) {
    u32 value0;
    value0 = (u32) &data_ov000_021b4c64;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 52u);
    return (s32) value0;
}

void func_ov000_02180638(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_ov000_021b4c64;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u32 *) ((value1) + 52u) = value0;
    return;
}
