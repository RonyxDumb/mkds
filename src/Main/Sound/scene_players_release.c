#include "Main/Sound/scene_players_release.h"
#include "Main/Unknown/code_0210d73c.h"
#include "Main/Unknown/code_0210d590.h"
#include "Main/Sound/sound_system.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "player.h"
#include "Main/Unknown/code_0210d0b4.h"

void UpdateScenePlayersNop(ScenePlayers *p0) {}

static inline void StartScenePlayersSeqIfSet(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    if (handle == NULL) {
        handle = &gScenePlayersSeqPlayer;
    }
    if (scenePlayers->mSeqId == 0xff) {
        return;
    }
    StartSeqAtVolume(seqNo, gSceneSeqVolume, handle);
}

void StartScenePlayersForScene(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = 2;
    if (scenePlayers->mSeqStartProgress != 2) {
        return;
    }
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqId, &gScenePlayersSeqPlayer);
}

void StartScenePlayersForRace(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = 3;
    if (scenePlayers->mSeqStartProgress != 3) {
        return;
    }
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqId, &gScenePlayersSeqPlayer);
}

void StartScenePlayersSeqNo(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    StartScenePlayersSeqIfSet(scenePlayers, seqNo, handle);
}

void StartScenePlayersSeq(ScenePlayers *scenePlayers) {
    StartScenePlayersSeqIfSet(scenePlayers, gScenePlayers.mSeqId, &gScenePlayersSeqPlayer);
}

void StopScenePlayersSeq(ScenePlayers *scenePlayers, u32 fadeSteps) {
    if (scenePlayers->mSeqId == 0xff) {
        return;
    }
    NNS_SndPlayerStopSeq(&scenePlayers->mSeqPlayer, fadeSteps);
}

u32 ScenePlayersReturnArgument(ScenePlayers *scenePlayers) {
    return (u32) scenePlayers;
}

void ReleaseScenePlayers(ScenePlayers *scenePlayers, s32 unused) {
    ReleaseAllSoundSources();
    scenePlayers->mProgress = 0;
}
