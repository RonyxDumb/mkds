#include "Main/Sound/mic_auto_sampling.h"
#include "Main/Sound/mic_buffer_sleep.h"
#include "Main/Sound/mic_sample_analysis.h"
#include "microphone_sampling.h"

void TouchMicInputStopMicAutoSampling(MicBuffer *micBuffer) {
    StopMicSampleAnalysis();
    MIC_StopAutoSampling();
}

void StartMicAutoSampling(MicBuffer *micBuffer) {
    MIC_StartAutoSampling(&micBuffer->mAutoParam);
    StartMicSampleAnalysis();
}

void StopMicAutoSampling(MicBuffer *micBuffer) {
    StopMicSampleAnalysis();
    MIC_StopAutoSampling();
}
