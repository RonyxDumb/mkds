#include "01/code_021858a0.h"

#pragma thumb off
void func_ov001_021858b4(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b488;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value1) + (8)) = (u32) value0;
    return;
}
#pragma thumb on

#pragma thumb off
void func_ov001_021858a0(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b488;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value1) + (4)) = (u32) value0;
    return;
}
#pragma thumb on
