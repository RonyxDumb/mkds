#pragma once

#include "types.h"
#include "Main/Unknown/code_0210b000.h" // SoundStartParams, SoundDistanceSquaredChange
#include "code_0212bcac.h"

void func_0210b760(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSoundFromParams(SoundStartParams *request);
void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared);
