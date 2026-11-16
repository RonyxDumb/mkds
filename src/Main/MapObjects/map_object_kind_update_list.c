#include "Main/MapObjects/map_object_kind_update_list.h"

#include "Main/MapObjects/map_object_list.h"

MapObjectList *FindMapObjectKindUpdateList(u32 kind) {
    s32 kindCount = GetMapObjectKindCount();
    s32 rowIndex;

    for (rowIndex = 0; rowIndex < kindCount; rowIndex++) {
        if (gMapObjectKindRows[rowIndex].mKind == kind) {
            return gMapObjectKindRows[rowIndex].mDescriptor->mLists[3];
        }
    }
    return NULL;
}

void *FindMapObjectKindDrawList0(u32 kind) {
    s32 kindCount = GetMapObjectKindCount();
    s32 rowIndex;

    for (rowIndex = 0; rowIndex < kindCount; rowIndex++) {
        if (gMapObjectKindRows[rowIndex].mKind == kind) {
            return gMapObjectKindRows[rowIndex].mDescriptor->mLists[0];
        }
    }
    return NULL;
}
