#pragma once

#include "types.h"
#include "mic.h" // MICAutoParam

u8 UpdateMicSampleAnalysis(void);
void SetMicSampleAnalysisMode(u32 arg0);
void StopMicSampleAnalysis(void);
void StartMicSampleAnalysis(void);
void InitMicSampleAnalysis(MICAutoParam *a);
s32 GetMicSampleAmplitude(s32 a);
