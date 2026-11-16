#pragma once

#include "types.h"
#include "sound_player_control.h"
#include "Main/Sound/sound_seq.h" // SoundHandlePool
#include "sound_archive_load.h"

NNSSndSeqPlayer **GetSndHandleSlot(unsigned int index);
NNSSndSeqPlayer **GetSecondSndHandleSlot(void);
NNSSndSeqPlayer **GetSndHandles(void);

void SetSoundOutputEffect(s32 type);

SoundHandlePool *GetSoundHandlePool(u32 index);

void SetPlayerVolumeTarget(u32 index, u32 value);

NNSSndArc *SetGlobalSdatActive(void);

void nullsub_12(void);

void StartMissionRunCountSeq(s32 count, s32 countLimit);
