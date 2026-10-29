#include "Main/Unknown/code_02038c9c.h"

u32 func_02038c9c(Unk021755a0 *arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value3 = (u32) * (const u32 *) ((value0) + (108));
    *(u8 *) ((value3) + (2)) = (u8) value1;
    value0 = (u32) * (const u32 *) ((value0) + (108));
    *(u8 *) ((value0) + (3)) = (u8) value2;
    return (u32) value0;
}
