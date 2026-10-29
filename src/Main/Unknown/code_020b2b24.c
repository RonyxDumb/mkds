#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/unk_02175628.h"

u16 func_020b2b40(Unk02175628 *p, u32 a) {
    return p->mUnk_00 & a;
}

u16 func_020b2b24(s32 a, u32 b) {
    return func_020b2b40(&data_02175628[a], b);
}
