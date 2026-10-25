#include "Main/Unknown/code_020c5df0.h"

u32 func_020c5df0(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) &data_0217b3f4;
    value3 = (u32) * (const u32 *) ((value0) + (0));
    value2 = (u32) * (const u32 *) ((value3) + (4));
    value1 = (value2) + (1u);
    *(u32 *) ((value3) + (4)) = (u32) value1;
    compareLeft0 = value2;
    compareRight0 = 0x3cu;
    if ((s32) compareLeft0 < (s32) compareRight0) {
        return (u32) value0;
    }
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value3 = (u32) &func_020c5dd8;
    value1 = 0u;
    *(u32 *) ((value2) + (0)) = (u32) value3;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = (u32) value1;
    return (u32) value0;
}
