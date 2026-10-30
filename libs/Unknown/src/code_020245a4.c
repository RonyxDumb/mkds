#include "code_020245a4.h"
#include "code_0200fd1c.h"

void func_020245a4(Unk02021f9c *a) {
    Unk02021fd0 *p;
    s32 i;
    Unk020245a4_08 *q;

    p = (Unk02021fd0 *) ((u8 *) a + a->mUnk_0c);
    for (i = 0; i < a->mUnk_0e; i++) {
        switch (p->mUnk_00) {
            case 0x46494e46:
                q = (Unk020245a4_08 *) (p + 1);
                q->mUnk_08 += (u32) a;
                if (q->mUnk_0c != 0) {
                    q->mUnk_0c += (u32) a;
                }
                if (q->mUnk_10 != 0) {
                    q->mUnk_10 += (u32) a;
                }
                break;
            case 0x43574448:
                q = (Unk020245a4_08 *) (p + 1);
                if (q->mUnk_04 != 0) {
                    q->mUnk_04 += (u32) a;
                }
                break;
            case 0x434d4150:
                q = (Unk020245a4_08 *) (p + 1);
                if (q->mUnk_08 != 0) {
                    q->mUnk_08 += (u32) a;
                }
                break;
            case 0x43474c50:
                break;
        }
        p = (Unk02021fd0 *) ((u8 *) p + p->mUnk_04);
    }
}

// non-matching: 62.5%, the repeated null and tag checks are written as plain conditions and compile differently
u32 func_0202469c(Unk02021f9c *a, Unk02022ce4 **b) {
    u32 r;
    Unk02021fd0 *p;
    s32 ok;

    ok = 0;
    if (a != 0 && a->mUnk_00 == 0x4e465452) {
        if (a != 0 && a->mUnk_06 == 0x100) {
            ok = 1;
        }
    }
    if (ok) {
        r = 0;
    } else {
        ok = 0;
        if (a != 0 && a->mUnk_00 == 0x4e465452) {
            if (a != 0 && a->mUnk_06 == 1) {
                ok = 1;
            }
        }
        if (ok) {
            r = 1;
        } else {
            func_0200fd1c();
        }
    }
    func_020245a4(a);
    p = func_02021fd0(a, 0x46494e46);
    if (p == 0) {
        *b = 0;
        return 0;
    }
    *b = (Unk02022ce4 *) (p + 1);
    if (r != 0) {
        (*b)->mUnk_07 = (*b)->mUnk_04.mUnk_02;
        (*b)->mUnk_04.mUnk_02 = 0;
    }
    return r + 1;
}

// non-matching: 82.6%, register use and the order of the shifts differ
u32 func_020247fc(Unk020247fc *a, s32 b) {
    s32 n;
    u32 c;
    u32 r;
    u8 *p;

    n = a->mUnk_04;
    c = a->mUnk_05;
    if (n >= b) {
        a->mUnk_04 = n - b;
        r = c >> (n - b);
    } else {
        p = a->mUnk_00;
        a->mUnk_00 = p + 1;
        r = c << (b - n);
        a->mUnk_05 = *p;
        a->mUnk_04 = 8;
        r = func_020247fc(a, b - n) | r;
    }
    return r & (0xff >> (8 - b));
}

u16 func_02024868(u8 **a) {
    u8 *p;
    u8 c;

    p = *a;
    c = *p++;
    *a = p;
    return c;
}

u16 func_0202487c(u8 **a) {
    u16 c;
    u8 *p;

    p = *a;
    c = *p;
    if ((c >= 0x81 && c < 0xa0) || c >= 0xe0) {
        c = p[1] | (c << 8);
        *a = *a + 2;
    } else {
        *a = *a + 1;
    }
    return c;
}

u16 func_020248d0(u8 **a) {
    u8 *p;
    u16 c;

    p = *a;
    c = *p;
    if ((c & 0x80) == 0) {
        *a = p + 1;
    } else if ((c & 0xe0) == 0xc0) {
        c = ((c & 0x1f) << 6) | (p[1] & 0x3f);
        *a = p + 2;
    } else {
        c = ((c & 0x1f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f);
        *a = p + 3;
    }
    return c;
}

u16 func_02024960(u16 **a) {
    u16 *p;
    u16 c;

    p = *a;
    c = *p++;
    *a = p;
    return c;
}
