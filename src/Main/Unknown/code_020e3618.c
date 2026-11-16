#include "Main/Unknown/code_020e3618.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"

#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"

#pragma thumb off

BOOL bridge_isBridge(u32 kind) {
    switch (kind) {
        case MAP_OBJECT_KIND_BRIDGE:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void bridge_loadModel(void) {
    void *file;

    file = mobj_getMapObjFile(aBridge_nsbmd);
    model2_createFromNsbmd(&bridge_sModel, file, NULL);
    CreateModelAnimation(0, bridge_sModel, &bridge_sNsbcaAnim, file, mobj_getMapObjFile(aBridge_nsbca));
    ((Unk020e1dc0 *) *(void **) bridge_sRenderPart)->field2C = anim_getAnimLength(bridge_sNsbcaAnim);
    model_setPolyIdLightFlagsEmi(bridge_sModel, 0x3f, 2, 0x294a);
    dcol_setModel(*(void **) bridge_sRenderPart, bridge_sModel);
}

void bridge_init(Bridge *bridge, struct CourseMapRow *courseRow) {
    bridge->fieldE8 = bridge->field0.mPos;
    bridge->fieldA0 = *(Unk020e38a0_28 *) &bridge->field0.mMatrix;
    bridge->fieldC4 = *(Unk020e38a0_28 *) &bridge->field0.mMatrix;
    bridge->field124.x = 0;
    bridge->field124.y = 0;
    bridge->field124.z = 0;
    bridge->field130 = 1;
    bridge->field144 = ((courseRow->field28 * 0x10000) / 0x168) >> 1;
    bridge->field146 = (0x10000 / courseRow->field2A) >> 1;
    bridge->field14C = courseRow->field2C;
    bridge->field14E = courseRow->field2E;
    bridge->field150 = 0;
    bridge->field148 = 0;
    if (gRaceMultiConfig->mMode == 5) {
        bridge->field146 = 0;
        bridge->field148 = ((courseRow->field30 * 0x10000) / 0x168) >> 1;
    }
    bridge->field100 = ((s64) bridge->field0.mScale.x * 0x5a000) >> 12;
    bridge->field104 = (s32) (((s64) bridge->field0.mScale.y * 0x1e000) >> 12) >> 1;
    bridge->field108 = ((s64) bridge->field0.mScale.z * 0x15e000) >> 12;
    bridge->field10C = ((s64) bridge->field0.mScale.z * 0x32000) >> 12;
    bridge->field110 = 0;
    bridge->field114.x = 1;
    bridge->field114.y = 0;
    bridge->field114.z = 1;
    bridge->field120 = 0x800;
    bridge->field134 = 0;
    bridge->field138 = 0;
    bridge->field0.mFlags |= data_02158c88;
    bridge->field0.mFlags &= ~2;
    bridge->field0.mFlags &= ~8;
    bridge->field0.mAlpha = 0x1f;
    if (courseRow->fieldC.y < 0) {
        mobj_initSoundEmitterForObjectSfxParam4(&bridge->field0);
    }
}

#pragma thumb off

void *choro_setupConfig(void) {
    Unk020e03f8 *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(const Unk020e03f8 *) data_02158c3c;
    return kindData;
}

void *choro_setupMainRenderPart(void) {
    void *drawList;

    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    choro_sMainRenderPart = drawList;
    *(Unk020e039c *) drawList = *(const Unk020e039c *) data_02158c10;
    mobj_renderPartSetThisPointer(&choro_sMainRenderPart);
    return choro_sMainRenderPart;
}

void *choro_setupShadowRenderPart(void) {
    void *drawList;

    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    choro_sShadowRenderPart = drawList;
    *(Unk020e039c *) drawList = *(const Unk020e039c *) data_02158be4;
    mobj_renderPartSetThisPointer(&choro_sShadowRenderPart);
    return choro_sShadowRenderPart;
}

void *choro_setupLogicPart(void) {
    void *updateList;

    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    choro_sLogicPart = updateList;
    *(Unk020e0340 *) updateList = *(const Unk020e0340 *) data_02158bbc;
    mobj_logicPartSetThisPointer(&choro_sLogicPart);
    return choro_sLogicPart;
}

void choro_applyMainMaterial(void) {
    bbm_applyMaterial(gChoropu);
}

void choro_renderMain(s32 a, Unk020e1e98 *choropu, s32 c, u16 alpha) {
    MtxFx43 *matrix;

    switch (choropu->field0.mStateMachine.mState) {
        case 4:
            gChoropu->mFrameIndex = 1;
            matrix = bbm_getBillboardAtPos(&choropu->field0.mPos);
            bbm_renderTransformedScaled(gChoropu, matrix, &choropu->field0.mScale, 0, alpha);
            break;
        case 5:
            break;
        case 6:
        case 7:
            gChoropu->mFrameIndex = 1;
            matrix = bbm_getBillboardAtPos(&choropu->field0.mPos);
            bbm_renderTransformedRotatedScaled(gChoropu, matrix, choropu->fieldB4.field4, &choropu->field0.mScale, 0, alpha);
            break;
        default:
            gChoropu->mFrameIndex = 0;
            matrix = bbm_getBillboardAtPos(&choropu->field0.mPos);
            bbm_renderTransformedScaled(gChoropu, matrix, &choropu->field0.mScale, 0, alpha);
    }
}
