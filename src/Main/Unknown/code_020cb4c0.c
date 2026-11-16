#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb600.h"
#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_render(u32 a) {
    MenuScene *menu;
    enum { K0 } screenNumber;

    if (scene_areUpdatesSuspended() == 0) {
        if (menu_sysdat_getOverlayRelatedNum() == 1 || menu_sysdat_getOverlayRelatedNum() == 2) {
            if (gMenuSceneState->mUnk_958 == FALSE) {
                if (StartDataSharingSync() != 1) {
                    return;
                }
                gMenuSceneState->mUnk_958 = TRUE;
            }
            if (gMenuSceneState->mUnk_95c == FALSE) {
                if (FinishDataSharingSync() != 1) {
                    return;
                }
                gMenuSceneState->mUnk_95c = TRUE;
            }
        }
        oam_resetBuffers(gMenuSceneState->mMainOam, gMenuSceneState->mSubOam);
        if (gMenuSceneState->mScreenInitPending != FALSE) {
            gMenuSceneState->mScreenInitPending = FALSE;
            menu_initSubMenu();
            menu = gMenuSceneState;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(a);
        } else {
            menu = gMenuSceneState;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(a);
            if (gMenuSceneState->mUnk_004 != 0) {
                menu_destroySubMenu();
                menu_initSubMenu();
            }
        }
        gmenu_render();
        AdvanceLinkLevelIcons();
        if (mbright_isFadedIn() != 0) {
            menu_increaseFrameCounter(&gMenuSceneState->mFramesSinceScreenSwitch);
        }
    }
}

void func_020cb4c0(void) {
    if (scene_areUpdatesSuspended() == 0) {
        if (menu_sysdat_getOverlayRelatedNum() == 1 || menu_sysdat_getOverlayRelatedNum() == 2) {
            if (gMenuSceneState->mUnk_958 == FALSE || gMenuSceneState->mUnk_95c == FALSE) {
                return;
            }
        }
        oam_prepareBuffers(gMenuSceneState->mMainOam, gMenuSceneState->mSubOam);
    }
}
