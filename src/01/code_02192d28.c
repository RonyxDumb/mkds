#include "01/code_02192d28.h"

u32 func_ov001_02192d28(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) func_020364e8();
    value0 = (u32) func_020364e0((unsigned int) value0);
    value1 = 84u;
    value0 = (u32) func_02036bec((void *) value0, (u32) value1);
    value1 = (u32) &data_ov001_021a9bc8;
    *(u32 *) ((value1) + 0u) = (u32) value0;
    return (u32) value0;
}
