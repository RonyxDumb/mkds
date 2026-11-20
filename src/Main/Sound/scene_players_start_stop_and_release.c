#include "Main/Sound/scene_players_start_stop_and_release.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_set_load.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Sound/sound_sources.h"

void UpdateScenePlayersNop(ScenePlayers *scenePlayers) {}

static inline void StartScenePlayersSeqIfSet(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    if (handle == NULL) {
        handle = &gScenePlayers.mSeqPlayer;
    }
    if (scenePlayers->mSeqInfo.mSeqId == SOUND_ID_NONE) {
        return;
    }
    StartSeqAtVolume(seqNo, gSceneSeqVolume, handle);
}

void StartScenePlayersForScene(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = SCENE_PLAYERS_PROGRESS_SCENE_STARTED;
    if (scenePlayers->mSeqInfo.mSeqStartProgress != SCENE_PLAYERS_PROGRESS_SCENE_STARTED) {
        return;
    }
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqInfo.mSeqId, &gScenePlayers.mSeqPlayer);
}

void StartScenePlayersForRace(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = SCENE_PLAYERS_PROGRESS_RACE_STARTED;
    if (scenePlayers->mSeqInfo.mSeqStartProgress != SCENE_PLAYERS_PROGRESS_RACE_STARTED) {
        return;
    }
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqInfo.mSeqId, &gScenePlayers.mSeqPlayer);
}

void StartScenePlayersSeqNo(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    StartScenePlayersSeqIfSet(scenePlayers, seqNo, handle);
}

void StartScenePlayersSeq(ScenePlayers *scenePlayers) {
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqInfo.mSeqId, &gScenePlayers.mSeqPlayer);
}

void StopScenePlayersSeq(ScenePlayers *scenePlayers, u32 fadeSteps) {
    if (scenePlayers->mSeqInfo.mSeqId == SOUND_ID_NONE) {
        return;
    }
    NNS_SndPlayerStopSeq(&scenePlayers->mSeqPlayer, fadeSteps);
}

void ScenePlayersNop(ScenePlayers *scenePlayers) {}

void ReleaseScenePlayers(ScenePlayers *scenePlayers, s32 unused) {
    ReleaseAllSoundSources();
    scenePlayers->mProgress = SCENE_PLAYERS_PROGRESS_RELEASED;
}
