#include "Main/Unknown/code_02109110.h"

void func_02109110(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    u32 value12;
    value12 = (u32) &func_0210cf20;
    *(u8 *) ((value0) + (60)) = (u8) value1;
    value3 = ~(0u);
    value1 = value2;
    *(u32 *) ((value0) + (64)) = (u32) value3;
    func_0210cf20((int) value0, (u32) value1);
    return;
}
