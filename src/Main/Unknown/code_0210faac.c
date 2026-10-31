#include "Main/Unknown/code_0210faac.h"

u32 func_0210fac4(void) {
    u32 value0;
    value0 = (u32) &data_0217d244;
    value0 = (u32) * (const u32 *) ((value0) + (12));
    return value0;
}

u32 func_0210faac(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d244;
    value1 = (u32) * (const u32 *) ((value0) + (8));
    value1 = (value1) | (8u);
    *(u32 *) ((value0) + (8)) = value1;
    return value0;
}
