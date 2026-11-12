#pragma once

#include "types.h"
#include "player.h"

typedef struct SoundStartParams SoundStartParams;

void StartSndHandleSoundEx(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSndHandleSoundUnchecked(SoundStartParams *request, NNSSndSeqPlayer **handle);
