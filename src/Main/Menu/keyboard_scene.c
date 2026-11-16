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

KeyboardScene *g_KeyboardOam;

#pragma thumb on
void Scene_Keyboard_Initialize_from_thumb(s16 *sceneNumbers) {
    void *heap;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    g_KeyboardOam = Mem_AllocateHeap(heap, sizeof(*g_KeyboardOam));
    InitializeKeyboardContext_from_thumb(heap, sceneNumbers[0]);
}
#pragma thumb off

#pragma thumb on
void Scene_Keyboard_Finalize_from_thumb(void) {
    ReleaseKeyboard();
    g_KeyboardOam = NULL;
}
#pragma thumb off

SceneCallbacks g_Scene_Keyboard = {
    Scene_Keyboard_Initialize_from_thumb, Scene_Keyboard_Update_from_thumb, Scene_Keyboard_Finalize_from_thumb, Scene_Keyboard_VBlank_from_thumb, 0, 0, 10, 10, 0};

#pragma thumb on
void Scene_Keyboard_VBlank_from_thumb(void) {
    WriteKeyboardRegisters();
    CopyOamBuffersToMemory_from_thumb(g_KeyboardOam, &g_KeyboardOam->mSubOam);
}

void Scene_Keyboard_Update_from_thumb(s16 *sceneNumbers) {
    OamBuffer_ResetValues16_from_thumb(g_KeyboardOam, &g_KeyboardOam->mSubOam);
    AdvanceKeyboard();
    OamBuffer_SomeFn2_from_thumb(g_KeyboardOam, &g_KeyboardOam->mSubOam);
    if (sceneNumbers != NULL) {
        if (GetKeyboardContextNextSceneId_from_thumb() != -1) {
            sceneNumbers[2] = GetKeyboardContextNextSceneId_from_thumb();
        }
    }
}

s32 SceneFn_Keyboard_from_thumb(void *sceneNumbers) {
    SceneCallbacks callbacks = g_Scene_Keyboard;
    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}
#pragma thumb off

#pragma thumb on

RaceHudOamBuffer *GetKeyboardOam_from_thumb(void) {
    return &g_KeyboardOam->mMainOam;
}

RaceHudOamBuffer *GetKeyboardSecondBuffer(void) {
    return &g_KeyboardOam->mSubOam;
}

#pragma thumb off
