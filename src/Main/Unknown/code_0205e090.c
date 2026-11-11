#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/unk_02165000.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/unk_0217a000.h"

void ClearShapeMapObjectCountListPointer(void) {
    gShapeMapObjectCountList = NULL;
}

s32 UpdateShapeMapObjectCounts(void) {
    BOOL result = FALSE;
    u16 shapeIndex = 0;
    ShapeMapObjectCount *entry;
    CourseMapShape *courseMapShape;
    s32 mapObjectCount;
    u16 mapObjectIndex;
    u8 insideCount;
    for (shapeIndex = 0; shapeIndex < gShapeMapObjectCountList->mEntryCount; shapeIndex++) {
        entry = &gShapeMapObjectCountList->mEntries[shapeIndex];
        courseMapShape = GetCourseMapShape(entry->mShapeIndex);
        mapObjectCount =
            FindMapObjectsOfKindInRadius(&courseMapShape->mPos, entry->mRadius, courseMapShape->mKindValue);
        insideCount = 0;
        for (mapObjectIndex = 0; mapObjectIndex < mapObjectCount; mapObjectIndex++) {
            if (IsPosInCourseMapShape(&GetFoundMapObject(mapObjectIndex)->mPos, courseMapShape) != 0) {
                insideCount = insideCount + 1;
            }
        }
        if (entry->mMapObjectCount < insideCount) {
            entry->mIncreaseCount++;
        }
        entry->mMapObjectCount = insideCount;
        if (entry->mIncreaseCount > courseMapShape->mIncreaseCountLimit) {
            result = TRUE;
            break;
        }
    }
    return result;
}

void CreateRunScenesState(void *heap) {
    gRunScenesState = HeapAlloc(heap, 0x10);
    gRunScenesState->mKind = 0;
    gRunScenesState->mNextKind = 3;
    gRunScenesState->mSndHeapsBuffer = NULL;
}

void InitRunScenesKind(void) {
    void *heap;
    s32 sndHeapsKind;
    heap = GetHeap(GetCurrentHeapCall());
    switch (gRunScenesState->mKind) {
        case 0:
            if (gBootInfo->mUnk_00 == 2) {
                sndHeapsKind = 2;
            } else {
                sndHeapsKind = 0;
                StartLoadOverlay(1);
                FinishOverlayLoad();
            }
            InitConnectionBuffers(heap);
            break;
        case 1:
            sndHeapsKind = 1;
            StartLoadOverlay(0);
            FinishOverlayLoad();
            CreateWiFiSessionHeap(heap);
            break;
    }
    if (sndHeapsKind == 2) {
        return;
    }
    heap = HeapAlloc(heap, GetSndHeapsBufferSize(sndHeapsKind));
    CreateSndHeaps(sndHeapsKind, (u32) heap);
    gRunScenesState->mSndHeapsBuffer = heap;
}

int GetCurrentSceneNumber(void) {
    return gSceneNumbers[1];
}

u32 GetNextSceneNumber(void) {
    return gSceneNumbers[2];
}
