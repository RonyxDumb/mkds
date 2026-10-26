#include "Main/Unknown/code_02146cb0.h"

#pragma thumb on
void func_02146cb0(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    *(u32 *) ((value0) + 0u) = (u32) value2;
    *(u32 *) ((value0) + 4u) = (u32) value1;
    value1 = 0u - (value1);
    *(u32 *) ((value0) + 8u) = (u32) value1;
    *(u32 *) ((value0) + 12u) = (u32) value2;
    return;
}
#pragma thumb off
