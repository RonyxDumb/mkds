#include "Main/Unknown/code_0211130c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"

#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111368.h"
#include "Main/Unknown/code_021113ac.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021115b0.h"

#pragma thumb on

void recordsMenu_onCreate(s16 *sceneNumbers) {
    void *heap;
    heap = proc_getHeap(proc_getCurrent());
    gRecordMainOam = heap_alloc(heap, 0x404);
    gRecordSubOam = heap_alloc(heap, 0x404);
    InitRecordSceneObject(heap, *sceneNumbers);
}

#pragma thumb off

#pragma thumb on
void recordsMenu_onDelete(void) {
    u32 address;
    u32 zero;
    ReleaseRecordSceneObject();
    zero = 0u;
    address = (u32) &gRecordMainOam;
    *(u32 *) ((address) + 0u) = zero;
    address = (u32) &gRecordSubOam;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void recordsMenu_afterDraw(void) {
    u32 mainOam;
    u32 subOam;
    WriteRecordSceneRegisters();
    mainOam = (u32) &gRecordMainOam;
    mainOam = *(const u32 *) ((mainOam) + 0u);
    subOam = (u32) &gRecordSubOam;
    subOam = *(const u32 *) ((subOam) + 0u);
    oam_applyBuffers((void *) mainOam, (void *) subOam);
}
#pragma thumb off

#pragma thumb on

void recordsMenu_onDraw(Unk02111324 *sceneNumbers) {
    oam_resetBuffers(gRecordMainOam, gRecordSubOam);
    AdvanceRecordScene();
    oam_prepareBuffers(gRecordMainOam, gRecordSubOam);
    if (sceneNumbers != NULL && GetRecordNextScene() != -1) {
        sceneNumbers->field4 = GetRecordNextScene();
    }
}

void *GetRecordMainOam(void) {
    return gRecordMainOam;
}

void *GetRecordSubOam(void) {
    return gRecordSubOam;
}

#pragma thumb off
