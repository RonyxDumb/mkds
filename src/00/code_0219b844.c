#include "00/code_0219b844.h"

u32 func_ov000_0219b844(const u8 *values, s32 count) {
    u32 mask = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        mask |= 1 << values[i];
    }
    return mask;
}
