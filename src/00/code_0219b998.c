#include "00/code_0219b998.h"

s32 func_ov000_0219b998(void) {
    s32 i = 0;
    void **slot = data_ov000_021b54d0;
    for (; i < 32; slot++, i++) {
        if (*slot == 0) {
            return i;
        }
    }
    return -1;
}
