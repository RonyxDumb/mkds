#include "Main/Unknown/code_0205a4e8.h"

u32 func_0205a4e8(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &data_0217aa14;
    value2 = 0x88u;
    value3 = (u32) * (const u32 *) ((value3) + (0));
    value3 = (value3) + (0x104u);
    value2 = (value0) * (value2) + (value3);
    value0 = (value2) + (0x20u);
    value0 = (value0) + ((value1 << 1));
    return (u32) value0;
}
