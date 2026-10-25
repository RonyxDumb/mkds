#include "00/code_02182fdc.h"
#include "Main/Unknown/code_021201e4.h"

int func_02120220(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217d384;
    value1 = 0x244u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x400u);
    value0 = (u32) * (const s16 *) ((value0) + (62));
    return (int) value0;
}

void func_02120200(int arg0, u16 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &data_0217d384;
    value2 = 0x244u;
    value3 = (u32) * (const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    value0 = (value2) + (0x400u);
    *(u16 *) ((value0) + (62)) = (u16) value1;
    return;
}

u8 func_021201e4(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217d384;
    value1 = 0x244u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u8 *) ((value1) + (1105));
    return (u8) value0;
}
