#include "Main/Unknown/code_02047b6c.h"

#pragma thumb on
void func_02047b6c(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((void *) value0);
    value1 = (value4 << 16);
    value1 = (value1 >> 16);
    value0 = (u32) func_020176b0((u32) value0, (u32) value1);
    return;
}
#pragma thumb off
