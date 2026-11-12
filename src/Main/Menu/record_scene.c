#include "Main/Menu/record_scene.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/System/heap.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Graphics/oam_lists.h"

#include "Main/Menu/record_vs.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/heap_call.h"

void *gRecordSubOam;
void *gRecordMainOam;

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
