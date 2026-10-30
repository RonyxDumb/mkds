#include "code_0200cd1c.h"

// non-matching: the original loads the callee address into r1 and branches with bx r1; ours uses ip
s32 func_0200cd1c(u32 a) {
    return func_0200ce80(a);
}

// non-matching: the original counts leading zeros with the clz instruction (C has no spelling for it); the count is a
// loop here
s32 func_0200cd28(void) {
    u32 *p;
    s32 n;
    s32 r;
    u32 m;
    p = (u32 *) 0x027fffb0;
    n = 0;
    for (m = *p; n < 32 && (m & 0x80000000u) == 0; m = m << 1) {
        n++;
    }
    if (n != 32) {
        r = 0x40;
    } else {
        p = p + 1;
        n = 0;
        for (m = *p; n < 32 && (m & 0x80000000u) == 0; m = m << 1) {
            n++;
        }
        if (n == 32) {
            return -3;
        }
        r = 0x60;
    }
    r = r + n;
    *p = *p & ~(0x80000000u >> n);
    return r;
}

// non-matching: the original keeps the shifted bit in its own register (mov, lsr, then orr); ours folds the shift into
// the orr
void func_0200cd80(s32 a) {
    u32 *p;
    p = (u32 *) 0x027fffb0;
    if (a >= 0x60) {
        p = p + 1;
        a = a - 0x60;
    } else {
        a = a - 0x40;
    }
    *p = *p | (0x80000000u >> a);
}
