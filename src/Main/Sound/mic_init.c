#include "Main/Sound/mic_init.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Sound/mic_sample_analysis.h"
#include "mic.h"
#include "pm.h"
#include "Main/Unknown/code_0210f090.h"

u32 gMicInitialized;

void InitMicAndAmp(void) {
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    gMicInitialized = 1;
}

void SetupMicAutoSampling(MicBuffer *micBuffer) {
    MICAutoParam *autoParam;
    s32 sampleIndex;

    if (gMicInitialized == 0) {
        MIC_Init();
        PM_Init();
        PM_SetAmp(1);
        gMicInitialized = 1;
    }
    micBuffer->mSkipFrames = 0;
    for (sampleIndex = 0; sampleIndex < 0x400; sampleIndex++) {
        micBuffer->mSamples[sampleIndex] = 0;
    }
    micBuffer->mAutoParam.mType = MIC_SAMPLING_TYPE_SIGNED_8BIT;
    autoParam = &micBuffer->mAutoParam;
    autoParam->mBuffer = micBuffer;
    autoParam->mSize = 0x400;
    autoParam->mRate = 0x105d;
    autoParam->mLoopEnable = 1;
    autoParam->mFullCallback = 0;
    autoParam->mFullArg = 0;
    InitMicSampleAnalysis(autoParam);
    SetMicSampleAnalysisMode(0);
    PM_SetAmpGain(3);
}
