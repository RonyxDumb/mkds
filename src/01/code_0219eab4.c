#include "01/code_0219eab4.h"

u32 func_ov001_0219eab4(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_ov001_021ca410;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 68u);
    value0 = 0u - (value0);
    value1 = (value0 << 16);
    value0 = 0x1ff0000u;
    value1 = (value1) & (value0);
    value0 = 0x4000010u;
    *(u32 *) ((value0) + 0u) = (u32) value1;
    return (u32) value0;
}
