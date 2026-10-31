#include "00/code_0219b8bc.h"
#include "00/code_0219887c.h"
#include "00/code_0219b958.h"

s32 func_ov000_0219b8bc(u32 a) {
    s32 b;

    for (b = 0; b < 0x20; b++) {
        if (data_ov000_021b54d0[b] != 0 && a == func_ov000_0219887c(data_ov000_021b54d0[b])[1]) {
            return 1;
        }
    }
    return 0;
}
