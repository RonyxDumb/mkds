#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on
u32 func_02152a6c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (value0 >> 11);
    value1 = 0x1fffffu;
    value0 = (value0) & (value1);
    return (u32) value0;
}
#pragma thumb off
