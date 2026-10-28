#include "Main/Unknown/code_020f5978.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020ee684.h"

void func_020f5978(Unk020f5d6c *a) {
    u16 x;
    u16 v;
    u16 n;

    x = (u16) (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                   ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                   : 8);
    if (x >= 8) {
        v = 8;
    } else {
        n = (u16) (func_0203c8dc(x) - 1);
        if (n < 1) {
            n = data_021759c0->mUnk_3d0;
        }
        v = (u16) data_0217561c->mUnk_474[(u8) n - 1];
    }
    func_020ec918(&a->mUnk_000, 0xd000, 0x29, v, 0);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 0x708) {
        func_020f29e8((u32) a);
        a->mUnk_23c.mUnk_10 = 1;
        a->mUnk_23c.mUnk_12 = 1;
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 0x10) {
        if (func_020f11f0((u32) a, 1) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 4) {
        if (func_020f1180(a, 1) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
    }
}
