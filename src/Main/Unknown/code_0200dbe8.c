#include "Main/Unknown/code_0200dbe8.h"

void func_0200dc1c(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = (u32) value1;
    value12 = (u32) &func_0200df68;
    value0 = value2;
    *(u32 *) ((value2) + (176)) = (u32) value1;
    func_0200df68((int) value0);
    return;
}

u32 func_0200dbe8(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value0 = (u32) func_0200fca0();
    value1 = (u32) &data_0216ff5c;
    value4 = (u32) * (const u32 *) ((value1) + (12));
    *(u32 *) ((value1) + (12)) = (u32) value5;
    value0 = (u32) func_0200fcb4((u32) value0);
    value0 = value4;
    return (u32) value0;
}
