#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void SwitchMenuScreen(s32 screenNumber, s32 nextScreenNumber) {
    gMenuScene->mFramesSinceScreenSwitch = 0;
    gMenuScene->mScreenSwitched = 1;
    gMenuScene->mPreviousScreenNumber = gMenuScene->mScreenNumber;
    gMenuScene->mScreenNumber = screenNumber;
    gMenuScene->mNextScreenNumber = nextScreenNumber;
}
#pragma thumb off
