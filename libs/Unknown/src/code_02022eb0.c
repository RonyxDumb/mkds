#include "code_02022eb0.h"

static inline u32 clz_inline(u32 x) {
    u32 r;
    asm { clz r, x }
    return r;
}

// non-matching: 56.3%; the leading-zero counts are inline asm and the stack-kept values and call argument setup
// differ from the original
s32 func_02022eb0(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    Unk02022eb0 *p;
    s32 lb;
    s32 lc;
    s32 sx;
    s32 sy;
    u32 mx;
    u32 my;
    s32 m;
    s32 nx;
    s32 ny;
    s32 i;
    s32 j;
    s32 n;
    s32 r;
    s32 k;
    s32 t;
    u32 w;

    p = (Unk02022eb0 *) a;
    if (b < 8) {
        lb = 31 - clz_inline(b);
    } else {
        lb = 3;
    }
    if (c < 8) {
        lc = 31 - clz_inline(c);
    } else {
        lc = 3;
    }
    sx = data_usa_021530f8[lc][lb][0];
    sy = data_usa_021530f8[lc][lb][1];
    mx = b & (-1 << sx);
    my = c & (-1 << sy);
    if (f == 0) {
        m = 1;
    } else {
        m = 2;
    }
    n = 0;
    k = func_02024168(&data_usa_021530f8[lc][lb][0]);
    nx = b >> sx;
    ny = c >> sy;
    t = (m << sx << sy) >> h;
    for (j = 0; j < ny; j++) {
        for (i = 0; i < nx; i++) {
            w = p->mUnk_00;
            w = (w & 0xfe00ff00) | ((e + (j << sy) * 8) & 0xff) | (((d + (i << sx) * 8) & 0x1ff) << 16);
            p->mUnk_00 = w;
            p->mUnk_00 = (p->mUnk_00 & 0x3fff3fff) | k;
            p->mUnk_04 = (p->mUnk_04 & -0x400) | g;
            g += t;
            p->mUnk_00 = (p->mUnk_00 & ~0x2000) | (f << 13);
            p++;
        }
    }
    n += nx * ny;
    if (mx < b) {
        r = func_02022eb0(p, b - mx, my, d + mx * 8, e, f, g, h);
        p += r;
        g += (m * (b - mx) * my) >> h;
        n += r;
    }
    if (my < c) {
        r = func_02022eb0(p, mx, c - my, d, e + my * 8, f, g, h);
        p += r;
        g += (m * mx * (c - my)) >> h;
        n += r;
    }
    if (mx < b && my < c) {
        n += func_02022eb0(p, b - mx, c - my, d + mx * 8, e + my * 8, f, g, h);
    }
    return n;
}
