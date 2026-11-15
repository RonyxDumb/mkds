#pragma once

#include "types.h"
#include "Main/MapObjects/sanbo_pieces.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObjectList

void UpdateSanbo(void *mapObjectList, Sanbo *sanbo); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 SanboFX_MulInline(s32 value, s32 scale);
s32 SanboFX_SinIdx(s32 angle);
void InitSanboObjects(MapObjectList *mapObjectList);
void DrawSanbo(void *mapObjectList, Sanbo *sanbo);
