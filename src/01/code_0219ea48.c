#include "01/code_0219ea48.h"
#include "01/code_0219e0a8.h"

#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02105000.h"
#include "01/code_0219f8ec.h"
#include "01/unk_021ca000.h"

void *gEndingSceneUnusedBlock;

void InitEndingScene(void) {
    void *heap = GetHeap(GetCurrentHeapCall());

    gEndingSceneUnusedBlock = HeapAlloc(heap, 4);
    CreateEndingScene(heap);
}

void ReleaseEndingScene(void) {
    ClearEndingScenePointer();
    *(u32 *) &gEndingSceneUnusedBlock = 0;
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
