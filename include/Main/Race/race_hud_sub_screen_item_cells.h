#pragma once

#include "types.h"
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudSubScreenCells
#include "Main/Race/race_hud_keyboard_map_object_work.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

s32 CreateRaceHudSubScreenItemBoxCells(void);
void DrawRaceHudSubScreenEarthenPipeCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenEarthenPipeCells(void);
void ClearRaceHudSubScreenEarthenPipeCells(void);
s32 CreateRaceHudSubScreenEarthenPipeCells(void);
void DrawRaceHudSubScreenWanwanCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenWanwanCells(void);
void ClearRaceHudSubScreenWanwanCells(void);
BOOL CreateRaceHudSubScreenWanwanCells(void);
void DrawRaceHudSubScreenDossunCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenDossunCells(void);
void ClearRaceHudSubScreenDossunCells(void);
s32 CreateRaceHudSubScreenDossunCells(void);
void DrawRaceHudSubScreenSmanCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenSmanCells(void);
void ClearRaceHudSubScreenSmanCells(void);
s32 CreateRaceHudSubScreenSmanCells(void);
void DrawRaceHudSubScreenMoveTreeCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenMoveTreeCells(void);
void ClearRaceHudSubScreenMoveTreeCells(void);
s32 CreateRaceHudSubScreenMoveTreeCells(void);
void DrawRaceHudSubScreenPukupukuCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenPukupukuCells(void);
void ClearRaceHudSubScreenPukupukuCells(void);
s32 CreateRaceHudSubScreenPukupukuCells(void);
void DrawRaceHudSubScreenChoropuCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenChoropuCells(void);
void ClearRaceHudSubScreenChoropuCells(void);
s32 CreateRaceHudSubScreenChoropuCells(void);
void DrawRaceHudSubScreenKoopaBlockCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenKoopaBlockCells(void);
void ClearRaceHudSubScreenKoopaBlockCells(void);
s32 CreateRaceHudSubScreenKoopaBlockCells(void);
void DrawRaceHudSubScreenCarCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenCarCells(void);
void ClearRaceHudSubScreenCarCells(void);
BOOL CreateRaceHudSubScreenCarCells(void);
void DrawRaceHudSubScreenSecondHand(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenSecondHand(void);
void ClearRaceHudSubScreenSecondHandPointer(void);
BOOL CreateRaceHudSubScreenSecondHand(void);
void DrawRaceHudSubScreenKarts(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenKarts(void);
void ClearRaceHudSubScreenKarts(void);
s32 CreateRaceHudSubScreenKarts(void);
void DrawRaceHudSubScreenItemCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenItemCells(void);
void ClearRaceHudSubScreenItemCells(void);
s32 CreateRaceHudSubScreenItemCells(void);
void DrawRaceHudSubScreenCrabCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenCrabCells(void);

extern s32 gRaceHudSubScreenItemPoolIndices[10];

extern struct RaceHudSubScreenCells *gRaceHudSubScreenWanwanCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenPukupukuCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenEarthenPipeCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenItemCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenDossunCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenSmanCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenMoveTreeCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenChoropuCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenKoopaBlockCells;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenCarCells;
extern struct RaceHudSubScreenSecondHand *gRaceHudSubScreenSecondHand;
extern struct RaceHudSubScreenKarts *gRaceHudSubScreenKarts;

extern RaceHudSubScreenCells *gRaceHudSubScreenCrabCells;
