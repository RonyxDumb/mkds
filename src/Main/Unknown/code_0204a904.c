#include "Main/Unknown/code_0204a904.h"

void irec_startPlayback(KeyRecording *record) {
    record->mPairIndex = 0x0u;
    record->mRepeatCount = 0x0u;
    record->mStatus = 0x2u;
}

void irec_stopPlayback(KeyRecording *record) {
    record->mStatus = 0x0u;
}
