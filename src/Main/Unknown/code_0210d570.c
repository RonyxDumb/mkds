#include "Main/Unknown/code_0210d570.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "Main/Unknown/unk_0217d000.h"

u32 ScenePlayersReturnArgument(ScenePlayers *scenePlayers) {
    return (u32) scenePlayers;
}

void ReleaseScenePlayers(ScenePlayers *scenePlayers, s32 unused) {
    ReleaseAllSoundSources();
    scenePlayers->mProgress = 0;
}
