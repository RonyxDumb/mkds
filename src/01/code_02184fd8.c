#include "01/code_02184fd8.h"

void func_ov001_02184fd8(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value3 = (value0) + (0u);
    value3 = (value3) + 128u;
    value3 = (u32) * (const u32 *) ((value3) + 0u);
    value3 = (u32) * (const u32 *) ((value3) + 16u);
    value1 = (value1) - (value3);
    value1 = (value1 << 12);
    *(u32 *) ((value0) + 4u) = (u32) value1;
    value1 = (value0) + (0u);
    value1 = (value1) + 128u;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = (u32) * (const u32 *) ((value1) + 20u);
    value1 = (value2) - (value1);
    value1 = (value1 << 12);
    *(u32 *) ((value0) + 8u) = (u32) value1;
    return;
}
