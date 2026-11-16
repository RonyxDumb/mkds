#include "Main/Scene/run_scenes.h"
#include "Main/System/scene_numbers.h"
#include "Main/System/heap.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/heap_call.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Net/wifi_session.h"
#include "Main/Course/course_map_sections.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/System/startup.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Sound/sound_handle_pool.h"
#include "03/System/application.h"
#include "00/Lib/DWC/internet_connection.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "overlay_rom_loader.h"
#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "vram_bank_display_setup.h"
#include "fixed_point_graphics_setup.h"
#include "card_rom_backup_access.h"
#include "overlay_id_symbols.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
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

const u8 g_LangConversionTable[6] = {0, 1, 2, 3, 4, 5};
const u32 g_SceneFnTable[16] = {
    (u32) SceneFn_Title,
    (u32) SceneFn_Menu,
    (u32) SceneFn_Race,
    (u32) SceneFn_Emblem,
    (u32) SceneFn_Menu2,
    (u32) RunTestScene,
    (u32) SceneFn_WLMenu,
    (u32) RunOptionScene,
    (u32) SceneFn_Record,
    (u32) SceneFn_Logo,
    (u32) SceneFn_Result,
    (u32) RunNicknameScene,
    (u32) RunWiFiMenuScene,
    (u32) RunGhostScene,
    (u32) SceneFn_Keyboard_from_thumb,
    (u32) RunEndingScene,
};
s16 g_SceneExecutionContext[3] = {-1, -1, -1};
RunScenesState *g_SceneOverlayConfig;
ShapeMapObjectCountList *g_GlobalAR;

// Scene functions in scene-number order.

void ResetGlobalAR(void) {
    g_GlobalAR = NULL;
}

s32 UpdateShapeMapObjectCounts(void) {
    BOOL result = FALSE;
    u16 shapeIndex = 0;
    ShapeMapObjectCount *entry;
    CourseMapShape *courseMapShape;
    s32 mapObjectCount;
    u16 mapObjectIndex;
    u8 insideCount;
    for (shapeIndex = 0; shapeIndex < g_GlobalAR->mEntryCount; shapeIndex++) {
        entry = &g_GlobalAR->mEntries[shapeIndex];
        courseMapShape = GetGlobalPENkmAREAByIndex_from_thumb(entry->mShapeIndex);
        mapObjectCount =
            GetAreaSomeCount(&courseMapShape->mPos, entry->mRadius, courseMapShape->mKindValue);
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

void InitializeSceneOverlayConfig(void *heap) {
    g_SceneOverlayConfig = Mem_AllocateHeap(heap, sizeof(*g_SceneOverlayConfig));
    g_SceneOverlayConfig->mKind = RUN_SCENES_KIND_CONNECTION;
    g_SceneOverlayConfig->mNextKind = RUN_SCENES_KIND_NONE;
    g_SceneOverlayConfig->mSndHeapsBuffer = NULL;
}

void InitRunScenesKind(void) {
    void *heap;
    s32 sndHeapsKind;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    switch (g_SceneOverlayConfig->mKind) {
        case RUN_SCENES_KIND_CONNECTION:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                sndHeapsKind = 2;
            } else {
                sndHeapsKind = 0;
                UpdateOverlayStatusWithKind(OVERLAY_SLOT_OV001);
                WaitOverlayLoadedStarted();
            }
            InitializeSomeZEPointers(heap);
            break;
        case RUN_SCENES_KIND_WIFI_SESSION:
            sndHeapsKind = 1;
            UpdateOverlayStatusWithKind(OVERLAY_SLOT_OV000);
            WaitOverlayLoadedStarted();
            CreateStructBHeap_from_thumb(heap);
            break;
    }
    if (sndHeapsKind == 2) {
        return;
    }
    heap = Mem_AllocateHeap(heap, ComputeRAudioBufferAllocSize(sndHeapsKind));
    SomeAudioInit(sndHeapsKind, (u32) heap);
    g_SceneOverlayConfig->mSndHeapsBuffer = heap;
}

int GetCurrentSceneId(void) {
    return g_SceneExecutionContext[1];
}

u32 GetNextSceneId(void) {
    return g_SceneExecutionContext[2];
}

#pragma opt_loop_invariants off

static inline void LoadOverlayAndRunDWCUtility(void *utilityWork, void *overlayId) {
    u8 languageIndex;
    u32 languageValue;
    if (Fs_LoadOverlay(0, (u32) overlayId) != 0) {
        Os_SetIrqHandler(1, NULL);
        Os_DisableIrqHandler(1);
        reg_OS_IME;
        reg_OS_IME = 0;
        Os_DisableIrq();
        GX_VBlankIntr(0);
        DWC_SetAuthServer(2);
        languageValue = 1;
        languageIndex = g_GlobalP->mLanguageIndex;
        if (languageIndex < 6) {
            languageValue = g_LangConversionTable[languageIndex];
        }
#ifdef version_EUR
        RunMainLoop(utilityWork, languageValue, 0);
#else
        RunMainLoop(utilityWork, languageValue, 0x20);
#endif
        EnableVblankIRQ();
        Fs_UnloadOverlay(0, (u32) overlayId);
    }
}

// Runs the DWC utility from overlay 3, then rebuilds the sound heaps.
void LoadExecuteOverlay1(void) {
    void *expHeapFromMaxFree;
    void *utilityWork;
    void *heap;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    WaitForWorkerTask();
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT && g_SceneOverlayConfig->mSndHeapsBuffer != NULL) {
        DisposeSomeSoundStuff();
        Mem_FreeHeap(heap, g_SceneOverlayConfig->mSndHeapsBuffer);
        g_SceneOverlayConfig->mSndHeapsBuffer = NULL;
    }
    nullsub_12();
    expHeapFromMaxFree = Mem_CreateChildExpHeap(heap);
    utilityWork = Mem_AllocateHeapAligned(expHeapFromMaxFree, 0x40000, HEAP_ALIGN_CACHE_LINE);
    LoadOverlayAndRunDWCUtility(utilityWork, SDK_OVERLAY_OV003_ID);
    Mem_DestroyHeap(expHeapFromMaxFree);
    SetBrightness(&reg_GX_MASTER_BRIGHT, 0x10);
    SetBrightness(&reg_GXS_DB_MASTER_BRIGHT, 0x10);
    EnableGreenSwap();
    SetGlobalSdatActive();
    heap = Mem_AllocateHeap(heap, ComputeRAudioBufferAllocSize(1));
    SomeAudioInit(1, (u32) heap);
    g_SceneOverlayConfig->mSndHeapsBuffer = heap;
}

static inline BOOL IsRunScenesNextKindSameOrKindThree(void) {
    if (g_SceneOverlayConfig->mNextKind == RUN_SCENES_KIND_NONE || g_SceneOverlayConfig->mNextKind == g_SceneOverlayConfig->mKind) {
        return TRUE;
    }
    return FALSE;
}

s32 SceneLoopExecuteFunction(s16 *sceneNumber) {
    HeapCall heapCall;
    void *heap;
    InitRunScenesKind();
    while (IsRunScenesNextKindSameOrKindThree()) {
        g_SceneOverlayConfig->mNextKind = RUN_SCENES_KIND_NONE;
        g_SceneExecutionContext[0] = g_SceneExecutionContext[1];
        g_SceneExecutionContext[1] = *sceneNumber;
        g_SceneExecutionContext[2] = -1;
        ExecutionContext_Create(&heapCall, g_SceneFnTable[*sceneNumber]);
        ExecutionContext_Execute(&heapCall, (u32) g_SceneExecutionContext);
        if (g_SceneExecutionContext[2] != -1) {
            *sceneNumber = g_SceneExecutionContext[2];
        } else {
            *sceneNumber = 9;
        }
        switch (g_GlobalP->mConnectionKind) {
            case CONNECTION_KIND_NONE:
            case CONNECTION_KIND_MEMBER_SELECT:
            case CONNECTION_KIND_WL_MENU:
                g_SceneOverlayConfig->mNextKind = RUN_SCENES_KIND_CONNECTION;
                break;
            case CONNECTION_KIND_WIFI_MENU:
                g_SceneOverlayConfig->mNextKind = RUN_SCENES_KIND_WIFI_SESSION;
                break;
            case CONNECTION_KIND_WIFI_TOP_MENU:
                LoadExecuteOverlay1();
                g_GlobalP->mConnectionKind = CONNECTION_KIND_WIFI_MENU;
                break;
        }
    }
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT && g_SceneOverlayConfig->mSndHeapsBuffer != NULL) {
        DisposeSomeSoundStuff();
        Mem_FreeHeap(heap, g_SceneOverlayConfig->mSndHeapsBuffer);
        g_SceneOverlayConfig->mSndHeapsBuffer = NULL;
    }
    switch (g_SceneOverlayConfig->mKind) {
        case RUN_SCENES_KIND_CONNECTION:
            FinishConnectionEnd();
            break;
        case RUN_SCENES_KIND_WIFI_SESSION:
            DeleteWiFiSessionHeap();
            break;
    }
    return 0;
}

void RunMain(void) {
    HeapCall heapCall;
    g_SceneOverlayConfig->mSceneNumber = SCENE_LOGO;
    g_SceneOverlayConfig->mKind = RUN_SCENES_KIND_CONNECTION;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        g_GlobalP->mConnectionKind = CONNECTION_KIND_WL_MENU;
        g_GlobalB488->mWLMenuKind = 0;
        g_SceneOverlayConfig->mSceneNumber = SCENE_WL_MENU;
    }
    do {
        g_SceneOverlayConfig->mNextKind = RUN_SCENES_KIND_NONE;
        ExecutionContext_Create(&heapCall, (u32) SceneLoopExecuteFunction);
        ExecutionContext_Execute(&heapCall, (u32) &g_SceneOverlayConfig->mSceneNumber);
        g_SceneOverlayConfig->mKind = g_SceneOverlayConfig->mNextKind;
    } while (1);
}
