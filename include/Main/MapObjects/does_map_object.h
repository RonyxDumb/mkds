#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct MapObject MapObject;

void *FindMainRaceOrMainEffectMapObjFile(const char *name);
void *FindCourseMapObjFile(const char *name);

void UpdateRaceMNumberPairNop(void);
void InitRaceMNumberPair(void);
u32 DecimalNonZeroDigitsToBitMask(s32 number);
BOOL DoesMapObjectRespondToItemObject(MapObject *mapObject, ItemObject *itemObject);
