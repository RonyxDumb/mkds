#include "03/code_021d1d88.h"

u32 func_ov003_021d1d88(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (value4) + (1u);
    value0 = (value0 << 2);
    value0 = (value0) + 8u;
    value1 = 4u;
    value0 = (u32) func_ov003_021d285c((u32) value0, (u32) value1);
    value1 = (value4) + (1u);
    *(u16 *) ((value0) + 0u) = (u16) value1;
    value1 = 0u;
    *(u8 *) ((value0) + 2u) = (u8) value1;
    *(u8 *) ((value0) + 3u) = (u8) value1;
    return (u32) value0;
}
