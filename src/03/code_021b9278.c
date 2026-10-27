#include "03/code_021b9278.h"

s32 func_ov003_021b9278(const u8 *bytes, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        u32 value = *bytes++;
        if (value < 0x20 || value > 0x7f) {
            return -1;
        }
    }
    return 0;
}
