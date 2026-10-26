#include "Main/Unknown/code_020f813c.h"

#pragma thumb on
u32 func_020f813c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (value0) + (2u);
    value1 = (u32) * (const u8 *) ((value0) + 1u);
    value0 = (u32) * (const u8 *) ((value0) + 0u);
    value1 = (value1) * (value0);
    value0 = (value2) + (value1);
    return (u32) value0;
}
#pragma thumb off
