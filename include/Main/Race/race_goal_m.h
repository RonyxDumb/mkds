#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"
#include "g2d_Animation.h"

#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

// Object behind gRaceStartGp, 0x41c bytes, allocated by InitRaceStartGp.
typedef struct RaceStartGp {
    /* 00 */ s32 mUpdateFrames;
    /* 04 */ Nclr *mRaceStartGpMONclr;
    /* 08 */ Ncgr *mRaceStartGpMONcgr;
    /* 0c */ NNSG2dCellDataWithBR *mRaceStartGpMNcerEntries[3];
    /* 18 */ RaceHudOamBuffer mMainOam;
} RaceStartGp;

void InitRaceStartGp(void);


void ClearRaceTaPositionsPointer(void);
void InitRaceTaPositions(void);
void ResetRaceTaKartPositions(s32 kartIndex);
void HideRaceTaKartPositions(s32 kartIndex);
void DrawRaceStartGp(void);
u16 UpdateRaceStartGp(void);
void UploadRaceStartGpOam(void);
void DrawRaceLinkLevel(RaceHudOamBuffer *oamBuffer);
void UpdateRaceLinkLevel(void);
void ClearRaceLinkLevelPointer(void);

void UpdateRaceTaPositions(void);
void DrawRaceTaPositions(RaceHudOamBuffer *oamBuffer);

void ClearRaceStartGpPointer(void);

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// RaceGoalM.mMissionRecordValue and mComputedMissionRecordValue when there is no value (no record saved, or the entry
// kart did not finish).
#define MISSION_RECORD_VALUE_NONE 9

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
    /* 14 */ s32 mMissionRecordValue;
    /* 18 */ s32 mComputedMissionRecordValue;
} RaceGoalM;

void InitRaceLinkLevel(void);
void DrawRaceGoalMMissionRun(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalMGrandPrix(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalM(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalM(void);

void ClearRaceGoalMPointer(void);

void InitRaceGoalM(void);

unsigned int GetRaceGoalMUpdateFrames(void);
BOOL IsRaceGoalMReady(void);

extern const Vec3 gVec3Zero;
extern struct RaceTaPositions *gRaceTaPositions;
extern struct RaceGoalM *gRaceGoalM;
extern struct RaceStartGp *gRaceStartGp;
extern struct RaceLinkLevel *gRaceLinkLevel;
