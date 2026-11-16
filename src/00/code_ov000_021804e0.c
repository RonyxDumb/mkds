#include "00/code_ov000_021804e0.h"

#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02077bc0.h"

u8 *data_ov000_021b4c60;

void InitWiFiMenuScene(s16 *a) {
    void *b;
    b = proc_getHeap(proc_getCurrent());
    data_ov000_021b4c60 = heap_alloc(b, 0x808);
    InitWiFiStates(b, *a);
}

void ReleaseWiFiMenuScene(void) {
    ReleaseWiFiStates();
    data_ov000_021b4c60 = NULL;
}

void func_ov000_0218058c(void) {
    AdvanceKartModelMenuLoad();
    func_ov000_02180704();
    oam_applyBuffers(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
}

void UpdateWiFiMenuScene(SceneNumbers *a) {
    oam_resetBuffers(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
    AdvanceWiFiStates();
    oam_prepareBuffers(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
    if (a != NULL) {
        if (GetWiFiNextScene() != -1) {
            if (GetWiFiNextScene() == 0) {
                gSystemData->mUnk_20 = 0;
            }
            a->mNextScene = GetWiFiNextScene();
        }
    }
}

s32 RunWiFiMenuScene(SceneNumbers *a) {
    SceneCallbacks b = {
        InitWiFiMenuScene, UpdateWiFiMenuScene, ReleaseWiFiMenuScene, func_ov000_0218058c, 0, 0, 10, 10, 0};
    scene_runScene(a, &b);
    return 0;
}

void *func_ov000_021804f4(void) {
    return data_ov000_021b4c60;
}

void *test_run(void) {
    return data_ov000_021b4c60 + 0x404;
}
