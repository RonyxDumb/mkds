#include "Main/Unknown/code_0211398c.h"

#pragma thumb on
u32 func_021139a0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d348;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 106u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    value0 = (value0) + (1u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
u32 func_0211398c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d348;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 106u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    value0 = (value0) - (1u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    return (u32) value0;
}
#pragma thumb off
