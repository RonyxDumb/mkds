#include "Main/Unknown/code_02058754.h"

#pragma thumb on
u32 func_02058754(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0217aa00;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x1622u;
    value1 = (value1) + (value0);
    value2 = (u32) * (const u8 *) ((value1) + 0u);
    value0 = 1u;
    value2 = (value2) | (value0);
    *(u8 *) ((value1) + 0u) = (u8) value2;
    return value0;
}
#pragma thumb off
