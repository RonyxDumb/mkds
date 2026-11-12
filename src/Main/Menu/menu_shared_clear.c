#include "Main/Menu/menu_shared_clear.h"
#include "Main/Menu/menu_mi_fill.h"
#include "00/code_02181f98.h"

#pragma thumb on

void ClearMenuShared(void) {
    MenuMI_CpuClearFast(gMenuShared, 0x130);
    gMenuShared->mTitleBlendDone = 0;
    gMenuShared->mRaceSetupRequested = 0;
    gMenuShared->mMenuEntryKind = 0;
    gMenuShared->mGhostSceneInitialCallbacksIndex = 0;
    gMenuShared->mUnfilledNotEliminated = 0;
    gMenuShared->mLVselIndex6Requested = 0;
    gMenuShared->mWiFiMenuStartKind = 0;
    gMenuShared->mWiFiVSSettingKartType = 0;
    gMenuShared->mWiFiTopMenuRequested = FALSE;
    gMenuShared->mStaffRollEndedEarly = 0;
}

#pragma thumb off
