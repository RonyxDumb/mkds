#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/unk_02175628.h"

u32 ScrollListGetPairX(InputSlotPair *pair) {
    return pair->mPairX;
}

u32 ScrollListGetSlotPairX(u32 slot) {
    return ScrollListGetPairX(&gInputSlots[slot].mPair);
}

u32 ScrollListGetPairY(InputSlotPair *pair) {
    return pair->mPairY;
}

u32 ScrollListGetSlotPairY(u32 slot) {
    return ScrollListGetPairY(&gInputSlots[slot].mPair);
}
