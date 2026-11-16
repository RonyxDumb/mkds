#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on

s32 GetFramesSinceMenuScreenSwitch(void) {
    return gMenuScene->mFramesSinceScreenSwitch;
}

u32 GetMenuScreenSwitched(void) {
    return (gMenuScene->mScreenSwitched);
}

u32 GetPreviousMenuScreenNumber(void) {
    return (gMenuScene->mPreviousScreenNumber);
}

u32 GetMenuScreenNumber(void) {
    return (gMenuScene->mScreenNumber);
}

u32 GetNextMenuScreenNumber(void) {
    return (gMenuScene->mNextScreenNumber);
}

#pragma thumb off

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
