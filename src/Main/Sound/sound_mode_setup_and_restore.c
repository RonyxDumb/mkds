#include "Main/Sound/sound_mode_setup_and_restore.h"
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
#include "Main/Sound/sound_mode.h"

void SetupSoundMode(SoundModeHolder *modeHolder, ScenePlayers *scenePlayers, u32 unusedValue) {
    modeHolder->mMode = SCENE_SOUND_MODE_STOPPED;
    modeHolder->mUnk_14 = unusedValue;
    modeHolder->mScenePlayers = scenePlayers;
    modeHolder->mSavedMode = SCENE_SOUND_MODE_STOPPED;
    modeHolder->mKartStarSeqPlayer = NULL;
}

void RestoreSavedSoundMode(SoundModeHolder *modeHolder) {
    SetSoundMode(modeHolder, modeHolder->mSavedMode);
}
