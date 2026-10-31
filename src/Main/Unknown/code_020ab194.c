#include "Main/Unknown/code_020ab194.h"

#pragma thumb on
u32 func_020ab194(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217b234;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &data_0217b238;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off
