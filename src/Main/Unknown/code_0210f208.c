#include "Main/Unknown/code_0210f208.h"
#include "Main/Unknown/code_0210f230.h"

void InitCourseSoundSlot(CourseSoundSlot *p0, u32 p1, u32 p2) {
    p0->mPreviousVolumeHandle = p1;
    p0->mVolumeHandle = p1;
    p0->mFirstTableIndex = p2;
    p0->mLowVolume = 0x28;
    p0->mMidVolume = 0x50;
    p0->mHighVolume = 0x7f;
}
