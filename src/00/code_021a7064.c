#include "00/code_021a7064.h"
#include "00/code_021a7088.h"

Unk021a7064 *func_ov000_021a7064(Unk021a7064Func param_1, Unk021a6fa8 *param_2, s32 param_3) {
    Unk021a7064 *a;

    a = func_ov000_021a7088(param_3);
    if (a != 0) {
        a->mUnk_00 = param_1;
        a->mUnk_04 = param_2;
        a->mUnk_0d = param_3;
        a->mUnk_0c = param_2->mUnk_73;
    }
    return a;
}
