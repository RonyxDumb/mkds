#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam
#include "gfd_LinkedListPlttVramMan.h"
#include "gfd_LinkedListTexVramMan.h"

// gMicSampleAnalysisMode: how strict the amplitude and interval limits are (the loose mode has the lowest amplitude
// limits, the strict mode also has lower limits on the interval counts).
#define MIC_ANALYSIS_MODE_LOOSE 0
#define MIC_ANALYSIS_MODE_MIDDLE 1
#define MIC_ANALYSIS_MODE_STRICT 2

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
