#include "Main/Sound/mic_auto_sampling.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Sound/mic_sample_analysis.h"
#include "mic.h"

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
