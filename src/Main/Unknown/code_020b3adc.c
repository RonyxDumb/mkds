#include "Main/Unknown/code_020b3adc.h"

u32 func_020b3af4(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b35c;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = (u32) value1;
    return (u32) value0;
}

u32 func_020b3adc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b35c;
    value1 = 0u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (0)) = (u32) value1;
    return (u32) value0;
}
