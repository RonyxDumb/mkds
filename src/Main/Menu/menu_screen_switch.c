#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/single_play_select_screen3.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

#pragma thumb on

s32 GetFramesSinceMenuScreenSwitch(void) {
    return g_GlobalB43C->mFramesSinceScreenSwitch;
}

u32 GetMenuScreenSwitched(void) {
    return (g_GlobalB43C->mScreenSwitched);
}

u32 GetPreviousMenuScreenNumber(void) {
    return (g_GlobalB43C->mPreviousScreenNumber);
}

u32 GetMenuScreenNumber(void) {
    return (g_GlobalB43C->mScreenNumber);
}

u32 GetNextMenuScreenNumber(void) {
    return (g_GlobalB43C->mNextScreenNumber);
}

#pragma thumb off

#pragma optimize_for_size on
#pragma thumb on
void SwitchMenuScreen(s32 screenNumber, s32 nextScreenNumber) {
    g_GlobalB43C->mFramesSinceScreenSwitch = 0;
    g_GlobalB43C->mScreenSwitched = 1;
    g_GlobalB43C->mPreviousScreenNumber = g_GlobalB43C->mScreenNumber;
    g_GlobalB43C->mScreenNumber = screenNumber;
    g_GlobalB43C->mNextScreenNumber = nextScreenNumber;
}
#pragma thumb off
