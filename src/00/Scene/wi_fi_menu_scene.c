#include "00/Scene/wi_fi_menu_scene.h"

#include "00/Menu/wi_fi_states_release.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Kart/karts.h"

OamEntryList *gWiFiMenuOamLists;

void InitWiFiMenuScene(s16 *sceneNumbers) {
    void *heap;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    gWiFiMenuOamLists = Mem_AllocateHeap(heap, 2 * sizeof(OamEntryList));
    InitWiFiStates(heap, *sceneNumbers);
}

void ReleaseWiFiMenuScene(void) {
    ReleaseWiFiStates();
    gWiFiMenuOamLists = NULL;
}

void WriteWiFiMenuSceneRegisters(void) {
    AdvanceKartModelMenuLoad();
    WriteWiFiStatesRegisters();
    CopyOamBuffersToMemory_from_thumb(gWiFiMenuOamLists, gWiFiMenuOamLists + 1);
}

void UpdateWiFiMenuScene(SceneNumbers *sceneNumbers) {
    OamBuffer_ResetValues16_from_thumb(gWiFiMenuOamLists, gWiFiMenuOamLists + 1);
    AdvanceWiFiStates();
    OamBuffer_SomeFn2_from_thumb(gWiFiMenuOamLists, gWiFiMenuOamLists + 1);
    if (sceneNumbers != NULL) {
        if (GetWiFiNextScene() != -1) {
            if (GetWiFiNextScene() == 0) {
                g_GlobalP->mConnectionKind = CONNECTION_KIND_NONE;
            }
            sceneNumbers->mNextScene = GetWiFiNextScene();
        }
    }
}

s32 RunWiFiMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = {
        InitWiFiMenuScene, UpdateWiFiMenuScene, ReleaseWiFiMenuScene, WriteWiFiMenuSceneRegisters, 0, 0, 10, 10, 0};
    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}

void *GetWiFiMenuMainOamList(void) {
    return gWiFiMenuOamLists;
}

void *GetWiFiMenuSubOamList(void) {
    return gWiFiMenuOamLists + 1;
}
