#include "00/GameSpy/gt2Utility.h"
#include "00/GameSpy/darray.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/GameSpy/nonport.h"
#include "00/unk_021b4000.h"
#include "00/code_0219b1d4.h"
#include "00/code_0219b1f8.h"
#include "00/code_021a3a18.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b5000.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021a6d5c.h"

Unk0219b1d4 *func_ov000_0219b178(void) {
    Unk0219b1d4 a = {0};

    if (data_ov000_021b52c4 == NULL) {
        data_ov000_021b52c4 = DarrayCreate(0x40, 4, (void (*)(void *)) func_ov000_0219b1d4);
    }
    DarrayAppend(data_ov000_021b52c4, &a);
    return DarrayGetElement(data_ov000_021b52c4, DarrayGetCount(data_ov000_021b52c4) - 1);
}

void func_ov000_0219b130(Unk0219b1d4 *a) {
    s32 b;

    for (b = 0; b < DarrayGetCount(data_ov000_021b52c4); b++) {
        if (a == DarrayGetElement(data_ov000_021b52c4, b)) {
            DarrayRemoveWithoutCallback(data_ov000_021b52c4, b);
            return;
        }
    }
}

void func_ov000_0219b110(void) {
    if (data_ov000_021b52c4 != NULL) {
        DarrayDelete(data_ov000_021b52c4);
        data_ov000_021b52c4 = NULL;
    }
}

BOOL func_ov000_0219b0ec(const u8 *a) {
    if (memcmp(a, data_ov000_021b400c, 6) == 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov000_0219b0b0(u32 a, u32 b, u16 c, void *d, s32 e) {
    Unk021a4654 f;

    f.field1 = 2;
    f.field2 = c >> 8 & 0xff | c << 8 & 0xff00;
    f.field4 = b;
    func_ov000_0218e3e4(a, d, e, 0, &f, 8);
}

u32 func_ov000_0219b05c(void) {
    s32 a;
    u32 *c;
    Unk021a8f84 *d;
    s32 e;

    a = 0;
    d = func_ov000_0218e5e4();
    if (d == NULL) {
        return a;
    }
    e = 0;
    while (1) {
        c = *OFFSET_PTR(u32 *, d->fieldC, e);
        if (c == NULL) {
            break;
        }
        if (*c != 0x0100007f) {
            a = *c;
            if (func_ov000_0218e57c(c) != FALSE) {
                return a;
            }
        }
        e += 4;
    }
    return a;
}

static inline void func_ov000_0219aa64_inline(void *a, const void *b) {
    u8 *p = a;
    const u8 *q = b;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    p[4] = q[4];
    p[5] = q[5];
}

u16 func_ov000_0219b038(u32 a) {
    Unk021a4654 b;
    u32 c;
    s32 d;
    u16 e;

    c = 8;
    d = func_ov000_0218e394(a, &b, &c);
    e = 0;
    if (d != -1) {
        e = b.field2;
    }
    return e;
}

void func_ov000_0219aeb0(Unk0219b1d4 *a) {
    Unk0219aeb0 b;
    u32 c;
    u32 d;
    u32 e;
    u16 f;
    Unk0219aeb0 *g;

    g = (Unk0219aeb0 *) &b;
    g->field0 = *(Unk021b400c *) data_ov000_021b400c;
    g->field6 = 2;
    g->field7 = 0;
    g->fieldD = a->fieldC;
    c = a->field8;
    *(u32 *) g->field8 = (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    c = 0;
    if (a->field4 != -1) {
        c = 1;
    }
    g->fieldE = c;
    c = (func_ov000_0219b05c() << 24 & 0xff000000) |
        ((func_ov000_0219b05c() << 8 & 0xff0000) |
         ((func_ov000_0219b05c() >> 24 & 0xff) | (func_ov000_0219b05c() >> 8 & 0xff00)));
    b.fieldF = c >> 24;
    b.field10 = c >> 16;
    b.field11 = c >> 8;
    b.field12 = c;
    b.field13 = 0;
    b.field14 = 0;
    strcpy(b.field15, data_ov000_021b4d6c);
    d = strlen(data_ov000_021b4d6c) + 0x16;
    if (g->fieldE != 0 && a->field14[0] == 0) {
        g->fieldC = 0;
        func_ov000_0219b0b0(a->field4, data_ov000_021b52c0, 0x6cfd, g, d);
    }
    if (a->field14[1] == 0) {
        g->fieldC = 1;
        func_ov000_0219b0b0(a->mDescriptor, data_ov000_021b52c0, 0x6cfd, g, d);
    }
    if (g->fieldE != 0) {
        e = a->field4;
    } else {
        e = a->mDescriptor;
    }
    f = (func_ov000_0219b038(g->fieldE != 0 ? a->field4 : a->mDescriptor) >> 8 & 0xff) |
        (func_ov000_0219b038(e) << 8 & 0xff00);
    b.field13 = f >> 8;
    b.field14 = f;
    if (a->field14[2] == 0) {
        g->fieldC = 2;
        func_ov000_0219b0b0(a->mDescriptor, data_ov000_021b52bc, 0x6cfd, g, d);
    }
    a->field28 = func_ov000_0218e8c4() + 500;
    a->field24 = 30;
}

void func_ov000_0219ade4(Unk0219b1d4 *a) {
    Unk0219ade4 b;
    u32 c;
    s32 d;

    func_ov000_0219aa64_inline(&b.field0, data_ov000_021b400c);
    b.field6 = 2;
    b.field7 = 7;
    c = a->field8;
    *(u32 *) b.field8 = (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    *(u32 *) b.fieldC = a->field2C;
    *(u16 *) b.field10 = a->field30 >> 8 & 0xff | a->field30 << 8 & 0xff00;
    b.field12 = a->field32;
    b.field13 = a->field10 != 2;
    d = a->field4;
    if (d == -1) {
        d = a->mDescriptor;
    }
    func_ov000_0219b0b0(d, a->field2C, a->field30, &b, 0x14);
    a->field28 = func_ov000_0218e8c4() + 700;
    a->field24 = 12;
    if (a->field32 != 0) {
        a->field33 = 1;
    }
}

u32 func_ov000_0219adb4(const char *a) {
    u32 b;
    Unk021a8f84 *c;

    b = func_ov000_0218e374((u32) a);
    if (b == -1) {
        c = func_ov000_021a8f84(a);
        if (c == NULL) {
            return 0;
        }
        b = **c->fieldC;
    }
    return b;
}

u32 func_ov000_0219ad88(char *a, const char *b) {
    char c[0x80];

    if (a == NULL) {
        snprintf(c, 0x80, data_ov000_021b404c, data_ov000_021b4d6c, b);
        a = c;
    }
    return func_ov000_0219adb4(a);
}

BOOL func_ov000_0219ad20(void) {
    if (data_ov000_021b52c0 == 0) {
        data_ov000_021b52c0 = func_ov000_0219ad88(data_ov000_021b52b8, data_ov000_021b4014);
    }
    if (data_ov000_021b52bc == 0) {
        data_ov000_021b52bc = func_ov000_0219ad88(data_ov000_021b52b4, data_ov000_021b4030);
    }
    if (data_ov000_021b52c0 == 0 || data_ov000_021b52bc == 0) {
        return FALSE;
    }
    return TRUE;
}

s32 func_ov000_0219ac7c(u32 a, u32 b, u32 c, void (*d)(s32 a, void *b), void (*e)(s32 a, s32 b, void *c, void *d),
                        void *f) {
    Unk0219b1d4 *g;

    if (data_ov000_021b4d28 != 1) {
        return 2;
    }
    if (func_ov000_0219ad20() == FALSE) {
        return 3;
    }
    g = func_ov000_0219b178();
    if (g == NULL) {
        return 1;
    }
    g->field4 = a;
    g->fieldC = c;
    g->field8 = b;
    g->field34 = d;
    g->field38 = e;
    g->field3C = f;
    g->mDescriptor = func_ov000_0218e554(2, 2, 0);
    g->field20 = 0;
    g->field32 = 0;
    g->field33 = 0;
    g->field2C = 0;
    g->field30 = 0;
    g->field24 = 0;
    if (g->mDescriptor == -1) {
        func_ov000_0219b130(g);
        return 2;
    }
    func_ov000_0219aeb0(g);
    return 0;
}

void func_ov000_0219ac50(u32 a) {
    Unk0219b1d4 *b;

    b = func_ov000_0219b1f8(a);
    if (b != NULL) {
        if (b->mDescriptor != -1) {
            func_ov000_0218e53c(b->mDescriptor);
        }
        b->mDescriptor = -1;
        b->field10 = 4;
    }
}

void func_ov000_0219ab24(Unk0219b1d4 *a) {
    Unk021a4654 c;
    s32 d;
    s32 f;
    Unk021a4654 h;

    d = 8;
    if (a->field10 == 4) {
        func_ov000_0219b130(a);
        return;
    }
    if (a->mDescriptor != -1) {
        do {
            if (func_ov000_0218e668(a->mDescriptor) == 0) {
                break;
            }
            f = func_ov000_0218e438(a->mDescriptor, data_ov000_021b52c8, 0x200, 0, (u8 *) &c, &d);
            if (f == -1) {
                break;
            }
            func_ov000_0219a7e4(data_ov000_021b52c8, f, &c);
            if (a->field10 == 4) {
                break;
            }
        } while (a->mDescriptor != -1);
    }
    if (a->field10 == 0 || a->field10 == 2) {
        if (func_ov000_0218e8c4() > a->field28) {
            if (a->field20 > a->field24) {
                a->field38(2, -1, NULL, a->field3C);
                func_ov000_0219ac50(a->field8);
            } else {
                a->field20 = a->field20 + 1;
                if (a->field10 == 0) {
                    func_ov000_0219aeb0(a);
                } else {
                    func_ov000_0219ade4(a);
                }
            }
        }
    }
    if (a->field10 == 3) {
        if (func_ov000_0218e8c4() > a->field28) {
            if (a->field4 == -1) {
                h.field1 = 2;
                h.field2 = a->field30 >> 8 & 0xff | a->field30 << 8 & 0xff00;
                h.field4 = a->field2C;
                a->field38(0, a->mDescriptor, &h, a->field3C);
                a->mDescriptor = -1;
            }
            func_ov000_0219ac50(a->field8);
        }
    }
    if (a->field10 == 1) {
        if (func_ov000_0218e8c4() > a->field28) {
            a->field38(1, -1, NULL, a->field3C);
            func_ov000_0219ac50(a->field8);
        }
    }
}

void func_ov000_0219aaec(void) {
    s32 a;

    if (data_ov000_021b52c4 != NULL) {
        for (a = DarrayGetCount(data_ov000_021b52c4) - 1; a >= 0; a--) {
            func_ov000_0219ab24(DarrayGetElement(data_ov000_021b52c4, a));
        }
    }
}

void func_ov000_0219aa64(Unk0219b1d4 *a, Unk021a4654 *b) {
    Unk0219aa64 c;
    u32 d;

    func_ov000_0219aa64_inline(&c.field0, data_ov000_021b400c);
    c.field6 = 2;
    c.field7 = 6;
    c.fieldD = a->fieldC;
    d = a->field8;
    *(u32 *) c.field8 = (d << 24 & 0xff000000) | ((d << 8 & 0xff0000) | ((d >> 24 & 0xff) | (d >> 8 & 0xff00)));
    func_ov000_0219b0b0(a->mDescriptor, b->field4, b->field2 >> 8 & 0xff | b->field2 << 8 & 0xff00, &c, 0x15);
}

void func_ov000_0219a9e4(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c) {
    s32 d;

    if (b->field13 == 0) {
        func_ov000_0219aa64(a, c);
    }
    if (a->field10 < 2) {
        if (b->field13 != 0) {
            d = 3;
            if (b->field13 == 1) {
                d = 1;
            } else if (b->field13 == 2) {
                d = 2;
            }
            a->field38(d, -1, NULL, a->field3C);
            func_ov000_0219ac50(a->field8);
        } else {
            a->field2C = *(u32 *) b->fieldC;
            a->field30 = *(u16 *) b->field10 >> 8 & 0xff | *(u16 *) b->field10 << 8 & 0xff00;
            a->field20 = 0;
            a->field10 = 2;
            a->field34(a->field10, a->field3C);
            func_ov000_0219ade4(a);
        }
    }
}

void func_ov000_0219a958(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c) {
    if (a->field10 >= 2) {
        a->field2C = c->field4;
        a->field30 = c->field2 >> 8 & 0xff | c->field2 << 8 & 0xff00;
        a->field32 = 1;
        if (b->field12 == 0) {
            func_ov000_0219ade4(a);
            return;
        }
        if (a->field10 == 2) {
            if (a->field33 == 0) {
                func_ov000_0219ade4(a);
            }
            a->field10 = 3;
            a->field28 = func_ov000_0218e8c4() + 5000;
            if (a->field4 != -1) {
                a->field38(0, a->field4, c, a->field3C);
            }
        } else if (b->field13 == 0) {
            func_ov000_0219ade4(a);
        }
    }
}

void func_ov000_0219a8bc(Unk0219b1d4 *a, Unk0219aa64 *b, Unk021a4654 *c) {
    u32 d;

    switch (b->field7) {
        case 1:
            d = b->fieldC;
            if (d <= 2) {
                a->field14[d] = 1;
                if (a->field10 == 0 && a->field14[1] != 0 && a->field14[2] != 0 &&
                    (a->field4 == -1 || a->field14[0] != 0)) {
                    a->field10 = 1;
                    a->field28 = func_ov000_0218e8c4() + 10000;
                    a->field34(a->field10, a->field3C);
                }
            }
            break;
        case 2:
            b->field7 = 3;
            func_ov000_0219b0b0(a->mDescriptor, c->field4, c->field2 >> 8 & 0xff | c->field2 << 8 & 0xff00, b, 0x15);
            break;
    }
}

void func_ov000_0219a7e4(u8 *a, s32 b, void *c) {
    Unk0219ade4 d;
    Unk0219aa64 e;
    u32 f;
    u32 g;
    Unk0219b1d4 *h;

    if (func_ov000_0219b0ec(a) != FALSE) {
        f = a[7];
        if (f == 5 || f == 7) {
            if (b >= 0x14) {
                d = *(Unk0219ade4 *) a;
                g = *(u32 *) d.field8;
                h = func_ov000_0219b1f8((g << 24 & 0xff000000) |
                                        ((g << 8 & 0xff0000) | ((g >> 24 & 0xff) | (g >> 8 & 0xff00))));
                if (h != NULL) {
                    if (f == 5) {
                        func_ov000_0219a9e4(h, &d, c);
                    } else {
                        func_ov000_0219a958(h, &d, c);
                    }
                }
            }
        } else if (b >= 0x15) {
            e = *(Unk0219aa64 *) a;
            g = *(u32 *) e.field8;
            h = func_ov000_0219b1f8((g << 24 & 0xff000000) |
                                    ((g << 8 & 0xff0000) | ((g >> 24 & 0xff) | (g >> 8 & 0xff00))));
            if (h != NULL) {
                func_ov000_0219a8bc(h, &e, c);
            }
        }
    }
}

u32 Gt2FormatAddress(u32 a, u32 b, char *c) {
    Unk021b5dfc d;
    char *e;

    e = c;
    if (e == NULL) {
        data_ov000_021b5284 ^= 1;
        e = data_ov000_021b5288[data_ov000_021b5284];
    }
    if (a != 0) {
        d.field0 = a;
        if (b != 0) {
            sprintf(e, data_ov000_021b3ffc, func_ov000_021a8c6c(d), b);
        } else {
            sprintf(e, data_ov000_021b4004, func_ov000_021a8c6c(d));
        }
    } else if (b != 0) {
        sprintf(e, data_ov000_021b4008, b);
    } else {
        e[0] = 0;
    }
    return (u32) e;
}

BOOL Gt2ParseAddress(const char *a, u32 *b, u16 *c) {
    char d[0x100];
    const char *e;
    const char *f;
    s32 g;
    s32 h;
    u32 i;
    u32 j;
    Unk021a8f84 *k;

    if (a == NULL || *(s8 *) a == 0) {
        i = 0;
        j = 0;
    } else {
        e = strchr(a, 0x3a);
        if (e == NULL) {
            j = 0;
        } else {
            if (e == a) {
                a = NULL;
                i = 0;
            } else {
                g = e - a;
                if (g >= 0x100) {
                    __msl_assertion_failed(data_ov000_021b3fcc, data_ov000_021b3fec, NULL, 0x81);
                }
                memcpy(d, a, g);
                d[g] = 0;
                a = d;
            }
            f = e + 1;
            h = *(s8 *) (e + 1);
            if (h != 0) {
                do {
                    if (h < 0 || h >= 0x80) {
                        g = 0;
                    } else {
                        g = data_0215d284[h] & 8;
                    }
                    if (g == 0) {
                        return FALSE;
                    }
                    f++;
                    h = *(s8 *) f;
                } while (h != 0);
            }
            g = StrtolBase10(e + 1);
            if (g < 0 || g > 0xffff) {
                return FALSE;
            }
            j = (u16) g;
        }
        if (a != NULL) {
            i = func_ov000_0218e374((u32) a);
            if (i == -1) {
                k = func_ov000_021a8f84(a);
                if (k == NULL) {
                    return FALSE;
                }
                i = **k->fieldC;
            }
        }
    }
    if (b != NULL) {
        *b = i;
    }
    if (c != NULL) {
        *c = j;
    }
    return TRUE;
}
