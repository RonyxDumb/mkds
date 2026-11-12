#include "Main/MapObjects/map_object_list_count_get.h"
#include "Main/MapObjects/attractor.h"

u32 GetMapObjectListCount(MapObjectList *list) {
    return list->mMapObjectCount;
}
