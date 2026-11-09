#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// Object behind gRaceGoalM, 0x1c bytes allocated by InitRaceGoalM.
typedef struct RaceGoalM {
// 0 once the followed kart has status 1 or the race is done, until mUpdateFrames passes 0x14 (0x1e or 0x4b by the
// entry end kind in Mission Run); 1 at init.
    /* 00 */ s32 mReady;
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mRankIndex;
    /* 0c */ s32 mPointsGained;
    /* 10 */ u16 mFirstPlaceKartIndex;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
} RaceGoalM;

void InitRaceLinkLevel(void);
void DrawRaceGoalMMissionRun(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalMGrandPrix(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalM(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalM(void);
