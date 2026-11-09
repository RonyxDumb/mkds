#pragma once

#include "types.h"
#include "Main/Unknown/code_02105ec0.h" // PlayerVolumeFade

void StartCursorMoveSound(void);
s32 StepValueTowardTarget(PlayerVolumeFade *volumeFade, s32 target);
void InitSoundRequestQueues(void);
void ResetSoundRequestQueues(void);
