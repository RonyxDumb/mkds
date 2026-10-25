#include "Main/Unknown/code_02013b20.h"

u32 func_02013b20(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u16 *) ((value0) + (18));
    value0 = (value0) + (0xcu);
    value2 = (u32) * (const u16 *) ((value0) + (value3));
    value0 = (value0) + (value3);
    value0 = (value0) + (4u);
    value0 = (value2) * (value1) + (value0);
    return (u32) value0;
}
