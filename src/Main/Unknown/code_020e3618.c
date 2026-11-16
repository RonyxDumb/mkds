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
    ((Unk020e1dc0 *) *(void **) bridge_sRenderPart)->mUnk_2c = anim_getAnimLength(bridge_sNsbcaAnim);
    model_setPolyIdLightFlagsEmi(bridge_sModel, 0x3f, 2, 0x294a);
    dcol_setModel(*(void **) bridge_sRenderPart, bridge_sModel);
}

void bridge_init(Bridge *bridge, struct CourseMapRow *courseRow) {
    bridge->mUnk_0e8 = bridge->mUnk_000.mPos;
    bridge->mUnk_0a0 = *(Unk020e38a0_28 *) &bridge->mUnk_000.mMatrix;
    bridge->mUnk_0c4 = *(Unk020e38a0_28 *) &bridge->mUnk_000.mMatrix;
    bridge->mUnk_124.x = 0;
    bridge->mUnk_124.y = 0;
    bridge->mUnk_124.z = 0;
    bridge->mUnk_130 = 1;
    bridge->mUnk_144 = ((courseRow->mUnk_28 * 0x10000) / 0x168) >> 1;
    bridge->mUnk_146 = (0x10000 / courseRow->mUnk_2a) >> 1;
    bridge->mUnk_14c = courseRow->mUnk_2c;
    bridge->mUnk_14e = courseRow->mUnk_2e;
    bridge->mUnk_150 = 0;
    bridge->mUnk_148 = 0;
    if (gRaceMultiConfig->mMode == 5) {
        bridge->mUnk_146 = 0;
        bridge->mUnk_148 = ((courseRow->mUnk_30 * 0x10000) / 0x168) >> 1;
    }
    bridge->mUnk_100 = ((s64) bridge->mUnk_000.mScale.x * 0x5a000) >> 12;
    bridge->mUnk_104 = (s32) (((s64) bridge->mUnk_000.mScale.y * 0x1e000) >> 12) >> 1;
    bridge->mUnk_108 = ((s64) bridge->mUnk_000.mScale.z * 0x15e000) >> 12;
    bridge->mUnk_10c = ((s64) bridge->mUnk_000.mScale.z * 0x32000) >> 12;
    bridge->mUnk_110 = 0;
    bridge->mUnk_114.x = 1;
    bridge->mUnk_114.y = 0;
    bridge->mUnk_114.z = 1;
    bridge->mUnk_120 = 0x800;
    bridge->mUnk_134 = 0;
    bridge->mUnk_138 = 0;
    bridge->mUnk_000.mFlags |= data_02158c88;
    bridge->mUnk_000.mFlags &= ~2;
    bridge->mUnk_000.mFlags &= ~8;
    bridge->mUnk_000.mAlpha = 0x1f;
    if (courseRow->mUnk_0c.y < 0) {
        mobj_initSoundEmitterForObjectSfxParam4(&bridge->mUnk_000);
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

    switch (choropu->mUnk_000.mStateMachine.mState) {
        case 4:
            gChoropu->mFrameIndex = 1;
            matrix = bbm_getBillboardAtPos(&choropu->mUnk_000.mPos);
            bbm_renderTransformedScaled(gChoropu, matrix, &choropu->mUnk_000.mScale, 0, alpha);
            break;
        case 5:
            break;
        case 6:
        case 7:
            gChoropu->mFrameIndex = 1;
            matrix = bbm_getBillboardAtPos(&choropu->mUnk_000.mPos);
            bbm_renderTransformedRotatedScaled(gChoropu, matrix, choropu->mUnk_0b4.mUnk_04, &choropu->mUnk_000.mScale, 0, alpha);
            break;
        default:
            gChoropu->mFrameIndex = 0;
            matrix = bbm_getBillboardAtPos(&choropu->mUnk_000.mPos);
            bbm_renderTransformedScaled(gChoropu, matrix, &choropu->mUnk_000.mScale, 0, alpha);
    }
}
