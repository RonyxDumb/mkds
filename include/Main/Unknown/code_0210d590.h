#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217d000.h"

void StartScenePlayersForScene(ScenePlayers *scenePlayers);
void StartScenePlayersForRace(ScenePlayers *scenePlayers);
void StartScenePlayersSeqNo(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle);
void StartScenePlayersSeq(ScenePlayers *scenePlayers);
void StopScenePlayersSeq(ScenePlayers *scenePlayers, u32 fadeSteps);
