#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void InitRaceTimeDigits(void);
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *oamBuffer);
void UpdateRaceLapNumber(void);
void ClearRaceLapNumberPointer(void);
void InitRaceLapNumber(void);
void DrawRaceRankListBattleState1To3Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListBattleState0Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListNonBattleRows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListState1To3Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListState0Rows(RaceHudOamBuffer *oamBuffer);
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
