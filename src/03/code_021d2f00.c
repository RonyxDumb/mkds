#include "03/code_021d2f00.h"
#include "03/code_021d1000.h"
#include "03/code_021d2fa0.h"
#include "03/unk_021da000.h"

void func_ov003_021d2f00(u32 *a) {
    Unk021d2fa0 *b;
    s32 c = 0;

    *a = (*a & 0xc1fffcff) | 0x200;
    b = *(Unk021d2fa0 **) data_ov003_021da2f0;
    if ((u32) a >= (u32) b + 0x400) {
        c = 1;
    }
    func_ov003_021d1d0c((Unk021d1d88 *) b->mUnk_800[c], a);
}
