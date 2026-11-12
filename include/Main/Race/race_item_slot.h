#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceMissionRunCount(RaceHudOamBuffer *oamBuffer);
void DrawRaceModeCount(RaceHudOamBuffer *oamBuffer);
void UpdateRaceModeCount(void);
void InitRaceModeCount(void);
BOOL IsRaceKeyRecordingNotFull(void);
void DrawRaceItemSlot(RaceHudOamBuffer *oamBuffer);
void UpdateRaceItemSlot(void);
void ClearRaceItemSlotPointer(void);

void ClearRaceModeCountPointer(void);

void InitRaceItemSlot(void);

extern struct RaceItemSlot *gRaceItemSlot;
extern struct RaceModeCount *gRaceModeCount;
