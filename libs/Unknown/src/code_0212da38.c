#include "code_0212da38.h"
#include "code_020207ec.h"
#include "code_0212d254.h"
#include "code_0212d968.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_02020000.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_020219b0.h"
#include "code_02017f24.h"

void func_0212df28(void *buf, u32 size, void *p, u32 idx) {
    u8 *q = buf;

    if (q == func_02021968(p, idx)) {
        func_020219b0(p, idx, 0);
    }
    func_02020990(q, q + size);
}

u32 func_0212de34(Unk02021968 *a, u32 b, u32 c, Unk0212d9dc *d) {
    u32 *e;
    u32 n;
    u32 end;
    u32 size;
    u32 start;
    void *buf;

    if (func_02021968(a, b) != 0) {
        return 1;
    }
    n = func_020219e8(a);
    e = (u32 *) a + (a->mUnk_38 + b);
    start = e[15];
    end = b < n - 1 ? e[16] : a->mUnk_08;
    size = end - start;
    if (d == 0) {
        return 0;
    }
    buf = func_0212db7c(d, size + 32, func_0212df28, a, b);
    if (buf == 0) {
        return 0;
    }
    if (func_0212d27c(c, buf, size, start) != size) {
        return 0;
    }
    func_0200ee58(buf, size);
    func_020219b0(a, b, buf);
    return 1;
}

u32 func_0212dd64(Unk02021968 *a, Unk02021968 *b, u32 c, u32 d, Unk0212d9dc *e) {
    Unk02021bc8 it;
    Unk02021bc8 init;
    Unk020219f0 rec;

    func_02021bc8(&init);
    it = init;
    if (b == 0) {
        return 0;
    }
    if (func_020219f0(b, &rec, &it) != 0) {
        do {
            if (rec.mUnk_00 == 1 && c == rec.mUnk_04) {
                if (func_0212de34(a, rec.mUnk_02, d, e) == 0) {
                    return 0;
                }
            }
        } while (func_020219f0(b, &rec, &it) != 0);
    }
    return 1;
}

Unk0212d9dc *func_0212dcc8(void *base, u32 size) {
    Unk0212d9dc *a;
    void *p;
    u32 end;
    u32 n;

    end = (u32) base + size;
    a = (Unk0212d9dc *) (((u32) base + 3) & ~3);
    if ((u32) a > end) {
        return 0;
    }
    n = end - (u32) a;
    if (n < 16) {
        return 0;
    }
    p = func_020180e0(a + 1, n - 16, 0);
    if (p == 0) {
        return 0;
    }
    if (func_0212d9dc(a, p) != 0) {
        return a;
    }
    func_020180d4(p);
    return 0;
}

void func_0212dcac(Unk0212d9dc *a) {
    func_0212dbec(a);
    func_020180d4(a->mUnk_00);
}

void func_0212dbec(Unk0212d9dc *a) {
    Unk02017328 *e;
    void *node;
    u32 flag = 0;

    for (e = func_02017328(&a->mUnk_04, 0); e != 0; e = func_02017328(&a->mUnk_04, 0)) {
        for (node = func_02017328(e, 0); node != 0; node = func_02017328(e, node)) {
            Unk0212db7c *n = node;

            if (n->mUnk_0c != 0) {
                n->mUnk_0c(n + 1, n->mUnk_08, n->mUnk_10, n->mUnk_14);
                flag = 1;
            }
        }
        func_02017354(&a->mUnk_04, e);
    }
    func_0201804c(a->mUnk_00, 3);
    if (flag != 0) {
        func_0212d968();
    }
    func_0212d98c(a);
}

void *func_0212db7c(Unk0212d9dc *a, u32 size, UnkFunc *f, void *p, u32 v) {
    Unk0212db7c *n;
    Unk02017328 *e;

    n = func_0201808c(a->mUnk_00, ((size + 31) & ~31) + 32, 32);
    if (n == 0) {
        return 0;
    }
    e = func_02017328(&a->mUnk_04, 0);
    n->mUnk_08 = size;
    n->mUnk_0c = f;
    n->mUnk_10 = p;
    n->mUnk_14 = v;
    func_020174a4(e, n);
    return n + 1;
}

s32 func_0212db24(Unk0212d9dc *a) {
    if (func_02017fb4(a->mUnk_00, a->mUnk_04.mUnk_08) == 0) {
        return -1;
    }
    if (func_0212d98c(a) != 0) {
        return a->mUnk_04.mUnk_08 - 1;
    }
    func_02017f58(a->mUnk_00, 0);
    return -1;
}

void func_0212da38(Unk0212d9dc *a, s32 n) {
    Unk02017328 *e;
    void *node = 0;
    u32 flag = 0;

    if (n == 0) {
        func_0212dbec(a);
        return;
    }
    if (n < a->mUnk_04.mUnk_08) {
        do {
            e = func_02017328(&a->mUnk_04, 0);
            for (node = func_02017328(e, node); node != 0; node = func_02017328(e, node)) {
                Unk0212db7c *p = node;

                if (p->mUnk_0c != 0) {
                    p->mUnk_0c(p + 1, p->mUnk_08, p->mUnk_10, p->mUnk_14);
                    flag = 1;
                }
            }
            func_02017354(&a->mUnk_04, e);
        } while (n < a->mUnk_04.mUnk_08);
    }
    func_02017f58(a->mUnk_00, n);
    if (flag != 0) {
        func_0212d968();
    }
    func_02017fb4(a->mUnk_00, a->mUnk_04.mUnk_08);
    func_0212d98c(a);
}
