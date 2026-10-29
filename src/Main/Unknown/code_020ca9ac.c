#include "Main/Unknown/code_020ca9ac.h"

u16 func_020ca9c8(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020ca9ac(u32 a, u32 b) {
    return func_020ca9c8(&data_02175628[a], b);
}
