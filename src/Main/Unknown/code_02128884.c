#include "Main/Unknown/code_02128884.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020ae630.h"

#include "Main/Unknown/code_021288a4.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0212898c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02128940.h"
#include "Main/Unknown/code_02128958.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0212a000.h"

#pragma thumb on
void nicknameEditor_onCreate(s16 *sceneNumbers) {
    void *heap;
    heap = proc_getHeap(proc_getCurrent());
    sNicknameOamBuffers = heap_alloc(heap, 0x808);
    nickname_create(heap, sceneNumbers[0]);
}
#pragma thumb off

#pragma thumb on
void nicknameEditor_onDelete(void) {
    u32 address;
    u32 zero;
    nickname_finish();
    zero = 0u;
    address = (u32) &sNicknameOamBuffers;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

SceneCallbacks nicknameEditor_vtable = {
    nicknameEditor_onCreate, nicknameEditor_onDraw, nicknameEditor_onDelete, nicknameEditor_afterDraw, 0, 0, 10, 10, 0};

#pragma thumb on
void nicknameEditor_afterDraw(void) {
    nickname_vblank();
    oam_applyBuffers(sNicknameOamBuffers, &sNicknameOamBuffers->mUnk_404);
}

void nicknameEditor_onDraw(s16 *sceneNumbers) {
    oam_resetBuffers(sNicknameOamBuffers, &sNicknameOamBuffers->mUnk_404);
    nickname_render();
    oam_prepareBuffers(sNicknameOamBuffers, &sNicknameOamBuffers->mUnk_404);
    if (sceneNumbers != NULL) {
        if (nickname_getField72() != -1) {
            sceneNumbers[2] = nickname_getField72();
        }
    }
}

s32 keyboard_run(void *sceneNumbers) {
    SceneCallbacks callbacks = nicknameEditor_vtable;
    scene_runScene(sceneNumbers, &callbacks);
    return 0;
}
#pragma thumb off

#pragma thumb on

OamList *nickname_getMainOamBuf(void) {
    return &sNicknameOamBuffers->mUnk_00;
}

OamList *nickname_getSubOamBuf(void) {
    return &sNicknameOamBuffers->mUnk_404;
}

#pragma thumb off
