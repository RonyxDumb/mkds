#include "Main/Menu/menu_shared_clear.h"
#include "Main/Menu/menu_mi_fill.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/ghost_scene.h"
#include "Main/Menu/menu_entry_kind.h"

#pragma thumb on

MenuShared *gMenuShared;

void ClearMenuShared(void) {
    MenuMI_CpuClearFast(gMenuShared, 0x130);
    gMenuShared->mTitleBlendDone = 0;
    gMenuShared->mRaceSetupRequested = 0;
    gMenuShared->mMenuEntryKind = MENU_ENTRY_SINGLE_PLAY_SELECT;
    gMenuShared->mGhostSceneInitialCallbacksIndex = GHOST_SCENE_CALLBACKS_SEND;
    gMenuShared->mUnfilledNotEliminated = 0;
    gMenuShared->mLVselIndex6Requested = 0;
    gMenuShared->mWiFiMenuStartKind = 0;
    gMenuShared->mWiFiVSSettingKartType = WIFI_MATCH_TYPE_BUDDIES;
    gMenuShared->mWiFiTopMenuRequested = FALSE;
    gMenuShared->mStaffRollEndedEarly = 0;
}

#pragma thumb off
