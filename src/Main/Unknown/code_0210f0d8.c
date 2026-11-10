#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Unknown/code_0201ec30.h"
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
