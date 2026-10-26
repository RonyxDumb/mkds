#include "Main/Unknown/code_020cae38.h"

u32 func_020cae38(void) {
    u32 value0;
    value0 = (u32) &data_021759d0;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (28));
    value0 = (value0 << 29);
    value0 = ((u32) ((s32) value0 >> 31));
    return (u32) value0;
}
