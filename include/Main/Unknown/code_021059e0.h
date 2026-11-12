#pragma once

#include "types.h"
#include "player.h"

void LowerSndHandleVolumes(void);
void RaiseSndHandleVolumes(void);
void StartChoisesSValueSeq(s32 valueIndex);
void StopAllSeqPlayers(void);
void SetSndHandleTrackVolume(NNSSndSeqPlayer **handle, u32 volume);
void SetSndHandleTrackPitch(NNSSndSeqPlayer **handle, u32 pitch);
void StartSoundOncePerFrame(s32 seqNo);
void StartMissionRunLVselSeq(u32 mode);
void StartSceneSeqIfIdle(void);
