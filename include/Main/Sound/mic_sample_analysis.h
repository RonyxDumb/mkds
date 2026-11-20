#pragma once

#include "types.h"
#include "microphone_sampling.h" // MICAutoParam
#include "linked_palette_vram_alloc.h"
#include "linked_texture_vram_alloc.h"

// gMicSampleAnalysisMode: how tight most amplitude and histogram limits of UpdateMicSampleAnalysis are, and how many
// matches in a row it needs before it reports a value (the 2nd for loose, the 3rd otherwise).
#define MICROPHONE_ANALYSIS_MODE_LOOSE 0
#define MICROPHONE_ANALYSIS_MODE_MIDDLE 1
#define MICROPHONE_ANALYSIS_MODE_STRICT 2

u8 UpdateMicSampleAnalysis(void);
void SetMicSampleAnalysisMode(u32 mode);
void StopMicSampleAnalysis(void);
void StartMicSampleAnalysis(void);
void InitMicSampleAnalysis(MICAutoParam *autoParam);
s32 GetMicSampleAmplitude(s32 sample);

u32 ClampMicSample(u32 rawSample);

extern u8 gMicSampleAnalysisMode;

extern u8 gMicSampleAnalysisValue;

extern s32 gMicMaxAmplitude;

extern MICAutoParam *gMicSampleAnalysisParam;

extern s32 gMicSampleAnalysisRunning;

extern s32 gMicSampleAnalysisMatchCount;

extern s32 gMicCrossingLevel;

extern u8 gMicIntervalHistogram[4];

extern s32 gMicNearMaxSampleCount;

extern s32 gMicMaxCrossingInterval;
