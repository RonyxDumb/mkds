#include "Main/Unknown/code_020fd804.h"

void func_020fd804(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) * (const u32 *) ((value0) + (408));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if ((u32) compareLeft0 == (u32) compareRight0) {
    }
    if ((u32) compareLeft0 == (u32) compareRight0) {
    }
    if ((u32) compareLeft0 == (u32) compareRight0) {
        return;
    }
    value1 = (u32) * (const u16 *) ((value0) + (2));
    value1 = (value1) & ~(1u);
    *(u16 *) ((value0) + (2)) = (u16) value1;
    func_020d2398((void *) value0);
}
