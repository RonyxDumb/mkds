#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a0ff0.h"

Vec3 *func_020a0ff0(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0xcu);
    return (Vec3 *) value0;
}
