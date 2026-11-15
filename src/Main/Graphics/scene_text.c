#include "Main/Graphics/scene_text.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
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
#include "Main/Sound/sound_seq.h"
#include "Main/Graphics/scene_text_init.h"

#pragma thumb on

void AdvanceSceneText(void) {
    if (gSceneText->mUseTxtSystem != FALSE) {
        AdvanceTxtSystem();
    }
    if (gSceneText->mUseSelectChoises != FALSE) {
        AdvanceSelectChoises();
    }
    if (gSceneText->mUseSelectReturn != FALSE) {
        AdvanceSelectReturn();
    }
}

void WriteSceneTextRegisters(void) {
    if (gSceneText->mUseTxtSystem != FALSE) {
        WriteTxtSystemRegisters();
    }
    if (gSceneText->mUseSelectChoises != FALSE) {
        WriteSelectChoisesRegisters();
    }
    if (gSceneText->mUseSelectReturn != FALSE) {
        WriteSelectReturnRegisters();
    }
}

#pragma thumb off
