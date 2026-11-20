#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/attractor.h"

#pragma thumb on
u32 InitMapObjectUpdateList(MapObjectList *list) {
    u32 valueA = (u32) list;
    u32 valueB;
    u32 listPointer;
    listPointer = (valueA) + (0u);
    valueA = (u32) GetCurrentHeapCall();
    valueA = (u32) GetHeap((void *) valueA);
    valueB = *(const u16 *) ((listPointer) + 4u);
    valueB = (valueB << 2);
    valueA = (u32) HeapAlloc((void *) valueA, valueB);
    *(u32 *) ((listPointer) + 0u) = valueA;
    valueB = 0u;
    *(u16 *) ((listPointer) + 4u) = valueB;
    valueA = MAP_OBJECT_LIST_ITEM_FIRST_RESPONSE_UNSET;
    *(u32 *) ((listPointer) + 24u) = valueA;
    *(u32 *) ((listPointer) + 28u) = valueB;
    *(u32 *) ((listPointer) + 32u) = valueA;
    return valueA;
}

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
    if (mapObjectList->mItemFirstResponse == MAP_OBJECT_LIST_ITEM_FIRST_RESPONSE_UNSET) {
        mapObjectList->mItemFirstResponse = GetItemObjectFirstResponse(6, mapObject);
    }
}

void SetUpdateListSlot(void *listSlot) {
    (*(MapObjectList **) listSlot)->mDrawOrder = listSlot;
}

#pragma thumb off
