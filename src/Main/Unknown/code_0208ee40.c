#include "Main/Unknown/code_0208ee40.h"

void func_0208ee40(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u32 *) ((value1) + (20));
    value2 = (u32) * (const u32 *) ((value1) + (28));
    value1 = 0u;
    *(u32 *) ((value0) + (8)) = (u32) value2;
    *(u16 *) ((value0) + (12)) = (u16) value1;
    value1 = (u32) * (const u32 *) ((value3) + (0));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (16)) = (u32) value1;
    value1 = (u32) * (const u32 *) ((value3) + (4));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (20)) = (u32) value1;
    value1 = (u32) * (const u32 *) ((value3) + (8));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (24)) = (u32) value1;
}
