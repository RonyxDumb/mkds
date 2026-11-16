#pragma once

#include "types.h"

// Screen numbers: the first argument of menu_gotoState (stored as the current screen number, member 0xc of the object
// behind gMenuSceneState) and the number menu_getPrevState returns for the previous screen. Only the screens
// that have a single number and a named Init class are defined; the other numbers stay literals. LoadCCSelectionMenu /
// ReleaseSelectEngine (started and released by menu_initSubMenu and menu_destroySubMenu).
#define SCREEN_SELECT_ENGINE 4
// SPM_LoadBattleStageSelectionMenu / ReleaseSelectBattleStage.
#define SCREEN_SELECT_BATTLE_STAGE 0x11
// SPM_LoadMissionRunMenu / ReleaseMissionRunLVsel.
#define SCREEN_MISSION_RUN_LVSEL 0x12
// SPM_LoadMissionRunLevelMenu / ReleaseMissionRunMSsel.
#define SCREEN_MISSION_RUN_MSSEL 0x13
// menu_ta_init / menu_ta_destroy.
#define SCREEN_TIME_ATTACK_TOP_MENU 0x14
// InitSelectGhost (released by ReleaseSelectGhost).
#define SCREEN_SELECT_GHOST 0x1a

void menu_gotoState(s32 screenNumber, s32 nextScreenNumber);
