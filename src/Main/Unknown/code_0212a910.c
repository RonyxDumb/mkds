#include "Main/Unknown/code_0212a910.h"

#pragma thumb on
void func_0212a910(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) &data_0217d404;
    value2 = (u32) * (const u32 *) ((value2) + 0u);
    value0 = (value0 << 2);
    *(u32 *) ((value2) + (value0)) = (u32) value1;
}
#pragma thumb off
