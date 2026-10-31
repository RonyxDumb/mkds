#include "00/code_02186d7c.h"
#include "00/code_02186000.h"
#include "00/code_02186a38.h"
#include "00/code_02186a84.h"
#include "00/code_02187230.h"
#include "00/code_021a9200.h"
#include "00/code_021ab548.h"
#include "00/code_021ae258.h"
#include "00/code_021ae304.h"
#include "00/code_021b0014.h"
#include "00/code_02187274.h"
#include "code_0200d118.h"
#include "code_0200dc3c.h"
#include "code_0200e904.h"
#include "code_0200f5ac.h"
#include "code_0200fe7c.h"
#include "code_0213a460.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_021ae2f4.h"
#include "00/code_021adb80.h"
#include "00/code_02186a10.h"

void func_ov000_02186d7c(void *param_0) {
    Unk02186d7c *p = param_0;
    Unk02186d7cB4 *a;
    Unk02186d7c118 *b;
    Unk02186d7cBuf *c;
    const u8 *x;
    s32 d;
    int g;
    u64 t0;
    u64 t1;
    u8 f;
    int h;
    u32 m;
    s32 r;
    u64 t;
    s8 *q;
    s8 e;
    s32 n;
    Unk0201000c v1;
    u8 *s;
    const u8 *y;

    f = 0;
    a = &p->mUnk_b4;
    b = &p->mUnk_118;
    c = &p->mUnk_938;
    d = p->mUnk_04.mUnk_1c;
    if (d <= 0) {
        d = 60000;
    }
    func_0214d168(a, 0, 0x64);
    a->mUnk_3c = 0xb68;
    a->mUnk_40 = p->mUnk_91c;
    a->mUnk_48 = 0x5ea;
    a->mUnk_4c = p->mUnk_920;
    func_ov000_021ae304((void *) a);
    g = func_ov000_021acef8((const char *) p->mUnk_a8);
    if (g == 0) {
        p->mUnk_24 = 2;
        return;
    }
    func_ov000_021ae270();
    if (p->mUnk_b0 == 1) {
        func_0214d168(b, 0, 0x804);
        b->mUnk_7e4 = func_ov000_02186a84;
        b->mUnk_7d4 = p->mUnk_a8;
        a->mUnk_0c = b;
        func_ov000_021ab594((u32) data_ov000_021b1204, 0xb);
        func_ov000_021a9200(1);
        h = 0x1bb;
    } else {
        h = 0x50;
    }
    func_ov000_021ae290(0, h, g);
    t0 = func_0200f5ac();
    if (p->mUnk_b0 == 1) {
        func_0201000c(&v1);
        func_ov000_021a9c5c(&v1, 0x20);
        t1 = t0;
    }
    if (func_ov000_021ae134() != 0) {
        p->mUnk_24 = 3;
        func_ov000_021ae258();
        func_ov000_021ae2f4();
        return;
    }
    p->mUnk_928.mUnk_04 = p->mUnk_928.mUnk_00;
    s = p->mUnk_928.mUnk_00;
    p->mUnk_928.mUnk_08 = s + func_0213a434(s);
    while (p->mUnk_928.mUnk_04 < p->mUnk_928.mUnk_08) {
        if (data_ov000_021b63b4 == 0) {
            p->mUnk_24 = 5;
            goto fail;
        }
        n = p->mUnk_928.mUnk_08 - p->mUnk_928.mUnk_04;
        if (n > 0x238) {
            n = 0x238;
        }
        n = func_ov000_021adbf4(p->mUnk_928.mUnk_04, n);
        if (n <= 0) {
            p->mUnk_24 = 5;
            goto fail;
        }
        func_ov000_021adb80();
        t = func_0200f5ac();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mUnk_24 = 4;
            goto fail;
        }
        if (p->mUnk_b0 == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                func_0201000c(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        p->mUnk_928.mUnk_04 += n;
        if (func_ov000_02187230((int) p) == 0) {
            p->mUnk_24 = 7;
            goto fail;
        }
    }
    func_ov000_02186a10((Unk021868d0 *) p, (Unk02186998 *) &p->mUnk_928);
    func_0200ed34(&p->mUnk_948);
    if (p->mUnk_04.mUnk_08 == 0) {
        if (func_ov000_02186a38((Unk021868d0 *) p, (Unk02186998 *) &p->mUnk_938, p->mUnk_04.mUnk_0c) == 0) {
            p->mUnk_24 = 1;
            func_0200ecc4(&p->mUnk_948);
            goto fail;
        }
    } else {
        p->mUnk_938.mUnk_00 = p->mUnk_04.mUnk_08;
        p->mUnk_938.mUnk_04 = p->mUnk_938.mUnk_00;
        p->mUnk_938.mUnk_08 = p->mUnk_938.mUnk_00 + p->mUnk_04.mUnk_0c;
        p->mUnk_938.mUnk_0c = p->mUnk_04.mUnk_0c;
    }
    c->mUnk_04 = c->mUnk_00;
    c->mUnk_08 = c->mUnk_00 + c->mUnk_0c;
    func_0200ecc4(&p->mUnk_948);
    while (1) {
        if (data_ov000_021b63b4 == 0) {
            p->mUnk_24 = 5;
            goto fail;
        }
        func_0200ed34(&p->mUnk_948);
        if (c->mUnk_04 >= c->mUnk_08 - 1) {
            func_0200ecc4(&p->mUnk_948);
            goto done;
        }
        n = func_ov000_021adbac();
        if (n > 0) {
            x = func_ov000_021adf78((u32 *) &n);
            if (x == 0) {
                func_0200ecc4(&p->mUnk_948);
                goto done;
            }
            r = c->mUnk_08 - 1 - c->mUnk_04;
            m = n;
            if ((s32) m >= r) {
                m = r;
            }
            func_0214d1fc(x, c->mUnk_04, m);
            c->mUnk_04 += m;
            *c->mUnk_04 = 0;
            if (f != 1) {
                s = c->mUnk_00;
                if (func_02139f70(s, data_ov000_021b1230) != 0) {
                    f = 1;
                    p->mUnk_964 = func_02139f70(s, data_ov000_021b1230) + 4;
                    y = func_02139f70(c->mUnk_00, data_ov000_021b1348);
                    if (y != 0) {
                        y = y + func_0213a434(data_ov000_021b1348);
                        q = (s8 *) func_02139f70(y, data_ov000_021b1258);
                        e = *q;
                        *q = 0;
                        p->mUnk_960 = func_0213bf90(y);
                        *q = e;
                    }
                }
            }
            if (n > m) {
                func_ov000_021adf00(n);
                func_0200ecc4(&p->mUnk_948);
                goto done;
            }
            func_ov000_021adf00(m);
        }
        if (n < 0) {
            func_0200ecc4(&p->mUnk_948);
            goto done;
        }
        if (p->mUnk_960 > 0 && n > 0 && p->mUnk_964 + p->mUnk_960 <= c->mUnk_04) {
            func_0200ecc4(&p->mUnk_948);
            goto done;
        }
        t = func_0200f5ac();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mUnk_24 = 6;
            func_0200ecc4(&p->mUnk_948);
            goto fail;
        }
        if (p->mUnk_b0 == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                func_0201000c(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        func_0200ecc4(&p->mUnk_948);
        if (func_ov000_02187230((int) p) == 0) {
            p->mUnk_24 = 7;
            goto fail;
        }
    }
done:
    func_ov000_021ae094();
    func_ov000_021ae048();
    func_ov000_021ae258();
    func_ov000_021ae2f4();
    p->mUnk_24 = 8;
    return;
fail:
    func_ov000_021ae094();
    func_ov000_021ae048();
    func_ov000_021ae258();
    func_ov000_021ae2f4();
}
