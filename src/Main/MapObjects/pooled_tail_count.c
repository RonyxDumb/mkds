#include "Main/MapObjects/pooled_tail_count.h"
#include "Main/MapObjects/attractor.h"

s32 CountMapObjectsBeforePooledTail(MapObjectList *list) {
    s32 count = list->mMapObjectCount;

    while (count > 1 && *(u16 *) list->mMapObjects[count - 1] == 0x6f) {
        count--;
    }
    return count;
}
