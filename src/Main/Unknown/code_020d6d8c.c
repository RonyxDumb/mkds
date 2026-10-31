#include "Main/Unknown/code_020d6d8c.h"

u32 func_020d6d8c(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3 = arg3;
    u32 value12;
    u32 value14;
    u32 compareLeft0;
    u32 compareRight0;
    value14 = (u32) &data_0216bb7c;
    value12 = 0x38u;
    value12 = (value2) * (value12) + (value14);
    value1 = (u32) * (const u32 *) ((value12) + ((value1 << 2)));
    compareLeft0 = value0;
    compareRight0 = 0u;
    value0 = (u32) * (const u8 *) ((value1) + (value3));
    if (compareLeft0 != compareRight0) {
        value0 = 0u;
    }
    return value0;
}
