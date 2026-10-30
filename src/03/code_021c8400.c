#include "03/code_021c8400.h"

u32 func_ov003_021c8400(void) {
    Unk021d299c a;
    Unk021d299c *b;
    s32 c;
    s32 d;
    s32 e;
    Unk021d299c *f;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return 0xe;
    }
    c = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    b = &a;
    a = data_ov003_021d643c;
    for (d = 0; d < 4; d++, c++, a.mUnk_02 += 0x1d) {
        if (c != 2 && c != 6) {
            if (func_ov003_021d2970(b) != 0) {
                return data_ov003_021d6454[c];
            }
        }
    }
    e = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 2) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 2;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 3;
            }
            break;
        }
    }
    e = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 6) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 7;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 8;
            }
            break;
        }
    }
    d = 0;
    f = data_ov003_021d649c;
    for (; d < 3; d++) {
        if (func_ov003_021d2a34(f) != 0) {
            return d + 0xb;
        }
        f++;
    }
    return 0xe;
}
