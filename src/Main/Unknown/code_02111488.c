#include "Main/Unknown/code_02111488.h"

#pragma thumb on
void func_02111488(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u32 *) ((value1) + 12u) = (u32) value0;
    return;
}
#pragma thumb off
