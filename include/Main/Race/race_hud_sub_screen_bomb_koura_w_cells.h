#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceHudSubScreenBombKouraWCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenBombKouraWCells(void);

void ClearRaceHudSubScreenBombKouraWCells(void);

s32 CreateRaceHudSubScreenBombKouraWCells(void);
void UpdateRaceHudSubScreenBgPalette(u16 *palette);
void CopyRaceHudSubScreenBgColors(void);

void InitRaceHudSubScreenBgColors(void);

extern struct RaceHudSubScreenBgColors *gRaceHudSubScreenBgColors;
extern struct RaceHudSubScreenCells *gRaceHudSubScreenBombKouraWCells;
