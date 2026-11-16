#include "Main/Sound/mic_buffer_sleep.h"
#include "Main/Sound/mic_sample_analysis.h"

u32 Struct59C4Sub_SomeFn_1(MicBuffer *micBuffer) {
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

void Struct59C4Sub_SomeFn_2(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mSkipFrames = MICROPHONE_BUFFER_SKIP_FROM_PRE_SLEEP;
    StopMicSampleAnalysis();
}

void Struct59C4Sub_SomeFn_3(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mSkipFrames = MICROPHONE_BUFFER_SKIP_FROM_POST_SLEEP;
    StartMicSampleAnalysis();
}
