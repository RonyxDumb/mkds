#include "03/code_021d1770.h"

void func_ov003_021d1770(Unk021d1770 *param_1, int param_2, u32 *param_3, s32 *param_4) {
    Unk021d1770_08 *t;

    t = param_1->mUnk_08;
    *param_3 = (t[param_2].mUnk_00 & 0x01ff0000) >> 0x10;
    *param_4 = t[param_2].mUnk_00 & 0xff;
}
