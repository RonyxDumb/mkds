#include "Main/Unknown/code_0210dc60.h"
#include "Main/Unknown/unk_0217d000.h"

void SetupSoundMode(SoundModeHolder *modeHolder, ScenePlayers *scenePlayers, u32 p2) {
    modeHolder->mMode = 0;
    modeHolder->field14 = p2;
    modeHolder->mScenePlayers = scenePlayers;
    modeHolder->mSavedMode = 0;
    modeHolder->field18 = NULL;
}
