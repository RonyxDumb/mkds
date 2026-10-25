#include "01/code_0218b2b8.h"

void func_ov001_0218b2b8(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 11u;
    value1 = 0x2d8u;
    *(u32 *) ((value0) + (value1)) = (u32) value2;
    value2 = (u32) * (const u32 *) ((value0) + 120u);
    value1 = (u32) &data_ov001_021a6598;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    value2 = (value2) | (value1);
    *(u32 *) ((value0) + 120u) = (u32) value2;
    return;
}
