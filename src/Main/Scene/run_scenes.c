#include "Main/Scene/run_scenes.h"
#include "Main/System/heap.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/heap_call.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Net/wifi_session.h"
#include "Main/Course/code_02042064.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/System/startup.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Sound/sound_handle_pool.h"
#include "03/code_021c2000.h"
#include "03/System/application.h"
#include "00/code_021a3000.h"
#include "00/Lib/DWC/dwc_connectinet.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "code_02004dc0.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "gx.h"
#include "code_021458c4.h"
#include "data_00000000.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "registers.h"
#include "Main/Menu/title_scene.h"
#include "Main/Scene/menu_scene.h"
#include "Main/System/key_recording.h"
#include "Main/Scene/wl_menu_scene_callback.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/Menu/keyboard_scene.h"
#include "01/Scene/test_scene.h"
#include "01/Menu/option_nickname_scenes.h"
#include "00/Scene/wi_fi_menu_scene.h"
#include "Main/Menu/menu_shared_clear.h"

const u8 gDWCUtilityLanguageTable[6] = {0, 1, 2, 3, 4, 5};
const u32 gSceneFuncs[16] = {
    (u32) RunTitleScene,
    (u32) RunMenuScene,
    (u32) RunRaceScene,
    (u32) RunEmblemScene,
    (u32) RunSecondMenuScene,
    (u32) RunTestScene,
    (u32) RunWLMenuScene,
    (u32) RunOptionScene,
    (u32) RunRecordScene,
    (u32) RunLogoScene,
    (u32) RunResultScene,
    (u32) RunNicknameScene,
    (u32) RunWiFiMenuScene,
    (u32) RunGhostScene,
    (u32) RunKeyboardScene,
    (u32) RunEndingScene,
};
s16 gSceneNumbers[3] = {-1, -1, -1};
RunScenesState *gRunScenesState;
ShapeMapObjectCountList *gShapeMapObjectCountList;

// Scene functions in scene-number order.

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
    gRunScenesState = HeapAlloc(heap, sizeof(*gRunScenesState));
    gRunScenesState->mKind = RUN_SCENES_KIND_CONNECTION;
    gRunScenesState->mNextKind = RUN_SCENES_KIND_NONE;
    gRunScenesState->mSndHeapsBuffer = NULL;
}

void InitRunScenesKind(void) {
    void *heap;
    s32 sndHeapsKind;
    heap = GetHeap(GetCurrentHeapCall());
    switch (gRunScenesState->mKind) {
        case RUN_SCENES_KIND_CONNECTION:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                sndHeapsKind = 2;
            } else {
                sndHeapsKind = 0;
                StartLoadOverlay(OVERLAY_SLOT_OV001);
                FinishOverlayLoad();
            }
            InitConnectionBuffers(heap);
            break;
        case RUN_SCENES_KIND_WIFI_SESSION:
            sndHeapsKind = 1;
            StartLoadOverlay(OVERLAY_SLOT_OV000);
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
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    RunScenesSoundNop();
    expHeapFromMaxFree = CreateExpHeapFromMaxFree(heap);
    utilityWork = HeapAllocAligned(expHeapFromMaxFree, 0x40000, HEAP_ALIGN_CACHE_LINE);
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
    if (gRunScenesState->mNextKind == RUN_SCENES_KIND_NONE || gRunScenesState->mNextKind == gRunScenesState->mKind) {
        return TRUE;
    }
    return FALSE;
}

s32 RunScenes(s16 *sceneNumber) {
    HeapCall heapCall;
    void *heap;
    InitRunScenesKind();
    while (IsRunScenesNextKindSameOrKindThree()) {
        gRunScenesState->mNextKind = RUN_SCENES_KIND_NONE;
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
            case CONNECTION_KIND_NONE:
            case CONNECTION_KIND_MEMBER_SELECT:
            case CONNECTION_KIND_WL_MENU:
                gRunScenesState->mNextKind = RUN_SCENES_KIND_CONNECTION;
                break;
            case CONNECTION_KIND_WIFI_MENU:
                gRunScenesState->mNextKind = RUN_SCENES_KIND_WIFI_SESSION;
                break;
            case CONNECTION_KIND_WIFI_TOP_MENU:
                RunDWCUtility();
                gStartupWork->mConnectionKind = CONNECTION_KIND_WIFI_MENU;
                break;
        }
    }
    heap = GetHeap(GetCurrentHeapCall());
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    switch (gRunScenesState->mKind) {
        case RUN_SCENES_KIND_CONNECTION:
            FinishConnectionEnd();
            break;
        case RUN_SCENES_KIND_WIFI_SESSION:
            DeleteWiFiSessionHeap();
            break;
    }
    return 0;
}

void RunScenesForever(void) {
    HeapCall heapCall;
    gRunScenesState->mSceneNumber = 9;
    gRunScenesState->mKind = RUN_SCENES_KIND_CONNECTION;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        gStartupWork->mConnectionKind = CONNECTION_KIND_WL_MENU;
        gMenuShared->mWLMenuKind = 0;
        gRunScenesState->mSceneNumber = 6;
    }
    do {
        gRunScenesState->mNextKind = RUN_SCENES_KIND_NONE;
        InitHeapCall(&heapCall, (u32) RunScenes);
        RunHeapCall(&heapCall, (u32) &gRunScenesState->mSceneNumber);
        gRunScenesState->mKind = gRunScenesState->mNextKind;
    } while (1);
}
