#include "01/code_0219a0c0.h"

u32 func_ov001_0219a0c0(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0;
    u32 value1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value0 = (u32) &data_ov001_021a9bf0;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 60u);
    value0 = 0u - (value0);
    value1 = (value0 << 16);
    value0 = 0x1ff0000u;
    value1 = (value1) & (value0);
    value0 = 0x4000010u;
    *(u32 *) ((value0) + 0u) = (u32) value1;
    value3 = (u32) &func_02111428;
    value0 = (u32) func_02111428((unsigned int) value0, (unsigned int) value1, (unsigned int) value2);
    return (u32) value0;
}
