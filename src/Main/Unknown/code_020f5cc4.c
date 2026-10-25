#include "Main/Unknown/code_020f5cc4.h"

void func_020f5cc4(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value4 = value0;
    value3 = (u32) * (const s16 *) ((value4) + (218));
    value2 = ~(0u);
    compareLeft0 = value3;
    compareRight0 = value2;
    if ((u32) compareLeft0 == (u32) compareRight0) {
    }
    if ((u32) compareLeft0 == (u32) compareRight0) {
        return;
    }
    func_020f1150((int) value0, (int) value1);
    value0 = (value4) + (0x200u);
    value1 = 4u;
    *(u16 *) ((value0) + (76)) = (u16) value1;
    value1 = 1u;
    *(u16 *) ((value0) + (78)) = (u16) value1;
    return;
}
