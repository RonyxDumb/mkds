#include "Main/Unknown/code_021529e0.h"

#pragma thumb on
void func_021529e0(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value4 = (value1) + (0u);
    value0 = (u32) func_02152a6c((u32) value0);
    value1 = 3u;
    value0 = (value0) & ~(value1);
    value1 = (value0) + (0u);
    value1 = (value1) | (value4);
    value0 = (value5) + (0u);
    func_02152a04((u32) value0, (u32) value1);
    return;
}
#pragma thumb off
