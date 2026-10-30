#include "Main/Unknown/code_02095fec.h"
#include "Main/Unknown/code_020968c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"

static inline u16 func_02095fec_inline(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline void func_02095fec_inline_2(Unk02096a04 *p, s32 n) {
    Unk0210b7a8 s;
    s32 v;

    if (p->mUnk_00.mUnk_78 & 4) {
        return;
    }
    if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
        v = 2;
    } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
        v = 3;
    } else {
        v = 4;
    }
    s.mUnk_00 = n;
    s.mUnk_04 = &p->mUnk_00.mUnk_04;
    s.mUnk_08 = v;
    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
    func_0210b7a8(&s);
}

void func_02095fec(void *a, Unk02096a04 *p) {
    s32 v;

    p->mUnk_00.mUnk_10.y = 0;
    switch (p->mUnk_104) {
        case 0:
            break;
        case 1:
            p->mUnk_b8 += p->mUnk_c0;
            p->mUnk_c0 -= 0x800;
            if (p->mUnk_b4 >= 0x2000) {
                p->mUnk_b4 += p->mUnk_bc;
                p->mUnk_bc -= 0x19a;
            } else {
                p->mUnk_b4 = 0x2000;
                p->mUnk_104 = 2;
                func_02095fec_inline_2(p, 0x16c);
            }
            break;
        case 2:
            if (p->mUnk_b8 >= 0x2000) {
                p->mUnk_b8 += p->mUnk_c0;
                p->mUnk_c0 -= 0x800;
            }
            p->mUnk_c4 += p->mUnk_dc;
            p->mUnk_cc = p->mUnk_d0 + func_020968c0(p->mUnk_d4, func_020968dc(p->mUnk_c4)) - p->mUnk_c8;
            p->mUnk_c8 += p->mUnk_cc;
            if (p->mUnk_d4 > 0) {
                v = p->mUnk_d4 + p->mUnk_d8;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_d4 = v;
            } else if (p->mUnk_d4 < 0) {
                v = p->mUnk_d4 + p->mUnk_d8;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_d4 = v;
            }
            if (p->mUnk_dc > 0) {
                v = p->mUnk_dc + p->mUnk_e0;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_dc = v;
            } else if (p->mUnk_dc < 0) {
                v = p->mUnk_dc + p->mUnk_e0;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_dc = v;
            }
            p->mUnk_e4 += p->mUnk_fc;
            p->mUnk_ec = p->mUnk_f0 + func_020968c0(p->mUnk_f4, func_020968dc(p->mUnk_e4)) - p->mUnk_e8;
            p->mUnk_e8 += p->mUnk_ec;
            if (p->mUnk_f4 > 0) {
                v = p->mUnk_f4 + p->mUnk_f8;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_f4 = v;
            } else if (p->mUnk_f4 < 0) {
                v = p->mUnk_f4 + p->mUnk_f8;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_f4 = v;
            }
            if (p->mUnk_fc > 0) {
                v = p->mUnk_fc + p->mUnk_100;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_fc = v;
            } else if (p->mUnk_fc < 0) {
                v = p->mUnk_fc + p->mUnk_100;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_fc = v;
            }
            if (p->mUnk_f4 == 0 && p->mUnk_b0 != 2 && p->mUnk_b0 != 5) {
                p->mUnk_104 = 0;
            }
            break;
    }
    if ((p->mUnk_b0 == 6 || p->mUnk_b0 == 7) && p->mUnk_104 == 0) {
        if (data_021759c0->mUnk_08 == 4) {
            p->mUnk_b0 = 3;
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
        } else {
            p->mUnk_b0 = 0;
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
        }
    }
    switch (p->mUnk_b0) {
        case 0:
            if (p->mUnk_ac-- > 0) {
                return;
            }
            p->mUnk_ac = (u16) (func_02095fec_inline(30) + 30);
            p->mUnk_b0 = 1;
            p->mUnk_104 = 0;
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d3);
            break;
        case 1:
            if (p->mUnk_a0 < 0x7800) {
                p->mUnk_a0 += 0x400;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            if (p->mUnk_ac-- > 0) {
                p->mUnk_a0 = 0x7800;
                p->mUnk_a4 = -0x7800;
                return;
            }
            p->mUnk_a0 = 0x7800;
            p->mUnk_a4 = -0x7800;
            p->mUnk_b0 = 2;
            break;
        case 2:
            if (p->mUnk_a0 > 0x2000) {
                p->mUnk_a0 -= 0x400;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
            p->mUnk_ac = (u16) (func_02095fec_inline(15) + 15);
            p->mUnk_b0 = 3;
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d4);
            break;
        case 3:
            if (p->mUnk_ac-- > 0) {
                return;
            }
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
            p->mUnk_ac = (u16) (func_02095fec_inline(90) + 90);
            p->mUnk_b0 = 4;
            p->mUnk_104 = 0;
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d3);
            break;
        case 4:
            if (p->mUnk_a0 < 0x124cd) {
                p->mUnk_a0 += 0xc00;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            if (p->mUnk_ac-- > 0) {
                p->mUnk_a0 = 0x124cd;
                p->mUnk_a4 = 0x34cd;
                return;
            }
            p->mUnk_a0 = 0x124cd;
            p->mUnk_a4 = 0x34cd;
            p->mUnk_b0 = 5;
            break;
        case 5:
            if (p->mUnk_a0 > 0x2000) {
                p->mUnk_a0 -= 0xc00;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            p->mUnk_ac = (u16) (p->mUnk_00.mUnk_9c->mUnk_28 + func_02095fec_inline(60) - 30);
            if (data_021759c0->mUnk_08 == 4) {
                p->mUnk_b0 = 3;
                p->mUnk_a0 = 0x2000;
                p->mUnk_a4 = -0xd000;
            } else {
                p->mUnk_b0 = 0;
                p->mUnk_a0 = 0x2000;
                p->mUnk_a4 = -0xd000;
            }
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d4);
            break;
    }
}
