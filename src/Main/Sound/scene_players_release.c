#include "Main/Sound/scene_players_release.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
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
#include "Main/Sound/sound_sources.h"

void UpdateScenePlayersNop(ScenePlayers *scenePlayers) {}

static inline void StartScenePlayersSeqIfSet(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    if (handle == NULL) {
        handle = &gScenePlayers.mSeqPlayer;
    }
    if (scenePlayers->mSeqInfo.mSeqId == 0xff) {
        return;
    }
    StartSeqAtVolume(seqNo, gSceneSeqVolume, handle);
}

void StartScenePlayersForScene(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = 2;
    if (scenePlayers->mSeqInfo.mSeqStartProgress != 2) {
        return;
    }
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqInfo.mSeqId, &gScenePlayers.mSeqPlayer);
}

void StartScenePlayersForRace(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = 3;
    if (scenePlayers->mSeqInfo.mSeqStartProgress != 3) {
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
    if (scenePlayers->mSeqInfo.mSeqId == 0xff) {
        return;
    }
    NNS_SndPlayerStopSeq(&scenePlayers->mSeqPlayer, fadeSteps);
}

void ScenePlayersNop(ScenePlayers *scenePlayers) {}

void ReleaseScenePlayers(ScenePlayers *scenePlayers, s32 unused) {
    ReleaseAllSoundSources();
    scenePlayers->mProgress = 0;
}
