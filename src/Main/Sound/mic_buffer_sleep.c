#include "Main/Sound/mic_buffer_sleep.h"
#include "Main/Sound/mic_sample_analysis.h"

u32 UpdateMicBufferInput(MicBuffer *micBuffer) {
    if (micBuffer->mSkipFrames == 0) {
        return UpdateMicSampleAnalysis();
    }
    if (micBuffer->mSkipFrames < MICROPHONE_BUFFER_SKIP_LAST) {
        micBuffer->mSkipFrames = micBuffer->mSkipFrames + 1;
    } else {
        micBuffer->mSkipFrames = 0;
    }
    return 0;
}

void PreSleepMicBuffer(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mSkipFrames = MICROPHONE_BUFFER_SKIP_FROM_PRE_SLEEP;
    StopMicSampleAnalysis();
}

void PostSleepMicBuffer(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mSkipFrames = MICROPHONE_BUFFER_SKIP_FROM_POST_SLEEP;
    StartMicSampleAnalysis();
}
