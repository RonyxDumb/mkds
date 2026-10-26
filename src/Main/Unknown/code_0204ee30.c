#include "Main/Unknown/code_0204ee30.h"

#pragma thumb on
u32 func_0204ee4c(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217aa00;
    value3 = (u32) * (const u32 *) ((value2) + 0u);
    value2 = 136u;
    value0 = (value0) * (value2);
    value2 = (value3) + (value0);
    value0 = 0x1714u;
    *(u32 *) ((value2) + (value0)) = (u32) value1;
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
u32 func_0204ee30(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0217aa00;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x1e44u;
    value1 = (value1) + (value0);
    value2 = (u32) * (const u8 *) ((value1) + 0u);
    value0 = 1u;
    value2 = (value2) & ~(value0);
    *(u8 *) ((value1) + 0u) = (u8) value2;
    return (u32) value0;
}
#pragma thumb off
