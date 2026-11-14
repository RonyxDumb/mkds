#include "Main/System/key_recording_read.h"

void StartReadingKeyRecording(KeyRecording *record) {
    record->mPairIndex = 0x0u;
    record->mRepeatCount = 0x0u;
    record->mStatus = KEY_RECORDING_PLAYING;
}

void FinishReadingKeyRecording(KeyRecording *record) {
    record->mStatus = KEY_RECORDING_IDLE;
}
