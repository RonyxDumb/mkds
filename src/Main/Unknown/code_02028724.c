#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/unk_02175628.h"

u32 func_0202876c(InputSlotPair *p0) {
    return p0->mPairX;
}

u32 func_0202874c(u32 slot) {
    return func_0202876c(&gInputSlots[slot].mPair);
}

u32 func_02028744(InputSlotPair *p0) {
    return p0->mPairY;
}

u32 func_02028724(u32 slot) {
    return func_02028744(&gInputSlots[slot].mPair);
}
