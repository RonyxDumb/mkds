#include "Main/System/key_recording_start.h"
#include "code_0214d018.h"

void StartKeyRecording(KeyRecording *record) {
    if (record->mBuffer == NULL) {
        return;
    }
    if (record->mBufferCleared == FALSE) {
        if (record->mBuffer != NULL) {
            MI_CpuFill8(record->mBuffer, 0, 0xdcc);
        }
        record->mBufferCleared = TRUE;
    }
    record->mBuffer->mPairByteCount = 0;
    record->mBufferCleared = FALSE;
    record->mPairIndex = 0;
    record->mRepeatCount = 0;
    record->mStatus = KEY_RECORDING_RECORDING;
}
