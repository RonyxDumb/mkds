#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "sprite_animation_control.h"

#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

// The Grand Prix start screen: its frame counter, palette, chars, cell entries and the NtrMain OAM buffer.
typedef struct RaceStartGp {
    /* 00 */ s32 mUpdateFrames;
    /* 04 */ Nclr *mRaceStartGpMONclr;
    /* 08 */ Ncgr *mRaceStartGpMONcgr;
    /* 0c */ NNSG2dCellDataWithBR *mRaceStartGpMNcerEntries[3];
    /* 18 */ RaceHudOamBuffer mMainOam;
} RaceStartGp;

void InitializeRaceIntroData(void);


void ClearRaceTaPositionsPointer(void);
void InitRaceTaPositions(void);
void ResetRaceTaKartPositions(s32 kartIndex);
void HideRaceTaKartPositions(s32 kartIndex);
void DrawRaceStartGp(void);
u16 IncrementRaceIntroFrameCounter(void);
void LoadRaceIntroDataOam(void);
void DrawRaceLinkLevel(RaceHudOamBuffer *oamBuffer);
void UpdateRaceLinkLevel(void);
void ResetGlobalB3EC(void);

void UpdateRaceTaPositions(void);
void DrawRaceTaPositions(RaceHudOamBuffer *oamBuffer);

void Reset33(void);

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// RaceGoalM.mMissionRecordValue and mComputedMissionRecordValue when there is no value (no record saved, or the entry
// kart did not finish).
#define MISSION_RECORD_VALUE_NONE 9

// The mission goal: its ready flag, update frames, rank, points gained, first place kart and the mission record values.
typedef struct RaceGoalM {
// 0 once the followed kart has status 1 or the race is done, until mUpdateFrames passes 0x14 (0x1e or 0x4b by the
// entry end kind in Mission Run); 1 at StructDC_SomeFn_from_thumb.
    /* 00 */ s32 mReady;
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mRankIndex;
    /* 0c */ s32 mPointsGained;
    /* 10 */ u16 mFirstPlaceKartIndex;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ s32 mMissionRecordValue;
    /* 18 */ s32 mComputedMissionRecordValue;
} RaceGoalM;

void CreateGlobalB3EC(void);
void DrawRaceGoalMMissionRun(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalMGrandPrix(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalM(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalM(void);

void ResetGlobalB3F0(void);

void CreateGlobalB3F0(void);

unsigned int GetB3F0_Beb1(void);
BOOL GetB3F0_Beb0(void);

extern const Vec3 gVec3Zero;
extern struct RaceTaPositions *gRaceTaPositions;
extern struct RaceGoalM *g_GlobalB3F0;
extern struct RaceStartGp *g_ref_GlobalRaceIntro;
extern struct RaceLinkLevel *g_GlobalB3EC;

// RaceGoalM.mComputedMissionRecordValue (0 to 7, higher is better): the three best values start a sequence; a value of
// the count or more has no cell. The friend-on frame count restarts at the first limit and the friend cell shows below
// the second.
#define MISSION_RECORD_VALUE_THIRD_BEST 5
#define MISSION_RECORD_VALUE_SECOND_BEST 6
#define MISSION_RECORD_VALUE_BEST 7
#define MISSION_RECORD_VALUE_COUNT 8
#define RACE_LINK_FRIEND_ON_CYCLE_FRAMES 0x78
#define RACE_LINK_FRIEND_ON_SHOWN_FRAMES 0x69
