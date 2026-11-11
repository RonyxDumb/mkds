#include "Main/Unknown/code_021000d0.h"

#include "Main/Unknown/code_020d2b78.h"

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
