#include "Main/Unknown/code_02050300.h"

u32 func_02050300(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa00;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + (0x400u);
    value1 = (u32) * (const u16 *) ((value0) + (84));
    value1 = (value1) | (1u);
    *(u16 *) ((value0) + (84)) = (u16) value1;
    return (u32) value0;
}
