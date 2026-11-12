#include "Main/Sound/mic_buffer_sleep.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Sound/mic_sample_analysis.h"

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
