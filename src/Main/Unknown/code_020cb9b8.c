#include "Main/Unknown/code_020cb9b8.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020cba30.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Ui/CupPicture.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void ReleaseMenu(void) {
    if (gMenuSceneState->mScreenInitPending == FALSE) {
        gMenuSceneState->mPreviousScreenNumber = gMenuSceneState->mScreenNumber;
        gMenuSceneState->mScreenNumber = 0x1f;
        menu_destroySubMenu();
    }
    if (menu_MB_IsMultiBootChild_22() == 0) {
        cpic_finalize();
        ClearGhostRecordSetPointer();
    }
    gmenu_finish();
    ClearLinkLevelIconsPointer();
    FreeSinglePlayerMenuInfo();
    model_releaseAll();
    SetSinglePlayerMenuTarget(0);
    SetB488_B5(0);
    menu_G2_SetBlendAlpha(0, 0x3f, 6, 10);
    menu_G2S_SetBlendAlpha(0, 0x3f, 6, 10);
    gMenuSceneState = NULL;
}
