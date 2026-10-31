#include "00/code_0219d674.h"
#include "00/code_0218f960.h"
#include "00/code_0219cfc0.h"
#include "00/code_0219d000.h"

void func_ov000_0219d674(struct Unk0218f960 *a, s32 *b) {
    Unk0218ec44 c;
    u32 d;
    Unk021b5664 *e;
    if (data_ov000_021b5664->mUnk_34 != 0) {
        d = func_ov000_0219d5e4(b[0]);
        if (d != -1) {
            func_ov000_0218ec44(a, b[2], &c);
            e = data_ov000_021b5664;
            e->mUnk_34(d, c.mUnk_004, c.mUnk_108, e->mUnk_38);
        }
    }
}
