#include "Main/Unknown/code_0210b760.h"

#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/unk_0217c000.h"

void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared) {
    s32 value;
    s32 oldChange;

    value = tracker->mDistanceSquared;
    if (value == -1) {
        tracker->mDistanceSquared = distanceSquared;
        tracker->mDifference = 0;
        return;
    }
    oldChange = tracker->mDifference;
    tracker->mPrevDistanceSquared = value;
    tracker->mDistanceSquared = distanceSquared;
    tracker->mDifference = (tracker->mPrevDistanceSquared - tracker->mDistanceSquared) >> tracker->mShift;
    value = tracker->mDifference;
    if (value > 0x600 || value < -0x600) {
        tracker->mDifference = oldChange;
    }
}

void StartSoundFromParams(SoundStartParams *request) {
    if (gRaceSoundKind & 1) {
        StartSoundOnPoolEntry(0, request->mSoundId, request->mPositionSource, request);
    }
}

void StartSndHandleSound(SoundStartParams *request, NNSSndSeqPlayer **handle) {
    if (gRaceSoundKind & 1) {
        StartOrUpdateSndHandleSoundInMode2(0, request->mSoundId, request->mPositionSource, handle, request);
    }
}
