#include "00/code_0219b868.h"
#include "00/code_021a158c.h"
#include "00/code_021a1620.h"

u32 func_ov000_0219b868(u32 a) {
    void *b;
    s32 d;
    s32 e;

    d = func_ov000_021a158c(&b);
    for (e = 0; e < d; e++) {
        if (a == ((u8 *) b)[e]) {
            break;
        }
    }
    if (e == d) {
        return 0;
    }
    return func_ov000_021a1620(e, d);
}
