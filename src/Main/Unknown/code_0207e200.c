#include "Main/Unknown/code_0207e200.h"
#include "Main/Unknown/code_020888b4.h"

u32 func_0207e200(struct Unk02089a24 *arg0, struct Unk020888b4 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value4;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value4 = value0;
    value0 = (u32) * (const u32 *) ((value2) + (716));
    value0 = (u32) * (const u32 *) ((value0) + (16));
    *(u32 *) ((value4) + (0)) = (u32) value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    *(u32 *) ((value4) + (16)) = (u32) value0;
    value0 = (u32) * (const u16 *) ((value1) + (4));
    value0 = (u32) func_020853f0((u32) value0);
    *(u32 *) ((value4) + (28)) = (u32) value0;
    value0 = (u32) * (const u32 *) ((value4) + (28));
    value2 = 0u;
    *(u32 *) ((value4) + (32)) = (u32) value0;
    *(u32 *) ((value4) + (36)) = (u32) value2;
    value1 = (u32) * (const u32 *) ((value4) + (0));
    value0 = ~(0u);
    *(u32 *) ((value4) + (4)) = (u32) value1;
    *(u32 *) ((value4) + (8)) = (u32) value2;
    *(u32 *) ((value4) + (12)) = (u32) value2;
    value1 = (u32) * (const u32 *) ((value4) + (0));
    *(u32 *) ((value4) + (16)) = (u32) value1;
    *(u32 *) ((value4) + (20)) = (u32) value0;
    *(u32 *) ((value4) + (24)) = (u32) value2;
    return (u32) value0;
}
