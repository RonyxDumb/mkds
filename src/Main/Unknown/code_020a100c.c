#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020a10ac(u16 a, s32 b) {
    data_0217b1fc->mUnk_000[a].mUnk_50 += b;
}

int func_020a1084(int a) {
    if (data_0217b1fc->mUnk_000[a].mUnk_08 != 0) {
        return 1;
    }
    return 0;
}

s32 func_020a1048(u16 a) {
    Unk0217b1fc *d;
    s32 r;
    s32 v;

    d = data_0217b1fc;
    r = 0;
    v = d->mUnk_000[a].mUnk_4c;
    if (d->mUnk_3b0 == v) {
        if (d->mUnk_3ac != v) {
            r = 1;
        }
    }
    return r;
}

s32 func_020a100c(s32 a) {
    Unk0217b1fc_000 *e;
    s32 r;

    e = &data_0217b1fc->mUnk_000[a];
    r = 0;
    if (data_0217b1fc->mUnk_3b4 == e->mUnk_46) {
        if (data_0217b1fc->mUnk_3a8 < 0) {
            r = 1;
        }
    }
    return r;
}
