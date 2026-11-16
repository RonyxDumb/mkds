#include "Main/Unknown/code_0204a9e4.h"

void irec_setBufferToNull(KeyRecording *record) {
    record->mBuffer = NULL;
}

void irec_init(KeyRecording *record) {
    record->mPairIndex = 0x0u;
    record->mRepeatCount = 0x0u;
    record->mStatus = 0x0u;
}
