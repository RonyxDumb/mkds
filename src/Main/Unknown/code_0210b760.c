#include "Main/Unknown/code_0210b760.h"

#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/unk_0217c000.h"

void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared) {
    s32 a;
    s32 oldChange;

    a = tracker->field0;
    if (a == -1) {
        tracker->field0 = distanceSquared;
        tracker->field8 = 0;
        return;
    }
    oldChange = tracker->field8;
    tracker->field4 = a;
    tracker->field0 = distanceSquared;
    tracker->field8 = (tracker->field4 - tracker->field0) >> tracker->fieldC;
    a = tracker->field8;
    if (a > 0x600 || a < -0x600) {
        tracker->field8 = oldChange;
    }
}

void sub_210B7A8(Unk0210b7a8 *request) {
    if (data_0217c780 & 1) {
        sfx_210BF24(0, request->mSoundId, (u32) request->mPositionSource, request);
    }
}

void sub_210B760(Unk0210b7a8 *request, NNSSndSeqPlayer **handle) {
    if (data_0217c780 & 1) {
        sub_210BEE8(0, request->mSoundId, (u32) request->mPositionSource, handle, request);
    }
}
