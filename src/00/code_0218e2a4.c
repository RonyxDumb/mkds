#include "00/code_0218e2a4.h"

void func_ov000_0218e2a4(u32 seed) {
    if (seed != 0) {
        seed &= 0x7fffffff;
    } else {
        seed = 1;
    }
    data_ov000_021b23ac = seed;
}
