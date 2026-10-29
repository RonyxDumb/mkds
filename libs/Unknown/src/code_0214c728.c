#include "code_0214c728.h"

// non-matching: hand-written routine (ldm and stm to the same address); this C writes through a volatile pointer
void func_0214c74c(const void *a, void *b) {
    const u32 *s;
    vu32 *d;
    s32 i;

    s = (const u32 *) a;
    d = (vu32 *) b;
    for (i = 0; i < 2; i++) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d[4] = s[4];
        d[5] = s[5];
        d[6] = s[6];
        d[7] = s[7];
        s += 8;
    }
}

// non-matching: hand-written routine (ldm and stm to the same address); this C writes through a volatile pointer
void func_0214c728(const void *a, void *b) {
    const u32 *s;
    vu32 *d;
    s32 i;

    s = (const u32 *) a;
    d = (vu32 *) b;
    for (i = 0; i < 4; i++) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        s += 3;
    }
}
