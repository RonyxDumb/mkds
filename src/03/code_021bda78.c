#include "03/code_021bda78.h"

s32 func_ov003_021bda78(u8 *p, u32 a, const void *b, u32 c) {
    s32 d;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    d = func_ov003_021bdaa4(p + 8, a, b, c) - p;
    *(u16 *) p = d - 8;
    return d;
}
