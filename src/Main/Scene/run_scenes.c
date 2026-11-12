#include "Main/Scene/run_scenes.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/System/heap.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Net/wifi_session.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/System/startup.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108ec4.h"
#include "03/code_021c2000.h"
#include "03/System/application.h"
#include "00/code_021a3000.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "01/Menu/record_time_attack.h"
#include "code_02004dc0.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "gx.h"
#include "code_021458c4.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "registers.h"

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
            if (gBootInfo->mBootType == 2) {
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

#pragma opt_loop_invariants off

static inline void LoadOverlayAndRunDWCUtility(void *utilityWork, void *overlayId) {
    u8 languageIndex;
    u32 languageValue;
    if (FS_LoadOverlay(0, (u32) overlayId) != 0) {
        OS_SetIrqFunction(1, NULL);
        OS_DisableIrqMask(1);
        reg_OS_IME;
        reg_OS_IME = 0;
        OS_DisableInterrupts();
        GX_VBlankIntr(0);
        DWC_SetAuthServer(2);
        languageValue = 1;
        languageIndex = gStartupWork->mLanguageIndex;
        if (languageIndex < 6) {
            languageValue = gDWCUtilityLanguageTable[languageIndex];
        }
        RunMainLoop(utilityWork, languageValue, 0x20);
        EnableVBlankIrq();
        FS_UnloadOverlay(0, (u32) overlayId);
    }
}

// Runs the DWC utility from overlay 3, then rebuilds the sound heaps.
void RunDWCUtility(void) {
    void *expHeapFromMaxFree;
    void *utilityWork;
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBootInfo->mBootType != 2 && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    RunScenesSoundNop();
    expHeapFromMaxFree = CreateExpHeapFromMaxFree(heap);
    utilityWork = HeapAllocAligned(expHeapFromMaxFree, 0x40000, 0x20);
    LoadOverlayAndRunDWCUtility(utilityWork, SDK_OVERLAY_OV003_ID);
    HeapDestroy(expHeapFromMaxFree);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0x10);
    WaitIrqAndTurnOnDisplays();
    SetCurrentSndArc();
    heap = HeapAlloc(heap, GetSndHeapsBufferSize(1));
    CreateSndHeaps(1, (u32) heap);
    gRunScenesState->mSndHeapsBuffer = heap;
}

static inline BOOL IsRunScenesNextKindSameOrKindThree(void) {
    if (gRunScenesState->mNextKind == 3 || gRunScenesState->mNextKind == gRunScenesState->mKind) {
        return TRUE;
    }
    return FALSE;
}

s32 RunScenes(s16 *sceneNumber) {
    HeapCall heapCall;
    void *heap;
    InitRunScenesKind();
    while (IsRunScenesNextKindSameOrKindThree()) {
        gRunScenesState->mNextKind = 3;
        gSceneNumbers[0] = gSceneNumbers[1];
        gSceneNumbers[1] = *sceneNumber;
        gSceneNumbers[2] = -1;
        InitHeapCall(&heapCall, gSceneFuncs[*sceneNumber]);
        RunHeapCall(&heapCall, (u32) gSceneNumbers);
        if (gSceneNumbers[2] != -1) {
            *sceneNumber = gSceneNumbers[2];
        } else {
            *sceneNumber = 9;
        }
        switch (gStartupWork->mConnectionKind) {
            case 0:
            case 1:
            case 2:
                gRunScenesState->mNextKind = 0;
                break;
            case 3:
                gRunScenesState->mNextKind = 1;
                break;
            case 4:
                RunDWCUtility();
                gStartupWork->mConnectionKind = 3;
                break;
        }
    }
    heap = GetHeap(GetCurrentHeapCall());
    if (gBootInfo->mBootType != 2 && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    switch (gRunScenesState->mKind) {
        case 0:
            FinishConnectionEnd();
            break;
        case 1:
            DeleteWiFiSessionHeap();
            break;
    }
    return 0;
}

void RunScenesForever(void) {
    HeapCall heapCall;
    gRunScenesState->mSceneNumber = 9;
    gRunScenesState->mKind = 0;
    if (gBootInfo->mBootType == 2) {
        gStartupWork->mConnectionKind = 2;
        gMenuShared->mWLMenuKind = 0;
        gRunScenesState->mSceneNumber = 6;
    }
    do {
        gRunScenesState->mNextKind = 3;
        InitHeapCall(&heapCall, (u32) RunScenes);
        RunHeapCall(&heapCall, (u32) &gRunScenesState->mSceneNumber);
        gRunScenesState->mKind = gRunScenesState->mNextKind;
    } while (1);
}
