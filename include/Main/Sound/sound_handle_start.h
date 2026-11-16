#pragma once

#include "types.h"
#include "sound_player_control.h"

typedef struct SoundStartParams SoundStartParams;

void StartSndHandleSoundEx(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSndHandleSoundUnchecked(SoundStartParams *request, NNSSndSeqPlayer **handle);
