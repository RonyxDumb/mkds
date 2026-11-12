#include "Main/Menu/keyboard_scene.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/System/heap.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Graphics/oam_lists.h"

#include "Main/Unknown/code_021288a4.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Menu/keyboard_buttons.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02128940.h"
#include "Main/Unknown/code_02128958.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_0212a000.h"

#pragma thumb on
void InitKeyboardScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    gKeyboardScene = HeapAlloc(heap, 0x808);
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
