#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u16 GetPackedTouchPoint(void);
void ResetGlobal59C4(void);
void UpdateInputSlotPair(InputSlotPair *pair, s32 packedTouchPoint, s32 micOverThreshold);
void UpdateTouchMicInput(void);
void Scene_Race_PostSleepImpl(void);
void PreSleepMicInput(void);
void ResetGlobal59C4Sub(void);
void StopTouchAutoSampling(void);
void CreateGlobal59C4Sub(void *heap);
void StartTouchAutoSampling(void);
