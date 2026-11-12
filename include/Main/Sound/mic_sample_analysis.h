#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam
#include "gfd_LinkedListPlttVramMan.h"
#include "gfd_LinkedListTexVramMan.h"

u8 UpdateMicSampleAnalysis(void);
void SetMicSampleAnalysisMode(u32 mode);
void StopMicSampleAnalysis(void);
void StartMicSampleAnalysis(void);
void InitMicSampleAnalysis(MICAutoParam *autoParam);
s32 GetMicSampleAmplitude(s32 sample);

u32 ClampMicSample(u32 arg0);

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
