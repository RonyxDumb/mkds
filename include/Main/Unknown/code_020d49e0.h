#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;

u32 mobj_renderPartAddInstance(MapObjectList *list, MapObject *mapObject);
u32 mobj_renderPartAllocInstanceList(MapObjectList *list);
