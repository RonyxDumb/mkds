#include "Main/Unknown/code_02125ed0.h"

#pragma thumb on
void func_02125ed0(int arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217d3f0;
    value2 = (u32) * (const u32 *) ((value2) + 0u);
    value0 = (value0 << 2);
    value2 = (value2) + (value0);
    value0 = 0x2250u;
    *(u32 *) ((value2) + (value0)) = value1;
}
#pragma thumb off
