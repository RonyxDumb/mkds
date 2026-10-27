#include "00/code_0218e56c.h"

s32 func_ov000_0218e56c(s32 result, s32 fallback) {
    if (result < 0) {
        data_ov000_021b4e08 = result;
        result = fallback;
    }
    return result;
}
