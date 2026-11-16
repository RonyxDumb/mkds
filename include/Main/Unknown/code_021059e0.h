#pragma once

#include "types.h"
#include "code_0212bcac.h"

void sfx_handleRacePause(void);
void sfx_handleRaceContinue(void);
void sfx_emitRaceChoiceActivationSound(s32 a);
void sound_stopSeqAll(void);
void SetSndHandleTrackVolume(NNSSndSeqPlayer **handle, u32 volume);
void SetSndHandleTrackPitch(NNSSndSeqPlayer **handle, u32 pitch);
void sfx_2105AC0(s32 seqNo);
void MKDS_SND_PlayTwinkelSound(u32 a);
void func_021059e0(void);
