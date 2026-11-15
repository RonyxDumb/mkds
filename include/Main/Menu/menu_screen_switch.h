#pragma once

#include "types.h"

// Screen numbers: the first argument of SwitchMenuScreen (stored as the current screen number, member 0xc of the object
// behind gMenuScene) and the number GetPreviousMenuScreenNumber returns for the previous screen. The screens that
// InitCurrentMenuScreen and ReleasePreviousMenuScreen start and release are named after their Init class and the race
// mode whose entry path leads to them (RaceSetup.mMode, set up in menu.c).
// InitSelectEngine / ReleaseSelectEngine.
// No screen: the value of the previous, current and next screen number when no screen is open.
#define SCREEN_NONE 0x1f
#define SCREEN_SELECT_ENGINE 4
// InitSelectCharacter / ReleaseSelectCharacter, one number per race mode.
#define SCREEN_SELECT_CHARACTER_GRAND_PRIX 5
#define SCREEN_SELECT_CHARACTER_VS 8
#define SCREEN_SELECT_CHARACTER_BATTLE 15
#define SCREEN_SELECT_CHARACTER_TIME_ATTACK 21
// InitSelectKart / ReleaseSelectKart.
#define SCREEN_SELECT_KART_GRAND_PRIX 6
#define SCREEN_SELECT_KART_VS 9
#define SCREEN_SELECT_KART_TIME_ATTACK 22
// InitSelectCupGrid / ReleaseSelectCupGrid.
#define SCREEN_SELECT_CUP_GRID_GRAND_PRIX 7
#define SCREEN_SELECT_CUP_GRID_VS 11
#define SCREEN_SELECT_CUP_GRID_TIME_ATTACK 23
// InitSelectCupM / ReleaseSelectCupM.
#define SCREEN_SELECT_CUP_M_VS 12
#define SCREEN_SELECT_CUP_M_TIME_ATTACK 24
// InitSelectCupCourse / ReleaseSelectCupCourse.
#define SCREEN_SELECT_CUP_COURSE_VS 13
#define SCREEN_SELECT_CUP_COURSE_TIME_ATTACK 25
// InitSelectRaceRule / ReleaseSelectRaceRule.
#define SCREEN_SELECT_RACE_RULE_VS 10
#define SCREEN_SELECT_RACE_RULE_BATTLE 16
// InitSelectGame / ReleaseSelectGame.
#define SCREEN_SELECT_GAME 14
// Has no Init class: InitCurrentMenuScreen calls SetNextRaceSetupFromCopy.
#define SCREEN_NEXT_RACE_SETUP 29
// InitSelectBattleStage / ReleaseSelectBattleStage.
#define SCREEN_SELECT_BATTLE_STAGE 0x11
// InitMissionRunLVsel / ReleaseMissionRunLVsel.
#define SCREEN_MISSION_RUN_LVSEL 0x12
// InitMissionRunMSsel / ReleaseMissionRunMSsel.
#define SCREEN_MISSION_RUN_MSSEL 0x13
// InitTimeAttackTopMenu / ReleaseTimeAttackTopMenu.
#define SCREEN_TIME_ATTACK_TOP_MENU 0x14
// InitSelectGhost (released by ReleaseSelectGhost).
#define SCREEN_SELECT_GHOST 0x1a

void SwitchMenuScreen(s32 screenNumber, s32 nextScreenNumber);

unsigned int GetNextMenuScreenNumber(void);
unsigned int GetMenuScreenNumber(void);
unsigned int GetPreviousMenuScreenNumber(void);
unsigned int GetMenuScreenSwitched(void);
s32 GetFramesSinceMenuScreenSwitch(void);
