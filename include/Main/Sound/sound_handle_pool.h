#pragma once

#include "types.h"
#include "player.h"
#include "Main/Sound/sound_seq.h" // SoundHandlePool
#include "code_0212d214.h"

NNSSndSeqPlayer **GetSndHandleSlot(unsigned int index);
NNSSndSeqPlayer **GetSecondSndHandleSlot(void);
NNSSndSeqPlayer **GetSndHandles(void);

void SetSoundOutputEffect(s32 type);

SoundHandlePool *GetSoundHandlePool(u32 index);

void SetPlayerVolumeTarget(u32 index, u32 value);

NNSSndArc *SetCurrentSndArc(void);

void RunScenesSoundNop(void);

void StartMissionRunCountSeq(s32 count, s32 countLimit);
