#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/unk_02175628.h"

u32 SelectKartGetPairX(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mPairX;
}

u32 SelectKartGetSlotPairX(u32 slot) {
    return SelectKartGetPairX(&gInputSlots[slot].mPair);
}

u32 SelectKartGetPairY(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mPairY;
}

u32 SelectKartGetSlotPairY(u32 slot) {
    return SelectKartGetPairY(&gInputSlots[slot].mPair);
}
