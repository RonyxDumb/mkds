#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam

u8 UpdateMicSampleAnalysis(void);
void SetMicSampleAnalysisMode(u32 mode);
void StopMicSampleAnalysis(void);
void StartMicSampleAnalysis(void);
void InitMicSampleAnalysis(MICAutoParam *autoParam);
s32 GetMicSampleAmplitude(s32 sample);
