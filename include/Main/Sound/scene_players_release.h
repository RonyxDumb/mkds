#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "sound_player_type.h"
#include "stream.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
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
