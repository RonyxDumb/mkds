#include "Main/System/key_recording_reset.h"

void StructCYB_ResetInputRecord(KeyRecording *record) {
    record->mBuffer = NULL;
}

void StructCYB_SomeFn(KeyRecording *record) {
    record->mPairIndex = 0x0u;
    record->mRepeatCount = 0x0u;
    record->mStatus = KEY_RECORDING_IDLE;
}
