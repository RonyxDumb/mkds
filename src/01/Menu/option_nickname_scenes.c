#include "01/Menu/option_nickname_scenes.h"
#include "01/unk_021ca000.h"
#include "01/Menu/option_states.h"
#include "01/Menu/nickname_scene.h"
#include "01/Menu/ending_scene_callbacks.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "01/code_02192000.h"
#include "01/code_02198000.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/Menu/ending_scene.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"

u8 *gNicknameBuffers;
u8 *gOptionBuffers;

static SceneCallbacks gOptionSceneCallbacks = {
    InitOptionScene, UpdateOptionScene, ReleaseOptionScene, WriteOptionSceneRegisters, 0, 0, 10, 10, 0};
static SceneCallbacks gEndingSceneCallbacks = {
    InitEndingScene, UpdateEndingScene, ReleaseEndingScene, WriteEndingSceneRegistersWrapper, 0, 0, 30, 1, 0};

int RunEndingScene(void *sceneNumbers) {
    SceneCallbacks local = gEndingSceneCallbacks;

    RunScene(sceneNumbers, &local);
    return 0;
}

void InitOptionScene(s16 *sceneNumbers) {
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    gOptionBuffers = HeapAlloc(heap, 0x808);
    InitOptionStates((heap), *sceneNumbers);
}

void ReleaseOptionScene(void) {
    ReleaseOptionStates();
    gOptionBuffers = NULL;
}

void WriteOptionSceneRegisters(void) {
    WriteOptionStatesRegisters();
    UploadOamLists(gOptionBuffers, gOptionBuffers + 0x404);
}

void UpdateOptionScene(s16 *sceneNumbers) {
    ClearOamListCounts(gOptionBuffers, gOptionBuffers + 0x404);
    AdvanceOptionStates();
    HideUnusedOams(gOptionBuffers, gOptionBuffers + 0x404);
    if (sceneNumbers != NULL && GetOptionNextScene() != -1) {
        sceneNumbers[2] = GetOptionNextScene();
    }
}

int RunOptionScene(void *sceneNumbers) {
    SceneCallbacks local = gOptionSceneCallbacks;

    RunScene(sceneNumbers, &local);
    return 0;
}

u8 *GetOptionFirstBuffer(void) {
    return gOptionBuffers;
}

u8 *GetOptionSecondBuffer(void) {
    return gOptionBuffers + 0x404;
}

void InitNicknameScene(s16 *sceneNumbers) {
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    gNicknameBuffers = HeapAlloc(heap, 0x808);
    InitNicknameSceneObject(heap, *sceneNumbers);
}

void ReleaseNicknameScene(void) {
    ReleaseNicknameSceneObject();
    gNicknameBuffers = NULL;
}

void WriteNicknameSceneRegisters(void) {
    u8 *nicknameBuffers;

    NicknameWriteSceneTextRegistersWrapper();
    nicknameBuffers = gNicknameBuffers;
    UploadOamLists(nicknameBuffers, nicknameBuffers + 0x404);
}

void UpdateNicknameScene(s16 *sceneNumbers) {
    ClearOamListCounts(gNicknameBuffers, gNicknameBuffers + 0x404);
    AdvanceNicknameScene();
    HideUnusedOams(gNicknameBuffers, gNicknameBuffers + 0x404);
    if (sceneNumbers != NULL && GetNicknameSceneNextScene() != -1) {
        sceneNumbers[2] = GetNicknameSceneNextScene();
    }
}

int RunNicknameScene(void *sceneNumbers) {
    SceneCallbacks callbacks = {
        InitNicknameScene, UpdateNicknameScene, ReleaseNicknameScene, WriteNicknameSceneRegisters, 0, 0, 10, 10, 0,
    };

    RunScene(sceneNumbers, &callbacks);
    return 0;
}
