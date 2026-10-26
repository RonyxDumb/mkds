#include "Main/Unknown/code_020617d8.h"

u32 func_020617f0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa54;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (52)) = (u32) value1;
    return (u32) value0;
}

u32 func_020617d8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa54;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value1) + (4));
    *(u32 *) ((value1) + (60)) = (u32) value0;
    return (u32) value0;
}
