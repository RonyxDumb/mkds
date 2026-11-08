#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/unk_02175628.h"

u32 func_0202f0a0(InputSlotPair *pair) {
    return pair->mPairX;
}

u32 func_0202f080(u32 slot) {
    return func_0202f0a0(&data_02175628[slot].mUnk_48);
}

u32 func_0202f078(InputSlotPair *pair) {
    return pair->mPairY;
}

u32 func_0202f058(u32 slot) {
    return func_0202f078(&data_02175628[slot].mUnk_48);
}
