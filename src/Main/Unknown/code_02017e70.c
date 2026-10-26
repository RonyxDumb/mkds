#include "Main/Unknown/code_02017e70.h"

u32 func_02017e70(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u32 *) ((value0) + (0));
    value2 = 0u;
    *(u16 *) ((value3) + (0)) = (u16) value1;
    *(u16 *) ((value3) + (2)) = (u16) value2;
    value1 = (u32) * (const u32 *) ((value0) + (4));
    value0 = (value3) + (0x10u);
    value0 = (value1) - (value0);
    *(u32 *) ((value3) + (4)) = (u32) value0;
    *(u32 *) ((value3) + (8)) = (u32) value2;
    value0 = value3;
    *(u32 *) ((value3) + (12)) = (u32) value2;
    return (u32) value0;
}
