#include "Main/Unknown/code_020d3d94.h"

u32 func_020d3d94(void) {
    u32 value0;
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value1 = (u32) &data_0217b4e4;
    value0 = 0u;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
        return value0;
    }
    value1 = (u32) * (const u32 *) ((value1) + (368));
    compareLeft1 = value1;
    compareRight1 = 0u;
    if (compareLeft1 != compareRight1) {
        value0 = 1u;
    }
    return value0;
}
