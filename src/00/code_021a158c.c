#include "00/code_021a158c.h"
#include "00/code_0219de4c.h"

u32 func_ov000_021a158c(void **output) {
    if (data_ov000_021b566c == 0) {
        return 0;
    }
    *output = data_ov000_021b566c->mUnk_2b8;
    return data_ov000_021b566c->mUnk_0d + 1;
}
