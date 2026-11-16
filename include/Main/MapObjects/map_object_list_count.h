#pragma once

#include "types.h"

typedef struct MapObjectList MapObjectList;

void AddToMapObjectListCount(MapObjectList *mapObjectList, s32 addedCount);
void ClearMapObjectListCount(MapObjectList *mapObjectList);
