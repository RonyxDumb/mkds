#pragma once

#include "types.h"

// Halfwords the first three functions index with a count minus one or two.
extern u16 data_02153ea0[];
extern u16 data_02153eb0[];
// 8-byte entries.
extern u8 data_02153e98[];
extern u8 data_02153ec0[];

void bres_initVSTeams(void *heap);
void bres_initDraw(void *heap);
void bres_initLose(void *heap);
void bres_initVictory(void *heap);
void bres_2033AB8(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 d);
void bres_2033B80(s32 entryIndex);
void bres_2033C80(s32 entryIndex);
