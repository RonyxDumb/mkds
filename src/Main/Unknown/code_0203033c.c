#include "Main/Unknown/code_0203033c.h"

u32 func_02030364(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = 0x4001048u;
    compareLeft0 = value1;
    compareRight0 = 0u;
    value1 = (u32) * (const u16 *) ((value2) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x4001048u;
    if (compareLeft0 != compareRight0) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}

u32 func_0203033c(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = 0x400104au;
    compareLeft0 = value1;
    compareRight0 = 0u;
    value1 = (u32) * (const u16 *) ((value2) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x400104au;
    if (compareLeft0 != compareRight0) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}
