#include "Main/Unknown/code_02110484.h"
#include "code_02147cd8.h"

void func_021104dc(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 value5;
    u32 value12;
    u32 value14;
    value14 = (u32) &data_0217d1ec;
    value12 = (u32) &data_0217d20c;
    value5 = 3u;
    value3 = (u32) &data_0217d1f8;
    value2 = (u32) &data_0217d21c;
    value1 = (u32) &data_0217d1e8;
    value4 = 0u;
    *(u32 *) ((value14) + (0)) = (u32) value0;
    *(u32 *) ((value12) + (0)) = (u32) value5;
    *(u32 *) ((value3) + (0)) = (u32) value5;
    *(u32 *) ((value2) + (0)) = (u32) value5;
    *(u32 *) ((value1) + (0)) = (u32) value4;
    return;
}

u32 func_02110484(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0216cb28;
    value1 = 0x8340000u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) - (0x14u);
    value0 = (value0 << 12);
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value2 = (u32) &data_0217d200;
    value1 = 0x8340000u;
    *(u32 *) ((value2) + (0)) = (u32) value0;
    value0 = 0x61000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_0217d208;
    *(u32 *) ((value1) + (0)) = (u32) value0;
    return (u32) value0;
}
