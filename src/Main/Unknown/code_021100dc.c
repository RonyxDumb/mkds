#include "Main/Unknown/code_021100dc.h"

u32 func_021100dc(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value12 = (u32) * (const u32 *) ((value0) + (0));
    value0 = 0u;
    value3 = (u32) * (const u16 *) ((value12) + (58));
    compareLeft0 = value3;
    compareRight0 = value2;
    if ((u32) compareLeft0 != (u32) compareRight0) {
        return (u32) value0;
    }
    value2 = (u32) * (const u16 *) ((value12) + (56));
    compareLeft1 = value2;
    compareRight1 = value1;
    if ((u32) compareLeft1 == (u32) compareRight1) {
        value0 = 1u;
    }
    return (u32) value0;
}
