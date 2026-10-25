#include "01/code_02185a14.h"

#pragma thumb off
void func_ov001_02185a14(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b488;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value1) + (12)) = (u32) value0;
    return;
}
#pragma thumb on
