#include "Main/Unknown/code_0210b850.h"

void ResetSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker) {
    tracker->mDistanceSquared = -1;
    tracker->mPrevDistanceSquared = -1;
    tracker->mDifference = 0;
    tracker->mShift = 6;
}
