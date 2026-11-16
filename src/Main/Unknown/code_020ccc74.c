#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_gotoState(s32 screenNumber, s32 nextScreenNumber) {
    gMenuSceneState->mFramesSinceScreenSwitch = 0;
    gMenuSceneState->mUnk_004 = 1;
    gMenuSceneState->mPreviousScreenNumber = gMenuSceneState->mScreenNumber;
    gMenuSceneState->mScreenNumber = screenNumber;
    gMenuSceneState->mNextScreenNumber = nextScreenNumber;
}
#pragma thumb off
