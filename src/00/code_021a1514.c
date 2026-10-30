#include "00/code_021a1514.h"

// non-matching: original loads the data pointer into r5 (the byte cursor) and copies it to r3 (adds r3, r5, #0), ours loads r3 and copies to r5 (3 words differ, same size)
u32 func_ov000_021a1514(void **param_1) {
    s32 i;
    u8 *c;
    u8 *q;
    Unk021b566c *p;
    u8 b;
    if (data_ov000_021b566c == 0) {
        return 0;
    }
    func_0214d168(data_ov000_021b5678, 0, 0x20);
    i = 0;
    p = data_ov000_021b566c;
    if (i <= p->mUnk_0e) {
        q = data_ov000_021b5678;
        c = (u8 *) p;
        do {
            b = c[0x2b8];
            if ((p->mUnk_2d8 & (1 << b)) == 0) {
                break;
            }
            *q = b;
            c++;
            q++;
            i++;
        } while (i <= p->mUnk_0e);
    }
    *param_1 = data_ov000_021b5678;
    return data_ov000_021b566c->mUnk_0e + 1;
}
