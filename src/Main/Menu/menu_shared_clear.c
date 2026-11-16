#include "Main/Menu/menu_shared_clear.h"
#include "Main/Menu/menu_mi_fill.h"
#include "00/Menu/wi_fi_vs_setting.h"

#pragma thumb on

MenuShared *g_GlobalB488;

void CreateGlobalB488_from_thumb(void) {
    SpecialMemoryZero_0(g_GlobalB488, 0x130);
    g_GlobalB488->mTitleBlendDone = 0;
    g_GlobalB488->mRaceSetupRequested = 0;
    g_GlobalB488->mMenuEntryKind = 0;
    g_GlobalB488->mGhostSceneInitialCallbacksIndex = 0;
    g_GlobalB488->mUnfilledNotEliminated = 0;
    g_GlobalB488->mLVselIndex6Requested = 0;
    g_GlobalB488->mWiFiMenuStartKind = 0;
    g_GlobalB488->mWiFiVSSettingKartType = 0;
    g_GlobalB488->mWiFiTopMenuRequested = FALSE;
    g_GlobalB488->mStaffRollEndedEarly = 0;
}

#pragma thumb off
