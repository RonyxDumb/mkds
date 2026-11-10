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
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateMenuScreen(u32 sceneArg) {
    MenuScene *menu;
    enum { K0 } screenNumber;

    if (IsDataSharingIncomplete() == 0) {
        if (MenuGetConnectionKind() == 1 || MenuGetConnectionKind() == 2) {
            if (gMenuScene->mDataSharingSyncStarted == FALSE) {
                if (StartDataSharingSync() != 1) {
                    return;
                }
                gMenuScene->mDataSharingSyncStarted = TRUE;
            }
            if (gMenuScene->mDataSharingSyncFinished == FALSE) {
                if (FinishDataSharingSync() != 1) {
                    return;
                }
                gMenuScene->mDataSharingSyncFinished = TRUE;
            }
        }
        ClearOamListCounts(gMenuScene->mMainOam, gMenuScene->mSubOam);
        if (gMenuScene->mScreenInitPending != FALSE) {
            gMenuScene->mScreenInitPending = FALSE;
            InitCurrentMenuScreen();
            menu = gMenuScene;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(sceneArg);
        } else {
            menu = gMenuScene;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(sceneArg);
            if (gMenuScene->mScreenSwitched != 0) {
                ReleasePreviousMenuScreen();
                InitCurrentMenuScreen();
            }
        }
        AdvanceSceneText();
        AdvanceLinkLevelIcons();
        if (AreBrightnessFadesClear() != 0) {
            MenuIncrementCounterSaturating(&gMenuScene->mFramesSinceScreenSwitch);
        }
    }
}

void HideUnusedMenuOams(void) {
    if (IsDataSharingIncomplete() == 0) {
        if (MenuGetConnectionKind() == 1 || MenuGetConnectionKind() == 2) {
            if (gMenuScene->mDataSharingSyncStarted == FALSE || gMenuScene->mDataSharingSyncFinished == FALSE) {
                return;
            }
        }
        HideUnusedOams(gMenuScene->mMainOam, gMenuScene->mSubOam);
    }
}
