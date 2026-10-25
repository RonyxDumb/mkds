#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f40a0.h"

void func_020f40a0(s32 arg0, s32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value2 = (u32) &data_0217bc48;
    value3 = ((u32) &data_027e00cc);
    value12 = (u32) * (const u32 *) ((value2) + (0));
    value2 = 0x1cu;
    value2 = (value0) * (value2) + (value12);
    value12 = (u32) * (const u32 *) ((value2) + (8));
    value2 = (u32) * (const u32 *) ((value3) + (0));
    value0 = 0x44u;
    value2 = (value12) * (value0) + (value2);
    value0 = (u32) * (const u32 *) ((value2) + (28));
    value0 = (value0) - (value1);
    *(u32 *) ((value2) + (28)) = (u32) value0;
    return;
}
