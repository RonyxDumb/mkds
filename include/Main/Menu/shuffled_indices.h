#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_park.h" // RandomState64

BOOL CreateRaceHudSubScreenPakkunSpitCells(void);
void ClearShuffledIndices(void);
void FillShuffledIndices(void);

RandomState64 *ShuffledIndicesGetConnectionWorkRandomState(void);
unsigned int ShuffledIndicesGetConnectionKind(void);
