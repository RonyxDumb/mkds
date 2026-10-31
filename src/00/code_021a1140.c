#include "00/code_021a1140.h"
#include "00/code_02188720.h"
#include "00/code_021a3264.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

void func_ov000_021a1140(s32 a) {
    vu16 h;
    vu16 g;

    data_ov000_021b566c->mUnk_0c = 0;
    data_ov000_021b566c->mUnk_174[0] = 0;
    data_ov000_021b566c->mUnk_176 = func_ov000_021a3448(0x10000);
    data_ov000_021b566c->mUnk_178 = 0;
    data_ov000_021b566c->mUnk_17c = 0;
    data_ov000_021b566c->mUnk_184 = 0;
    data_ov000_021b566c->mUnk_19c = 0;
    data_ov000_021b566c->mUnk_1a1 = 0;
    data_ov000_021b566c->mUnk_1a2 = 0;
    data_ov000_021b566c->mUnk_1a3[0] = 0;
    data_ov000_021b566c->mUnk_1a3[1] = 0;
    data_ov000_021b566c->mUnk_19f = 0;
    data_ov000_021b566c->mUnk_1a0 = 0;
    data_ov000_021b566c->mUnk_1a8 = 0;
    data_ov000_021b566c->mUnk_1aa = 0;
    data_ov000_021b566c->mUnk_1ac = 0;
    data_ov000_021b566c->mUnk_1d0 = 0;
    data_ov000_021b566c->mUnk_1e0 = 0;
    func_0214d018_inline(&data_ov000_021b566c->mUnk_3b4, 0x98);
    if (a == 2) {
        data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
        if (data_ov000_021b566c->mUnk_15 == 3) {
            data_ov000_021b566c->mUnk_198 = 1;
            return;
        }
        if (data_ov000_021b566c->mUnk_15 == 2) {
            data_ov000_021b566c->mUnk_198 = 10;
            return;
        }
    } else {
        data_ov000_021b566c->mUnk_0d = 0;
        data_ov000_021b566c->mUnk_0e = 0;
        data_ov000_021b566c->mUnk_14 = 0;
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
        data_ov000_021b566c->mUnk_e8 = 0;
        data_ov000_021b566c->mUnk_19d = 0;
        data_ov000_021b566c->mUnk_1a6 = 0;
        data_ov000_021b566c->mUnk_1b0 = 0;
        data_ov000_021b566c->mUnk_1b4 = 0;
        data_ov000_021b566c->mUnk_1bc = 0;
        data_ov000_021b566c->mUnk_1c0 = 0;
        data_ov000_021b566c->mUnk_1c8 = 0;
        data_ov000_021b566c->mUnk_1ec = 0;
        data_ov000_021b566c->mUnk_1f0 = 0;
        data_ov000_021b566c->mUnk_2d8 = 0;
        func_0214d018_inline(data_ov000_021b566c->mUnk_24, 0x80);
        h = 0;
        func_0214cfe4(h, data_ov000_021b566c->mUnk_a4, 0x40);
        func_0214d018_inline(data_ov000_021b566c->mUnk_f4, 0x80);
        func_0214d018_inline(data_ov000_021b566c->mUnk_18c, 0xc);
        func_0214d018_inline(data_ov000_021b566c->mUnk_1f8, 0x80);
        g = 0;
        func_0214cfe4(g, data_ov000_021b566c->mUnk_278, 0x40);
        func_0214d168(data_ov000_021b566c->mUnk_2b8, 0, 0x20);
        func_0214d018_inline(data_ov000_021b566c->mUnk_330, 0x84);
        if (a == 1) {
            if (data_ov000_021b566c->mUnk_15 == 0) {
                data_ov000_021b566c->mUnk_198 = 3;
                return;
            }
            if (data_ov000_021b566c->mUnk_15 == 1) {
                data_ov000_021b566c->mUnk_198 = 4;
                return;
            }
        } else {
            data_ov000_021b566c->mUnk_15 = 0;
            data_ov000_021b566c->mUnk_16 = 0;
            data_ov000_021b566c->mUnk_18 = 0;
            data_ov000_021b566c->mUnk_1f4 = 0;
            data_ov000_021b566c->mUnk_19e = 0;
            data_ov000_021b566c->mUnk_454 = 0;
            data_ov000_021b566c->mUnk_458 = 0;
        }
    }
}
