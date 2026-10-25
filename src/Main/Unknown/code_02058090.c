#include "Main/Unknown/code_02058090.h"

#pragma thumb on
u32 func_02058090(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0217aa00;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x164eu;
    *(u8 *) ((value1) + (value0)) = (u8) value2;
    return (u32) value0;
}
#pragma thumb off
