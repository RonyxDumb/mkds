#pragma once

#include "types.h"

void SetUpdateListSlot(void *listSlot);

typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;

void AddMapObjectToUpdateList(MapObjectList *mapObjectList, MapObject *mapObject);

u32 InitMapObjectUpdateList(MapObjectList *list);
