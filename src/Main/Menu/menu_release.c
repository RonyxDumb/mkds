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
    if (gMenuScene->mScreenInitPending == FALSE) {
        gMenuScene->mPreviousScreenNumber = gMenuScene->mScreenNumber;
        gMenuScene->mScreenNumber = SCREEN_NONE;
        ReleasePreviousMenuScreen();
    }
    if (MenuMB_IsMultiBootChildWrapper() == 0) {
        ClearCupPicturePointer();
        ClearGhostRecordSetPointer();
    }
    ReleaseSceneText();
    ClearLinkLevelIconsPointer();
    ClearPicksHolderPointer();
    ReleaseAllResFiles();
    SetMenuEntryKind(0);
    SetUnfilledNotEliminated(0);
    WriteMainBlendAlpha(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    MenuWriteSubBlendAlpha(0, 0x3f, MENU_BLEND_FIRST_COEFFICIENT, MENU_BLEND_SECOND_COEFFICIENT);
    gMenuScene = NULL;
}
