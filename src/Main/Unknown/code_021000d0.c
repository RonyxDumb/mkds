#include "Main/Unknown/code_021000d0.h"

#include "Main/Unknown/code_020d2b78.h"

void *mobj_getLogicPartForObjectId(u32 a) {
    s32 n = mobj_getAvailableObjectCount();
    s32 i;

    for (i = 0; i < n; i++) {
        if (gMapObjTable[i].mKind == a) {
            return gMapObjTable[i].mUnk_04->mLists[3];
        }
    }
    return NULL;
}

void *mobj_getRenderPart0ForObjectId(u32 a) {
    s32 n = mobj_getAvailableObjectCount();
    s32 i;

    for (i = 0; i < n; i++) {
        if (gMapObjTable[i].mKind == a) {
            return gMapObjTable[i].mUnk_04->mLists[0];
        }
    }
    return NULL;
}
