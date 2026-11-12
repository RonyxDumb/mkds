#include "Main/Menu/record_scene.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/System/heap.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/oam_lists.h"

#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111368.h"
#include "Main/Unknown/code_021113ac.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021115b0.h"

#pragma thumb on

void InitRecordScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    gRecordMainOam = HeapAlloc(heap, 0x404);
    gRecordSubOam = HeapAlloc(heap, 0x404);
    InitRecordSceneObject(heap, *sceneNumbers);
}

#pragma thumb off

#pragma thumb on
void ReleaseRecordScene(void) {
    ReleaseRecordSceneObject();
    gRecordMainOam = NULL;
    gRecordSubOam = NULL;
}
#pragma thumb off

#pragma thumb on
void WriteRecordSceneRegistersCallback(void) {
    WriteRecordSceneRegisters();
    UploadOamLists(gRecordMainOam, gRecordSubOam);
}
#pragma thumb off

#pragma thumb on

void UpdateRecordScene(SceneNumbers *sceneNumbers) {
    ClearOamListCounts(gRecordMainOam, gRecordSubOam);
    AdvanceRecordScene();
    HideUnusedOams(gRecordMainOam, gRecordSubOam);
    if (sceneNumbers != NULL && GetRecordNextScene() != -1) {
        sceneNumbers->mNextScene = GetRecordNextScene();
    }
}

void *GetRecordMainOam(void) {
    return gRecordMainOam;
}

void *GetRecordSubOam(void) {
    return gRecordSubOam;
}

#pragma thumb off
