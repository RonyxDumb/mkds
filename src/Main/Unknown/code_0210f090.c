#include "Main/Unknown/code_0210f090.h"

#include "Main/Unknown/code_0201ec30.h"

u32 UpdateMicBufferInput(MicBuffer *micBuffer) {
    if (micBuffer->mSkipFrames == 0) {
        return UpdateMicSampleAnalysis();
    }
    if (micBuffer->mSkipFrames < 0x1e) {
        micBuffer->mSkipFrames = micBuffer->mSkipFrames + 1;
    } else {
        micBuffer->mSkipFrames = 0;
    }
    return 0;
}
