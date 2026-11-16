#include "00/code_02188720.h"
#include "00/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/code_02188008.h"
#include "00/code_02188694.h"
#include "00/code_02189478.h"
#include "00/code_0218a658.h"
#include "00/code_0218a000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218a67c.h"
#include "00/code_021892f4.h"
#include "code_0200fc8c.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_021519a8.h"

void func_ov000_02188d78(Unk02188d78 *p) {
    Unk02188408 *s;

    s = (Unk02188408 *) func_ov000_02188584(0x10);
    if (p->field0 == 5) {
        if (p->field2 != 0) {
            switch (p->field8) {
                case 0xd:
                    s->fieldD14 = 1;
                    break;
                case 0xf:
                    s->fieldD14 = 2;
                    break;
                case 0x11:
                    s->fieldD14 = 3;
                    break;
                default:
                    s->fieldD14 = 4;
                    break;
            }
        }
    } else if (p->field0 == 7) {
        func_ov000_02188ca8(p->field4);
    }
}

void func_ov000_02188ca8(Unk02188408Entry0xc0 *p) {
    Unk02188408 *s;
    s32 r;
    u32 a;

    r = -1;
    s = (Unk02188408 *) func_ov000_02188584(0x10);
    ((Unk021884e4 *) func_ov000_02188584(1))->fieldB = 1;
    a = func_ov000_02188528();
    switch (a) {
        case 3:
            if (p->fieldA == 0 || p->fieldC[0] == 0) {
                func_ov000_02189e54(p->field36);
            } else if (p->fieldA == 1 || p->fieldC[0] == 0x20) {
                func_ov000_02189e54(p->field36);
                r = func_ov000_02188bc0(p, s->fieldD10, s->field300);
            } else {
                r = func_ov000_02188bc0(p, s->fieldD10, s->field300);
            }
            break;
        case 4:
        case 5:
            r = func_ov000_02188bc0(p, 1, s->field300 + s->fieldD0F);
            if (r >= 0) {
                s->field300[s->fieldD0F].field0 = (s->field300[s->fieldD0F].field0 & ~0xf) | 1;
            }
            break;
        default:
            return;
    }
    if (r >= 0) {
        func_ov000_021889b0(func_ov000_02188b20(r, p, s), s);
    }
}

s32 func_ov000_02188c1c(Unk02188408Entry0xc0 *p) {
    Unk02188408 *s;
    u8 f;

    s = (Unk02188408 *) func_ov000_02188584(0x10);
    if (s->fieldD0C_0 == 0 || s->fieldD0C_0 == 4) {
        f = p->field2C >> 4 & 1;
        if (f == 1) {
            if (func_ov000_0218a658((const u8 *) p->fieldC) == 1) {
                return 6;
            }
        }
    }
    if (s->fieldD0C_0 == 0 || s->fieldD0C_0 == 5) {
        f = p->field2C >> 4 & 1;
        if (f == 1) {
            if (func_ov000_0218a6c8((const u8 *) p->fieldC) == 1) {
                return 7;
            }
        }
    }
    return -1;
}

s32 func_ov000_02188bc0(Unk02188408Entry0xc0 *p, s32 n, Unk02188408Entry24 *t) {
    s32 i;
    s32 r;
    u16 h;

    if (p->fieldA == 0x20) {
        r = func_ov000_02188c1c(p);
        if (r > 0) {
            return r;
        }
    }
    i = 0;
    if (n > 0) {
        h = p->fieldA;
        do {
            if ((u8) h == t->field3) {
                if (strncmp(p->fieldC, t->field4, h) == 0) {
                    return t->field1;
                }
            }
            t++;
            i++;
        } while (i < n);
    }
    return -1;
}

s32 func_ov000_02188b20(u32 a, Unk02188408Entry0xc0 *p, Unk02188408 *s) {
    s32 i;
    s32 r;
    char *e;
    s32 n;

    i = 0;
    r = -1;
    n = s->fieldD12;
    if (n > 0) {
        e = s->field470[0].field4;
        do {
            if (p->field4[0] == e[0] && p->field4[1] == e[1] && p->field4[2] == e[2] && p->field4[3] == e[3] &&
                p->field4[4] == e[4] && p->field4[5] == e[5]) {
                r = i;
                break;
            }
            e += 0xc0;
            i++;
        } while (i < s->fieldD12);
    }
    if (r == -1) {
        func_ov000_02188ad4(a, p, s);
        if (s->fieldD12 < 10) {
            s->fieldD12++;
        }
        r = 10;
    } else {
        func_ov000_02188a74(r, p, s);
    }
    return r;
}

void func_ov000_02188ad4(u8 a, Unk02188408Entry0xc0 *p, Unk02188408 *s) {
    Unk02188408Entry4 *t;
    Unk02188408Entry0xc0 *e;
    u16 h;

    t = &s->field444[10];
    e = &s->field470[10];
    t->field1 = a;
    h = p->field2;
    t->field2 = (h & 2) != 0 ? (u8) (h >> 2) : (u8) ((h >> 2) + 0x19);
    t->field3 = s->fieldD11 + 1;
    MIi_CpuCopy32(p, e, 0xc0);
}

void func_ov000_02188a74(u32 a, Unk02188408Entry0xc0 *p, Unk02188408 *s) {
    Unk02188408Entry4 *t;
    Unk02188408Entry0xc0 *e;
    u16 h;
    u8 v;
    s32 x;

    t = &s->field444[a];
    e = &s->field470[a];
    h = p->field2;
    x = (h & 2) != 0 ? (u8) (h >> 2) : (u8) ((h >> 2) + 0x19);
    v = x;
    if (v > t->field2) {
        t->field2 = v;
        t->field3 = s->fieldD11 + 1;
    }
    MIi_CpuCopy32(p, e, 0xc0);
}

void func_ov000_021889b0(u32 a, Unk02188408 *s) {
    Unk02188408Entry4 *t;
    Unk02188408Entry0xc0 *e;
    Unk02188408Entry4 *u;
    Unk02188408Entry0xc0 *w;
    Unk02188408Entry4 x;
    Unk02188408Entry0xc0 y;
    s32 i;

    t = s->field444;
    e = s->field470;
    i = a - 1;
    if (i >= 0) {
        u = &t[i];
        w = &e[i];
        do {
            if (t[a].field2 < u->field2) {
                break;
            }
            MIi_CpuCopy32(u, &x, 4);
            MIi_CpuCopy32(&t[a], u, 4);
            MIi_CpuCopy32(&x, &t[a], 4);
            MIi_CpuCopy32(w, &y, 0xc0);
            MIi_CpuCopy32(&e[a], w, 0xc0);
            MIi_CpuCopy32(&y, &e[a], 0xc0);
            a = i;
            u--;
            w--;
            i--;
        } while (i >= 0);
    }
    t += 10;
    func_0214d018_inline(t, 4);
    func_0214d018_inline(e + 10, 0xc0);
}

u32 func_ov000_02188868(Unk02188868 *p) {
    Unk021884e4 *z;
    Unk02188408 *q;
    Unk02188114 *y;
    s32 r;

    data_ov000_021b4d10 = p->field0(1, 0x18);
    func_0214d018_inline(data_ov000_021b4d10, 0x18);
    z = data_ov000_021b4d10;
    z->field0 = p->field0;
    z->field4 = p->field4;
    z->field9 = 1;
    z->field16 = 1;
    z->field8 = 1;
    data_ov000_021b4d00 = func_ov000_021886c4(0x10, 0xd18);
    data_ov000_021b4d04 = func_ov000_021886c4(2, 0x2300);
    data_ov000_021b4d08 = func_ov000_021886c4(4, 0x58);
    data_ov000_021b4d0c = func_ov000_021886c4(8, 0xc);
    func_0214d018_inline(data_ov000_021b4d00, 0xd18);
    func_0214d018_inline(data_ov000_021b4d04, 0x2300);
    func_0214d018_inline(data_ov000_021b4d08, 0x58);
    func_0214d018_inline(data_ov000_021b4d0c, 0xc);
    q = data_ov000_021b4d00;
    q->fieldD0A = p->field8;
    q->fieldD0B_0 = p->field9;
    y = data_ov000_021b4d0c;
    y->mAlloc = p->field0;
    y->mFree = p->field4;
    y->field8 = 0;
    q->fieldD0C_0 = p->fieldA;
    q->fieldD0C_4 = p->fieldB;
    DWCi_BM_GetApInfo(q);
    r = func_ov000_021a6470(data_ov000_021b4d04, 0x2300);
    if (r == 1 || r >= 4) {
        func_ov000_021885ec();
        return 0;
    }
    return 1;
}

s32 func_ov000_021887cc(void) {
    u8 a;
    u32 b;
    s32 c;

    a = func_ov000_02188528();
    if (a == 1) {
        a = func_ov000_02189f00();
    } else if (a < 7) {
        b = OS_DisableInterrupts();
        a = ((u8(*)(void)) func_ov000_02189e80)();
        func_ov000_02188534(a);
        OS_RestoreInterrupts(b);
    } else if (a < 9) {
        a = ((u8(*)(void)) func_ov000_0218922c)();
    } else if (a < 10) {
        a = ((u8(*)(void)) func_ov000_021897bc)();
    } else if (a < 16) {
        a = ((u8(*)(void)) func_ov000_0218a294)();
    } else if (a == 17) {
        a = func_ov000_021894c0();
    }
    func_ov000_02188534(a);
    if (a == 16) {
        c = func_ov000_02188408();
        func_ov000_021884a8();
        return c;
    }
    if (a == 18) {
        func_ov000_021884a8();
        return -1;
    }
    return 0;
}

u32 func_ov000_02188758(void) {
    u32 a;

    a = func_ov000_02188528();
    if (a <= 1) {
        return 0;
    }
    if (a < 7) {
        return 1;
    }
    if (a == 9) {
        return 4;
    }
    if (a < 10) {
        return 2;
    }
    if (a == 11) {
        return 4;
    }
    if (a < 16) {
        return 3;
    }
    if (a == 16) {
        return 5;
    }
    if (a == 17) {
        return 4;
    }
    return func_ov000_02189478();
}

u32 func_ov000_02188720(void) {
    u8 a;

    a = func_ov000_02188528();
    if (a == 0 || a == 0x12) {
        func_ov000_021885ec();
        return 1;
    }
    func_ov000_021892f4(&a);
    func_ov000_02188534(a);
    return 0;
}
