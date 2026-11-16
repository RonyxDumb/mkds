#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct MapObject MapObject;

void *FormatFindMapObjFileBuffer_0_from_thumb(const char *name);
void *FormatFindMapObjFileBuffer_from_thumb(const char *name);

void nullsub_11(void);
void InitRaceMNumberPair(void);
u32 DecimalNonZeroDigitsToBitMask(s32 number);
BOOL DoesMapObjectRespondToItemObject(MapObject *mapObject, ItemObject *itemObject);

void ClearRaceMNumberPairPointer(void);
