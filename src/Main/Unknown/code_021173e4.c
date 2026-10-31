#include "Main/Unknown/code_021173e4.h"

#pragma thumb on
void func_021173e4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0217d360;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 64u);
    value0 = 0u - (value0);
    value1 = (value0 << 16);
    value0 = 0x1ff0000u;
    value1 = (value1) & (value0);
    value0 = 0x4000010u;
    *(u32 *) ((value0) + 0u) = value1;
    value1 = 0x4000000u;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value0 = 0xffff1fffu;
    value2 = (value2) & (value0);
    *(u32 *) ((value1) + 0u) = value2;
}
#pragma thumb off
