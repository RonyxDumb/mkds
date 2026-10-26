#include "code_020231e4.h"

void func_020232b0(u16 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u32 h) {
    s32 xe;
    s32 ye;
    s32 x;
    u16 *row;
    u32 p;
    s32 r;
    s32 col;

    if (f <= 0x20) {
        func_02023244(a + (f * e + d), b, c, f, g, h);
        return;
    }
    ye = e + c;
    xe = d + b;
    p = (u16) (h << 12);
    for (; e < ye; e++) {
        if (e < 0x20) {
            r = e;
        } else {
            r = e + 0x20;
        }
        x = d;
        row = a + r * 32;
        for (; x < xe; x++) {
            if (x < 0x20) {
                col = x;
            } else {
                col = x + 0x3e0;
            }
            row[col] = p | g;
            g++;
        }
    }
}

void func_02023244(u16 *a, s32 b, s32 c, s32 d, s32 e, u32 f) {
    s32 j;
    s32 i;
    u16 *p;
    u32 t;

    t = (u16) (f << 12);
    for (i = 0; i < c; i++) {
        p = a;
        for (j = 0; j < b; j++) {
            *p++ = t | e++;
        }
        a += d;
    }
}

// non-matching: the original has one more instruction (a copy `add lr, ip, #0` of the first product) and different
// registers
u32 func_020231e4(u32 a, u32 b) {
    u32 ax;
    u32 by;
    u32 s;
    u32 a2;
    u32 b2;
    u32 r;
    u32 u;
    u32 t;
    u32 z;

    ax = a >> 3;
    by = b >> 3;
    s = ax * by;
    a2 = a & 4;
    r = (a & 1) + ((a & 2) >> 1);
    b2 = b & 4;
    t = s;
    t = by * ((a2 >> 2) + (r << 1)) + t;
    u = (b & 1) + ((b & 2) >> 1);
    t = ax * ((b2 >> 2) + (u << 1)) + t;
    return (r + (a2 >> 2)) * (u + (b2 >> 2)) + t;
}
