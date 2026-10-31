#include "Main/Unknown/code_020968c0.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_0218175c.h"
#include "code_02147cd8.h"

u32 func_0209702c(Unk02096a04 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    s32 v1;
    s32 g;
    u32 v2 = *b;
    Vec3 v;
    s32 t;
    u8 m = 1 << a->mUnk_74;
    Unk0210b7a8 s;
    u8 v3 = *c;
    Unk0210b7a8 s2;
    if (v2 == 3 || v2 == 4) {
        g = a->mUnk_29c;
        if (g != 1) {
            if (p->mUnk_b0 == 4 || (p->mUnk_b0 == 5 && p->mUnk_a0 > 0x7800)) {
                p->mUnk_00.mUnk_10.x = 0;
                p->mUnk_00.mUnk_10.y = 0x3800;
                p->mUnk_00.mUnk_10.z = 0;
                return v3;
            }
        }
        if ((((const Unk02096a04 *) p)->mUnk_108 & m) != 0) {
            goto tail;
        }
        v1 = p->mUnk_b0;
        if (v1 == 0 || v1 == 3) {
            p->mUnk_108 = p->mUnk_108 | m;
            if (data_021759c0->mUnk_68[a->mUnk_74].mUnk_08.mUnk_00 != 2) {
                if ((p->mUnk_00.mUnk_78 & 4) == 0) {
                    if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                        t = 2;
                    } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                        t = 3;
                    } else {
                        t = 4;
                    }
                    s.mUnk_00 = 0x16e;
                    s.mUnk_04 = &p->mUnk_00.mUnk_04;
                    s.mUnk_08 = t;
                    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
                    func_0210b7a8(&s);
                }
            }
            p->mUnk_00.mUnk_78 = p->mUnk_00.mUnk_78 | data_021564bc;
            return 0;
        }
        if (g == 1 && (v1 == 4 || (v1 == 5 && p->mUnk_a0 > 0x7800) || v1 == 1)) {
            p->mUnk_108 = p->mUnk_108 | m;
            if ((p->mUnk_00.mUnk_02 & 0x800) == 0 || a->mUnk_74 == data_021759c0->mUnk_62) {
                p->mUnk_104 = 1;
                p->mUnk_b4 = p->mUnk_a0;
                p->mUnk_b8 = p->mUnk_a4;
                p->mUnk_bc = 0x4000;
                p->mUnk_c0 = 0x1333;
                p->mUnk_c4 = 0;
                p->mUnk_d0 = 0;
                p->mUnk_d4 = 0x2000;
                p->mUnk_d8 = -0x40;
                p->mUnk_dc = 0x200;
                p->mUnk_e0 = 0;
                p->mUnk_e4 = 0;
                p->mUnk_f0 = 0;
                p->mUnk_f4 = 0x1000;
                p->mUnk_f8 = -0x30;
                p->mUnk_fc = 0x800;
                p->mUnk_100 = 0x100;
                func_020d26f8(&p->mUnk_00, a);
                if (data_021759c0->mUnk_08 == 4) {
                    v.x = (p->mUnk_00.mUnk_04.x + a->mUnk_80.x) >> 1;
                    v.y = (p->mUnk_00.mUnk_04.y + a->mUnk_80.y) >> 1;
                    v.z = (p->mUnk_00.mUnk_04.z + a->mUnk_80.z) >> 1;
                    func_0208b7bc(0x442, &v);
                    func_0208b7bc(0x443, &v);
                    if (data_021759c0->mUnk_08 == 4) {
                        func_ov001_0218175c(p->mUnk_00.mUnk_00);
                    }
                }
            }
            if ((p->mUnk_00.mUnk_02 & 0x800) == 0) {
                if (p->mUnk_b0 == 1) {
                    p->mUnk_b0 = 6;
                } else if (p->mUnk_b0 == 4) {
                    p->mUnk_b0 = 7;
                }
            }
            p->mUnk_00.mUnk_10.x = 0;
            p->mUnk_00.mUnk_10.y = 0;
            p->mUnk_00.mUnk_10.z = 0;
            return v3;
        }
        if (v1 != 1) {
            goto tail;
        }
        p->mUnk_108 = p->mUnk_108 | m;
        if ((p->mUnk_00.mUnk_02 & 0x800) == 0 || a->mUnk_74 == data_021759c0->mUnk_62) {
            p->mUnk_104 = 1;
            p->mUnk_b4 = p->mUnk_a0;
            p->mUnk_b8 = p->mUnk_a4;
            p->mUnk_bc = 0;
            p->mUnk_c0 = 0;
            p->mUnk_c4 = 0;
            p->mUnk_d0 = 0;
            p->mUnk_d4 = 0x2000;
            p->mUnk_d8 = -0x40;
            p->mUnk_dc = 0x200;
            p->mUnk_e0 = 0;
            p->mUnk_e4 = 0;
            p->mUnk_f0 = 0;
            p->mUnk_f4 = 0x1000;
            p->mUnk_f8 = -0x30;
            p->mUnk_fc = 0x800;
            p->mUnk_100 = 0x100;
            p->mUnk_00.mUnk_78 = p->mUnk_00.mUnk_78 | data_021564bc;
            if ((p->mUnk_00.mUnk_78 & 4) == 0) {
                if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                    t = 2;
                } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                    t = 3;
                } else {
                    t = 4;
                }
                s2.mUnk_00 = 0x16f;
                s2.mUnk_04 = &p->mUnk_00.mUnk_04;
                s2.mUnk_08 = t;
                s2.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
                func_0210b7a8(&s2);
            }
        }
        if ((p->mUnk_00.mUnk_02 & 0x800) == 0) {
            p->mUnk_b0 = 6;
        }
        p->mUnk_00.mUnk_10.x = (s32) (((s64) a->mUnk_a4.x * -0x4cd) >> 12);
        p->mUnk_00.mUnk_10.y = (s32) (((s64) a->mUnk_a4.y * -0x4cd) >> 12);
        p->mUnk_00.mUnk_10.z = (s32) (((s64) a->mUnk_a4.z * -0x4cd) >> 12);
        p->mUnk_00.mUnk_10.y = 0x3800;
        return 12;
    }
tail:
    p->mUnk_00.mUnk_78 = p->mUnk_00.mUnk_78 | data_021564bc;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
    return 0;
}

u32 func_02096f54(Unk02096a04 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    u8 v1 = *b;
    u8 v2 = *c;
    if (p->mUnk_b0 != 4) {
        return 0;
    }
    if (v1 == 2) {
        p->mUnk_104 = 1;
        p->mUnk_b4 = p->mUnk_a0;
        p->mUnk_b8 = p->mUnk_a4;
        p->mUnk_bc = 0x4000;
        p->mUnk_c0 = 0x1333;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_c4 = 0;
        p->mUnk_d0 = 0;
        p->mUnk_d4 = 0x2000;
        p->mUnk_d8 = -0x40;
        p->mUnk_dc = 0x200;
        p->mUnk_e0 = 0;
        p->mUnk_e4 = 0;
        p->mUnk_f0 = 0;
        p->mUnk_f4 = 0x1000;
        p->mUnk_f8 = -0x30;
        p->mUnk_fc = 0x800;
        p->mUnk_100 = 0x100;
        p->mUnk_00.mUnk_78 = p->mUnk_00.mUnk_78 | data_021564b8;
        if ((p->mUnk_00.mUnk_02 & 0x800) == 0) {
            p->mUnk_b0 = 7;
        }
    }
    return v2;
}

s32 func_02096df0(Unk02096a04 *p, const Vec3 *a, s32 b, Vec3 *c) {
    Vec3 s;
    s32 d;
    func_021484d0(a, &p->mUnk_00.mUnk_04, &s);
    if (s.y >= p->mUnk_a0 + b) {
        return 0;
    }
    d = func_021482cc(&s);
    if (d >= p->mUnk_00.mUnk_58.x + b) {
        return 0;
    }
    if (p->mUnk_b0 == 1) {
        c->x = 0;
        c->y = 0;
        c->z = 0;
        return 1;
    }
    if (p->mUnk_b0 == 4 || (p->mUnk_b0 == 5 && p->mUnk_a0 > 0x7800)) {
        if ((s64) s.x * s.x + (s64) s.y * s.y + (s64) s.z * s.z >= 0x10) {
            func_02039860(&s, &s);
        }
        d = p->mUnk_00.mUnk_58.x + b - d;
        c->x = (s32) (((s64) s.x * d) >> 12);
        c->y = (s32) (((s64) s.y * d) >> 12);
        c->z = (s32) (((s64) s.z * d) >> 12);
        return 1;
    }
    c->x = 0;
    c->y = 0;
    c->z = 0;
    return 1;
}

void func_02096d68(void *a) {
    data_0217b0f0 = func_0209bd08(a, "cover.nsbmd");
    data_0217b0f4 = func_0209bc74(a, "poo.nsbmd", "poo.nsbtp");
    data_0217b0ec = func_0209bd08(a, "hole.nsbmd");
    func_0209b940(data_0217b0f4, 0x3f);
    func_0209b940(data_0217b0ec, 0x3f);
}

void func_02096a04(void *a, Unk02096a04 *p) {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m[9];
    s32 f0[3];
    s32 f1[3];
    s32 f2[3];
    s32 f3[3];
    s32 f4[3];
    u16 e;
    s32 k;
    s32 v1;
    s32 j;
    s32 r;
    s32 t;
    w0 = 0x1e;
    func_01ff9048(0x14, &w0, 1);
    func_01ff9048(0x11, 0, 0);
    f0[1] = p->mUnk_a8 >> 4;
    f0[0] = 0;
    f0[2] = 0;
    func_01ff9048(0x1c, f0, 3);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 12);
    func_0209bbd0(a, data_0217b0ec);
    func_0209bb2c(a, data_0217b0ec, p);
    w1 = 1;
    func_01ff9048(0x12, &w1, 1);
    switch (p->mUnk_b0) {
        case 1:
        case 2:
        case 6:
            func_0209b688(data_0217b0f4, 0);
            break;
        case 4:
        case 5:
        case 7:
            func_0209b688(data_0217b0f4, 1);
            break;
    }
    if (p->mUnk_b0 != 0) {
        func_01ff9048(0x11, 0, 0);
        if (p->mUnk_104 != 0) {
            t = p->mUnk_b8 >> 4;
            f1[0] = 0;
            f1[1] = t;
            f1[2] = 0;
            func_01ff9048(0x1c, f1, 3);
        } else {
            t = p->mUnk_a4 >> 4;
            f2[0] = 0;
            f2[1] = t;
            f2[2] = 0;
            func_01ff9048(0x1c, f2, 3);
        }
        func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 12);
        func_0209bbd0(a, data_0217b0f4);
        func_0209bb2c(a, data_0217b0f4, p);
        w2 = 1;
        func_01ff9048(0x12, &w2, 1);
    }
    if (p->mUnk_104 == 1) {
        goto L;
    }
    if (p->mUnk_104 == 2) {
    L:
        e = p->mUnk_c8;
        k = ((u16) p->mUnk_e8 >> 4) * 2;
        v1 = data_0215d4b4[k];
        r = (s32) (((s64) v1 * 0x7000) >> 12);
        if (r <= 0) {
            r = -r;
        }
        t = p->mUnk_b4 + r;
        func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 12);
        f3[1] = t >> 4;
        f3[0] = 0;
        f3[2] = 0;
        func_01ff9048(0x1c, f3, 3);
        j = (e >> 4) * 2;
        func_02146d44(m, data_0215d4b4[j], data_0215d4b4[j + 1]);
        func_01ff9048(0x1a, m, 9);
        func_02146d60(m, v1, data_0215d4b4[k + 1]);
        func_01ff9048(0x1a, m, 9);
    } else {
        t = p->mUnk_a0 >> 4;
        f4[0] = 0;
        f4[1] = t;
        f4[2] = 0;
        func_01ff9048(0x1c, f4, 3);
        func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 12);
    }
    func_0209bbd0(a, data_0217b0f0);
    func_0209bb2c(a, data_0217b0f0, p);
}

void func_020968f4(Unk020968f4 *p) {
    s32 i;
    Unk02096a04 *o;
    Unk020f41c4_B *v1;
    if (p == 0) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != 0; i++) {
        o->mUnk_a8 = 0x1000;
        v1 = func_020d22d0();
        v1->mUnk_00 = (s64) v1->mUnk_08 * (s64) v1->mUnk_00 + v1->mUnk_10;
        o->mUnk_ac = (u16) (o->mUnk_00.mUnk_9c->mUnk_28 + (u16) (((u64) (u32) (v1->mUnk_00 >> 32) * 60) >> 32) - 30);
        if (data_021759c0->mUnk_08 == 4) {
            o->mUnk_b0 = 3;
            o->mUnk_a0 = 0x2000;
            o->mUnk_a4 = -0xd000;
        } else {
            o->mUnk_b0 = 0;
            o->mUnk_a0 = 0x2000;
            o->mUnk_a4 = -0xd000;
        }
    }
}

s32 func_020968dc(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

s32 func_020968c0(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}
