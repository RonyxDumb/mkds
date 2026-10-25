#include "Main/Unknown/code_0204a928.h"

void func_0204a928(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 compareLeft0;
    u32 compareRight0;
    value1 = (u32) * (const u32 *) ((value0) + (8));
    compareLeft0 = value1;
    compareRight0 = 1u;
    if ((u32) compareLeft0 != (u32) compareRight0) {
    }
    if ((u32) compareLeft0 != (u32) compareRight0) {
    }
    if ((u32) compareLeft0 != (u32) compareRight0) {
        return;
    }
    value3 = (u32) * (const u16 *) ((value0) + (4));
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0u;
    value3 = (value3 << 1);
    *(u32 *) ((value2) + (0)) = (u32) value3;
    *(u32 *) ((value0) + (8)) = (u32) value1;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0xdccu;
    func_0200ee58((u32) value0, (int) value1);
    return;
}
