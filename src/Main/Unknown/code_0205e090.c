#include "Main/Unknown/code_0205e090.h"
#include "Main/System/Heap.h"
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

u32 area_finalizeMissionRivalPassAreas(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &area_sMissionRivalPassAreaStatus;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

s32 area_updateMissionRivalPassAreas(void) {
    BOOL result = FALSE;
    u16 i = 0;
    ShapeMapObjectCount *entry;
    CourseMapShape *courseMapShape;
    s32 mapObjectCount;
    u16 j;
    u8 insideCount;
    for (i = 0; i < area_sMissionRivalPassAreaStatus->mEntryCount; i++) {
        entry = &area_sMissionRivalPassAreaStatus->mEntries[i];
        courseMapShape = mdat_getAreaEntryByIndex(entry->mShapeIndex);
        mapObjectCount = mobj_queryBySphere(&courseMapShape->mPos, entry->mRadius, courseMapShape->field3C);
        insideCount = 0;
        for (j = 0; j < mapObjectCount; j++) {
            if (mdat_isPointInsideArea(&mobj_getQueryResult(j)->mPos, courseMapShape) != 0) {
                insideCount = insideCount + 1;
            }
        }
        if (entry->mMapObjectCount < insideCount) {
            entry->mIncreaseCount++;
        }
        entry->mMapObjectCount = insideCount;
        if (entry->mIncreaseCount > courseMapShape->field3E) {
            result = TRUE;
            break;
        }
    }
    return result;
}

void scproc_init(void *heap) {
    scproc_sSceneProc = heap_alloc(heap, 0x10);
    scproc_sSceneProc->field0 = 0;
    scproc_sSceneProc->field4 = 3;
    scproc_sSceneProc->mSndHeapsBuffer = NULL;
}

void scproc_overlay_205E0B0(void) {
    void *h;
    s32 m;
    h = proc_getHeap(proc_getCurrent());
    switch (scproc_sSceneProc->field0) {
        case 0:
            if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
                m = 2;
            } else {
                m = 0;
                overlay_beginLoad(1);
                overlay_finishLoad();
            }
            InitConnectionBuffers(h);
            break;
        case 1:
            m = 1;
            overlay_beginLoad(0);
            overlay_finishLoad();
            CreateWiFiSessionHeap(h);
            break;
    }
    if (m == 2) {
        return;
    }
    h = heap_alloc(h, sound_getSomeSize2(m));
    CreateSndHeaps(m, (u32) h);
    scproc_sSceneProc->mSndHeapsBuffer = h;
}

int scproc_getCurrentScene(void) {
    u32 value0;
    value0 = (u32) &scproc_sSceneManager;
    value0 = *(const s16 *) ((value0) + (2));
    return value0;
}

u32 scproc_getNextScene(void) {
    u32 value0;
    value0 = (u32) &scproc_sSceneManager;
    value0 = *(const s16 *) ((value0) + (4));
    return value0;
}
