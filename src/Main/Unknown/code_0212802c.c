#include "Main/Unknown/code_0212802c.h"

#pragma thumb on
void func_0212804c(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d3f4;
    *(u32 *) ((value0) + 0u) = (u32) value1;
    return;
}
#pragma thumb off

#pragma thumb on
u32 func_0212802c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0x4001008u;
    value1 = (u32) * (const u16 *) ((value2) + 0u);
    value0 = 3u;
    value1 = (value1) & ~(value0);
    *(u16 *) ((value2) + 0u) = (u16) value1;
    value1 = (u32) * (const u16 *) ((value2) + 0u);
    value0 = 67u;
    value1 = (value1) & (value0);
    value0 = 0xb00u;
    value1 = (value1) | (value0);
    *(u16 *) ((value2) + 0u) = (u16) value1;
    return (u32) value0;
}
#pragma thumb off
