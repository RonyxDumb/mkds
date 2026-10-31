#include "Main/Unknown/code_020ab058.h"

#pragma thumb on
void func_020ab07c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b254;
    *(u32 *) ((value1) + 24u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab070(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b254;
    *(u32 *) ((value1) + 32u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab064(u16 (*arg0)(s32, u16)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b278;
    *(u32 *) ((value1) + 76u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab058(s32 (*arg0)(u32, s32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b278;
    *(u32 *) ((value1) + 80u) = value0;
}
#pragma thumb off
