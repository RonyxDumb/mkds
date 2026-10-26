#include "Main/Unknown/code_02063b50.h"

u32 func_02063b50(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value2 = (u32) * (const u32 *) ((value0) + (288));
    value3 = (value0) + (0x120u);
    *(u32 *) ((value1) + (0)) = (u32) value2;
    value0 = (u32) * (const u32 *) ((value3) + (4));
    *(u32 *) ((value1) + (4)) = (u32) value0;
    value0 = (u32) * (const u32 *) ((value3) + (8));
    *(u32 *) ((value1) + (8)) = (u32) value0;
    return (u32) value0;
}
