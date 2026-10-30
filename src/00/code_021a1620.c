#include "00/code_021a1620.h"

u32 func_ov000_021a1620(s32 param_1, s32 param_2) {
    Unk021b566c *p;
    u32 v1;
    u32 *m;
    s32 i;
    s32 n;
    s32 k;
    p = data_ov000_021b566c;
    if (p == 0) {
        return 0;
    }
    v1 = p->mUnk_f4[param_1];
    m = &p->mUnk_2d8;
    *m = *m & ~(1 << p->mUnk_2b8[param_1]);
    func_ov000_021a15b0();
    if (param_1 < param_2 - 1) {
        i = 0;
        n = param_2 - param_1;
        if (n > 0) {
            do {
                s32 a = param_1 + i;
                data_ov000_021b566c->mUnk_24[a] = data_ov000_021b566c->mUnk_24[a + 1];
                data_ov000_021b566c->mUnk_a4[a] = data_ov000_021b566c->mUnk_a4[a + 1];
                data_ov000_021b566c->mUnk_f4[a] = data_ov000_021b566c->mUnk_f4[a + 1];
                data_ov000_021b566c->mUnk_1f8[a] = data_ov000_021b566c->mUnk_1f8[a + 1];
                data_ov000_021b566c->mUnk_278[a] = data_ov000_021b566c->mUnk_278[a + 1];
                data_ov000_021b566c->mUnk_2b8[a] = data_ov000_021b566c->mUnk_2b8[a + 1];
                i++;
            } while (i < n);
        }
    }
    if (param_2 > 0) {
        k = param_2 - 1;
        data_ov000_021b566c->mUnk_24[k] = 0;
        data_ov000_021b566c->mUnk_a4[k] = 0;
        data_ov000_021b566c->mUnk_f4[k] = 0;
        data_ov000_021b566c->mUnk_1f8[k] = 0;
        data_ov000_021b566c->mUnk_278[k] = 0;
        data_ov000_021b566c->mUnk_2b8[k] = 0;
    }
    return v1;
}
