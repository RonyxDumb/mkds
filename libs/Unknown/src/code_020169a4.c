#include "code_020169a4.h"

Unk020169a4 *func_02016cd8(Unk020169a4 *p, u32 n) {
    u32 i;
    Unk020169a4 *q;
    u32 m;

    m = n - 1;
    i = 0;
    if (m != 0) {
        q = p;
        do {
            p[i].mUnk_0c = &p[i + 1];
            p[i + 1].mUnk_08 = q;
            i++;
            q++;
        } while (i < m);
    }
    p->mUnk_08 = 0;
    (p + n)[-1].mUnk_0c = 0;
    return p;
}

s32 func_02016c64(Unk020169a4 **a, Unk020169a4 **b, u32 c, u32 d) {
    Unk020169a4 *n;

    n = *b;
    if (n != 0) {
        *b = n->mUnk_0c;
    }
    if (n != 0) {
        n->mUnk_00 = c;
        n->mUnk_04 = d;
        n->mUnk_08 = 0;
        n->mUnk_0c = 0;
        if (*a != 0) {
            (*a)->mUnk_08 = n;
        }
        n->mUnk_0c = *a;
        n->mUnk_08 = 0;
        *a = n;
        return 1;
    }
    return 0;
}

s32 func_02016c44(Unk020169a4 **a, Unk020169a4 **b, u32 *c, u32 d) {
    return func_02016b00(a, b, c, d, 0);
}

s32 func_02016b00(Unk020169a4 **a, Unk020169a4 **b, u32 *c, u32 d, u32 e) {
    u32 addr;
    u32 need;
    u32 pad;
    Unk020169a4 *best;
    Unk020169a4 *n;
    Unk020169a4 *t;
    Unk020169a4 *prev;
    Unk020169a4 *next;

    best = 0;
    for (n = *a; n != 0; n = n->mUnk_0c) {
        if (e > 1) {
            addr = (n->mUnk_00 + (e - 1)) & ~(e - 1);
            pad = addr - n->mUnk_00;
            need = d + pad;
        } else {
            addr = n->mUnk_00;
            pad = 0;
            need = d;
        }
        if (n->mUnk_04 >= need) {
            best = n;
            break;
        }
    }
    if (best == 0) {
        goto fail;
    }
    if (pad != 0) {
        t = *b;
        if (t != 0) {
            *b = t->mUnk_0c;
        }
        if (t == 0) {
            goto fail;
        }
        t->mUnk_00 = best->mUnk_00;
        t->mUnk_04 = pad;
        t->mUnk_08 = 0;
        t->mUnk_0c = 0;
        if (*a != 0) {
            (*a)->mUnk_08 = t;
        }
        t->mUnk_0c = *a;
        t->mUnk_08 = 0;
        *a = t;
    }
    best->mUnk_04 -= need;
    best->mUnk_00 += need;
    if (best->mUnk_04 == 0) {
        prev = best->mUnk_08;
        next = best->mUnk_0c;
        if (prev != 0) {
            prev->mUnk_0c = next;
        } else {
            *a = next;
        }
        if (next != 0) {
            next->mUnk_08 = prev;
        }
        if (*b != 0) {
            (*b)->mUnk_08 = best;
        }
        best->mUnk_0c = *b;
        best->mUnk_08 = 0;
        *b = best;
    }
    *c = addr;
    return 1;
fail:
    *c = 0;
    return 0;
}

s32 func_020169a4(Unk020169a4 **a, Unk020169a4 **b, u32 c, u32 d) {
    u32 r[4];
    u32 *rp;
    Unk020169a4 *n;
    Unk020169a4 *next;
    Unk020169a4 *t;
    Unk020169a4 *prev;

    r[0] = c;
    r[1] = c + d;
    r[2] = c;
    r[3] = c + d;
    rp = r;
    for (n = *a; n != 0; n = next) {
        next = n->mUnk_0c;
        if (n->mUnk_00 == rp[1]) {
            r[3] = n->mUnk_00 + n->mUnk_04;
            prev = n->mUnk_08;
            if (prev != 0) {
                prev->mUnk_0c = next;
            } else {
                *a = next;
            }
            if (next != 0) {
                next->mUnk_08 = prev;
            }
            if (*b != 0) {
                (*b)->mUnk_08 = n;
            }
            n->mUnk_0c = *b;
            n->mUnk_08 = 0;
            *b = n;
        }
        if (n->mUnk_00 + n->mUnk_04 == rp[0]) {
            Unk020169a4 *p2;
            Unk020169a4 *q2;

            r[2] = n->mUnk_00;
            p2 = n->mUnk_08;
            q2 = n->mUnk_0c;
            if (p2 != 0) {
                p2->mUnk_0c = q2;
            } else {
                *a = q2;
            }
            if (q2 != 0) {
                q2->mUnk_08 = p2;
            }
            if (*b != 0) {
                (*b)->mUnk_08 = n;
            }
            n->mUnk_0c = *b;
            n->mUnk_08 = 0;
            *b = n;
        }
    }
    t = *b;
    if (t != 0) {
        *b = t->mUnk_0c;
    }
    if (t == 0) {
        return 0;
    }
    t->mUnk_00 = r[2];
    t->mUnk_04 = r[3] - r[2];
    t->mUnk_08 = 0;
    t->mUnk_0c = 0;
    if (*a != 0) {
        (*a)->mUnk_08 = t;
    }
    t->mUnk_0c = *a;
    t->mUnk_08 = 0;
    *a = t;
    return 1;
}
