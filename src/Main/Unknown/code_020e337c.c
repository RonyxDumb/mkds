#include "Main/Unknown/code_020e337c.h"

#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020f9c6c.h"

void func_020e3414(Unk020e1e98 *a) {
    Unk0210b7a8 buf;
    s32 v;

    a->mUnk_000.mUnk_04.y = a->mUnk_000.mUnk_04.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mUnk_04.y >= a->mUnk_0ac) {
        return;
    }
    if ((a->mUnk_000.mUnk_78 & 0x4) == 0) {
        v = a->mUnk_000.mUnk_70 == data_0217ca6c[2].mUnk_20 ? 2
                                                            : (a->mUnk_000.mUnk_70 == data_0217ca6c[3].mUnk_20 ? 3 : 4);
        buf.mUnk_00 = 0x128;
        buf.mUnk_04 = &a->mUnk_000.mUnk_04;
        buf.mUnk_08 = v;
        buf.mUnk_0c = func_020d4ef4(&a->mUnk_000.mUnk_04);
        func_0210b7a8(&buf);
    }
    a->mUnk_000.mUnk_80.mUnk_10 = 4;
    a->mUnk_000.mUnk_80.mUnk_12 = 1;
}

void func_020e33c0(Unk020e1e98 *a) {
    a->mUnk_000.mUnk_04.y = a->mUnk_0ac;
    a->mUnk_000.mUnk_10.y = 0x4800;
    a->mUnk_000.mUnk_02 &= ~0x1;
    if ((a->mUnk_000.mUnk_78 & 0x3) != 0) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    func_0208b7bc(0x30, &a->mUnk_000.mUnk_9c->mUnk_00);
}

void func_020e337c(Unk020e1e98 *a) {
    a->mUnk_000.mUnk_10.y -= 0x266;
    a->mUnk_000.mUnk_04.y = a->mUnk_000.mUnk_04.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mUnk_04.y < a->mUnk_0b0) {
        a->mUnk_000.mUnk_80.mUnk_10 = 5;
        a->mUnk_000.mUnk_80.mUnk_12 = 1;
    }
}
