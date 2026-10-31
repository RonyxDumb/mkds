#include "00/code_0219b5a8.h"
#include "00/code_0219b844.h"
#include "00/code_0219b8a8.h"
#include "00/code_021a15b0.h"
#include "00/code_021a17bc.h"

void func_ov000_0219b5a8(u32 a, u32 b, u32 c, u32 d, u32 e) {
    s32 f;
    Unk021b54c8 *h;

    if (a == 0 && b != 0) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_198 == 0) {
            func_ov000_021a1a10();
            func_ov000_0219b8a8(3);
        }
    } else if (a == 0) {
        func_ov000_0219b8a8(6);
        for (f = 0; f <= data_ov000_021b54c8->mUnk_33c.mUnk_0d; f++) {
            if (data_ov000_021b54c8->mUnk_30 == data_ov000_021b54c8->mUnk_33c.mUnk_f4[f]) {
                data_ov000_021b54c8->mUnk_2c = data_ov000_021b54c8->mUnk_33c.mUnk_2b8[f];
                break;
            }
        }
    }
    data_ov000_021b54c8->mUnk_33c.mUnk_2d8 =
        func_ov000_0219b844(data_ov000_021b54c8->mUnk_33c.mUnk_2b8, data_ov000_021b54c8->mUnk_33c.mUnk_0d + 1);
    func_ov000_021a15b0();
    h = data_ov000_021b54c8;
    if (h->mUnk_33c.mUnk_15 == 2 || h->mUnk_33c.mUnk_15 == 3) {
        h = data_ov000_021b54c8;
        h->mUnk_74(a, b, c, d, e, h->mUnk_78);
    } else {
        h->mUnk_6c(a, b, h->mUnk_70);
    }
}
