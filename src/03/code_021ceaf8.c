#include "03/code_021ceaf8.h"

void func_ov003_021ceaf8(Unk021d34e0 *param_1) {
    u32 w;
    s32 h;

    func_ov003_021d1770(data_ov003_021da284->mUnk_00, 0, &w, &h);
    h += 0xc;
    func_ov003_021cec50();
    if (h >= 192) {
        if (data_ov003_021da284->mUnk_1e != 0) {
            func_ov003_021d34e0(param_1, func_ov003_021ceab8);
            return;
        }
        func_ov003_021d34e0(param_1, func_ov003_021cea3c);
    }
}
