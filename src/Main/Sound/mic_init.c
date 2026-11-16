#include "Main/Sound/mic_init.h"

#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Sound/mic_sample_analysis.h"
#include "microphone_sampling.h"
#include "power_management_commands.h"
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
    autoParam->mRate = MICROPHONE_AUTO_SAMPLING_RATE;
    autoParam->mLoopEnable = 1;
    autoParam->mFullCallback = 0;
    autoParam->mFullArg = 0;
    InitMicSampleAnalysis(autoParam);
    SetMicSampleAnalysisMode(MICROPHONE_ANALYSIS_MODE_LOOSE);
    PM_SetAmpGain(3);
}
