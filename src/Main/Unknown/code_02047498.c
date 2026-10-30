#include "Main/Unknown/code_02047498.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void func_02047498(const void *a, s32 b) {
    Unk021759c8_9b0 *p = &data_021759c8->mUnk_9b0[b];
    func_0204f4d0(a, p->mUnk_00, &p->mUnk_04, p->mUnk_08_0, p->mUnk_08_29);
    p->mUnk_08_31 = 1;
}

#pragma thumb off
