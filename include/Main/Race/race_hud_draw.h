#pragma once

#include "types.h"
#include "Main/System/time_digits.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

void DrawRaceHud(void);

void UpdateRaceHudSubScreen(void);

void InitMap2D(void);

void UpdateRaceHud(void);
void ReleaseRaceHud(void);
void SetupRaceHudScreens(void);

void InitSubScreenGraphicsMode5(void);
void InitSubScreenGraphicsMode0(void);
void UploadRaceHud(void);
void InitRaceHud(void);

unsigned int GetRaceHudStepHasRun(void);

// Stores in *outSign the address of gRaceHud.mTimeDifferenceSign and in *outDigits the address of
// gRaceHud.mTimeDifferenceDigits.
void GetRaceHudTimeDifference(s32 **outSign, TimeDigits **outDigits);

unsigned int GetUseTimeDifference(void);
unsigned int GetShowLapTimeFrames(void);
BOOL GetShowLapTime(void);

extern u16 *gRaceHudSubScreenPalettes;

extern struct RaceHud *gRaceHud;

// Frames RaceHud.mGoalMDelayFrameCount is set to when the goal screen starts: Grand Prix and Time Attack, Battle,
// Versus and Wi-Fi, and the mission run goal.
#define RACE_HUD_GOAL_M_DELAY_GRAND_PRIX_TIME_ATTACK 0xc
#define RACE_HUD_GOAL_M_DELAY_BATTLE_VS_WIFI 0x8c
#define RACE_HUD_GOAL_M_DELAY_MISSION_RUN 0xaf
// Values of RaceHud.mSubScreenCourseScale: the sub screen course map scale; small for battle mini stage 3, medium for
// the other battle courses and mission run stages 1 to 4, large for all other races.
#define RACE_HUD_COURSE_SCALE_SMALL 0x40
#define RACE_HUD_COURSE_SCALE_MEDIUM 0x64
#define RACE_HUD_COURSE_SCALE_LARGE 0x86
// Frames the lap time stays shown, and the frame count at which RaceHud.mUpdateFrames wraps to 0.
#define RACE_HUD_LAP_TIME_SHOW_FRAMES 0x80
#define RACE_HUD_UPDATE_FRAMES_WRAP 0xc00
