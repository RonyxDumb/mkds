#include "Main/Unknown/code_020f830c.h"

#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020be930.h"
#include "Main/Unknown/code_020fa4c8.h"
#include "Main/Unknown/code_020f81c0.h"

// non-matching: 0x38c bytes vs 0x398. The loops have the original's shape (subscripts multiplied each pass,
// the table entry read at the top of the second loop); left: the three acc arms are laid out in another order
// (the original tests `j < 9`, then `m == 0`, then `m == 1`, with the plain add last and an `ldrh` in the `>> 2`
// arm), the 64-bit product for k is formed in another order, and registers differ.
s32 func_020f8a04(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
    Unk0217bc6c *q;
    Unk020f41c4_B *b;
    u16 *row;
    s32 m;
    u32 i;
    s32 j;
    s32 t;
    s32 x;
    s32 sel;
    u16 acc;
    u16 k;
    s32 n;

    sel = 0x13;
    if (param_2 != 0) {
        i = (u16) (param_2 - 1);
        m = 0;
        q = &data_0217bc74;
    } else {
        i = (u16) (param_3 - 1);
        m = param_1;
        q = param_4 != 0 ? &data_0217bc6c : &data_0217bc64;
    }
    row = q->mUnk_04[i];
    acc = 0;
    t = 0;
    if (data_021759c0->mUnk_08 != 4) {
        for (j = 0; j < 0xe; j++) {
            t += (u16) (data_0217bc34[(s32) j].mUnk_90 * (data_027e00cc[(s32) j].mUnk_1c - data_027e00cc[(s32) j].mUnk_18));
        }
    }
    for (j = 0; j < param_6; j++) {
        n = data_0217bc48[(s32) j].mUnk_08;
        if (!((j == 8 && data_0217bc60 > 0) || (j == 7 && data_0217bc5c > 0) || (j == 0xf && data_0217bc58 > 0))) {
            if (data_027e00cc[n].mUnk_20 - data_027e00cc[n].mUnk_1c > 0 &&
                data_0217bc48[(s32) j].mUnk_00 != 0) {
                x = data_0217bc34[n].mUnk_90 * data_0217bc48[(s32) j].mUnk_0c;
                if (x == 0 || t + x <= 0x28) {
                    if (j < 9 || m == 0) {
                        acc = acc + row[j];
                    } else if (m == 1) {
                        acc = acc + ((s16) row[j] >> 2);
                    } else {
                        acc = 3 * row[j] + acc;
                    }
                }
            }
        }
        data_0217bc7c[j] = acc;
    }
    b = &data_0217561c->mUnk_47c;
    if (acc != 0) {
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    }
    k = (u16) (acc != 0 ? (u32) (((u64) (u32) (b->mUnk_00 >> 32) * (u32) acc) >> 32) : (u32) (b->mUnk_00 >> 32));
    for (j = 0; j < param_6; j++) {
        if (k < data_0217bc7c[j]) {
            sel = j;
            break;
        }
    }
    if (func_020fab34(&sel) != 0) {
        func_020faa78(sel);
    }
    if (param_5 != 0) {
        if (param_2 != 0) {
            data_0217bc50 = 0;
            for (j = 0; j < param_6; j++) {
                if (j == sel || data_0217bc7c[j] != 0) {
                    data_0217bca0[data_0217bc50] = j;
                    data_0217bc50++;
                }
            }
        } else {
            data_0217bc50 = 0;
        }
    }
    return sel;
}

void func_020f89b0(Unk020ee684 *param_1, Unk020ee684 *param_2) {
    param_1->mUnk_018 = param_2;
    param_1->mUnk_000 = 0;
    param_1->mUnk_004 = 0;
    param_1->mUnk_00c = 0x13;
    param_1->mUnk_010 = 0x13;
    param_1->mUnk_014 = 0x13;
    param_1->mUnk_020 = 0;
    param_1->mUnk_024 = data_021759c0->mUnk_68[param_2->mUnk_1f8].mUnk_08.mUnk_00 == 3;
}

void func_020f87a8(Unk020ee684 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    Unk020ee684 *p;
    Unk0217bc48 *e;
    Unk027e00cc *v;
    enum { K0 } k, j;
    s32 a;
    s32 b;

    p = param_1->mUnk_018;
    a = data_021759c0->mUnk_08 == 5;
    if (param_1->mUnk_000 != 0) {
        return;
    }
    if (param_1->mUnk_014 != 0x13) {
        return;
    }
    param_1->mUnk_000 = 1;
    param_1->mUnk_00c = 0x13;
    if (!a) {
        func_020be930(param_1->mUnk_018->mUnk_1f8);
    }
    if (a) {
        param_1->mUnk_01c = 0;
        param_1->mUnk_004 = 0;
        param_1->mUnk_008 = 0x85;
        param_1->mUnk_028 = 0x10;
        param_1->mUnk_02c = 4;
    } else if (param_5 != 0) {
        param_1->mUnk_01c = 1;
        param_1->mUnk_004 = 0x4d;
        param_1->mUnk_008 = 0x65;
        param_1->mUnk_028 = 8;
        param_1->mUnk_02c = 3;
    } else {
        param_1->mUnk_01c = 0;
        param_1->mUnk_004 = 0;
        param_1->mUnk_008 = 0xd5;
        param_1->mUnk_028 = 0x10;
        param_1->mUnk_02c = 4;
    }
    b = p->mUnk_1f8 == data_021759c0->mUnk_62;
    if (p->mUnk_058.mUnk_000 != 0xf && p->mUnk_058.mUnk_004 >= 9) {
        param_1->mUnk_010 = func_020f8a04(0, param_2, param_3, param_4, b, 9);
    } else {
        param_1->mUnk_010 = func_020f8a04(func_02079b40(p->mUnk_1f8), param_2, param_3, param_4, b, 0x12);
    }
    if (a) {
        func_0205a750(param_1->mUnk_010);
        param_1->mUnk_020 = 1;
        return;
    }
    k = param_1->mUnk_010;
    e = &data_0217bc48[k];
    j = e->mUnk_08;
    v = &data_027e00cc[j];
    v->mUnk_1c += e->mUnk_0c;
}

void func_020f86c4(Unk020ee684 *param_1) {
    Unk020ee684 *p;
    Unk0217bc48 *e;
    Unk027e00cc *v;
    enum { K0 } k, j;

    p = param_1->mUnk_018;
    if (p->mUnk_014 != 0x13) {
        p->mUnk_014 = 0x13;
    }
    if (param_1->mUnk_000 != 0) {
        if (p->mUnk_020 == 0) {
            k = p->mUnk_010;
            e = &data_0217bc48[k];
            j = e->mUnk_08;
            v = &data_027e00cc[j];
            v->mUnk_1c -= e->mUnk_0c;
        }
        p->mUnk_000 = 0;
        p->mUnk_004 = 0;
        p->mUnk_00c = 0x13;
        p->mUnk_010 = 0x13;
        p->mUnk_014 = 0x13;
        p->mUnk_020 = 0;
    } else {
        if (p->mUnk_030.mUnk_00 != 0x13) {
            func_020f45f0(&p->mUnk_030, 1);
        }
    }
    param_1->mUnk_000 = 1;
    param_1->mUnk_004 = 0;
    param_1->mUnk_008 = 0x85;
    param_1->mUnk_00c = 0x13;
    param_1->mUnk_014 = 0x13;
    param_1->mUnk_010 = 0x13;
    param_1->mUnk_020 = 1;
}

s32 func_020f850c(Unk020ee684 *param_1, Unk020ee684 *param_2) {
    Unk0217bc48 *e;
    Unk027e00cc *v;
    enum { K0 } j;
    s32 a;
    u32 b;

    switch (param_1->mUnk_000) {
        case 1:
            param_1->mUnk_004++;
            a = data_021759c0->mUnk_08;
            if (a == 5 && param_1->mUnk_020 != 0) {
                b = param_2->mUnk_1f8 & 0xff;
                if (func_0205a310(((u8 *) data_0217aa18)[b]) == 0) {
                    b = func_0205a2ac(((u8 *) data_0217aa18)[b]);
                    if (func_020faca4(b) != 0) {
                        func_020faa78(b);
                    }
                    e = &data_0217bc48[b];
                    j = e->mUnk_08;
                    v = &data_027e00cc[j];
                    v->mUnk_1c += e->mUnk_0c;
                    param_1->mUnk_010 = b;
                    param_1->mUnk_020 = 0;
                    param_1->mUnk_008 += param_1->mUnk_004 - 0x6f;
                } else if (param_1->mUnk_004 > 0x6e) {
                    param_1->mUnk_004 = 0x67;
                }
                return 0;
            }
            if (param_1->mUnk_004 > 0x3c &&
                (((param_2->mUnk_1ec & 0x241) == 0x241 && a != 5 && param_1->mUnk_01c == 0) ||
                 param_1->mUnk_004 > param_1->mUnk_008)) {
                param_1->mUnk_004 = 0;
                param_1->mUnk_000 = 2;
            }
            break;
        case 2:
            param_1->mUnk_004++;
            if (param_1->mUnk_004 > param_1->mUnk_028 * 2) {
                return 1;
            }
            break;
    }
    return 0;
}

void func_020f8498(Unk020ee684 *param_1) {
    Unk0217bc48 *e;
    Unk027e00cc *v;
    enum { K0 } k, j;

    k = param_1->mUnk_010;
    e = &data_0217bc48[k];
    j = e->mUnk_08;
    v = &data_027e00cc[j];
    v->mUnk_1c -= e->mUnk_0c;
    param_1->mUnk_000 = 0;
    param_1->mUnk_004 = 0;
    param_1->mUnk_00c = 0x13;
    param_1->mUnk_010 = 0x13;
    param_1->mUnk_014 = 0x13;
    param_1->mUnk_020 = 0;
}

void func_020f8418(Unk020ee684 *param_1) {
    Unk0217bc48 *e;
    Unk027e00cc *v;
    enum { K0 } k, j;

    if (param_1->mUnk_020 == 0) {
        k = param_1->mUnk_010;
        e = &data_0217bc48[k];
        j = e->mUnk_08;
        v = &data_027e00cc[j];
        v->mUnk_1c -= e->mUnk_0c;
    }
    param_1->mUnk_000 = 0;
    param_1->mUnk_004 = 0;
    param_1->mUnk_00c = 0x13;
    param_1->mUnk_010 = 0x13;
    param_1->mUnk_014 = 0x13;
    param_1->mUnk_020 = 0;
}

static inline u32 func_020f830c_inline(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n != 0) {
        return ((b->mUnk_00 >> 32) * n) >> 32;
    }
    return b->mUnk_00 >> 32;
}

// non-matching: 0x108 bytes against 0x10c. The random step and its scaling are the inline helper above, which gives
// the original's second `n != 0` test and the general 64-bit multiply. Left: the original tests param_1->mUnk_000
// against 0 first, keeps the zero high word apart from `i = 0`, computes b before testing n and saves r4-r6 only
// (here r4-r7 and a pad word); n, q, i and b sit in other registers.
void func_020f830c(Unk020ee684 *param_1) {
    Unk020f41c4_B *b;
    u16 n;
    s32 *q;
    u32 i;

    switch (param_1->mUnk_000) {
        case 1:
            if (data_0217bc50 != 0) {
                n = data_0217bc50;
                q = data_0217bca0;
            } else {
                n = data_0217bc54;
                q = data_0217bce8;
            }
            b = &data_0217561c->mUnk_498;
            i = 0;
            if (n != 0) {
                i = (u16) func_020f830c_inline(b, n);
            }
            if (param_1->mUnk_00c == q[i]) {
                i = (u16) (i + 1);
                if (i >= n) {
                    i = 0;
                }
            }
            param_1->mUnk_00c = q[i];
            break;
        case 2:
            param_1->mUnk_00c = param_1->mUnk_010;
            break;
    }
}
