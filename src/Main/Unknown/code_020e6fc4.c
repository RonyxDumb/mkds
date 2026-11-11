#include "Main/Unknown/code_020e6fc4.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

#pragma thumb on
void ClearMapObjectListCount(MapObjectList *mapObjectList) {
    mapObjectList->mMapObjectCount = 0;
}

void AddToMapObjectListCount(MapObjectList *mapObjectList, s32 addedCount) {
    mapObjectList->mMapObjectCount = mapObjectList->mMapObjectCount + addedCount;
}
#pragma thumb off
