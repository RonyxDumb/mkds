#include "01/Menu/ending_scene_callbacks.h"
#include "01/Menu/ending_scene.h"

#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "01/Menu/mission_run_mission_select.h"
#include "01/Menu/menu_screen_work_structs.h"

void *gEndingSceneUnusedBlock;

void InitEndingScene(void) {
    void *heap = GetHeap(GetCurrentHeapCall());

    gEndingSceneUnusedBlock = HeapAlloc(heap, 4);
    CreateEndingScene(heap);
}

void ReleaseEndingScene(void) {
    ClearEndingScenePointer();
    gEndingSceneUnusedBlock = NULL;
}

void WriteEndingSceneRegistersWrapper(void) {
    WriteEndingSceneRegisters();
}

void UpdateEndingScene(int sceneNumbers) {
    u16 nextSceneValue;
    int nextScene;
    AdvanceEndingScene();
    if ((sceneNumbers != 0) && (nextScene = GetEndingSceneNextScene(), nextScene != -1)) {
        nextSceneValue = GetEndingSceneNextScene();
        *(u16 *) (sceneNumbers + 4) = nextSceneValue;
    }
}
