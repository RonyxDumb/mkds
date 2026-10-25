#include "Main/Unknown/code_020dc5dc.h"

u32 func_020dc5dc(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x555u;
    value1 = 0x1c2u;
    *(u32 *) ((value0) + (232)) = (u32) value2;
    *(u32 *) ((value0) + (236)) = (u32) value1;
    value0 = (u32) * (const u32 *) ((value0) + (472));
    value1 = 0x599u;
    *(u32 *) ((value0) + (168)) = (u32) value1;
    return (u32) value0;
}
