#include "Main/Unknown/code_02013bbc.h"

u32 func_02013bcc(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) * (const u16 *) ((value0) + (8));
    value0 = (value0) + (value2);
    value0 = (value0) + ((value1 << 4));
    return (u32) value0;
}

u32 func_02013bbc(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) * (const u16 *) ((value0) + (10));
    value0 = (value0) + (value2);
    value0 = (value0) + ((value1 << 4));
    return (u32) value0;
}
