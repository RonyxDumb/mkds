#include "03/code_021b7cac.h"

u32 func_ov003_021b7cac(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}
