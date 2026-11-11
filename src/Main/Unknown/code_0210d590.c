#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

static inline void StartScenePlayersSeqIfSet(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    if (handle == NULL) {
        handle = &data_0217d07c;
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
    StartScenePlayersSeqIfSet(scenePlayers, data_0217d070.mSeqId, &data_0217d07c);
}

void StartScenePlayersForRace(ScenePlayers *scenePlayers) {
    scenePlayers->mProgress = 3;
    if (scenePlayers->mSeqStartProgress != 3) {
        return;
    }
    StartScenePlayersSeqIfSet(scenePlayers, data_0217d070.mSeqId, &data_0217d07c);
}

void StartScenePlayersSeqNo(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    StartScenePlayersSeqIfSet(scenePlayers, seqNo, handle);
}

void StartScenePlayersSeq(ScenePlayers *scenePlayers) {
    StartScenePlayersSeqIfSet(scenePlayers, data_0217d070.mSeqId, &data_0217d07c);
}

void StopScenePlayersSeq(ScenePlayers *scenePlayers, u32 fadeSteps) {
    if (scenePlayers->mSeqId == 0xff) {
        return;
    }
    NNS_SndPlayerStopSeq(&scenePlayers->mSeqPlayer, fadeSteps);
}
