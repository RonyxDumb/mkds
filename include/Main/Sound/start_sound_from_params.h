#pragma once

#include "types.h"
#include "Main/Sound/sound_distance_squared_change.h" // SoundStartParams, SoundDistanceSquaredChange
#include "player.h"

void StartSndHandleSound(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSoundFromParams(SoundStartParams *request);
void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared);
