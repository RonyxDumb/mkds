#include "Main/Unknown/code_02009adc.h"

#pragma thumb on
void func_02009adc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0216fdc0;
    *(u16 *) ((value1) + 6u) = (u16) value0;
}
#pragma thumb off
