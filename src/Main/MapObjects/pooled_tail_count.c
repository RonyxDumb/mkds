#include "Main/MapObjects/pooled_tail_count.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

s32 CountMapObjectsBeforePooledTail(MapObjectList *list) {
    s32 count = list->mMapObjectCount;

    while (count > 1 && *(u16 *) list->mMapObjects[count - 1] == MAP_OBJECT_KIND_POOLED_ITEM_BOX) {
        count--;
    }
    return count;
}
