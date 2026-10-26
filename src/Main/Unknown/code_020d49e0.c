#include "Main/Unknown/code_020d49e0.h"

#pragma thumb on
u32 func_020d49f0(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((void *) value0);
    value1 = (u32) * (const u16 *) ((value4) + 4u);
    value1 = (value1 << 2);
    value0 = (u32) func_02036bec((void *) value0, (u32) value1);
    *(u32 *) ((value4) + 0u) = (u32) value0;
    value0 = 0u;
    *(u16 *) ((value4) + 4u) = (u16) value0;
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020d49e0(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u16 *) ((value0) + 4u);
    value2 = (value3) + (1u);
    *(u16 *) ((value0) + 4u) = (u16) value2;
    value2 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (value3 << 2);
    *(u32 *) ((value2) + (value0)) = (u32) value1;
    return (u32) value0;
}
#pragma thumb off
