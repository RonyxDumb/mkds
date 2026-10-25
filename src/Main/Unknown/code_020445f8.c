#include "Main/Unknown/code_020445f8.h"

u32 func_020445f8(void) {
    u32 value0;
    u32 value1;
    u32 value12;
    value0 = (u32) &data_021759c0;
    value12 = (u32) &func_0205950c;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value1) + (488));
    value1 = (u32) * (const u32 *) ((value1) + (496));
    value0 = (u32) func_0205950c((unsigned int) value0, (unsigned int) value1);
    return (u32) value0;
}
