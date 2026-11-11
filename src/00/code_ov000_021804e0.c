#include "00/code_ov000_021804e0.h"

#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02077bc0.h"

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
