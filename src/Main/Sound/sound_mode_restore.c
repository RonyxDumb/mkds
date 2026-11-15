#include "Main/Sound/sound_mode_restore.h"
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
#include "Main/Sound/sound_mode.h"

void SetupSoundMode(SoundModeHolder *modeHolder, ScenePlayers *scenePlayers, u32 unusedValue) {
    modeHolder->mMode = 0;
    modeHolder->mUnk_14 = unusedValue;
    modeHolder->mScenePlayers = scenePlayers;
    modeHolder->mSavedMode = 0;
    modeHolder->mKartStarSeqPlayer = NULL;
}

void RestoreSavedSoundMode(SoundModeHolder *modeHolder) {
    SetSoundMode(modeHolder, modeHolder->mSavedMode);
}
