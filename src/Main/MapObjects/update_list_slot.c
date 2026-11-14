#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/attractor.h"

#pragma thumb on
u32 InitMapObjectUpdateList(MapObjectList *list) {
    u32 value0 = (u32) list;
    u32 value1;
    u32 listPointer;
    listPointer = (value0) + (0u);
    value0 = (u32) GetCurrentHeapCall();
    value0 = (u32) GetHeap((void *) value0);
    value1 = *(const u16 *) ((listPointer) + 4u);
    value1 = (value1 << 2);
    value0 = (u32) HeapAlloc((void *) value0, value1);
    *(u32 *) ((listPointer) + 0u) = value0;
    value1 = 0u;
    *(u16 *) ((listPointer) + 4u) = value1;
    value0 = 3u;
    *(u32 *) ((listPointer) + 24u) = value0;
    *(u32 *) ((listPointer) + 28u) = value1;
    *(u32 *) ((listPointer) + 32u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
// While still unset, also fills the list's words 0x18 to 0x20.
void AddMapObjectToUpdateList(MapObjectList *mapObjectList, MapObject *mapObject) {
    u16 mapObjectIndex;
    MapObjectKindData *kindData;

    mapObjectIndex = mapObjectList->mMapObjectCount;
    mapObjectList->mMapObjectCount = mapObjectIndex + 1;
    mapObjectList->mMapObjects[mapObjectIndex] = mapObject;
    if (mapObjectList->mPassOrPosStepMode == MAP_OBJECT_LIST_POS_STEP_UNSET) {
        kindData = mapObject->mKindData;
        mapObjectList->mPassOrPosStepMode = kindData->mPosStepMode;
    }
    if (mapObjectList->mCollideItemObjectCallback == NULL) {
        kindData = mapObject->mKindData;
        mapObjectList->mCollideItemObjectCallback = kindData->mCollideItemObjectCallback;
    }
    if (mapObjectList->mItemFirstResponse == 3) {
        mapObjectList->mItemFirstResponse = GetItemObjectFirstResponse(6, mapObject);
    }
}
#pragma thumb off

#pragma thumb on

void SetUpdateListSlot(void *listSlot) {
    (*(MapObjectList **) listSlot)->mDrawOrder = listSlot;
}

#pragma thumb off
