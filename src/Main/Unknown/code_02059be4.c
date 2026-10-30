#include "Main/Unknown/code_02059be4.h"
#include "Main/Unknown/code_02004d80.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205a4e8.h"
#include "Main/Unknown/code_0205a534.h"
#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "02/unk_02180500.h"
#include "code_02004270.h"
#include "code_02004dc0.h"
#include "code_020176c0.h"
#include "code_02017f24.h"

void func_02059be4(void) {
    func_0202a658(func_020364e0(func_020364e8()));
}

u32 func_02059c04(struct Unk021000d0 *a) {
    u32 r;

    r = 0;
    if ((u32) a >= data_0217aa10->mUnk_a8) {
        if ((u32) a <= data_0217aa10->mUnk_ac) {
            r = 1;
        }
    }
    return r;
}

void func_02059c34(void) {
    if (data_0217aa10->mUnk_04 != 1 && data_0217aa10->mUnk_04 != 2) {
        return;
    }
    if (func_02005144(0, data_0217aa10->mUnk_08[data_0217aa10->mUnk_00].mUnk_00) == 0) {
        return;
    }
    data_0217aa10->mUnk_00 = 4;
    data_0217aa10->mUnk_04 = 0;
    if (data_0217aa10->mUnk_a4 != 0) {
        func_0201797c(data_0217aa10->mUnk_a4);
        data_0217aa10->mUnk_a4 = 0;
    }
}

s32 func_02059ce8(void) {
    enum { K0 } r;
    s32 v;
    Unk0217aa10 *p;

    r = 0;
    p = data_0217aa10;
    v = p->mUnk_04;
    if (v == 2) {
        return 1;
    }
    if (v != 1) {
        return r;
    }
    if (p->mUnk_58.mUnk_0c & 1) {
        v = 1;
    } else {
        v = r;
    }
    if (v != 0) {
        return r;
    }
    func_02005314(&p->mUnk_2c);
    func_020049e8(&data_0217aa10->mUnk_58);
    data_0217aa10->mUnk_04 = 2;
    return 1;
}

void func_02059d80(void) {
    if (data_0217aa10->mUnk_a4 == 0) {
        return;
    }
    func_0201797c(data_0217aa10->mUnk_a4);
    data_0217aa10->mUnk_a4 = 0;
}

void func_02059dc8(void) {
    if (data_0217aa10->mUnk_00 != 1) {
        return;
    }
    data_0217aa10->mUnk_a4 = func_02017988(data_ov002_021a9c00, 0x20800, 1);
}

// non-matching: same instructions and registers, but the original loads the address of data_0217aa10 first and then
// sets the constants 1, 2 and 0 (r4, r7, r5); here 1 and 0 come first, then the address, then 2.
void func_02059e1c(void) {
    enum { K0 } z;
    enum { K1 } o;
    s32 r;
    s32 v;

    o = 1;
    z = 0;
    do {
        r = z;
        v = data_0217aa10->mUnk_04;
        if (v == 2) {
            r = o;
        } else if (v == 1) {
            if (((data_0217aa10->mUnk_58.mUnk_0c & 1) ? o : z) == 0) {
                func_02005314(&data_0217aa10->mUnk_2c);
                func_020049e8(&data_0217aa10->mUnk_58);
                data_0217aa10->mUnk_04 = 2;
                r = o;
            }
        }
    } while (r == 0);
}

void func_02059ea4(s32 a) {
    Unk0217aa10 *p;
    s32 v;
    s32 s;

    p = data_0217aa10;
    v = p->mUnk_00;
    if (v == a) {
        return;
    }
    s = p->mUnk_04;
    switch (s) {
        case 0:
            func_020055f0(&p->mUnk_2c, 0, p->mUnk_08[a].mUnk_00);
            func_02004d80(&data_0217aa10->mUnk_58);
            func_02005558(&data_0217aa10->mUnk_2c, &data_0217aa10->mUnk_58);
            data_0217aa10->mUnk_04 = 1;
            data_0217aa10->mUnk_00 = a;
            break;
        case 1:
            break;
        case 2:
            switch (s) {
                case 1:
                case 2:
                    if (func_02005144(0, p->mUnk_08[v].mUnk_00) != 0) {
                        data_0217aa10->mUnk_00 = 4;
                        data_0217aa10->mUnk_04 = 0;
                        if (data_0217aa10->mUnk_a4 != 0) {
                            func_0201797c(data_0217aa10->mUnk_a4);
                            data_0217aa10->mUnk_a4 = 0;
                        }
                    }
                    break;
            }
            func_020055f0(&data_0217aa10->mUnk_2c, 0, data_0217aa10->mUnk_08[a].mUnk_00);
            func_02004d80(&data_0217aa10->mUnk_58);
            func_02005558(&data_0217aa10->mUnk_2c, &data_0217aa10->mUnk_58);
            data_0217aa10->mUnk_04 = 1;
            data_0217aa10->mUnk_00 = a;
            break;
        case 3:
            switch (s) {
                case 1:
                case 2:
                    if (func_02005144(0, p->mUnk_08[v].mUnk_00) != 0) {
                        data_0217aa10->mUnk_00 = 4;
                        data_0217aa10->mUnk_04 = 0;
                        if (data_0217aa10->mUnk_a4 != 0) {
                            func_0201797c(data_0217aa10->mUnk_a4);
                            data_0217aa10->mUnk_a4 = 0;
                        }
                    }
                    break;
            }
            func_020055f0(&data_0217aa10->mUnk_2c, 0, data_0217aa10->mUnk_08[a].mUnk_00);
            func_02004d80(&data_0217aa10->mUnk_58);
            func_02005558(&data_0217aa10->mUnk_2c, &data_0217aa10->mUnk_58);
            data_0217aa10->mUnk_04 = 1;
            data_0217aa10->mUnk_00 = a;
            break;
    }
}

void func_0205a0e4(void) {
    data_0217aa10->mUnk_00 = 4;
    data_0217aa10->mUnk_04 = 0;
}

void func_0205a108(void) {
    data_0217aa10->mUnk_a0 = func_020180e0(data_ov002_02180500, 0x50000, 0);
}

// non-matching: the original loads the three entry values 0, 1 and 2 from words after the function (no relocation)
// where this uses mov, so it is 0x14 bytes longer and the loads around them move; the rest is the same.
void func_0205a140(void *a) {
    Unk0217aa10_08 *e;

    data_0217aa10 = func_02036bec(a, 0xb0);
    data_0217aa10->mUnk_a8 = -1;
    data_0217aa10->mUnk_ac = 0;
    data_0217aa10->mUnk_08[0].mUnk_00 = 0;
    e = &data_0217aa10->mUnk_08[0];
    e->mUnk_04 = 0x021804c0;
    e->mUnk_08 = (u32) data_ov002_021b7ba0;
    if (e->mUnk_04 < data_0217aa10->mUnk_a8) {
        data_0217aa10->mUnk_a8 = e->mUnk_04;
    }
    if (e->mUnk_08 > data_0217aa10->mUnk_ac) {
        data_0217aa10->mUnk_ac = e->mUnk_08;
    }
    data_0217aa10->mUnk_08[1].mUnk_00 = 1;
    e = &data_0217aa10->mUnk_08[1];
    e->mUnk_04 = 0x021804c0;
    e->mUnk_08 = (u32) data_ov002_021ca440;
    if (e->mUnk_04 < data_0217aa10->mUnk_a8) {
        data_0217aa10->mUnk_a8 = e->mUnk_04;
    }
    if (e->mUnk_08 > data_0217aa10->mUnk_ac) {
        data_0217aa10->mUnk_ac = e->mUnk_08;
    }
    data_0217aa10->mUnk_08[2].mUnk_00 = 2;
    e = &data_0217aa10->mUnk_08[2];
    e->mUnk_04 = 0x021804c0;
    e->mUnk_08 = 0x021d04e0;
    if (e->mUnk_04 < data_0217aa10->mUnk_a8) {
        data_0217aa10->mUnk_a8 = e->mUnk_04;
    }
    if (e->mUnk_08 > data_0217aa10->mUnk_ac) {
        data_0217aa10->mUnk_ac = e->mUnk_08;
    }
    data_0217aa10->mUnk_a0 = 0;
    data_0217aa10->mUnk_a4 = 0;
}

s32 func_0205a2ac(s32 a) {
    s32 r;
    s32 f;

    r = 0x13;
    f = 0;
    if ((u16) (data_0217aa14->mUnk_104[a].mUnk_74 + 0xffff) <= 1) {
        f = 1;
    }
    if (f == 0) {
        r = data_0217aa14->mUnk_104[a].mUnk_68;
    }
    return r;
}

s32 func_0205a310(s32 a) {
    s32 r;
    Unk0217aa14_104 *e;

    e = &data_0217aa14->mUnk_104[a];
    r = 0;
    if ((u16) (e->mUnk_74 + 0xffff) <= 1) {
        r = 1;
    }
    return r;
}

void func_0205a350(void) {
    u8 i;
    Unk0217aa14_104_68 *p;
    s32 d;
    Unk0217aa14_104_20 *h;

    for (i = 0; i < 4; i++) {
        if (func_0205a50c(i) != 0) {
            p = &data_0217aa14->mUnk_104[i].mUnk_68_view;
            h = func_0205a4e8(i, i);
            switch (p->mUnk_0c) {
                case 0:
                    if (h->mUnk_00_12 == 2) {
                        func_0205a71c(i);
                        func_0205a4b0(p, h->mUnk_00_7);
                    }
                    break;
                case 2:
                    d = p->mUnk_08 - data_0217aa14->mUnk_728;
                    if ((s32) p->mUnk_0e < 100) {
                        func_0205a7dc(i, d, p->mUnk_00, 2);
                        p->mUnk_0e = p->mUnk_0e + 1;
                    } else if (d > 20) {
                        func_0205a7dc(i, d, p->mUnk_00, 2);
                    } else {
                        func_0205a7ac(i);
                        if (d <= 0) {
                            p->mUnk_0c = 3;
                        }
                    }
                    break;
                case 3:
                    func_0205a534(p);
                    break;
                case 4:
                    if (h->mUnk_00_12 != 2) {
                        p->mUnk_0c = 0;
                    }
                    break;
            }
        }
    }
}

void func_0205a4b0(Unk0217aa14_104_68 *a, s32 b) {
    s32 t;

    a->mUnk_0e = 0;
    t = data_0217aa14->mUnk_728;
    a->mUnk_0c = 2;
    a->mUnk_00 = b;
    a->mUnk_08 = t + 0x78;
    a->mUnk_04 = 0x13;
}
