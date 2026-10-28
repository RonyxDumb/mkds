#include "00/code_0219f4c4.h"

u32 func_ov000_0219f4c4(u32 *param_1, u32 param_2) {
    Unk021b566c *p;
    u32 i;
    p = data_ov000_021b566c;
    if (p->mUnk_19e != 0 && p->mUnk_198 == 4) {
        return 1;
    }
    for (i = 0; i < param_2; i++) {
        if (func_ov000_0218eb9c(p->mUnk_00, *param_1) == 0) {
            return 0;
        }
        p = data_ov000_021b566c;
        if (p->mUnk_19e != 0 && p->mUnk_198 == 1) {
            return 1;
        }
        param_1++;
    }
    return 1;
}
