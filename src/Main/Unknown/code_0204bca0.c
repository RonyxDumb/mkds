#include "Main/Unknown/code_0204bca0.h"

u32 func_0204bcb4(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value0 = (u32) func_0200fca0();
    value1 = (u32) &data_02179ec0;
    value2 = (value4) & ~(1u);
    *(u32 *) ((value1) + (2832)) = (u32) value2;
    value0 = (u32) func_0200fcb4((u32) value0);
    return (u32) value0;
}

void func_0204bca0(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_0200df68;
    value0 = (u32) &data_02175dd8;
    func_0200df68((int) value0);
    return;
}
