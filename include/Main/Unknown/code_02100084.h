#pragma once

#include "types.h"

typedef struct MapObjectList MapObjectList;

void *mobj_renderPartGetInstanceList(MapObjectList *list);
void **mobj_logicPartGetInstanceList(MapObjectList *list);
