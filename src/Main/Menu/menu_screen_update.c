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
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateMenuScreen(u32 sceneArg) {
    MenuScene *menu;
    enum { SCREEN_NUMBER_FIRST } screenNumber;

    if (IsDataSharingIncomplete() == 0) {
        if (GetPMaybeState_1() == 1 || GetPMaybeState_1() == 2) {
            if (g_GlobalB43C->mDataSharingSyncStarted == FALSE) {
                if (StartDataSharingSync() != 1) {
                    return;
                }
                g_GlobalB43C->mDataSharingSyncStarted = TRUE;
            }
            if (g_GlobalB43C->mDataSharingSyncFinished == FALSE) {
                if (FinishDataSharingSync() != 1) {
                    return;
                }
                g_GlobalB43C->mDataSharingSyncFinished = TRUE;
            }
        }
        OamBuffer_ResetValues16_from_thumb(g_GlobalB43C->mMainOam, g_GlobalB43C->mSubOam);
        if (g_GlobalB43C->mScreenInitPending != FALSE) {
            g_GlobalB43C->mScreenInitPending = FALSE;
            InitCurrentMenuScreen();
            menu = g_GlobalB43C;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(sceneArg);
        } else {
            menu = g_GlobalB43C;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(sceneArg);
            if (g_GlobalB43C->mScreenSwitched != 0) {
                ReleasePreviousMenuScreen();
                InitCurrentMenuScreen();
            }
        }
        NavigationContext_OnSceneUpdate_from_thumb();
        AdvanceLinkLevelIcons();
        if (Bright_IsBothScreensFadedIn() != 0) {
            MenuIncrementCounterSaturating(&g_GlobalB43C->mFramesSinceScreenSwitch);
        }
    }
}

void HideUnusedMenuOams(void) {
    if (IsDataSharingIncomplete() == 0) {
        if (GetPMaybeState_1() == 1 || GetPMaybeState_1() == 2) {
            if (g_GlobalB43C->mDataSharingSyncStarted == FALSE || g_GlobalB43C->mDataSharingSyncFinished == FALSE) {
                return;
            }
        }
        OamBuffer_SomeFn2_from_thumb(g_GlobalB43C->mMainOam, g_GlobalB43C->mSubOam);
    }
}
