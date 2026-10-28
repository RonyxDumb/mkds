#include "00/code_021a6c68.h"
#include "00/code_021a6c90.h"

s32 func_ov000_021a6c68(void) {
    u32 value = func_ov000_021a6c90();
    s32 level = 0;
    if (value >= 28) {
        level = 3;
    } else if (value >= 22) {
        level = 2;
    } else if (value >= 16) {
        level = 1;
    }
    return level;
}
