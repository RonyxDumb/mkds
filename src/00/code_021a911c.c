#include "00/code_021a911c.h"
#include "00/code_021a740c.h"

s32 func_ov000_021a911c(Unk021a6fa8 *a, Unk021a8e18 *b) {
    u32 c = b->mUnk_04;
    u16 d = ((b->mUnk_02 >> 8) & 0xff) | ((b->mUnk_02 << 8) & 0xff00);
    u32 e = ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00)));
    return func_ov000_021a7748(a, d, (u16 *) e);
}
