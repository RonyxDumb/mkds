#include "Main/Unknown/code_021000d0.h"

#include "Main/Unknown/code_020d2b78.h"

MapObjectList *FindMapObjectKindUpdateList(u32 a) {
    s32 n = GetMapObjectKindCount();
    s32 i;

    for (i = 0; i < n; i++) {
        if (gMapObjectKindRows[i].mKind == a) {
            return gMapObjectKindRows[i].mDescriptor->mLists[3];
        }
    }
    return NULL;
}

void *FindMapObjectKindDrawList0(u32 a) {
    s32 n = GetMapObjectKindCount();
    s32 i;

    for (i = 0; i < n; i++) {
        if (gMapObjectKindRows[i].mKind == a) {
            return gMapObjectKindRows[i].mDescriptor->mLists[0];
        }
    }
    return NULL;
}
