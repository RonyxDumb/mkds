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

void func_020f5978(Unk0206bcb0 *a) {
    u16 x;
    u16 v;
    u16 n;

    x = (u16) (!(*(u16 *) &a->mUnk_78 & 0x8000) ? (u16) (*(u16 *) &a->mUnk_78 & ~0xff00) : 8);
    if (x >= 8) {
        v = 8;
    } else {
        n = (u16) (func_0203c8dc(x) - 1);
        if (n < 1) {
            n = data_021759c0->mUnk_3d0;
        }
        v = (u16) data_0217561c->mUnk_474[(u8) n - 1];
    }
    func_020ec918((Unk020ec8bc *) a, 0xd000, 0x29, v, 0);
    if (!(*(u32 *) &a->mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (*(u32 *) &a->mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_240 > 0x708) {
        func_020f29e8((u32) a);
        ((u16 *) &a->mUnk_244)[4] = 1;
        ((u16 *) &a->mUnk_244)[5] = 1;
        return;
    }
    if (a->mUnk_240 > 0x10) {
        if (func_020f11f0((u32) a, 1) == 0) {
            return;
        }
        ((u16 *) &a->mUnk_244)[4] = 4;
        ((u16 *) &a->mUnk_244)[5] = 1;
        if (!(*(u32 *) &a->mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, ((s16 *) &a->mUnk_4c)[1]);
        return;
    }
    if (a->mUnk_240 > 4) {
        if (func_020f1180(a, 1) == 0) {
            return;
        }
        ((u16 *) &a->mUnk_244)[4] = 4;
        ((u16 *) &a->mUnk_244)[5] = 1;
        if (!(*(u32 *) &a->mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, ((s16 *) &a->mUnk_4c)[1]);
    }
}
