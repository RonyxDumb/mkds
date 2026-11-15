#include "Main/Sound/sound_mode_restore.h"
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
#include "Main/Sound/sound_mode.h"

void SetupSoundMode(SoundModeHolder *modeHolder, ScenePlayers *scenePlayers, u32 unusedValue) {
    modeHolder->mMode = SCENE_SOUND_MODE_STOPPED;
    modeHolder->mUnk_14 = unusedValue;
    modeHolder->mScenePlayers = scenePlayers;
    modeHolder->mSavedMode = 0;
    modeHolder->mKartStarSeqPlayer = NULL;
}

void RestoreSavedSoundMode(SoundModeHolder *modeHolder) {
    SetSoundMode(modeHolder, modeHolder->mSavedMode);
}
