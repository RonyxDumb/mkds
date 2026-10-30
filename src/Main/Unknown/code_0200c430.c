#include "Main/Unknown/code_0200c430.h"

#pragma thumb on
void func_0200c430(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (u32) &data_0216fdf4;
    *(u32 *) ((value1) + 0u) = (u32) value0;
    value1 = 0u;
    value2 = 0x21cu;
    value3 = (u32) &func_0214d168;
    func_0214d168((void *) value0, (u8) value1, (u32) value2);
}
#pragma thumb off
