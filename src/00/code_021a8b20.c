#include "00/code_021a8b20.h"
#include "00/code_021a8994.h"
#include "code_0200dc3c.h"

s32 func_ov000_021a8b20(void *a, s32 b, s64 c) {
    Unk021a8b20 *d;
    s32 e;
    u32 f;
    u32 g;
    s32 h;
    h = c != -1;
    for (;;) {
        d = a;
        e = 0;
        for (f = 0; f < b; f++) {
            g = d->mUnk_04 | 0xe0;
            g &= func_ov000_021a8994(d->mUnk_00);
            if (g != 0) {
                e++;
            }
            d->mUnk_06 = g;
            d++;
        }
        if (e > 0) {
            break;
        }
        if (h != 0 && c <= 0) {
            break;
        }
        func_0200dc3c(1);
        c -= 0x20b;
    }
    return e;
}
