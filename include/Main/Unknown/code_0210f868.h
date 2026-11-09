#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

typedef struct SoundSetPlayer SoundSetPlayer;

void StartThunderShrinkSound(void *kartAddress, int b);
void RequestThunderShrinkSound(Kart *kart);
void InitSoundSetPlayerWithVariables(SoundSetPlayer *player, s32 seqId, s32 firstBankId);
void SetSeqVariableEnabled(u32 slot, u32 enabled);
