#include "code_02022030.h"

void func_02022040(Unk02022030 *a) {
    if ((a->mUnk_10 > 0) ^ a->mUnk_04) {
        a->mUnk_00 = &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_02];
    } else {
        a->mUnk_00 = &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_00] - 1;
    }
    a->mUnk_0c = 0;
}

void func_02022030(Unk02022030 *a, Unk02021dc8 *b) {
    a->mUnk_18 = b;
    func_02022040(a);
}
