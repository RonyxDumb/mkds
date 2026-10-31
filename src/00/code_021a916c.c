#include "00/code_021a916c.h"
#include "00/code_021a8db8.h"
#include "00/code_021a740c.h"

s32 func_ov000_021a916c(s32 v1, const void *v2) {
    const Unk021a8e18 *a = v2;
    u16 b = ((a->mUnk_02 >> 8) & 0xff) | ((a->mUnk_02 << 8) & 0xff00);
    return func_ov000_021a7824((Unk021a6fa8 *) v1, b);
}
