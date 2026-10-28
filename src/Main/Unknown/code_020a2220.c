#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a2220.h"

void func_020a2220(u16 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &data_0217b1fc;
    value2 = 0x70u;
    value3 = (u32) * (const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    *(u32 *) ((value2) + (108)) = (u32) value1;
    return;
}
