#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

// The start of MapObjectList; the three creators below fill in mInit, mForEachObject and mBeforeObjects.
typedef struct Unk0209bef0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void *mInit;
    /* 0c */ void *mBeforeObjects;
    /* 10 */ void *mForEachObject;
    /* 14 */ u32 mAfterObjects;
    /* 18 */ u32 mUnk_18;
} Unk0209bef0;

#pragma thumb on
void *CreateMapObjectUpdateList(void *init, void *forEachObject, void *beforeObjects) {
    Unk0209bef0 *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 40);
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
// The 1 in the name is the value stored at +0x18, not a slot of the kind row.
void *CreateMapObjectDrawList1(void *init, void *forEachObject, void *beforeObjects) {
    Unk0209bef0 *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 44);
    list->mUnk_18 = 1;
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
void *CreateMapObjectDrawList2(void *init, void *forEachObject, void *beforeObjects) {
    Unk0209bef0 *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 44);
    list->mUnk_18 = 2;
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off
