#include "Main/Unknown/code_020cffa0.h"

u32 func_020cffa0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((unsigned int) value0);
    value1 = 0x38u;
    value0 = (u32) func_02036bec((void *) value0, (u32) value1);
    value1 = (u32) &data_0217b490;
    *(u32 *) ((value1) + (0)) = (u32) value0;
    return (u32) value0;
}
