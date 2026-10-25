#include "Main/Unknown/code_0211ff74.h"

u32 func_0211ff74(void) {
    u32 value0;
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) &data_0217d384;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + (0x1000u);
    value0 = (u32) * (const u32 *) ((value0) + (3896));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if ((u32) compareLeft0 == (u32) compareRight0) {
        return (u32) value0;
    }
    value0 = (u32) &data_0217aa14;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + (0x700u);
    value1 = (u32) * (const u16 *) ((value0) + (92));
    value1 = (value1) & ~(4u);
    *(u16 *) ((value0) + (92)) = (u16) value1;
    return (u32) value0;
}
