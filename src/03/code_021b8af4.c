#include "03/code_021b8af4.h"

u32 func_ov003_021b8af4(const u8 *bytes, s32 count) {
    u32 value = 0;
    s32 i;
    const u8 *cursor = bytes + (count - 1);
    for (i = 0; i < count; i++) {
        value = (value << 8) + *cursor--;
    }
    return value;
}
