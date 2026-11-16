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

void NavigationContext_OnSceneUpdate_from_thumb(void) {
    if (g_NavigationContext->mUseTxtSystem != FALSE) {
        TextSystemContext_OnSceneUpdate_from_thumb();
    }
    if (g_NavigationContext->mUseSelectChoises != FALSE) {
        SelectChoisesContext_OnSceneUpdate_from_thumb();
    }
    if (g_NavigationContext->mUseSelectReturn != FALSE) {
        SelectReturnContext_OnSceneUpdate_from_thumb();
    }
}

void NavigationContext_OnSceneVblank_from_thumb(void) {
    if (g_NavigationContext->mUseTxtSystem != FALSE) {
        TextSystemContext_OnSceneVblank_from_thumb();
    }
    if (g_NavigationContext->mUseSelectChoises != FALSE) {
        SelectChoisesContext_OnSceneVblank_from_thumb();
    }
    if (g_NavigationContext->mUseSelectReturn != FALSE) {
        SelectReturnContext_OnSceneVblank_from_thumb();
    }
}

#pragma thumb off
