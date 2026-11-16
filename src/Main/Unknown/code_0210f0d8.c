#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f090.h"
#include "code_0201ec30.h"
#include "mic.h"

void mic_finalize(MicBuffer *micBuffer) {
    sub_20203E4();
    MIC_StopAutoSampling();
}

void mic_startAutoSampling(MicBuffer *micBuffer) {
    MIC_StartAutoSampling(&micBuffer->mAutoParam);
    sub_202041C();
}

void mic_stopAutoSampling(MicBuffer *micBuffer) {
    sub_20203E4();
    MIC_StopAutoSampling();
}
