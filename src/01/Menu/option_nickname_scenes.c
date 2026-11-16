#include "01/Menu/option_nickname_scenes.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "01/Menu/option_states.h"
#include "01/Menu/nickname_scene.h"
#include "01/Menu/ending_scene_callbacks.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/System/heap_call.h"
#include "01/Menu/ending_scene.h"
#include "01/MapObjects/mission_run_map_object_flags.h"

OamEntryList *gNicknameBuffers;
OamEntryList *gOptionBuffers;

static SceneCallbacks gOptionSceneCallbacks = {
    InitOptionScene, UpdateOptionScene, ReleaseOptionScene, WriteOptionSceneRegisters, 0, 0, 10, 10, 0};
static SceneCallbacks gEndingSceneCallbacks = {
    InitEndingScene, UpdateEndingScene, ReleaseEndingScene, WriteEndingSceneRegistersWrapper, 0, 0, 30, 1, 0};

int RunEndingScene(void *sceneNumbers) {
    SceneCallbacks local = gEndingSceneCallbacks;

    OnSceneLoop(sceneNumbers, &local);
    return 0;
}

void InitOptionScene(s16 *sceneNumbers) {
    void *heap;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    gOptionBuffers = Mem_AllocateHeap(heap, 2 * sizeof(OamEntryList));
    InitOptionStates((heap), *sceneNumbers);
}

void ReleaseOptionScene(void) {
    ReleaseOptionStates();
    gOptionBuffers = NULL;
}

void WriteOptionSceneRegisters(void) {
    WriteOptionStatesRegisters();
    CopyOamBuffersToMemory_from_thumb(gOptionBuffers, gOptionBuffers + 1);
}

void UpdateOptionScene(s16 *sceneNumbers) {
    OamBuffer_ResetValues16_from_thumb(gOptionBuffers, gOptionBuffers + 1);
    AdvanceOptionStates();
    OamBuffer_SomeFn2_from_thumb(gOptionBuffers, gOptionBuffers + 1);
    if (sceneNumbers != NULL && GetOptionNextScene() != -1) {
        sceneNumbers[2] = GetOptionNextScene();
    }
}

int RunOptionScene(void *sceneNumbers) {
    SceneCallbacks local = gOptionSceneCallbacks;

    OnSceneLoop(sceneNumbers, &local);
    return 0;
}

OamEntryList *GetOptionFirstBuffer(void) {
    return gOptionBuffers;
}

OamEntryList *GetOptionSecondBuffer(void) {
    return gOptionBuffers + 1;
}

void InitNicknameScene(s16 *sceneNumbers) {
    void *heap;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    gNicknameBuffers = Mem_AllocateHeap(heap, 2 * sizeof(OamEntryList));
    InitNicknameSceneObject(heap, *sceneNumbers);
}

void ReleaseNicknameScene(void) {
    ReleaseNicknameSceneObject();
    gNicknameBuffers = NULL;
}

void WriteNicknameSceneRegisters(void) {
    OamEntryList *nicknameBuffers;

    NicknameWriteSceneTextRegistersWrapper();
    nicknameBuffers = gNicknameBuffers;
    CopyOamBuffersToMemory_from_thumb(nicknameBuffers, nicknameBuffers + 1);
}

void UpdateNicknameScene(s16 *sceneNumbers) {
    OamBuffer_ResetValues16_from_thumb(gNicknameBuffers, gNicknameBuffers + 1);
    AdvanceNicknameScene();
    OamBuffer_SomeFn2_from_thumb(gNicknameBuffers, gNicknameBuffers + 1);
    if (sceneNumbers != NULL && GetNicknameSceneNextScene() != -1) {
        sceneNumbers[2] = GetNicknameSceneNextScene();
    }
}

int RunNicknameScene(void *sceneNumbers) {
    SceneCallbacks callbacks = {
        InitNicknameScene, UpdateNicknameScene, ReleaseNicknameScene, WriteNicknameSceneRegisters, 0, 0, 10, 10, 0,
    };

    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}
