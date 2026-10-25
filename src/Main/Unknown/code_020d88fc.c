#include "Main/Unknown/code_020d88fc.h"

u32 func_020d88fc(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = (u32) * (const u32 *) ((value0) + (12));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = 0x54u;
    value0 = (value1) * (value0) + (value2);
    value0 = (value0) + (0x48u);
    return (u32) value0;
}
