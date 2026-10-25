#include "Main/Unknown/code_02037a04.h"

u32 func_02037a04(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_021755a0;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u8 *) ((value1) + (216));
    value0 = (value0) & ~(1u);
    *(u8 *) ((value1) + (216)) = (u8) value0;
    return (u32) value0;
}
