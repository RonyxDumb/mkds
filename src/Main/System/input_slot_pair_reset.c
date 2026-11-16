#include "Main/System/input_slot_pair_reset.h"

void ResetInputSlotPair(InputSlotPair *pair) {
    pair->mNoPairCount = 0xffffu;
    pair->mMicOverThreshold[0] = 0x0u;
    pair->mPairX = 0xffu;
    pair->mPairY = 0xffu;
    pair->mHasPair = 0x0u;
    pair->mValidity = TOUCH_VALIDITY_INVALID;
    pair->mPrevPairX = 0xffu;
    pair->mPrevPairY = 0xffu;
    pair->mPrevHasPair = 0x0u;
    pair->mPrevValidity = TOUCH_VALIDITY_INVALID;
}
