#include "00/code_021a323c.h"

void func_ov000_021a3250(u32 (*arg0)(void)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_ov000_021b5dd0;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x600u;
    *(u32 *) ((value2) + (value1)) = value0;
    return;
}

void func_ov000_021a323c(void (*arg0)(u32, void *, u32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_ov000_021b5dd0;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x604u;
    *(u32 *) ((value2) + (value1)) = value0;
    return;
}
