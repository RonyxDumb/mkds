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
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

SceneCallbacks gLogoSceneCallbacks = {InitLogoSceneCallback,
                                      UpdateLogoSceneCallback,
                                      ApplySavedSoundModeCallback,
                                      WriteLogoSceneRegistersCallback,
                                      NULL,
                                      NULL,
                                      0x1e,
                                      1,
                                      0};

void RunQueuedThreadFunctions(void *threadArgument) {
    for (;;) {
        if (gThreadFunctionQueue->mRunRequested != 0) {
            void (*queuedFunction)(void) = DequeueThreadFunction(gThreadFunctionQueue);
            if (queuedFunction == NULL) {
                gThreadFunctionQueue->mRunRequested = 0;
            } else {
                queuedFunction();
            }
        }
        OS_Sleep(2);
    }
}

u32 QueueThreadFunction(void (*function)(void)) {
    s32 checkedCount;
    s32 searchIndex;
    ThreadFunctionQueue *queue = gThreadFunctionQueue;
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

void WaitThreadFunctionsDone(void) {
    while (gThreadFunctionQueue->mRunRequested != 0) {
        OS_WaitIrq(1, 1);
    }
}

void InitLogoSceneCallback(void) {
    InitLogoScene(GetHeap(GetCurrentHeapCall()));
}

void ApplySavedSoundModeCallback(void) {
    ApplySavedSoundMode();
}

void WriteLogoSceneRegistersCallback(void) {
    WriteLogoSceneRegisters();
}

void UpdateLogoSceneCallback(void *sceneNumbers) {
    UpdateLogoScene(sceneNumbers);
}

s32 RunLogoScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gLogoSceneCallbacks;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}
