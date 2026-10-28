#include "03/code_021b7da0.h"

s32 func_ov003_021b7da0(const u8 *left, const u8 *right, s32 count) {
    s32 difference = 0;
    while (count-- > 0 && (difference = *left - *right) == 0) {
        left++;
        right++;
    }
    return difference;
}
