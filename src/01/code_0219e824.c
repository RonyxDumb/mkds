#include "01/code_0219e824.h"
#include "01/unk_021ca000.h"
#include "01/code_02192e78.h"
#include "01/code_0219853c.h"
#include "01/code_0219ea48.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "01/code_02192000.h"
#include "01/code_02198000.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/code_0219e0a8.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"

u8 *gNicknameBuffers;
u8 *gOptionBuffers;

static SceneCallbacks SettingsMenuVtable = {
    settingsMenu_onCreate, settingsMenu_onDraw, settingsMenu_onDelete, settingsMenu_afterDraw, 0, 0, 10, 10, 0};
static SceneCallbacks gEndingSceneCallbacks = {
    ending_init, ending_update, ending_finalize, ending_vblank, 0, 0, 30, 1, 0};

int ending_run(void *a) {
    SceneCallbacks local = gEndingSceneCallbacks;

    scene_runScene(a, &local);
    return 0;
}

void settingsMenu_onCreate(s16 *a) {
    void *heap;

    heap = proc_getHeap(proc_getCurrent());
    gOptionBuffers = heap_alloc(heap, 0x808);
    InitOptionStates((heap), *a);
}

void settingsMenu_onDelete(void) {
    func_ov001_02192f8c();
    gOptionBuffers = NULL;
}

void settingsMenu_afterDraw(void) {
    func_ov001_02192ec4();
    oam_applyBuffers(gOptionBuffers, gOptionBuffers + 0x404);
}

void settingsMenu_onDraw(s16 *a) {
    oam_resetBuffers(gOptionBuffers, gOptionBuffers + 0x404);
    AdvanceOptionStates();
    oam_prepareBuffers(gOptionBuffers, gOptionBuffers + 0x404);
    if (a != NULL && func_ov001_02192e84() != -1) {
        a[2] = func_ov001_02192e84();
    }
}

int option_run(void *a) {
    SceneCallbacks local = SettingsMenuVtable;

    scene_runScene(a, &local);
    return 0;
}

u8 *GetOptionFirstBuffer(void) {
    return gOptionBuffers;
}

u8 *GetOptionSecondBuffer(void) {
    return gOptionBuffers + 0x404;
}

void StartFirstTimeStartNicknameScreen(s16 *a) {
    void *heap;

    heap = proc_getHeap(proc_getCurrent());
    gNicknameBuffers = heap_alloc(heap, 0x808);
    func_ov001_021987d4(heap, *a);
}

void EndFirstTimeStartNicknameScreen(void) {
    func_ov001_021987bc();
    gNicknameBuffers = NULL;
}

void PostRenderFirstTimeStartNicknameScreen(void) {
    u8 *p;

    func_ov001_0219854c();
    p = gNicknameBuffers;
    oam_applyBuffers(p, p + 0x404);
}

void PreRenderFirstTimeStartNicknameScreen(s16 *a) {
    oam_resetBuffers(gNicknameBuffers, gNicknameBuffers + 0x404);
    func_ov001_02198554();
    oam_prepareBuffers(gNicknameBuffers, gNicknameBuffers + 0x404);
    if (a != NULL && func_ov001_0219853c() != -1) {
        a[2] = func_ov001_0219853c();
    }
}

int nickname_run(void *a) {
    SceneCallbacks callbacks = {
        StartFirstTimeStartNicknameScreen, PreRenderFirstTimeStartNicknameScreen, EndFirstTimeStartNicknameScreen, PostRenderFirstTimeStartNicknameScreen, 0, 0, 10, 10, 0,
    };

    scene_runScene(a, &callbacks);
    return 0;
}
