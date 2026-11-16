#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

s32 menu_getFrameCounter(void) {
    return gMenuSceneState->mFramesSinceScreenSwitch;
}

u32 menu_getField4(void) {
    return (gMenuSceneState->field4);
}

u32 menu_getPrevState(void) {
    return (gMenuSceneState->mPreviousScreenNumber);
}

u32 menu_getCurState(void) {
    return (gMenuSceneState->mScreenNumber);
}

u32 menu_getField10(void) {
    return (gMenuSceneState->mNextScreenNumber);
}

#pragma thumb off
