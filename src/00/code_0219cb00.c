#include "00/code_0219cb00.h"

void func_ov000_0219cb00(void) {
    Unk021b5664 *p = data_ov000_021b5664;
    if (p->mUnk_20 == 0) {
        func_ov000_0219d734(0xb, -70009);
        return;
    }
    p->mUnk_20--;
}

void func_ov000_0219cb30(void) {
    Unk021b5664 *p = data_ov000_021b5664;
    if (p->mUnk_20 == -1) {
        func_ov000_0219d734(0xb, -70009);
        return;
    }
    p->mUnk_20++;
}

// non-matching: size 0x98 against 0x9c; the last argument is kept in r5 and r6 is pushed as well, the original pushes
// r4 and r5 only and reads that argument again from [sp, #0x18] at the two callback calls
void func_ov000_0219cb64(u32 a, u32 b, s32 c, u32 d, s32 e, u32 f, u32 g) {
    u32 t;
    t = g;
    func_ov000_0219cb00();
    if (t == 0x80000001) {
        if (e != 0) {
            if (data_ov000_021b5664->mUnk_00 == 1) {
                data_ov000_021b5664->mUnk_1f++;
            } else {
                t = 0;
            }
        } else {
            func_ov000_0219d734(6, -72220);
        }
    }
    if ((t & 0x80000000) == 0) {
        if (e != 0) {
            if (data_ov000_021b5664->mUnk_4c != 0) {
                data_ov000_021b5664->mUnk_4c(1, (u32) (c - 2) <= 1 ? 1 : 0, g);
            }
        } else {
            func_ov000_0219d734(6, -72220);
            if (data_ov000_021b5664->mUnk_4c != 0) {
                data_ov000_021b5664->mUnk_4c(0, 0, g);
            }
        }
    }
}
