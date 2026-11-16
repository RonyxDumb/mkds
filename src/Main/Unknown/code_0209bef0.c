#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"

// The start of MapObjectList; the three creators below fill in mInit, mForEachObject and mBeforeObjects.
typedef struct Unk0209bef0 {
    /* 00 */ u8 field0[8];
    /* 08 */ void *mInit;
    /* 0c */ void *mBeforeObjects;
    /* 10 */ void *mForEachObject;
    /* 14 */ u32 mAfterObjects;
    /* 18 */ u32 field18;
} Unk0209bef0;

#pragma thumb on
void *mobj_createLogicPart(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = heap_alloc(proc_getHeap(proc_getCurrent()), 40);
    p->mInit = arg0;
    p->mBeforeObjects = arg2;
    p->mForEachObject = arg1;
    p->mAfterObjects = 0;
    return p;
}
#pragma thumb off

#pragma thumb on
// The 1 in the name is the value stored at +0x18, not a slot of the kind row.
void *mobj_createRenderPart3d(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = heap_alloc(proc_getHeap(proc_getCurrent()), 44);
    p->field18 = 1;
    p->mInit = arg0;
    p->mBeforeObjects = arg2;
    p->mForEachObject = arg1;
    p->mAfterObjects = 0;
    return p;
}
#pragma thumb off

#pragma thumb on
void *mobj_createRenderPart2d(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = heap_alloc(proc_getHeap(proc_getCurrent()), 44);
    p->field18 = 2;
    p->mInit = arg0;
    p->mBeforeObjects = arg2;
    p->mForEachObject = arg1;
    p->mAfterObjects = 0;
    return p;
}
#pragma thumb off
