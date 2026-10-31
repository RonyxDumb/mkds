#include "Main/Unknown/code_020ae5d4.h"

#pragma thumb on
u32 func_020ae5d4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = 0x402u;
    value0 = (value0) + (value1);
    value1 = (u32) * (const u16 *) ((value0) + 0u);
    value1 = (value1) + (1u);
    *(u16 *) ((value0) + 0u) = (u16) value1;
    return value0;
}
#pragma thumb off
