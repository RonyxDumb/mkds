#include "Main/Unknown/code_02009908.h"

#pragma thumb on
u32 func_02009908(UnkFunc *arg0, UnkFunc *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) &data_0216fc38;
    *(u32 *) ((value2) + 0u) = (u32) value0;
    value0 = (u32) &data_0216fc34;
    *(u32 *) ((value0) + 0u) = (u32) value1;
    return (u32) value0;
}
#pragma thumb off
