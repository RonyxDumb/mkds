#include "00/code_021a3f78.h"

void func_ov000_021a3f78(Unk021a4a08 *param_1, Unk021a471c *param_2) {
    param_2->mUnk_800 = 1;
    param_2->mUnk_000[0] = 0x5c;
    func_ov000_021a3fc8(param_1, param_2, 0);
    func_ov000_021a3fc8(param_1, param_2, 1);
    func_ov000_021a3fc8(param_1, param_2, 2);
    func_ov000_021a471c(param_2, data_ov000_021b43e4);
    param_2->mUnk_800 = param_2->mUnk_800 + -1;
    return;
}
