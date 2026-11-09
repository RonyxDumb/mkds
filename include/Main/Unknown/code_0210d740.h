#pragma once

#include "types.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_0217d000.h"

void StartSoundOutputEffect(u32 type);
void ChangeSoundOutputEffect(s32 type);
void StartSeqAtVolume(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle);
void UpdateSndMain(void);
void InitScenePlayers(ScenePlayers *scenePlayers, SceneSoundState *sceneSoundState, u32 sceneSoundRowIndex,
                      ScenePlayersSeqInfo seqInfo);
