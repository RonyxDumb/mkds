#include "Main/Unknown/code_0205c800.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219bb50.h"
#include "code_0200f5ac.h"

void func_0205c800(u16 a, void (*b)(u32)) {
    u16 i;
    s32 r;
    u16 n;

    r = -1;
    for (i = 1; i <= 4; i++) {
        n = a + i;
        if (n >= 4) {
            n = n - 4;
        }
        if (n != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << (u8) n)) != 0) {
            r = n;
            break;
        }
    }
    if (r == -1) {
        return;
    }
    b(r);
}

void func_0205c898(void) {
    s32 i;
    Unk0217aa14 *p;
    u8 n;
    u64 x;

    data_0217aa14->mUnk_0fa = 1 << func_ov000_0219bb50();
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_0f8 = 0;
    for (i = 0; i < 4; i++) {
        p = data_0217aa14;
        n = p->mUnk_014[i].mUnk_34;
        x = *(u64 *) &p->mUnk_014[i].mUnk_28;
        if (n == 0) {
            p->mUnk_104[i].mUnk_84 = 0;
        } else {
            p->mUnk_104[i].mUnk_84 = (x / n * 64 / 0x82ea + 32) / 33;
        }
    }
}

static inline s32 func_0205c98c_inline(void) {
    u8 i;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_014[i].mUnk_30 != 0) {
            func_0214d1fc(&p->mUnk_014[i], q, 0x28);
            *(u64 *) &q->mUnk_04 = func_0200f5ac();
            if (func_0205c340(i, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[i].mUnk_30 = 0;
            } else {
                func_0214d168(q, 0, 0x28);
            }
            return 1;
        }
    }
    return 0;
}

// non-matching: same size; 94 lines differ; first: original `mov r4, #0`, ours `mov r5, #0`
void func_0205c98c(void) {
    u8 m;
    u8 i;
    u16 k;
    u8 b;
    Unk0217aa14 *p;
    Unk0217aa14_014 *e;
    Unk0217aa14_754_04 *q;
    Unk0217aa14_754 *r;

    m = 0;
    for (i = 0; i < 4; i++) {
        if (i == func_ov000_0219bb50() || data_0217aa14->mUnk_014[i].mUnk_34 >= 12) {
            m = m | (1 << i);
        }
    }
    p = data_0217aa14;
    if (p->mUnk_749 == (p->mUnk_749 & m)) {
        p->mUnk_0fb = m;
        data_0217aa14->mUnk_010 = 2;
        data_0217aa14->mUnk_012 = 1;
    }
    if (func_0205c98c_inline() != 0) {
        return;
    }
    p = data_0217aa14;
    k = p->mUnk_0f8;
    if (k >= 4) {
        p->mUnk_0f8 = 0;
        return;
    }
    b = k;
    if ((p->mUnk_749 & (1 << b)) != 0 && b != func_ov000_0219bb50()) {
        p = data_0217aa14;
        e = &p->mUnk_014[b];
        if (e->mUnk_34 < 12) {
            r = p->mUnk_754;
            q = &r->mUnk_04;
            r->mUnk_04.mUnk_00_h = func_ov000_0219bb50();
            *(u64 *) &q->mUnk_04 = func_0200f5ac();
            q->mUnk_0c[0] = 0;
            q->mUnk_0c[1] = 0;
            q->mUnk_0c[2] = 0;
            q->mUnk_0c[3] = 0;
            q->mUnk_0c[4] = 0;
            *(u32 *) &q->mUnk_20[0] = 0;
            func_0205c340(b, 0, 0x28);
        } else {
            if (e->mUnk_36 == 0) {
                func_0205c340(b, 5, 0);
            }
            data_0217aa14->mUnk_014[b].mUnk_36++;
            if (data_0217aa14->mUnk_014[b].mUnk_36 > 4) {
                data_0217aa14->mUnk_014[b].mUnk_36 = 0;
            }
        }
    }
    data_0217aa14->mUnk_0f8++;
}

// non-matching: 0x114 bytes, original 0x108; 68 lines differ; first: original `mov r4, #0`, ours `mov r1, #0`
void func_0205cbe4(void) {
    u8 i;
    Unk0217aa14_014 *e;

    for (i = 0; i < 4;) {
        e = &data_0217aa14->mUnk_014[i];
        e->mUnk_04 = 0;
        e->mUnk_08 = 0;
        e->mUnk_0c = 0;
        e->mUnk_10 = 0;
        e->mUnk_14 = 0;
        e->mUnk_18 = 0;
        e->mUnk_1c = 0;
        e->mUnk_20 = 0;
        e->mUnk_24 = 0;
        e = &data_0217aa14->mUnk_014[i];
        i++;
        e->mUnk_28 = 0;
        e->mUnk_2c = 0;
        e->mUnk_34 = 0;
        e = &data_0217aa14->mUnk_014[i - 1];
        e->mUnk_35 = 0;
        e = &data_0217aa14->mUnk_014[i - 1];
        e->mUnk_36 = 0;
    }
    data_0217aa14->mUnk_0f8 = 0;
    data_0217aa14->mUnk_0fb = 0;
    data_0217aa14->mUnk_0fd = 0;
    data_0217aa14->mUnk_0f4 = 0;
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_758 = 1;
    data_0217aa14->mUnk_75c &= ~2;
    data_0217aa14->mUnk_75c |= 0x80;
    data_0217aa14->mUnk_75c &= ~0x10;
}

// non-matching: 0x40 bytes, original 0x38; 16 lines differ; first: original `ldr r0, [pc, #44]`, ours `ldr r0, [pc,
// #48]`
void func_0205ccec(void) {
    Unk0217aa14 *p;

    p = data_0217aa14;
    if (p == 0) {
        return;
    }
    if (p->mUnk_00e == 4 || p->mUnk_00e == 5) {
        p->mUnk_728++;
    }
}

// non-matching: 0x2ac bytes, original 0x2b0; 98 lines differ; first: original `ldr r1, [pc, #652]`, ours `ldr r1, [pc,
// #648]`
void func_0205cd24(void *a) {
    s32 i;
    s32 j;

    if (data_021759c0->mUnk_08 != 5) {
        return;
    }
    data_0217aa14 = func_02036bec(a, 0x760);
    data_0217aa14->mUnk_754 = func_02036b74(a, 0x6c, 0x20);
    for (i = 0; i < 16; i++) {
        data_0217aa14->mUnk_324[i].mUnk_04 = func_02036b74(a, 20, 32);
        for (j = 0; j < 4; j++) {
            ((Unk0217aa14_324(*)[4]) & data_0217aa14->mUnk_324[16])[i][j].mUnk_04 = func_02036b74(a, 20, 32);
        }
    }
    data_0217aa14->mUnk_0fc = data_0217aa18->mUnk_04;
    func_0214d168(data_0217aa14->mUnk_754, 0, 0x6c);
    for (i = 0; i < 4; i++) {
        func_0214d168(&data_0217aa14->mUnk_104[i], 0, 0x68);
        data_0217aa14->mUnk_104[i].mUnk_86_0 = 0;
    }
    data_0217aa14->mUnk_748 = 0;
    data_0217aa14->mUnk_749 = data_0217aa14->mUnk_0fc;
    for (i = 0; i < 4; i++) {
        data_0217aa14->mUnk_74a[i] = 0;
        data_0217aa14->mUnk_740[i] = 0;
    }
    func_0205ad88();
    func_0205a6b4();
    data_0217aa14->mUnk_75c |= 1;
    data_0217aa14->mUnk_75c |= 0x40;
    data_0217aa14->mUnk_010 = 0;
    data_0217aa14->mUnk_012 = 1;
    data_0217aa14->mUnk_758 = 0;
    for (i = 0; i < 4; i++) {
        data_0217aa14->mUnk_104[i].mUnk_80 = 0;
        if (data_0217aa18->mUnk_06[i] < 0) {
            data_0217aa14->mUnk_104[i].mUnk_86_1 = 0;
        } else {
            data_0217aa14->mUnk_104[i].mUnk_86_1 = func_0205d27c(data_0217aa18->mUnk_06[i]);
        }
    }
    func_02046be8(data_0217aa14, data_02165388, 6, 0);
}

void func_0205cfd4(u32 a) {
    u8 i;
    u8 n;

    for (i = 0, n = 0; i < 4; i++) {
        data_0217aa18->mUnk_06[i] = -1;
        if ((a & (1 << i)) != 0) {
            data_0217aa18->mUnk_00[n] = i;
            data_0217aa18->mUnk_06[i] = n;
            n++;
        }
    }
    data_0217aa18->mUnk_04 = a;
    while (n < 4) {
        data_0217aa18->mUnk_00[n] = -1;
        n++;
    }
}

void func_0205d07c(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_0217aa18->mUnk_00[i] = -1;
        data_0217aa18->mUnk_06[i] = -1;
    }
    data_0217aa18->mUnk_05 = 0;
}
