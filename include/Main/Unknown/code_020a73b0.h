#pragma once

#include "types.h"
#include "Main/Unknown/code_020a7000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

void UpdateSanbo(void *a, Sanbo *sanbo); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 SanboMulFixed12Rounded(s32 a, s32 b);
s32 SanboGetAnglePairFirst(s32 a);
void InitSanboObjects(MapObjectList *mapObjectList);
void DrawSanbo(void *a, Sanbo *sanbo);
