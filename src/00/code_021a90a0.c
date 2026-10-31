#include "00/code_021a90a0.h"
#include "00/code_021a8db8.h"
#include "00/code_021a7000.h"

s32 func_ov000_021a90a0(s32 v1, void *v2, s32 v3, s32 v4, void *v5) {
    Unk021a8e18 *a;
    u16 b;
    u32 c;
    s32 d = func_ov000_021a7de0(v1, (unsigned int) v2, v3, (unsigned int) &b, (unsigned int) &c, v4);
    if (d >= 0 && v5 != 0) {
        a = v5;
        a->mUnk_02 = ((b >> 8) & 0xff) | ((b << 8) & 0xff00);
        a->mUnk_04 = ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00)));
    }
    return d;
}
