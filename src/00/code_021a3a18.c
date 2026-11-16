#include "00/code_021a3a18.h"

#include "00/GameSpy/nonport.h"
#include "00/code_021a3000.h"
#include "00/code_021a3760.h"
#include "00/code_021a4000.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"
#include "00/code_021a4b84.h"
#include "code_021384cc.h"
#include "code_02139f70.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/code_021a6d5c.h"

s32 func_ov000_021a4a08(Unk021a4a08 **a, s32 b, s32 c, const char *d, const char *e, s32 f, s32 g, Unk021a4a08Func88 h,
                        Unk021a4a08Func8c i, Unk021a4a08Func8c j, Unk021a4a08Func94 k, Unk021a4a08Func98 l,
                        Unk021a4a08Func9c m, void *n) {
    char p[0x40];
    s32 r;
    s8 s;
    s32 t;
    Unk021a4a08 *o;

    if (a == NULL) {
        o = &data_ov000_021b4278;
    } else {
        *a = func_ov000_021a3690(0x110);
        o = *a;
    }
    srand(func_ov000_0218e8c4());
    strcpy((char *) o->field4, d);
    strcpy((char *) o->field44, e);
    o->fieldC0 = c;
    r = 0;
    o->fieldAC = 0;
    o->fieldB0 = 0;
    o->field0 = b;
    o->fieldB8 = 1;
    o->field10C = n;
    o->field88 = h;
    o->field8C = i;
    o->field90 = j;
    o->field94 = k;
    o->field98 = l;
    o->field9C = m;
    o->fieldA0 = 0;
    o->fieldA4 = 0;
    o->fieldD4 = 0;
    o->fieldBC = f;
    o->fieldC4 = FALSE;
    o->fieldC8 = g;
    o->field104 = 0;
    o->field108 = 0;
    o->fieldA8 = NULL;
    o->fieldB4 = FALSE;
    do {
        o->field84[r] = (s32) rand() % 0xff;
        r++;
    } while (r < 4);
    r = 0;
    do {
        o->fieldD8[r] = -1;
        r++;
    } while (r < 10);
    o->field100 = 0;
    if (data_ov000_021b5df8 == 0) {
        func_ov000_021a46d4();
    }
    if (f != 0) {
        s = data_ov000_021b5e10[0];
        if (s == 0) {
            sprintf(p, data_ov000_021b4464, d);
        }
        t = func_ov000_021a4654(s != 0 ? data_ov000_021b5e10 : p, 0x6cfc, &o->fieldCC, NULL);
    } else {
        t = 1;
    }
    if (t != 0) {
        return 0;
    }
    return 3;
}

void func_ov000_021a49f4(Unk021a4a08 *a, UnkFunc *b) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    a->fieldA0 = b;
}

void func_ov000_021a49e0(Unk021a4a08 *a, UnkFunc *b) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    a->fieldA4 = b;
}

void func_ov000_021a49cc(void *a, void (*b)(void *, u16)) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    *(void (**)(void *, u16))((u8 *) a + 0xa8) = b;
}

void func_ov000_021a49a0(Unk021a4a08 *a) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    if (a->fieldBC != 0) {
        func_ov000_021a4868(a);
    }
    func_ov000_021a4940(a);
}

void func_ov000_021a4940(Unk021a4a08 *a) {
    u8 b[8];
    s32 c;
    s32 d;
    s32 e;

    c = 8;
    if (a->fieldC4 != FALSE && func_ov000_0218e668(a->field0) != 0) {
        d = 0;
        do {
            e = func_ov000_0218e438(a->field0, data_ov000_021b5e50, 0xff, d, b, &c);
            if (e != ~d) {
                data_ov000_021b5e50[e] = d;
                func_ov000_021a3c14((Unk021a3a18 *) a, data_ov000_021b5e50, e, b);
            }
        } while (func_ov000_0218e668(a->field0) != 0);
    }
}

void func_ov000_021a4868(Unk021a4a08 *a) {
    u32 b;
    s32 c;

    b = func_ov000_0218e8c4();
    if (a->field0 != -1) {
        c = a->fieldB8;
        if (c > 0 && b - a->fieldAC > 10000) {
            if (c >= 4) {
                a->fieldB8 = 0;
                a->field9C(5, data_ov000_021b442c, a->field10C);
                return;
            }
            func_ov000_021a3a18((Unk021a3a18 *) a, 3);
            a->fieldB8 = a->fieldB8 + 1;
        } else if (a->fieldB4 != FALSE && b - a->fieldAC > 10000) {
            func_ov000_021a3a18((Unk021a3a18 *) a, 1);
        } else if (b - a->fieldAC > 60000 || a->fieldAC == 0 || b < a->fieldAC) {
            func_ov000_021a3a18((Unk021a3a18 *) a, 0);
        }
        if (b - a->fieldB0 > 20000) {
            func_ov000_021a3bbc((Unk021a3a18 *) a);
        }
    }
}

void func_ov000_021a4818(Unk021a4a08 *a) {
    int v1;
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    if (a->fieldBC != 0) {
        v1 = func_ov000_0218e8c4();
        if ((v1 - a->fieldAC) < (0x00002710u)) {
            a->fieldB4 = TRUE;
            return;
        }
        func_ov000_021a3a18((Unk021a3a18 *) a, 1);
        a->fieldB4 = FALSE;
    }
}

void func_ov000_021a47ac(Unk021a4a08 *a) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    if (a->fieldBC != 0) {
        func_ov000_021a3a18((Unk021a3a18 *) a, 2);
    }
    if (a->field0 != -1 && a->fieldC4 != FALSE) {
        func_ov000_0218e53c(a->field0);
    }
    a->field0 = -1;
    a->fieldAC = 0;
    if (a->fieldC4 != FALSE) {
        func_ov000_0218e8b4();
    }
    if (a != &data_ov000_021b4278) {
        func_ov000_021a3668(a);
    }
}

void func_ov000_021a4784(MatchingKeyIds *a, int b) {
    int v1;
    v1 = a->field100;
    if (((v1 < 0xfe) && (1 <= b)) && (b <= 254)) {
        a->field100 = v1 + 1;
        a->field0[v1] = (s8) b;
    }
}

static inline u16 func_ov000_021a4654_inline(u16 v1) {
    return ((v1 >> 8) & 0xff) | ((v1 << 8) & 0xff00);
}

void func_ov000_021a4760(Unk021a471c *a, s32 b) {
    char c[0x18];

    sprintf(c, data_ov000_021b4428, b);
    func_ov000_021a471c(a, c);
}

void func_ov000_021a471c(Unk021a471c *a, const char *b) {
    s32 c;
    s32 d;

    c = strlen(b) + 1;
    d = 0x800 - a->field800;
    if (c > d) {
        c = d;
    }
    if (c != 0) {
        memcpy(&a->field0[a->field800], b, c);
        a->field800 += c;
        a->field0[a->field800 - 1] = 0;
    }
}

void func_ov000_021a46d4(void) {
    Unk021a8f84 *a;
    Unk021a46d4 *b;
    Unk021a46d4 *d;

    a = func_ov000_0218e5e4();
    if (a != NULL) {
        data_ov000_021b5df8 = 0;
        d = (Unk021a46d4 *) data_ov000_021b5dfc;
        for (; data_ov000_021b5df8 < 5; data_ov000_021b5df8++) {
            b = (Unk021a46d4 *) a->fieldC[data_ov000_021b5df8];
            if (b == NULL) {
                break;
            }
            d[data_ov000_021b5df8] = *b;
        }
    }
}

BOOL func_ov000_021a4654(const char *a, u32 b, Unk021a4654 *c, Unk021a8f84 **d) {
    Unk021a8f84 *e;

    e = NULL;
    c->field1 = 2;
    c->field2 = func_ov000_021a4654_inline(b);
    if (a == NULL) {
        c->field4 = 0;
    } else {
        c->field4 = func_ov000_0218e374((u32) a);
    }
    if (c->field4 == -1) {
        if (strcmp(a, data_ov000_021b4418) != 0) {
            e = func_ov000_021a8f84(a);
            if (e == NULL) {
                return FALSE;
            }
            c->field4 = **e->fieldC;
        }
    }
    if (d != NULL) {
        *d = e;
    }
    return TRUE;
}

void func_ov000_021a4648(u8 *a, u8 *b) {
    u8 v1;
    v1 = *a;
    *a = *b;
    *b = v1;
}

u8 func_ov000_021a4610(u32 a) {
    if (a < 0x1a) {
        return a + 0x41 & 0xff;
    }
    if (a < 0x34) {
        return a + 0x47 & 0xff;
    }
    if (a < 0x3e) {
        return a - 4 & 0xff;
    }
    if (a == 0x3e) {
        return 0x2b;
    }
    if (a == 0x3f) {
        return 0x2f;
    }
    return 0;
}

void func_ov000_021a4578(const u8 *a, s32 b, u8 *c) {
    u8 d[7];
    s32 e;
    s32 f;
    u8 *g;
    s32 h;
    u8 i;
    u8 j;

    e = 0;
    if (b > 0) {
        do {
            for (f = 0, g = d; f <= 2; f++, e++) {
                if (e < b) {
                    *g = *a++;
                } else {
                    *g = 0;
                }
                g++;
            }
            i = d[0];
            d[3] = i >> 2;
            j = d[1];
            d[4] = ((i & 3) << 4) + (j >> 4);
            i = d[2];
            d[5] = ((j & 0xf) << 2) + (i >> 6);
            d[6] = i & 0x3f;
            for (h = 0, g = &d[3]; h <= 3; h++) {
                *c++ = func_ov000_021a4610(*g);
                g++;
            }
        } while (e < b);
    }
    *c = 0;
}

void func_ov000_021a44a0(u8 *a, s32 b, u8 *c, s32 d) {
    u8 e[0x100];
    s16 o;
    u8 *n;
    u8 g;
    u8 h;
    u8 i;
    u8 j;
    s16 k;
    s16 l;
    u8 *m;

    for (k = 0; k < 0x100; k++) {
        e[k] = k;
    }
    g = 0;
    h = 0;
    l = 0;
    m = e;
    do {
        h = (m[0] + a[g] + h) % 0x100;
        g = (g + 1) % b;
        func_ov000_021a4648(m, e + h);
        m++;
        l++;
    } while (l < 0x100);
    i = 0;
    h = 0;
    o = 0;
    if (d > 0) {
        do {
            i = (i + c[o] + 1) % 0x100;
            n = e + i;
            h = (*n + h) % 0x100;
            func_ov000_021a4648(n, e + h);
            j = (*n + e[h]) % 0x100;
            c[o] ^= e[j];
            o++;
        } while (o < d);
    }
}

void func_ov000_021a4480(u32 p0, u32 p1, u32 p2) {
    u32 v1;
    u32 v2;
    u32 v4;
    u32 v6;
    u32 v8;
    u32 v10;
    u32 v11;
    *(u8 *) ((p0) + (0)) = p1;
    v1 = ((p0) + (0x1u));
    v2 = (*(u8 *) ((p2) + (0)));
    *(u8 *) ((p0) + (1)) = v2;
    v4 = (*(u8 *) ((p2) + (1)));
    *(u8 *) ((v1) + (1)) = v4;
    v6 = (*(u8 *) ((p2) + (2)));
    *(u8 *) ((v1) + (2)) = v6;
    v8 = (*(u8 *) ((p2) + (3)));
    *(u8 *) ((v1) + (3)) = v8;
    v10 = 0x5u;
    v11 = 0x800u;
    *(u32 *) ((p0) + (0 + (v11))) = v10;
}

void func_ov000_021a4418(Unk021a4a08 *a, Unk021a471c *b, const char *c, s32 d) {
    u8 e[0x44];

    if (d >= 1 && d <= 0x41 && ((s8 *) c)[d - 1] == 0) {
        strcpy((char *) e, c);
        func_ov000_021a44a0(a->field44, strlen((const char *) a->field44), e, d - 1);
        func_ov000_021a4578(e, d - 1, &b->field0[b->field800]);
        b->field800 += strlen((const char *) &b->field0[b->field800]) + 1;
    }
}

void func_ov000_021a438c(Unk021a4a08 *a, const char *b) {
    u32 c;
    u32 d;
    u16 e;

    sscanf(b, data_ov000_021b440c, &c, &d);
    e = d;
    c = (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    if (c != 0 && e != 0) {
        if (a->field104 != c || a->field108 != e) {
            a->field104 = c;
            a->field108 = e;
            a->fieldA8(c, e, a->field10C);
        }
    }
}

void func_ov000_021a41dc(Unk021a4a08 *a, Unk021a471c *b, s32 c, s32 d, const u8 *e) {
    MatchingKeyIds f;
    u16 g;
    u16 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    s32 n;
    const u8 *o;
    const char *p;
    u8 *q;
    u8 *r;

    f.field100 = 0;
    if (d == 0) {
        return;
    }
    if ((u32) (c - 1) <= 1) {
        if ((u32) (0x800 - b->field800) < 2) {
            return;
        }
        i = a->field98(c, a->field10C);
        g = i;
        h = (g >> 8 & 0xff) | (g << 8 & 0xff00);
        r = &b->field0[b->field800];
        q = (u8 *) &h;
        r[0] = q[0];
        r[1] = q[1];
        b->field800 += 2;
    } else {
        i = 1;
    }
    if (d == 0xff) {
        a->field94(c, &f, a->field10C);
        l = 0;
        if (f.field100 > 0) {
            o = f.field0;
            do {
                p = data_ov000_021b45bc[*o];
                if (p == NULL) {
                    p = data_ov000_021b43f8;
                }
                func_ov000_021a471c(b, p);
                if (c == 0) {
                    k = b->field800;
                    a->field88(*o, b, a->field10C);
                    if (k == b->field800) {
                        func_ov000_021a471c(b, data_ov000_021b4400);
                    }
                }
                o++;
                l++;
            } while (l < f.field100);
        }
        if (0x800 - b->field800 < 1) {
            return;
        }
        b->field0[b->field800++] = 0;
        d = f.field100;
        e = f.field0;
        if (c == 0) {
            return;
        }
    }
    j = 0;
    if (i > 0) {
        m = j;
        do {
            n = m;
            if (d > 0) {
                do {
                    k = b->field800;
                    if (c == 0) {
                        a->field88(e[n], b, a->field10C);
                    } else if (c == 1) {
                        a->field8C(e[n], j, b, a->field10C);
                    } else if (c == 2) {
                        a->field90(e[n], j, b, a->field10C);
                    }
                    if (k == b->field800) {
                        func_ov000_021a471c(b, data_ov000_021b4400);
                    }
                    n++;
                } while (n < d);
            }
            j++;
        } while (j < i);
    }
}

void func_ov000_021a41a0(Unk021a4a08 *a, Unk021a471c *b, s32 c, const u8 *d, s32 e, const u8 *f, s32 g, const u8 *h) {
    func_ov000_021a41dc(a, b, 0, c, d);
    func_ov000_021a41dc(a, b, 1, e, f);
    func_ov000_021a41dc(a, b, 2, g, h);
}

void func_ov000_021a412c(Unk021a4a08 *a, Unk021a471c *b, const u8 *c, s32 d) {
    u8 h;
    u8 i;
    u8 j;
    const u8 *e;
    const u8 *g;
    const u8 *f;

    e = NULL;
    g = NULL;
    f = NULL;
    if (d >= 3) {
        h = *c++;
        d--;
        if (h != 0 && h != 0xff) {
            e = c;
            c += h;
            d -= h;
        }
        if (d >= 2) {
            i = *c++;
            d--;
            if (i != 0 && i != 0xff) {
                g = c;
                c += i;
                d -= i;
            }
            if (d >= 1) {
                j = *c;
                d--;
                if (j != 0 && j != 0xff) {
                    f = c + 1;
                    d -= j;
                }
                if (d >= 0) {
                    func_ov000_021a41a0(a, b, h, e, i, g, j, f);
                }
            }
        }
    }
}

void func_ov000_021a3fc8(Unk021a4a08 *a, Unk021a471c *b, s32 c) {
    char e[0x80];
    MatchingKeyIds d;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    const char *k;
    u8 *l;

    d.field100 = 0;
    if ((u32) (c - 1) <= 1) {
        f = a->field98(c, a->field10C);
    } else {
        f = 1;
    }
    a->field94(c, &d, a->field10C);
    h = 0;
    if (d.field100 > 0) {
        l = d.field0;
        i = h;
        do {
            k = data_ov000_021b45bc[*l];
            if (k == NULL) {
                k = data_ov000_021b43f8;
            }
            if (c == 0) {
                func_ov000_021a471c(b, k);
                b->field0[b->field800 - 1] = 0x5c;
                g = b->field800;
                a->field88(*l, b, a->field10C);
                if (g == b->field800) {
                    func_ov000_021a471c(b, data_ov000_021b4400);
                }
                b->field0[b->field800 - 1] = 0x5c;
            } else {
                j = i;
                if (f > 0) {
                    do {
                        sprintf(e, data_ov000_021b4404, k, j);
                        func_ov000_021a471c(b, e);
                        b->field0[b->field800 - 1] = 0x5c;
                        g = b->field800;
                        if (c == 1) {
                            a->field8C(*l, j, b, a->field10C);
                        } else if (c == 2) {
                            a->field90(*l, j, b, a->field10C);
                        }
                        if (g == b->field800) {
                            func_ov000_021a471c(b, data_ov000_021b4400);
                        }
                        b->field0[b->field800 - 1] = 0x5c;
                        j++;
                    } while (j < f);
                }
            }
            l++;
            h++;
        } while (h < d.field100);
    }
}

void func_ov000_021a3f78(Unk021a4a08 *a, Unk021a471c *b) {
    b->field800 = 1;
    b->field0[0] = 0x5c;
    func_ov000_021a3fc8(a, b, 0);
    func_ov000_021a3fc8(a, b, 1);
    func_ov000_021a3fc8(a, b, 2);
    func_ov000_021a471c(b, data_ov000_021b43e4);
    b->field800 = b->field800 + -1;
}

void func_ov000_021a3eb0(Unk021a3a18 *a, u8 *b, s32 c) {
    Unk021a3eb0 s = data_ov000_021b4270;
    s32 i;
    BOOL k = TRUE;
    u32 x;
    u8 *p;
    u8 *t;
    if (c >= 10) {
        for (i = 0; i < 6; i++) {
            if (s.field0[i] != b[i]) {
                k = FALSE;
                break;
            }
        }
    } else {
        k = FALSE;
    }
    if (k != FALSE) {
        t = (u8 *) &x;
        p = b + 6;
        t[0] = p[0];
        t[1] = p[1];
        t[2] = p[2];
        t[3] = p[3];
        if (a->fieldA0 != NULL) {
            a->fieldA0(((x << 24) & 0xff000000) | (((x << 8) & 0xff0000) | (((x >> 24) & 0xff) | ((x >> 8) & 0xff00))),
                       a->field10C);
        }
    } else if (a->fieldA4 != NULL) {
        a->fieldA4((s8 *) b, c, a->field10C);
    }
}

u32 func_ov000_021a3e5c(Unk021a3a18 *a, int b) {
    int v1;
    int v2;
    int *v4;
    v1 = 0;
    do {
        if (b == a->fieldD8[v1]) {
            return 1;
        }
        v1 = v1 + 1;
    } while (v1 < 10);
    v2 = (a->field100 + 1) % (10);
    v4 = &a->field100;
    *v4 = v2;
    a->fieldD8[*v4] = b;
    return 0;
}

void func_ov000_021a3c14(Unk021a3a18 *a, s8 *b, s32 c, void *d) {
    Unk021a4480 k;
    s32 t;
    s32 i;
    s8 *p5;
    s8 *p6;
    k.field800 = 0;
    if (a == NULL) {
        a = (Unk021a3a18 *) data_ov000_021b426c;
    }
    if (b[0] == 0x3b) {
        if (a->fieldD4 != NULL) {
            a->fieldD4(b, c, d);
            return;
        }
    } else if (b[0] == 0x5c) {
        func_ov000_021a3f78((Unk021a4a08 *) a, (Unk021a471c *) &k);
        func_ov000_0218e3e4(a->field0, &k, k.field800, 0, d, 8);
        return;
    } else if (c >= 7) {
        if ((u8) b[0] == 0xfe) {
            if ((u8) b[1] == 0xfd) {
                if (a->fieldB8 > 0) {
                    a->fieldB8 = 0;
                }
                t = b[2];
                p5 = b + 3;
                p6 = b + 7;
                c = c - 7;
                func_ov000_021a4480((u32) &k, t, (u32) p5);
                switch (t) {
                    case 0:
                        func_ov000_021a412c((Unk021a4a08 *) a, (Unk021a471c *) &k, (u8 *) p6, c);
                        break;
                    case 1:
                        if (c >= 13 && a->fieldA8 != 0) {
                            func_ov000_021a438c((Unk021a4a08 *) a, (const char *) (p6 + c - 13));
                        }
                        func_ov000_021a4418((Unk021a4a08 *) a, (Unk021a471c *) &k, (const char *) p6, c);
                        break;
                    case 2:
                        if (c > 0x20) {
                            c = 0x20;
                        }
                        k.field0[0] = 5;
                        memcpy(&k.field0[k.field800], p6, c);
                        k.field800 += c;
                        break;
                    case 4:
                        if (a->fieldB8 == -1) {
                            return;
                        }
                        for (i = 0; i < 4; i++) {
                            if (p5[i] != a->field84[i]) {
                                return;
                            }
                        }
                        if (c < 2) {
                            return;
                        }
                        a->fieldB8 = -1;
                        a->field9C(p6[0], (u8 *) (p6 + 1), a->field10C);
                        return;
                    case 6:
                        for (i = 0; i < 4; i++) {
                            if (p5[i] != a->field84[i]) {
                                return;
                            }
                        }
                        if (c < 4) {
                            return;
                        }
                        k.field0[0] = 7;
                        __memcpy(&k.field0[k.field800], p6, 4);
                        k.field800 += 4;
                        __memcpy(&i, p6, 4);
                        if (func_ov000_021a3e5c(a, i) == 0) {
                            func_ov000_021a3eb0(a, (u8 *) (p6 + 4), c - 4);
                        }
                        break;
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    default:
                        return;
                }
                func_ov000_0218e3e4(a->field0, &k, k.field800, 0, d, 8);
            }
        }
    }
}

void func_ov000_021a3bbc(Unk021a3a18 *a) {
    Unk021a4480 k;
    k.field800 = 0;
    func_ov000_021a4480((u32) &k, 8, (u32) a->field84);
    func_ov000_0218e3e4(a->field0, &k, k.field800, 0, a->fieldCC, 8);
    a->fieldB0 = func_ov000_0218e8c4();
}

void func_ov000_021a3a18(Unk021a3a18 *a, s32 b) {
    Unk021a4480 k;
    char t[0x14];
    s32 i;
    k.field800 = 0;
    func_ov000_021a4480((u32) &k, 3, (u32) a->field84);
    for (i = 0; i < data_ov000_021b5df8; i++) {
        sprintf(t, data_ov000_021b4388, i);
        func_ov000_021a471c((Unk021a471c *) &k, t);
        func_ov000_021a471c((Unk021a471c *) &k, func_ov000_021a8c6c(((Unk021b5dfc *) data_ov000_021b5dfc)[i]));
    }
    func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b4394);
    func_ov000_021a4760((Unk021a471c *) &k, a->fieldC0);
    func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43a0);
    func_ov000_021a471c((Unk021a471c *) &k, a->fieldC8 != 0 ? data_ov000_021b43a8 : data_ov000_021b43ac);
    if (b != 0) {
        func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43b0);
        func_ov000_021a4760((Unk021a471c *) &k, b);
    }
    func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43c0);
    func_ov000_021a471c((Unk021a471c *) &k, a->field4);
    if (a->fieldA8 != 0) {
        func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43cc);
        func_ov000_021a4760((Unk021a471c *) &k, a->field104);
        func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43d8);
        func_ov000_021a4760((Unk021a471c *) &k, a->field108);
    }
    if (b != 2) {
        func_ov000_021a41a0((Unk021a4a08 *) a, (Unk021a471c *) &k, 0xff, NULL, 0xff, NULL, 0xff, NULL);
    } else if (0x800 - k.field800 >= 1) {
        k.field0[k.field800++] = 0;
    }
    func_ov000_0218e3e4(a->field0, &k, k.field800, 0, a->fieldCC, 8);
    a->fieldAC = func_ov000_0218e8c4();
    a->fieldB0 = a->fieldAC;
    if (b != 0) {
        a->fieldB4 = 0;
    }
}
