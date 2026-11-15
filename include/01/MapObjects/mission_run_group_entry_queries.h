#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct Kart Kart;
typedef struct CourseMapGroupEntry CourseMapGroupEntry;

void DecrementEntryIndexSkipZero(MissionRunMapObject *mapObject);
CourseMapGroupEntry *GetNextGroupEntry(MissionRunMapObject *mapObject);
s32 GetCurrentGroupEntryPercent(MissionRunMapObject *mapObject);
s32 GetCurrentGroupEntryValue(MissionRunMapObject *mapObject);
CourseMapGroupEntry *GetCurrentGroupEntry(MissionRunMapObject *mapObject);
Kart *GetEntryKartFacingObject(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle);
Kart *GetEntryKartInAngleRange(MissionRunMapObject *mapObject, s32 angleOffset, s32 radius, s32 halfAngle);
Kart *GetEntryKartInRange(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle);
