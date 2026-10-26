#pragma avoid_byte all

#include "code_0213442c.h"
#include "code_02133e50.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_0213c94c.h"

u32 func_02134540(const u8 *a, u32 b, u32 c, Unk0213c94c *d) {
    u32 n;
    u32 t;
    u32 v;
    u32 l;
    int m;
    u8 *q;
    u8 *s1;
    u32 s2;

    if (func_0213c94c(d, 0) == 0) {
        func_0213c94c(d, -1);
    }
    n = b * c;
    if (n == 0 || d->mUnk_0d != 0 || d->mUnk_04_7 == 0) {
        return 0;
    }
    if (d->mUnk_04_7 == 2) {
        func_02135010();
    }
    m = 1;
    if (d->mUnk_04_12 != 0) {
        if (d->mUnk_04_5 != 2 && d->mUnk_04_5 != 1) {
            m = 0;
        }
    }
    if (d->mUnk_08_0 == 0 && (d->mUnk_04_2 & 2) != 0) {
        d->mUnk_08_0 = 1;
        func_02134508(d);
    }
    if (d->mUnk_08_0 != 1) {
        d->mUnk_0d = 1;
        d->mUnk_28 = 0;
        return 0;
    }
    t = 0;
    if (n != 0 && (d->mUnk_24 != d->mUnk_1c || m != 0)) {
        d->mUnk_28 = d->mUnk_20 - (d->mUnk_24 - d->mUnk_1c);
        v = 10;
        do {
            q = 0;
            l = d->mUnk_28;
            if (l > n) {
                l = n;
            }
            if (d->mUnk_04_5 == 1 && l != 0) {
                q = func_02134d80(a, v, l);
                if (q != 0) {
                    l = q + 1 - a;
                }
            }
            if (l != 0) {
                func_02134eb8(d->mUnk_24, a, l);
                a += l;
                n -= l;
                d->mUnk_24 += l;
                d->mUnk_28 -= l;
            }
            if (d->mUnk_28 == 0 || q != 0 || d->mUnk_04_5 == 0) {
                if (func_0213446c(d, 0) != 0) {
                    d->mUnk_0d = 1;
                    n = 0;
                    d->mUnk_28 = n;
                    break;
                }
            }
            t += l;
        } while (n != 0 && m != 0);
    }
    if (n != 0 && m == 0) {
        s1 = d->mUnk_1c;
        s2 = d->mUnk_20;
        d->mUnk_1c = (u8 *) a;
        d->mUnk_20 = n;
        d->mUnk_24 = (u8 *) a + n;
        if (func_0213446c(d, &l) == 0) {
            t += l;
        } else {
            d->mUnk_0d = 1;
            d->mUnk_28 = 0;
        }
        d->mUnk_1c = s1;
        d->mUnk_20 = s2;
        func_02134508(d);
        d->mUnk_28 = 0;
    }
    if (d->mUnk_04_5 != 2) {
        d->mUnk_28 = 0;
    }
    return t / b;
}

void func_0213453c(u8 *a, u32 *b) {}

void func_02134508(Unk0213c94c *a) {
    a->mUnk_24 = a->mUnk_1c;
    a->mUnk_28 = a->mUnk_20;
    a->mUnk_28 = a->mUnk_28 - (a->mUnk_18 & a->mUnk_2c);
    a->mUnk_34 = a->mUnk_18;
}

int func_0213446c(Unk0213c94c *a, u32 *b) {
    int n;
    int r;

    n = a->mUnk_24 - a->mUnk_1c;
    if (n != 0) {
        a->mUnk_28 = n;
        if (a->mUnk_04_12 == 0) {
            func_0213453c(a->mUnk_1c, &a->mUnk_28);
        }
        r = a->mUnk_40(a->mUnk_00, a->mUnk_1c, &a->mUnk_28, a->mUnk_48);
        if (b != 0) {
            *b = a->mUnk_28;
        }
        if (r != 0) {
            return r;
        }
        a->mUnk_18 = a->mUnk_18 + a->mUnk_28;
    }
    func_02134508(a);
    return 0;
}

void func_0213442c(const u8 *a, const u8 *b, const u8 *c, int d) {
    func_02135144((const u8 *) "Assertion (%s) failed in \"%s\", function \"%s\", line %d\n", a, b, c, d);
    func_02133fd8();
}
