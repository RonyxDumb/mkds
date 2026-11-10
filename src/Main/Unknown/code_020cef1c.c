#include "Main/Unknown/code_020cef1c.h"
#include "Main/Unknown/code_020cef68.h"
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
    gMenuShared->mUnk_1c = 0;
    gMenuShared->mUnk_54 = 0;
    gMenuShared->mUnk_58 = FALSE;
    gMenuShared->mUnk_70 = 0;
}

#pragma thumb off
