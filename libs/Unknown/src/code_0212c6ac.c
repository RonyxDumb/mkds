#include "code_0212c6ac.h"
#include "code_0212da38.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"

s32 func_0212c700(u32 a, Unk0212d9dc *b, u32 c) {
    Unk0212c700 *p;
    Unk0212d9dc *q;

    p = func_0212db7c(b, c + 0x14, func_0212bd10, 0, 0);
    if (p == 0) {
        return 0;
    }
    p->mUnk_0c = 0;
    p->mUnk_10 = a;
    p->mUnk_08 = 0;
    q = func_0212dcc8(p->mUnk_14, c);
    if (q == 0) {
        return 0;
    }
    p->mUnk_08 = q;
    func_020174a4(&data_0217d89c[a].mUnk_0c, p);
    return 1;
}

void func_0212c6f0(Unk0212c400 **a, u32 b) {
    func_0212c018(*a, b);
}

void func_0212c6ac(u32 a) {
    s32 i;
    Unk0212c400 *p;

    for (i = 0, p = data_0217d45c; i < 16; i++) {
        if (p->mUnk_2c != 0) {
            func_0212c018(p, a);
        }
        p++;
    }
}
