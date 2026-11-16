#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

typedef struct SoundSetPlayer SoundSetPlayer;

void func_0210f9f0(void *kartAddress, int b);
void StructMQRacerEntry_SomeFn_28(Kart *kart);
void LoadSomeSseq(SoundSetPlayer *player, s32 seqId, s32 firstBankId);
void SetSeqVariableEnabled(u32 slot, u32 enabled);
