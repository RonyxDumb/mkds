#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u16 GetPackedTouchPoint(void);
void ReleaseTouchMicInput(void);
void UpdateInputSlotPair(InputSlotPair *pair, s32 packedTouchPoint, s32 micOverThreshold);
void UpdateTouchMicInput(void);
void PostSleepMicInput(void);
void PreSleepMicInput(void);
void StopMicInput(void);
void StopTouchAutoSampling(void);
void StartMicInput(void *heap);
void StartTouchAutoSampling(void);
