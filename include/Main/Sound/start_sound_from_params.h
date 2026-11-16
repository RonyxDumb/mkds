#pragma once

#include "types.h"
#include "Main/Sound/sound_distance_squared_change.h" // SoundStartParams
#include "sound_player_control.h"

void StartSndHandleSound(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSoundFromParams(SoundStartParams *request);
