#include "Main/Unknown/code_021113f0.h"

#pragma thumb on
u32 func_02111418(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 48u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
u32 func_02111408(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 50u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    return (u32) value0;
}
#pragma thumb off

#pragma thumb on
void func_021113fc(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u16 *) ((value1) + 48u) = (u16) value0;
}
#pragma thumb off

#pragma thumb on
void func_021113f0(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u16 *) ((value1) + 50u) = (u16) value0;
}
#pragma thumb off
