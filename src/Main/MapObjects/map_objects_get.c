#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/attractor.h"

void **GetMapObjects(MapObjectList *list) {
    return list->mMapObjects;
}

void *RaceHudSubScreenGetMapObjects(MapObjectList *list) {
    return list->mMapObjects;
}
