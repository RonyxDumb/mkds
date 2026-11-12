#include "Main/Sound/sound_mode_restore.h"
#include "Main/Unknown/code_0210dc60.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Sound/sound_mode.h"

void SetupSoundMode(SoundModeHolder *modeHolder, ScenePlayers *scenePlayers, u32 p2) {
    modeHolder->mMode = 0;
    modeHolder->mUnk_14 = p2;
    modeHolder->mScenePlayers = scenePlayers;
    modeHolder->mSavedMode = 0;
    modeHolder->mKartStarSeqPlayer = NULL;
}

void RestoreSavedSoundMode(SoundModeHolder *modeHolder) {
    SetSoundMode(modeHolder, modeHolder->mSavedMode);
}
