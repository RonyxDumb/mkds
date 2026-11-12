#pragma once

#include "types.h"

void WriteChoisesSValueTiles(u16 *screenMap, s32 column, s32 row);
void WriteChoisesSListTiles(void);

int GetChoisesSPickedValue(void);
unsigned int GetChoisesSPrevOpenDuringRace(void);
void SetChoisesSOpenDuringRace(u32 openFlag);

u32 IsChoisesSOpen(void);

unsigned int GetChoisesSOpenDuringRace(void);
