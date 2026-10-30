#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"

void func_0207ffa4(Unk02080b1c *a, u32 b, Unk02080b1c_00 *c) {
    a->mUnk_08 = data_021557ec;
    a->mUnk_04 = c;
    a->mUnk_00 = a->mUnk_04->mUnk_00[0];
    func_021484d0(a->mUnk_00->mUnk_18, a->mUnk_04->mUnk_18, &a->mUnk_08);
    func_02039860(&a->mUnk_08, &a->mUnk_08);
    a->mUnk_14 = 0;
    a->mUnk_18 = 0;
    a->mUnk_1c = b;
}
