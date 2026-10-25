#include "Main/Unknown/code_0210b6a0.h"

u32 func_0210b6a0(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    value1 = 0xafc8000u;
    value0 = 0x384000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value2 = (u32) &data_0217ccb0;
    value1 = 0xafc8000u;
    *(u32 *) ((value2) + (0)) = (u32) value0;
    value0 = 0x1c2000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value3 = (u32) &data_0217ccbc;
    value2 = (u32) &data_0217ccb4;
    value12 = 0u;
    value1 = (u32) &data_0217ccb8;
    *(u32 *) ((value3) + (0)) = (u32) value0;
    *(u32 *) ((value2) + (0)) = (u32) value12;
    *(u32 *) ((value1) + (0)) = (u32) value12;
    return (u32) value0;
}
