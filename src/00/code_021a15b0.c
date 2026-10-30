#include "00/code_021a15b0.h"

void func_ov000_021a15b0(void) {
    Unk021b566c *p;
    s32 n;
    s32 i;
    u32 m;
    i = 0;
    n = -1;
    p = data_ov000_021b566c;
    m = p->mUnk_2d8;
    for (; i < 32; i++) {
        if ((m & (1 << i)) != 0) {
            n++;
        }
    }
    if (n == -1) {
        p->mUnk_0e = 0;
    } else {
        p->mUnk_0e = n;
    }
}
