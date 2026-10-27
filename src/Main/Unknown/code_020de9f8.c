#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020deb2c.h"
#include "Main/Unknown/unk_021759c0.h"

u8 func_020dea50(Unk020de6a8 *a, Unk020dea50_1 *b, void *c, u8 *d) {
    s32 v;
    s32 n;
    u32 m;

    if ((b->mUnk_7c & 0x400000) != 0) {
        return 0;
    }
    n = 0;
    a->mUnk_0a4 = 0;
    a->mUnk_002 |= data_021585a4;
    m = a->mUnk_078 & 3;
    v = data_021759c0->mUnk_70[b->mUnk_74].mUnk_00;
    if ((u32) v <= 3) {
        if (((1 << v) & 0xd) != 0) {
            n = 1;
        }
    }
    func_020deb2c(&a->mUnk_004, b, n != 0 ? a->mUnk_0f2 : a->mUnk_0f4, (int) m, a->mUnk_0ac);
    if (a->mUnk_0f8 != 0 || a->mUnk_09c->mUnk_32 != 0) {
        a->mUnk_0a4 = 0x80;
        func_020d2398((Unk020e71a0 *) a);
    }
    return *d;
}

u32 func_020de9f8(Unk020de6a8 *a) {
    if (a->mUnk_0f8 != 0) {
        return 0x270f000;
    }
    if (a->mUnk_0a8 == 0) {
        return 0;
    }
    return func_020d8828(&a->mUnk_108.mUnk_00, &a->mUnk_004);
}
