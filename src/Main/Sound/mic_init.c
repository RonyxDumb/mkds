#include "Main/Sound/mic_init.h"

#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/mic_sample_analysis.h"
#include "mic.h"
#include "pm.h"
#include "Main/Sound/mic_buffer_sleep.h"

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
    autoParam->mSize = sizeof(micBuffer->mSamples);
    autoParam->mRate = MIC_AUTO_SAMPLING_RATE;
    autoParam->mLoopEnable = 1;
    autoParam->mFullCallback = 0;
    autoParam->mFullArg = 0;
    InitMicSampleAnalysis(autoParam);
    SetMicSampleAnalysisMode(MIC_ANALYSIS_MODE_LOOSE);
    PM_SetAmpGain(3);
}
