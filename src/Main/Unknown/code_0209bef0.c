#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

#pragma thumb on
void *CreateMapObjectUpdateList(void *init, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 40);
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
    MapObjectList *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 44);
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
    MapObjectList *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 44);
    list->mUnk_18 = 2;
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off
