#include "Main/Unknown/code_020a128c.h"

u32 func_020a128c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value1 = (u32) &data_0217b1fc;
    value0 = 0u;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const u32 *) ((value2) + (948));
    compareLeft0 = value1;
    compareRight0 = 0u;
    if ((s32) compareLeft0 < (s32) compareRight0) {
        return value0;
    }
    value1 = (u32) * (const u32 *) ((value2) + (936));
    compareLeft1 = value1;
    compareRight1 = 0u;
    if ((s32) compareLeft1 < (s32) compareRight1) {
        value0 = 1u;
    }
    return value0;
}
