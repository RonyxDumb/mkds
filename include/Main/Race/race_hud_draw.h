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
