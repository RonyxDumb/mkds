#include "01/code_0218568c.h"

#pragma thumb off
u32 func_ov001_021856a8(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4000000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = (u32) value0;
    return (u32) value0;
}
#pragma thumb on

#pragma thumb off
u32 func_ov001_0218568c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = (u32) value0;
    return (u32) value0;
}
#pragma thumb on
