#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void InitRaceTimeDigits(void);
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *oamBuffer);
void UpdateRaceLapNumber(void);
void ClearRaceLapNumberPointer(void);
void InitRaceLapNumber(void);
void DrawRaceRankListBattleMapRows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListBattleKartIconsRows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListNonBattleRows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListMapRows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListKartIconsRows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListRankCells(RaceHudOamBuffer *oamBuffer);
u32 GetRaceRankListSNcerIndex(u16 kartIndex);
void DrawRaceRankList(RaceHudOamBuffer *oamBuffer);
void UpdateRaceRankList(void);
void ClearRaceRankListPointer(void);

void InitRaceRankList(void);
void StartRaceRankListItemInUse(s32 kartIndex, s32 itemId, s32 objectCount);

void StopRaceRankListItemInUse(int kartIndex);

extern struct RaceRankList *gRaceRankList;
extern struct RaceLapNumber *gRaceLapNumber;

// Frames of the rank list cycle: the kart cells move for this long, an item in use counts for this long, and the last
// lap number blinks for this long.
#define RACE_RANK_LIST_MOVE_FRAMES 0x1c
#define RACE_RANK_LIST_ITEM_IN_USE_FRAMES 0x24
#define RACE_LAP_NUMBER_BLINK_FRAMES 0x78
