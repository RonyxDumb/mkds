#include "00/code_0218cd74.h"

void func_ov000_0218cd74(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = (u32) arg2;
    u32 value3 = (u32) arg3;
    u32 value4;
    u32 value5;
    u32 value6;
    value5 = (value0) + (0u);
    value4 = (value2) + (0u);
    value6 = (value3) + (0u);
    value0 = (u32) * (const u32 *) ((value5) + 0u);
    func_02134eb8((u32 *) value0, (u32) value1, (int) value2);
    value0 = (u32) * (const u32 *) ((value6) + 0u);
    value0 = (value0) + (value4);
    *(u32 *) ((value6) + 0u) = (u32) value0;
    value0 = (u32) * (const u32 *) ((value5) + 0u);
    value0 = (value0) + (value4);
    *(u32 *) ((value5) + 0u) = (u32) value0;
    return;
}
