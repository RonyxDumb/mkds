#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "sprite_animation_control.h"

#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

// The Grand Prix start screen: its frame counter, palette, chars, cell entries and the main OAM buffer.
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

// MISSION_RECORD_VALUE_NONE: no value. For RaceGoalM.mMissionRecordValue: no record saved, or a mode other than
// MODE_MISSION_RUN. For mComputedMissionRecordValue: at init, or when the entry kart has not ended with
// RACE_END_KIND_GOAL (not ended yet, or ended by another kind).
#define MISSION_RECORD_VALUE_NONE 9

// The goal screen of the main screen: its ready flag, update frames, rank, points gained (Grand Prix), first place kart
// (Versus, Wi-Fi) and the mission record values (Mission Run).
typedef struct RaceGoalM {
// 1 at init; set to 0 while the followed kart has status GOAL_REACHED or the race is done, and to 1 again once
// mUpdateFrames is above 0x14 (Grand Prix, Time Attack, Versus, WiFi), above 0x1e after a goal end or above 0x4b
// otherwise (Mission Run), at once in the other modes; UpdateRaceGoalM returns first while IsRaceHudGoalMEnabled is 0.
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

// RaceGoalM.mComputedMissionRecordValue (the cells cover 0 to 7, higher is better): at frame 1 the three best values
// start a sound sequence; a value of the count or more has no cell. The friend-on frame count restarts at
// RACE_LINK_FRIEND_ON_CYCLE_FRAMES and the friend cell shows below RACE_LINK_FRIEND_ON_SHOWN_FRAMES.
#define MISSION_RECORD_VALUE_THIRD_BEST 5
#define MISSION_RECORD_VALUE_SECOND_BEST 6
#define MISSION_RECORD_VALUE_BEST 7
#define MISSION_RECORD_VALUE_COUNT 8
#define RACE_LINK_FRIEND_ON_CYCLE_FRAMES 0x78
#define RACE_LINK_FRIEND_ON_SHOWN_FRAMES 0x69
