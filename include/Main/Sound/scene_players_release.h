#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"

typedef struct ScenePlayers ScenePlayers;

void ReleaseScenePlayers(ScenePlayers *scenePlayers, s32 unused);

void ScenePlayersNop(ScenePlayers *scenePlayers);

void StartScenePlayersForScene(ScenePlayers *scenePlayers);
void StartScenePlayersForRace(ScenePlayers *scenePlayers);
void StartScenePlayersSeqNo(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle);
void StartScenePlayersSeq(ScenePlayers *scenePlayers);
void StopScenePlayersSeq(ScenePlayers *scenePlayers, u32 fadeSteps);

void UpdateScenePlayersNop(ScenePlayers *scenePlayers);
