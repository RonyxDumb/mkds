#include "Main/Unknown/code_020a2e4c.h"

void DisableBalloonHorizontalPull(Balloon *balloon) {
    balloon->mHorizontalPullEnabled = 0;
}

// Returns mScaleFactor.
s32 GetBalloonScaleFactor(Balloon *balloon) {
    return balloon->mScaleFactor;
}

// Stores mKartIndex.
void SetBalloonKartIndex(Balloon *balloon, u16 kartIndex) {
    balloon->mKartIndex = kartIndex;
}

// Stores mDrawCount and mDrawList.
void SetBalloonDrawCountAndList(Balloon *balloon, u16 drawCount, void *drawList) {
    balloon->mDrawCount = drawCount;
    balloon->mDrawList = drawList;
}
