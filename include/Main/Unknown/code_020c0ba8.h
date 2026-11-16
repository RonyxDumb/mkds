#pragma once

#include "types.h"

typedef struct RaceHudSubScreenCells RaceHudSubScreenCells;

BOOL mpicn_createMapObjIcon(RaceHudSubScreenCells **outCells, s32 kind);
BOOL mpicn_20C0BA8(RaceHudSubScreenCells **outCells, s32 objectCount);
