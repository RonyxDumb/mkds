#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void InitRaceTimeDigits(void);
void r2d_renderLapAndTimeDiff(RaceHudOamBuffer *oamBuffer);
void r2d_updateLapAndTimeDiff(void);
u32 r2d_finalizeLapAndTimeDiff(void);
void r2d_initLapAndTimeDiff(void);
void DrawRaceRankListBattleState1To3Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListBattleState0Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListNonBattleRows(RaceHudOamBuffer *a);
void DrawRaceRankListState1To3Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListState0Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListRankCells(RaceHudOamBuffer *oamBuffer);
u32 GetRaceRankListSNcerIndex(u16 kartIndex);
void DrawRaceRankList(RaceHudOamBuffer *oamBuffer);
void UpdateRaceRankList(void);
u32 ClearRaceRankListPointer(void);
