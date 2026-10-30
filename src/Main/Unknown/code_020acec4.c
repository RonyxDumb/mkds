#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/unk_02175628.h"

u16 func_020acee0(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020acec4(u32 a, u32 b) {
    return func_020acee0(&data_02175628[a], b);
}
