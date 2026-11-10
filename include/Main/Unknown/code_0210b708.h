#pragma once

#include "types.h"
#include "code_0212bcac.h"

typedef struct SoundStartParams SoundStartParams;

void StartSndHandleSoundEx(SoundStartParams *request, NNSSndSeqPlayer **handle);
void StartSndHandleSoundUnchecked(SoundStartParams *request, NNSSndSeqPlayer **handle);
