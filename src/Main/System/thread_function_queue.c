#include "Main/System/thread_function_queue.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Menu/logo_scene.h"
#include "Main/System/thread_function_queue_init.h"
#include "Main/System/heap_call.h"
#include "irq_wait_handler.h"
#include "thread_scheduler.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

SceneCallbacks g_Scene_Logo = {Scene_Logo_Initialize,
                                      Scene_Logo_Update,
                                      Scene_Logo_Finalize,
                                      Scene_Logo_VBlank,
                                      NULL,
                                      NULL,
                                      0x1e,
                                      1,
                                      0};

void WorkerThread_Main(void *threadArgument) {
    for (;;) {
        if (g_WorkerContext->mRunRequested != 0) {
            void (*queuedFunction)(void) = WorkerGetNextTaskFn(g_WorkerContext);
            if (queuedFunction == NULL) {
                g_WorkerContext->mRunRequested = 0;
            } else {
                queuedFunction();
            }
        }
        Os_Sleep(2);
    }
}

u32 WorkerInsertTask(void (*function)(void)) {
    s32 checkedCount;
    s32 searchIndex;
    ThreadFunctionQueue *queue = g_WorkerContext;
    u8 slotIndex;
    void (*slotFunction)(void);
    if (queue->mRunRequested != 0) {
        return 0;
    }
    searchIndex = queue->mNewestIndex;
    checkedCount = 0;
    do {
        slotIndex = searchIndex % 10;
        slotFunction = queue->mFunctions[slotIndex];
        if (slotFunction == NULL) {
            break;
        }
        checkedCount++;
        searchIndex++;
    } while (checkedCount < 10);
    if (slotFunction != NULL) {
        return 0;
    }
    queue->mFunctions[slotIndex] = function;
    queue->mNewestIndex = slotIndex;
    return 1;
}

void WaitForWorkerTask(void) {
    while (g_WorkerContext->mRunRequested != 0) {
        WaitForIRQ(1, 1);
    }
}

void Scene_Logo_Initialize(void) {
    InitializeLogoContext(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
}

void Scene_Logo_Finalize(void) {
    Scene_Logo_FinalizeImpl();
}

void Scene_Logo_VBlank(void) {
    Scene_Logo_VBlankImpl();
}

void Scene_Logo_Update(void *sceneNumbers) {
    Scene_Logo_UpdateImpl(sceneNumbers);
}

s32 SceneFn_Logo(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = g_Scene_Logo;

    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}
