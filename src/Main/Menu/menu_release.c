#include "Main/Menu/menu_release.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Menu/menu_screen_init.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Menu/menu.h"
#include "Main/Menu/cup_picture_load.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/message_screen.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on
#pragma optimize_for_size on
void ReleaseMenu(void) {
    if (g_GlobalB43C->mScreenInitPending == FALSE) {
        g_GlobalB43C->mPreviousScreenNumber = g_GlobalB43C->mScreenNumber;
        g_GlobalB43C->mScreenNumber = SCREEN_NONE;
        ReleasePreviousMenuScreen();
    }
    if (j_IsDwc_0() == 0) {
        ResetGlobalB4A4_from_thumb();
        ResetGlobalPK_from_thumb();
    }
    DisposeNavigationContext_from_thumb();
    ResetGlobalNN_from_thumb();
    ResetGlobalKTB_from_thumb();
    MaybeDisposeLoadedModelTextures();
    SetSinglePlayerMenuTarget(0);
    SetB488_B5(0);
    EnableAlphaSetBldcntBldalphaTop(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    EnableAlphaSetBldcntBldalphaSub(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    g_GlobalB43C = NULL;
}
