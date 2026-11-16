#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h"

typedef struct MapObjectList MapObjectList;

void *RaceHudSubScreenGetMapObjects(MapObjectList *list);
void **GetMapObjects(MapObjectList *list);

extern const MapObjectList gDramUpdateListInitial;
