#include "00/code_021a8b08.h"

void func_ov000_021a8b08(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) * (const u32 *) ((value0) + 0u);
    *(u32 *) ((value1) + 124u) = (u32) value2;
    *(u32 *) ((value0) + 0u) = (u32) value1;
    return;
}
