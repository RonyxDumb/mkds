#include "Main/Unknown/code_02111118.h"

u32 func_02111144(void) {
    u32 value0;
    value0 = (u32) &data_0217d32c;
    value0 = (u32) * (const u32 *) ((value0) + (8));
    value0 = (u32) * (const u32 *) ((value0) + (20));
    return (u32) value0;
}

u32 func_02111118(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217d328;
    value3 = 0u;
    value1 = (u32) &data_0217d324;
    value0 = (u32) &data_0217d320;
    *(u32 *) ((value2) + (0)) = (u32) value3;
    *(u32 *) ((value1) + (0)) = (u32) value3;
    *(u32 *) ((value0) + (0)) = (u32) value3;
    return (u32) value0;
}
