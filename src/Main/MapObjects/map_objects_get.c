#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/dram.h"

const MapObjectList gDramUpdateListInitial = {NULL, 0,    {0, 0}, NULL, PickDramAngleChoices, UpdateDram, NULL,
                                              0,    NULL, 0,      NULL};

void **GetMapObjects(MapObjectList *list) {
    return list->mMapObjects;
}

void *RaceHudSubScreenGetMapObjects(MapObjectList *list) {
    return list->mMapObjects;
}
