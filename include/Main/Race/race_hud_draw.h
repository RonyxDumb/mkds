#pragma once

#include "types.h"
#include "Main/System/time_digits.h"
#include "Main/MapObjects/data_0217b000.h"

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

// Stores in *a the address of the mTimeDifferenceSign member of gRaceHud and in *b the address of its
// mTimeDifferenceDigits member.
void GetRaceHudTimeDifference(s32 **outSign, TimeDigits **outDigits);

unsigned int GetUseTimeDifference(void);
unsigned int GetShowLapTimeFrames(void);
BOOL GetShowLapTime(void);

extern u16 *gRaceHudSubScreenPalettes;

extern struct RaceHud *gRaceHud;

// Frames RaceHud.mGoalMDelayFrameCount is set to when the goal screen starts: a race of one kart (Grand Prix, Time
// Attack), a race with several karts, and the mission run goal.
#define RACE_HUD_GOAL_M_DELAY_SOLO 0xc
#define RACE_HUD_GOAL_M_DELAY_MULTI 0x8c
#define RACE_HUD_GOAL_M_DELAY_MISSION_RUN 0xaf
// Values of RaceHud.mSubScreenCourseScale: the scale of the course map on the lower screen for a small, a medium and a
// large course.
#define RACE_HUD_COURSE_SCALE_SMALL 0x40
#define RACE_HUD_COURSE_SCALE_MEDIUM 0x64
#define RACE_HUD_COURSE_SCALE_LARGE 0x86
// Frames the lap time stays shown, and the frame count at which RaceHud.mUpdateFrames wraps to 0.
#define RACE_HUD_LAP_TIME_SHOW_FRAMES 0x80
#define RACE_HUD_UPDATE_FRAMES_WRAP 0xc00
