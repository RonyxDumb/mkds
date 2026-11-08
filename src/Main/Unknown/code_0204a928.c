#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/unk_02175000.h" // KeyRecording
#include "code_0200eddc.h"

void FinishKeyRecording(KeyRecording *keyRecording) {
    if (keyRecording->mStatus != 1) {
        return;
    }
    keyRecording->mBuffer->mUnk_00 = keyRecording->mPairIndex << 1;
    keyRecording->mStatus = 0;
    DC_StoreRange(keyRecording->mBuffer, 0xdcc);
}
