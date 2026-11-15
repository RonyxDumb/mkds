#include "Main/Menu/keyboard_scene.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/System/heap.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Graphics/oam_lists.h"

#include "Main/Menu/keyboard_buttons.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/heap_call.h"

KeyboardScene *gKeyboardScene;

#pragma thumb on
void InitKeyboardScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    gKeyboardScene = HeapAlloc(heap, sizeof(*gKeyboardScene));
    InitKeyboard(heap, sceneNumbers[0]);
}
#pragma thumb off

#pragma thumb on
void ReleaseKeyboardScene(void) {
    ReleaseKeyboard();
    gKeyboardScene = NULL;
}
#pragma thumb off

SceneCallbacks gKeyboardSceneCallbacks = {
    InitKeyboardScene, UpdateKeyboardScene, ReleaseKeyboardScene, WriteKeyboardSceneRegistersCallback, 0, 0, 10, 10, 0};

#pragma thumb on
void WriteKeyboardSceneRegistersCallback(void) {
    WriteKeyboardRegisters();
    UploadOamLists(gKeyboardScene, &gKeyboardScene->mSubOam);
}

void UpdateKeyboardScene(s16 *sceneNumbers) {
    ClearOamListCounts(gKeyboardScene, &gKeyboardScene->mSubOam);
    AdvanceKeyboard();
    HideUnusedOams(gKeyboardScene, &gKeyboardScene->mSubOam);
    if (sceneNumbers != NULL) {
        if (GetKeyboardNextScene() != -1) {
            sceneNumbers[2] = GetKeyboardNextScene();
        }
    }
}

s32 RunKeyboardScene(void *sceneNumbers) {
    SceneCallbacks callbacks = gKeyboardSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}
#pragma thumb off

#pragma thumb on

RaceHudOamBuffer *GetKeyboardFirstBuffer(void) {
    return &gKeyboardScene->mMainOam;
}

RaceHudOamBuffer *GetKeyboardSecondBuffer(void) {
    return &gKeyboardScene->mSubOam;
}

#pragma thumb off
