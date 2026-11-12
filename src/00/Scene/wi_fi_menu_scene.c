#include "00/Scene/wi_fi_menu_scene.h"

#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Kart/karts.h"

u8 *gWiFiMenuOamLists;

void InitWiFiMenuScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    gWiFiMenuOamLists = HeapAlloc(heap, 0x808);
    InitWiFiStates(heap, *sceneNumbers);
}

void ReleaseWiFiMenuScene(void) {
    ReleaseWiFiStates();
    gWiFiMenuOamLists = NULL;
}

void WriteWiFiMenuSceneRegisters(void) {
    AdvanceKartModelMenuLoad();
    WriteWiFiStatesRegisters();
    UploadOamLists(gWiFiMenuOamLists, gWiFiMenuOamLists + 0x404);
}

void UpdateWiFiMenuScene(SceneNumbers *sceneNumbers) {
    ClearOamListCounts(gWiFiMenuOamLists, gWiFiMenuOamLists + 0x404);
    AdvanceWiFiStates();
    HideUnusedOams(gWiFiMenuOamLists, gWiFiMenuOamLists + 0x404);
    if (sceneNumbers != NULL) {
        if (GetWiFiNextScene() != -1) {
            if (GetWiFiNextScene() == 0) {
                gStartupWork->mConnectionKind = 0;
            }
            sceneNumbers->mNextScene = GetWiFiNextScene();
        }
    }
}

s32 RunWiFiMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = {
        InitWiFiMenuScene, UpdateWiFiMenuScene, ReleaseWiFiMenuScene, WriteWiFiMenuSceneRegisters, 0, 0, 10, 10, 0};
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void *GetWiFiMenuMainOamList(void) {
    return gWiFiMenuOamLists;
}

void *GetWiFiMenuSubOamList(void) {
    return gWiFiMenuOamLists + 0x404;
}
