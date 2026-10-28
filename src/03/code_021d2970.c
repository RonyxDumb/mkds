#include "03/code_021d2970.h"
#include "03/code_021d2a34.h"

void func_ov003_021d2970(const Unk021d299c *input) {
    Unk021d299c rect;
    rect.mUnk_00 = input->mUnk_00;
    rect.mUnk_02 = input->mUnk_02;
    rect.mUnk_04 = input->mUnk_00 + input->mUnk_04;
    rect.mUnk_06 = input->mUnk_02 + input->mUnk_06;
    func_ov003_021d2a34(&rect);
}
