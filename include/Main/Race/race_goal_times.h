#pragma once

#include "types.h"

#include "Main/Race/race_hud_sub_screen_cells.h"

#include "Main/MapObjects/data_0217b000.h"
#include "g2d_Animation.h"

// RaceGoalTimes.mRecordCycleFrame counts this many frames; mCellIndexAdd steps through three cell sets, one per
// quarter (the second set twice), while a new record is shown. The sets start at offsets 0, 0xd and 0x1a.
#define RACE_GOAL_TIMES_CYCLE_FRAMES 16
#define RACE_GOAL_TIMES_CYCLE_QUARTER_FRAMES 4
#define RACE_GOAL_TIMES_CELL_SET_FIRST 0
#define RACE_GOAL_TIMES_CELL_SET_SECOND 0xd
#define RACE_GOAL_TIMES_CELL_SET_THIRD 0x1a

// Object behind gRaceGoalTimes.
typedef struct RaceGoalTimes {
    /* 00 */ TimeDigits mFinishTime;
    /* 1c */ TimeDigits mLapTimes[5];
// Counts 0 to 15; picks mCellIndexAdd by quarters.
    /* a8 */ s32 mRecordCycleFrame;
// Added to the cell number of a time row: 0, 0xd or 0x1a.
    /* ac */ s32 mCellIndexAdd;
} RaceGoalTimes;

void DrawRaceHudSubScreenCreamCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenCreamCells(void);
s32 CreateRaceHudSubScreenCreamCells(void);
void DrawRaceHudSubScreenBerryCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenBerryCells(void);
void ClearRaceHudSubScreenBerryCells(void);
s32 CreateRaceHudSubScreenBerryCells(void);
void DrawRaceGoalTimeDigits(RaceHudOamBuffer *oamBuffer, s32 originX, s32 originY, TimeDigits *digits, s32 cellOffset);
void DrawRaceGoalTimes(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalTimes(void);
void ClearRaceGoalTimesPointer(void);
void InitRaceGoalTimes(void);
void DrawRaceHudSubScreenFireball2Cells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenFireball2Cells(void);
void ClearRaceHudSubScreenFireball2Cells(void);

void ClearRaceHudSubScreenCreamCells(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenCreamCells;
extern struct RaceGoalTimes *gRaceGoalTimes;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenBerryCells;

extern RaceHudSubScreenCells *gRaceHudSubScreenFireball2Cells;
