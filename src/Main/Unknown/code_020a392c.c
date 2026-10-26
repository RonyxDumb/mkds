#include "Main/Unknown/code_020a392c.h"

u32 func_020a392c(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value4;
    value4 = value0;
    value0 = (u32) * (const u32 *) ((value1) + (168));
    value0 = (u32) func_0208606c((int) value0);
    *(u16 *) ((value4) + (114)) = (u16) value0;
    return (u32) value0;
}
