#include "Main/Sound/sound_distance_squared_change_reset.h"

void ResetSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker) {
    tracker->mDistanceSquared = -1;
    tracker->mPrevDistanceSquared = -1;
    tracker->mDifference = 0;
    tracker->mShift = SOUND_DISTANCE_CHANGE_SHIFT;
}
