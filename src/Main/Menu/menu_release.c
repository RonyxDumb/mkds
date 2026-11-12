#include "Main/Menu/menu_release.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Menu/menu_screen_init.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/Menu/menu.h"
#include "Main/Menu/cup_picture_load.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void ReleaseMenu(void) {
    if (gMenuScene->mScreenInitPending == FALSE) {
        gMenuScene->mPreviousScreenNumber = gMenuScene->mScreenNumber;
        gMenuScene->mScreenNumber = 0x1f;
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
    WriteMainBlendAlpha(0, 0x3f, 6, 10);
    MenuWriteSubBlendAlpha(0, 0x3f, 6, 10);
    gMenuScene = NULL;
}
