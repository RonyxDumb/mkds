#include "Main/System/key_recording_start.h"
#include "cpu_copy_fill.h"

void StartKeyRecording(KeyRecording *record) {
    if (record->mBuffer == NULL) {
        return;
    }
    if (record->mBufferCleared == FALSE) {
        if (record->mBuffer != NULL) {
            Mem_CpuFill8(record->mBuffer, 0, sizeof(*record->mBuffer));
        }
        record->mBufferCleared = TRUE;
    }
    record->mBuffer->mPairByteCount = 0;
    record->mBufferCleared = FALSE;
    record->mPairIndex = 0;
    record->mRepeatCount = 0;
    record->mStatus = KEY_RECORDING_RECORDING;
}
