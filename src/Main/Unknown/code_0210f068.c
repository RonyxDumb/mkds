#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Unknown/code_0201ec30.h"

void PreSleepMicBuffer(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mSkipFrames = 1;
    StopMicSampleAnalysis();
}

void PostSleepMicBuffer(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mSkipFrames = 2;
    StartMicSampleAnalysis();
}
