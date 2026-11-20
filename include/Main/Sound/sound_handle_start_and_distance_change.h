#pragma once

#include "types.h"
#include "Main/Sound/sound_distance_squared_change.h" // SoundDistanceSquaredChange
#include "sound_player_control.h"

typedef struct SoundStartParams SoundStartParams;

void StartSndHandleSoundEx(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSndHandleSoundUnchecked(SoundStartParams *request, NNSSndSeqPlayer **handle);
void AdvanceSoundDistanceSquaredChange(SoundDistanceSquaredChange *tracker, u32 distanceSquared);
