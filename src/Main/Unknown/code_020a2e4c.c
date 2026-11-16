#include "Main/Unknown/code_020a2e4c.h"

void func_020a2e68(Balloon *balloon) {
    balloon->mUnk_e0 = 0;
}

// Returns mScaleFactor.
s32 blln_getInflationProgress(Balloon *balloon) {
    return balloon->mScaleFactor;
}

// Stores mKartIndex.
void blln_setDriverId(Balloon *balloon, u16 kartIndex) {
    balloon->mKartIndex = kartIndex;
}

// Stores mDrawCount and mDrawList.
void blln_setSubBalloons(Balloon *balloon, u16 drawCount, void *drawList) {
    balloon->mDrawCount = drawCount;
    balloon->mDrawList = drawList;
}
