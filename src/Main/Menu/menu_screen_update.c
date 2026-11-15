#include "Main/Menu/menu_screen_update.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Menu/menu_connection_kind.h"
#include "Main/Menu/menu_counter.h"
#include "Main/Menu/menu_screen_init.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Menu/message_screen.h"
#include "Main/MapObjects/data_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateMenuScreen(u32 sceneArg) {
    MenuScene *menu;
    enum { SCREEN_NUMBER_FIRST } screenNumber;

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
