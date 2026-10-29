#include "Main/Unknown/code_020b6e00.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b8624.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0212b090.h"
#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "00/code_02182fdc.h"

s32 func_020b8220(s32 a, s32 b) {
    Unk020ee684 *p;
    u32 k;
    enum { K0 } j;

    switch (b) {
        case 0:
            return 0x1b;
        case 1:
            return 0x14;
        case 2:
            return 0x22;
        case 3:
            return 0x17;
        case 4:
            return 0x11;
        case 5:
            p = &(*(Unk020ee684 **) data_027e00c8)[(u16) a];
            j = p->mUnk_030.mUnk_00;
            if (data_0217bc48[j].mUnk_08 == 3) {
                k = (u16) p->mUnk_030.mUnk_08;
            } else {
                k = 0;
            }
            switch (k) {
                case 1:
                    return 0x11;
                case 2:
                    return 0x12;
                case 0:
                case 3:
                    return 0x13;
            }
            break;
        case 6:
            return 0x1f;
        case 7:
            return 0x20;
        case 8:
            return 0x21;
        case 9:
            return 0x1c;
        case 10:
            return 0x23;
        case 11:
            return 0x15;
        case 12:
            return 0x19;
        case 13:
            return 0x18;
        case 14:
            return 0x1d;
        case 16:
            return 0x1e;
        case 15:
            return 0x1a;
        case 17:
            return 0x16;
    }
    return a;
}

void func_020b80a8(void) {
    void *p;
    void *a;
    u16 i;
    s32 y;
    s32 x;
    s32 b;
    s32 c;
    s32 k;
    u8 v1[0x20];
    Unk02180728 o;
    u16 t[22];

    p = func_020b403c(0);
    a = func_0212b090();
    func_0212b09c();
    func_02023408(v1, a, 0x20, 4, 4);
    o.mUnk_00 = v1;
    o.mUnk_08 = 1;
    o.mUnk_04 = p;
    o.mUnk_0c = 0;
    i = 0;
    k = 0;
    for (; i < 8; i++) {
        y = (i % 4) << 6;
        x = (((u32) i >> 2) << 4) + 8;
        func_020adff0(i, t, k);
        if (i == func_020b4d9c()) {
            if (data_021759c0->mUnk_58 != 0) {
                if (data_021759c0->mUnk_70[i].mUnk_04 == 0) {
                    b = 10;
                    c = 11;
                } else {
                    b = 8;
                    c = 9;
                }
            } else {
                b = 12;
                c = 13;
            }
        } else {
            b = 14;
            c = 15;
        }
        func_02024340(&o, y, x + 1, c, 0x40a, t);
        func_02024340(&o, y, x, b, 0x40a, t);
    }
}

void func_020b7fd8(s32 a, s32 *b, s32 *c) {
    s32 t;

    *b = (&data_021759c0->mUnk_70[a] - 1)->mUnk_28;
    switch (*b) {
        case 0:
        case 2:
        case 8:
        case 10:
        case 11:
            *c = 7;
            break;
        case 1:
        case 3:
        case 9:
            *c = 8;
            break;
        case 4:
        case 5:
            *c = 9;
            break;
        case 6:
        case 7:
            *c = 10;
            break;
        case 12:
            t = data_0217b488->mUnk_10c[a];
            *b = t % 4 + 12;
            if (t < 4) {
                *c = 5;
            } else {
                *c = 6;
            }
            break;
    }
}

void func_020b7ee8(s32 a, s32 *b, s32 *c) {
    Unk02056bc0 t;

    func_02056bc0(data_021759c0->mUnk_00, a, &t);
    if (t.mUnk_18 != 0) {
        *b = t.mUnk_19;
    } else {
        *b = 0;
        *c = 0;
        return;
    }
    switch (*b) {
        case 0:
        case 2:
        case 8:
        case 10:
        case 11:
            *c = 7;
            break;
        case 1:
        case 3:
        case 9:
            *c = 8;
            break;
        case 4:
        case 5:
            *c = 9;
            break;
        case 6:
        case 7:
            *c = 10;
            break;
        case 12:
            break;
    }
}

void func_020b7a80(u16 *a, void *b) {
    Unk020b4934 *o = 0;
    void *p;
    Unk020b4a44 *v1;
    Unk020b4a44 *v2;
    Unk020b4a44 *v3;
    Unk020b4a44 *v4;
    Unk020b4a44 *v5;
    Unk020b4a44 *v6;
    Unk020b4a44 *v7;
    s32 i;

    func_020b49f4(&o, func_020b47c0("race_transfer_map_mr_s_o.NCGR"));
    p = o->mUnk_14;
    switch (data_021759c0->mUnk_2e) {
        case 0x9:
            func_020b46d0(p, 0x0, 0, 4, 4, b, 0, 12);
            v1 = 0;
            func_020b4a7c(&v1, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v1->mUnk_0c[0x0 + i];
            }
            break;
        case 0x32:
            func_020b46d0(p, 0x4, 0, 8, 4, b, 0, 12);
            v2 = 0;
            func_020b4a7c(&v2, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v2->mUnk_0c[0x10 + i];
            }
            break;
        case 0x15:
            func_020b46d0(p, 0xc, 0, 4, 4, b, 0, 12);
            v3 = 0;
            func_020b4a7c(&v3, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v3->mUnk_0c[0x20 + i];
            }
            break;
        case 0x33:
            func_020b46d0(p, 0x10, 0, 4, 4, b, 0, 12);
            v4 = 0;
            func_020b4a7c(&v4, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v4->mUnk_0c[0x50 + i];
            }
            break;
        case 0x11:
            func_020b46d0(p, 0x14, 0, 4, 4, b, 0, 12);
            v5 = 0;
            func_020b4a7c(&v5, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v5->mUnk_0c[0x60 + i];
            }
            break;
        case 0xa:
            func_020b46d0(p, 0x18, 0, 4, 4, b, 0, 12);
            v6 = 0;
            func_020b4a7c(&v6, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v6->mUnk_0c[0x70 + i];
            }
            break;
        case 0x31:
            func_020b46d0(p, 0x0, 4, 8, 4, b, 0, 12);
            v7 = 0;
            func_020b4a7c(&v7, func_020b47c0("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v7->mUnk_0c[0x80 + i];
            }
            break;
    }
}

void func_020b6e00(u16 *a, void *b) {
    s32 x;
    s32 y;
    Unk020b4934 *o = 0;
    Unk020b4a44 *q1;
    Unk020b4a44 *q2;
    Unk020b4a44 *q3;
    Unk020b4a44 *q4;
    Unk020b4a44 *q5;
    Unk020b4a44 *q6;
    Unk020b4a44 *q7;
    Unk020b4a44 *q8;
    Unk020b4a44 *q9;
    Unk020b4a44 *q10;
    Unk020b4a44 *q11;
    Unk020b4a44 *q12;
    Unk020b4a44 *q13;
    Unk020b4a44 *q14;
    Unk020b4a44 *q15;
    void *p;
    u8 i;
    u8 j;
    u8 k;
    s32 n;
    Unk020b6e00 *r;

    func_020b49f4(&o, func_020b47c0("race_transfer_s_o.NCGR"));
    p = o->mUnk_14;
    for (i = 0; i < (s32) data_021759c0->mUnk_3d0; i++) {
        func_020b7fd8(i, &x, &y);
        func_020b46d0(p, x << 1, 0, 2, 2, b, i << 1, 0);
        r = (Unk020b6e00 *) data_0217b3c4->mUnk_2d8[i]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
    }
    for (j = 0; j < (s32) data_021759c0->mUnk_3d0; j++) {
        func_020b7fd8(j, &x, &y);
        func_020b46d0(p, x << 1, 2, 2, 2, b, (j << 1) + 0x10, 0);
        r = (Unk020b6e00 *) data_0217b3c4->mUnk_2d8[j + 8]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        r = (Unk020b6e00 *) data_0217b3c4->mUnk_5fc[j]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        r = (Unk020b6e00 *) data_0217b3c4->mUnk_6ac[j]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        if (data_021759c0->mUnk_08 == 1) {
            r = (Unk020b6e00 *) data_0217b3c4->mUnk_74c[j + 7]->mUnk_04;
            r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        }
    }
    if (data_021759c0->mUnk_08 == 1) {
        for (j = 0; j < 6; j++) {
            func_020b7ee8(j, &x, &y);
            func_020b46d0(p, x << 1, 2, 2, 2, b, ((j + 2) << 1) + 0x10, 0);
            r = (Unk020b6e00 *) data_0217b3c4->mUnk_74c[j + 8]->mUnk_04;
            r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        }
    }
    for (k = 0; k < (s32) data_021759c0->mUnk_3d0; k++) {
        s32 t[8][2] = {{16, 8}, {16, 10}, {11, 12}, {18, 12}, {25, 12}, {11, 14}, {18, 14}, {25, 14}};

        func_020b46d0(func_0212b090(), (k % 4) << 3, ((u32) k >> 2) << 1, 7, 2, b, t[k][0], t[k][1]);
    }
    func_0212b09c();
    func_020b49f4(&o, func_020b47c0("race_transfer_map_s_o.NCGR"));
    p = o->mUnk_14;
    if (data_021759c0->mUnk_08 == 2) {
        func_020b46d0(p, 0x14, 6, 0xc, 4, b, 0, 8);
        func_020b46d0(p, 0x14, 0xa, 0xb, 4, b, 0, 0xc);
        q1 = 0;
        func_020b4a7c(&q1, func_020b47c0("race_transfer_map_s_o.NCLR"));
        for (n = 0; n < 16; n++) {
            a[0x40 + n] = q1->mUnk_0c[0xd0 + n];
        }
    } else {
        switch (data_021759c0->mUnk_00) {
            case 15:
            case 31:
            case 46:
                func_020b46d0(p, 0x0, 0, 4, 2, b, 0, 8);
                q2 = 0;
                func_020b4a7c(&q2, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q2->mUnk_0c[n];
                }
                break;
            case 10:
            case 18:
            case 35:
                func_020b46d0(p, 0x4, 0, 5, 2, b, 0, 8);
                q3 = 0;
                func_020b4a7c(&q3, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q3->mUnk_0c[0x10 + n];
                }
                break;
            case 27:
                func_020b46d0(p, 0x9, 0, 6, 2, b, 0, 8);
                q4 = 0;
                func_020b4a7c(&q4, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q4->mUnk_0c[0x20 + n];
                }
                break;
            case 36:
                func_020b46d0(p, 0xf, 0, 3, 2, b, 0, 8);
                q5 = 0;
                func_020b4a7c(&q5, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q5->mUnk_0c[0x30 + n];
                }
                break;
            case 33:
                func_020b46d0(p, 0, 2, 0xc, 4, b, 0, 8);
                func_020b46d0(p, 0, 6, 0xb, 4, b, 0, 0xc);
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b45b0(p, 0, 2, 8, 8, b, 0, 8);
                }
                q6 = 0;
                func_020b4a7c(&q6, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q6->mUnk_0c[0x40 + n];
                }
                break;
            case 24:
            case 38:
                func_020b46d0(p, 0x14, 0, 8, 4, b, 0, 8);
                q7 = 0;
                func_020b4a7c(&q7, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q7->mUnk_0c[0x50 + n];
                }
                break;
            case 16:
            case 30:
                func_020b46d0(p, 0x1d, 0, 3, 2, b, 0, 8);
                q8 = 0;
                func_020b4a7c(&q8, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q8->mUnk_0c[0x60 + n];
                }
                break;
            case 17:
                func_020b46d0(p, 0xc, 4, 8, 4, b, 0, 8);
                q9 = 0;
                func_020b4a7c(&q9, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q9->mUnk_0c[0x70 + n];
                }
                break;
            case 1:
            case 9:
            case 25:
            case 39:
                func_020b46d0(p, 0xc, 2, 8, 2, b, 0, 8);
                q10 = 0;
                func_020b4a7c(&q10, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q10->mUnk_0c[0x80 + n];
                }
                break;
            case 11:
            case 14:
            case 19:
            case 26:
                func_020b46d0(p, 0x13, 4, 12, 4, b, 0, 8);
                q11 = 0;
                func_020b4a7c(&q11, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q11->mUnk_0c[0x90 + n];
                }
                break;
            case 34:
                func_020b46d0(p, 0x8, 10, 8, 4, b, 0, 8);
                q12 = 0;
                func_020b4a7c(&q12, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q12->mUnk_0c[0x80 + n];
                }
                break;
            case 12:
            case 32:
                func_020b46d0(p, 0xc, 8, 8, 2, b, 0, 8);
                q13 = 0;
                func_020b4a7c(&q13, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q13->mUnk_0c[0xa0 + n];
                }
                break;
            case 29:
                func_020b46d0(p, 0x12, 10, 2, 2, b, 0, 8);
                q14 = 0;
                func_020b4a7c(&q14, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q14->mUnk_0c[0xb0 + n];
                }
                break;
            case 23:
                func_020b46d0(p, 0x0, 10, 8, 6, b, 0, 8);
                q15 = 0;
                func_020b4a7c(&q15, func_020b47c0("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q15->mUnk_0c[0xe0 + n];
                }
                break;
        }
    }
    if (data_021759c0->mUnk_08 == 4) {
        func_020b7a80(a, b);
    }
}
