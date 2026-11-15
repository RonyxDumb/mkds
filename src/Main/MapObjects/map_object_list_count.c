#include "Main/MapObjects/map_object_list_count.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"

#pragma thumb on
void ClearMapObjectListCount(MapObjectList *mapObjectList) {
    mapObjectList->mMapObjectCount = 0;
}

void AddToMapObjectListCount(MapObjectList *mapObjectList, s32 addedCount) {
    mapObjectList->mMapObjectCount = mapObjectList->mMapObjectCount + addedCount;
}
#pragma thumb off
