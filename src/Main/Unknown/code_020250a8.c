#include "Main/Unknown/code_020250a8.h"
#include "code_02147cd8.h"

u32 func_020250a8(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_02161ae4;
    value0 = 0x1000u;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_02161ae0;
    value2 = (u32) &data_02174e10;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x1000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_02161adc;
    value2 = (u32) &data_02174e0c;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x1000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_02174e08;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}
