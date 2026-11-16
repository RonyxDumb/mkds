#include "00/code_0218a71c.h"
#include "code_02133048.h"

u8 func_ov000_0218a898(Unk0218a71c *p, u32 n, const u8 *v1, u32 m, u8 *j, u32 *k) {
    u32 v2;
    u32 v;
    u32 c;
    if (n == 0) {
        return 0;
    }
    c = 0;
    for (v2 = 1; v2 < n; v2 = v2 * 2 + 1) {
    }
    do {
        u32 q = (*k)++;
        *j = p->field0[*j] + v1[q];
        if (*k >= m) {
            *k = 0;
            *j = *j + m;
        }
        v = v2 & *j;
        c++;
        if (c > 11) {
            v = v % n;
        }
    } while (v > n);
    return v;
}

void func_ov000_0218a854(Unk0218a71c *p) {
    s32 i;
    u32 v;
    p->field100[0] = 1;
    p->field100[1] = 3;
    p->field100[2] = 5;
    p->field100[3] = 7;
    p->field100[4] = 11;
    i = 0;
    v = 255;
    for (; i < 256; i++, v--) {
        p->field0[i] = v;
    }
}

void func_ov000_0218a7bc(Unk0218a71c *p, const u8 *v1, u32 n) {
    u8 j;
    u32 k;
    s32 i;
    u32 l;
    u8 t;
    if (n < 1) {
        func_ov000_0218a854(p);
        return;
    }
    for (i = 0; i < 256; i++) {
        p->field0[i] = i;
    }
    k = 0;
    j = 0;
    for (l = 255; (s32) l >= 0; l--) {
        u8 r = func_ov000_0218a898(p, l, v1, n, &j, &k);
        t = p->field0[l];
        p->field0[l] = p->field0[r];
        p->field0[r] = t;
    }
    p->field100[0] = p->field0[1];
    p->field100[1] = p->field0[3];
    p->field100[2] = p->field0[5];
    p->field100[3] = p->field0[7];
    p->field100[4] = p->field0[j];
    j = 0;
    k = 0;
}

u8 func_ov000_0218a71c(Unk0218a71c *p, u8 x) {
    u8 a;
    u8 b;
    u8 c;
    u32 e;
    a = p->field100[0];
    p->field100[0] = a + 1;
    p->field100[1] = p->field100[1] + p->field0[a];
    c = p->field100[4];
    b = p->field0[c];
    p->field0[c] = p->field0[p->field100[1]];
    p->field0[p->field100[1]] = p->field0[p->field100[3]];
    p->field0[p->field100[3]] = p->field0[p->field100[0]];
    p->field0[p->field100[0]] = b;
    p->field100[2] = p->field100[2] + p->field0[b];
    e = x ^ p->field0[(p->field0[p->field100[2]] + p->field0[p->field100[0]]) & 0xff];
    p->field100[3] =
        e ^ p->field0[p->field0[(p->field0[p->field100[1]] + (p->field0[p->field100[3]] + p->field0[p->field100[4]])) &
                                    0xff]];
    p->field100[4] = x;
    return p->field100[3];
}
