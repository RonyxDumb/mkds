#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020d6000.h"

#pragma thumb on
// While still unset, also fills the list's words 0x18 to 0x20.
void AddMapObjectToUpdateList(MapObjectList *mapObjectList, MapObject *mapObject) {
    u16 mapObjectIndex;
    MapObjectKindData *kindData;

    mapObjectIndex = mapObjectList->mMapObjectCount;
    mapObjectList->mMapObjectCount = mapObjectIndex + 1;
    mapObjectList->mMapObjects[mapObjectIndex] = mapObject;
    if (mapObjectList->mUnk_18 == 3) {
        kindData = mapObject->mKindData;
        mapObjectList->mUnk_18 = kindData->mUnk_20;
    }
    if (mapObjectList->mUnk_1c == NULL) {
        kindData = mapObject->mKindData;
        mapObjectList->mUnk_1c = kindData->mCollideItemObjectCallback;
    }
    if (mapObjectList->mUnk_20 == 3) {
        mapObjectList->mUnk_20 = GetItemObjectFirstResponse(6, mapObject);
    }
}
#pragma thumb off
