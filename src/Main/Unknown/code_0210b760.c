#include "Main/Unknown/code_0210b760.h"

#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/unk_0217c000.h"

void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared) {
    s32 a;
    s32 oldChange;

    a = tracker->mDistanceSquared;
    if (a == -1) {
        tracker->mDistanceSquared = distanceSquared;
        tracker->mDifference = 0;
        return;
    }
    oldChange = tracker->mDifference;
    tracker->mPrevDistanceSquared = a;
    tracker->mDistanceSquared = distanceSquared;
    tracker->mDifference = (tracker->mPrevDistanceSquared - tracker->mDistanceSquared) >> tracker->mShift;
    a = tracker->mDifference;
    if (a > 0x600 || a < -0x600) {
        tracker->mDifference = oldChange;
    }
}

void func_0210b7a8(Unk0210b7a8 *request) {
    if (data_0217c780 & 1) {
        func_0210bf24(0, request->mSoundId, request->mPositionSource, request);
    }
}

void func_0210b760(Unk0210b7a8 *request, NNSSndSeqPlayer **handle) {
    if (data_0217c780 & 1) {
        func_0210bee8(0, request->mSoundId, request->mPositionSource, handle, request);
    }
}
