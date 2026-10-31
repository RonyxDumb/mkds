#include "00/code_0218b228.h"

u32 func_ov000_0218b228(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) * (const u16 *) ((value0) + 12u);
    value2 = ((u32) ((s32) value1 >> 8));
    value0 = 255u;
    value2 = (value2) & (value0);
    value1 = (value1 << 8);
    value0 = 0xff00u;
    value1 = (value1) & (value0);
    value2 = (value2) | (value1);
    value0 = (value2 << 16);
    value0 = (value0 >> 16);
    return value0;
}
