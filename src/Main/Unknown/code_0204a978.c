#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void irec_startRecording(KeyRecording *record) {
    if (record->mBuffer == NULL) {
        return;
    }
    if (record->fieldC == FALSE) {
        if (record->mBuffer != NULL) {
            MI_CpuFill8(record->mBuffer, 0, 0xdcc);
        }
        record->fieldC = TRUE;
    }
    record->mBuffer->field0 = 0;
    record->fieldC = FALSE;
    record->mPairIndex = 0;
    record->mRepeatCount = 0;
    record->mStatus = 1;
}
