#include "Main/Unknown/code_020ffc08.h"

void func_020ffc08(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    value1 = (u32) * (const u16 *) ((value0) + (166));
    value12 = (value0) + (0xa6u);
    value1 = (value1) + (0x96u);
    *(u16 *) ((value0) + (166)) = (u16) value1;
    value1 = (u32) * (const u32 *) ((value0) + (188));
    value1 = (value1) - (0x96u);
    *(u32 *) ((value0) + (188)) = (u32) value1;
    value3 = (u32) * (const u32 *) ((value0) + (188));
    compareLeft0 = value3;
    compareRight0 = 0u;
    if ((s32) compareLeft0 >= (s32) compareRight0) {
        return;
    }
    value2 = (u32) * (const u16 *) ((value12) + (0));
    value1 = 1u;
    value2 = (value2) + (value3);
    *(u16 *) ((value12) + (0)) = (u16) value2;
    *(u16 *) ((value0) + (144)) = (u16) value1;
    *(u16 *) ((value0) + (146)) = (u16) value1;
}
