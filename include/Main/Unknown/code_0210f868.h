#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

typedef struct SoundSetPlayer SoundSetPlayer;

void StartThunderShrinkSound(void *kartAddress, int secondArgument);
void RequestThunderShrinkSound(Kart *kart);
void InitSoundSetPlayerWithVariables(SoundSetPlayer *player, s32 seqId, s32 firstBankId);
void SetSeqVariableEnabled(u32 slot, u32 enabled);
