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

extern u8 data_02161ad8;

extern u8 data_02173288;

extern s32 data_0217328c;

extern MICAutoParam *gMicSampleAnalysisParam;

extern s32 data_02173294;

extern s32 data_02173298;

extern s32 data_0217329c;

extern u8 gMicIntervalHistogram[4];

extern s32 data_021732a4;

extern s32 data_021732a8;
