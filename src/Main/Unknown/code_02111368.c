#include "Main/Unknown/code_02111368.h"

#pragma thumb on
void func_0211138c(void) {
    u32 value0;
    u32 value1;
    func_02111584();
    value1 = 0u;
    value0 = (u32) &data_0217d33c;
    *(u32 *) ((value0) + 0u) = value1;
    value0 = (u32) &data_0217d340;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_02111368(void) {
    u32 value0;
    u32 value1;
    func_021114b0();
    value0 = (u32) &data_0217d33c;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value1 = (u32) &data_0217d340;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    func_020ae5f0((void *) value0, (void *) value1);
}
#pragma thumb off
