#include "code_020162b0.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

void func_02016414(u32 a, s32 b) {
    data_02173214.mUnk_08 = a;
    func_020162b0();
    if (b != 0) {
        data_021619f4 = (u32(*)(s32, s32, s32)) func_020162d4;
        data_021619f8 = (void (*)(void *)) func_020162cc;
    }
}

// non-matching: 3 extra instructions. The pool constant 0x7fff8 and the result p land in r3 and r2 (the original
// keeps the constant in ip and p in r3), and the two failure branches of the c != 1 arm go to separate blocks (the
// original shares one block).
u32 func_020162d4(u32 a, s32 b, s32 c) {
    u32 p;
    u32 e;
    u32 r;
    u32 pad;
    u32 end;
    if (a == 0) {
        a = 8;
    } else {
        a = (a + 7) & ~7;
    }
    if (a >= 0x7fff8) {
        return 0;
    }
    p = 0;
    if (c == 1) {
        e = data_02173214.mUnk_00;
        if (b != 0) {
            pad = (8 - (e & 7)) & 7;
        } else {
            pad = (16 - (e & 0xf)) & 0xf;
        }
        r = a + pad;
        if (data_02173214.mUnk_04 - e >= r) {
            end = e + r;
            if (b != 0 && end > 0x10000) {
                e = 0;
            } else {
                p = e + pad;
                e = 1;
                data_02173214.mUnk_00 += r;
            }
        } else {
            e = 0;
        }
    } else {
        e = data_02173214.mUnk_04;
        if (e >= a) {
            if (b != 0) {
                pad = (e - a) & 7;
            } else {
                pad = (e - a) & 0xf;
            }
            r = a + pad;
            if (e - data_02173214.mUnk_00 >= r) {
                if (b != 0 && e > 0x10000) {
                    e = 0;
                } else {
                    e = 1;
                    data_02173214.mUnk_04 -= r;
                    p = data_02173214.mUnk_04;
                }
            } else {
                e = 0;
            }
        } else {
            e = 0;
        }
    }
    if (e != 0) {
        return ((p >> 3) & 0xffff) | ((a >> 3) << 16);
    }
    return 0;
}

u32 func_020162cc(void) {
    return 0;
}

void func_020162b0(void) {
    data_02173214.mUnk_00 = 0;
    data_02173214.mUnk_04 = data_02173214.mUnk_08;
}
