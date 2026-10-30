#include "Main/Unknown/code_0203a3cc.h"

// non-matching: same instructions, but the index (a * 0x5c) is in r2 and the halfword at 0x4c in r3; the original has
// the index in r3 and the halfword in r2.
u32 func_0203a3cc(u32 a) {
    u32 r;
    u32 f;
    u16 x;
    r = 0;
    f = 0;
    x = data_02175628[a].mUnk_4c;
    if (x == 0 && data_02175628[a].mUnk_58 < 5) {
        f = 1;
    }
    if (f == 0 && data_02175628[a].mUnk_54 == 0 && x != 0) {
        r = 1;
    }
    return r;
}
