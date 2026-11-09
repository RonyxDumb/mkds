#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_02036820.h"
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

BOOL IsBridgeKind(u32 kind) {
    switch (kind) {
        case MAP_OBJECT_KIND_BRIDGE:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void CreateBridge(void) {
    void *file;

    file = FindCourseMapObjFile(gBridgeNsbmdName);
    CreateNsbmd(&gBridge, file, NULL);
    CreateModelAnimation(0, gBridge, &gBridgeNsbca, file, FindCourseMapObjFile(gBridgeNsbcaName));
    data_0217b7c4->mAnimationFrameCount = GetModelAnimationFrameCountFixed(gBridgeNsbca);
    func_02084968(gBridge, 0x3f, 2, 0x294a);
    SetMapObjectsModel(&data_0217b7c4->mMapObjectList, gBridge);
}

void InitBridge(Bridge *bridge, struct CourseMapRow *courseRow) {
    bridge->mUnk_000.mCollisionData.mUnk_e8 = bridge->mUnk_000.mMapObject.mPos;
    bridge->mUnk_000.mCollisionData.mPrevMatrix = bridge->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    bridge->mUnk_000.mCollisionData.mInitialMatrix = bridge->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.x = 0;
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.y = 0;
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.z = 0;
    bridge->mUnk_000.mCollisionData.mUnk_130 = 1;
    bridge->mSwingAmplitude = ((courseRow->mUnk_28 * 0x10000) / 0x168) >> 1;
    bridge->mSwingAnglePerFrame = (0x10000 / courseRow->mUnk_2a) >> 1;
    bridge->mPeakPauseFrameCount = courseRow->mUnk_2c;
    bridge->mTroughPauseFrameCount = courseRow->mUnk_2e;
    bridge->mPauseTimer = 0;
    bridge->mSwingAngle = 0;
    if (gRaceSetup->mMode == 5) {
        bridge->mSwingAnglePerFrame = 0;
        bridge->mSwingAngle = ((courseRow->mUnk_30 * 0x10000) / 0x168) >> 1;
    }
    bridge->mUnk_000.mCollisionData.mUnk_100 = ((s64) bridge->mUnk_000.mMapObject.mScale.x * 0x5a000) >> 12;
    bridge->mUnk_000.mCollisionData.mHalfSizeY = (s32) (((s64) bridge->mUnk_000.mMapObject.mScale.y * 0x1e000) >> 12) >> 1;
    bridge->mUnk_000.mCollisionData.mPositiveHalfSizeZ = ((s64) bridge->mUnk_000.mMapObject.mScale.z * 0x15e000) >> 12;
    bridge->mUnk_000.mCollisionData.mNegativeHalfSizeZ = ((s64) bridge->mUnk_000.mMapObject.mScale.z * 0x32000) >> 12;
    bridge->mUnk_000.mCollisionData.mUnk_110 = 0;
    bridge->mUnk_000.mCollisionData.mUnk_114.x = 1;
    bridge->mUnk_000.mCollisionData.mUnk_114.y = 0;
    bridge->mUnk_000.mCollisionData.mUnk_114.z = 1;
    bridge->mUnk_000.mCollisionData.mUnk_120 = 0x800;
    bridge->mUnk_000.mCollisionData.mUnk_134 = COLLISION_SHAPE_BOX;
    bridge->mUnk_000.mCollisionData.mUnk_138 = 0;
    bridge->mUnk_000.mMapObject.mFlags |= data_02158c88;
    bridge->mUnk_000.mMapObject.mFlags &= ~2;
    bridge->mUnk_000.mMapObject.mFlags &= ~8;
    bridge->mUnk_000.mMapObject.mAlpha = 0x1f;
    if (courseRow->mUnk_0c.y < 0) {
        CreateMapObjectSoundSourceFalloff4(&bridge->mUnk_000.mMapObject);
    }
}

#pragma thumb off

void *CreateChoropuKindData(void) {
    Unk020e03f8 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158c3c;
    return kindData;
}

void *CreateChoropuDrawList(void) {
    Unk020e039c *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b7bc = drawList;
    *drawList = data_02158c10;
    SetDrawListSlot(&data_0217b7bc);
    return data_0217b7bc;
}

void *CreateChoropuShadowDrawList(void) {
    Unk020e039c *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b7c0 = drawList;
    *drawList = data_02158be4;
    SetDrawListSlot(&data_0217b7c0);
    return data_0217b7c0;
}

void *CreateChoropuUpdateList(void) {
    Unk020e0340 *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b7b4 = updateList;
    *updateList = data_02158bbc;
    SetUpdateListSlot(&data_0217b7b4);
    return data_0217b7b4;
}

void SetupDrawChoropu(void) {
    QueueNsbmdModelMaterial(gChoropu);
}

void DrawChoropu(s32 a, Unk020e2f0c *choropu, s32 c, u16 alpha) {
    MtxFx43 *matrix;

    switch (choropu->mUnk_000.mStateMachine.mState) {
        case 4:
            gChoropu->mFrameIndex = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mUnk_000.mPos);
            DrawNsbmdModelWithMatrixAndMaxAlpha(gChoropu, matrix, &choropu->mUnk_000.mScale, 0, alpha);
            break;
        case 5:
            break;
        case 6:
        case 7:
            gChoropu->mFrameIndex = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mUnk_000.mPos);
            DrawNsbmdModelWithMatrixAndAngle(gChoropu, matrix, choropu->mUnk_0b8, &choropu->mUnk_000.mScale, 0, alpha);
            break;
        default:
            gChoropu->mFrameIndex = 0;
            matrix = SetViewTransposeMatrixPos(&choropu->mUnk_000.mPos);
            DrawNsbmdModelWithMatrixAndMaxAlpha(gChoropu, matrix, &choropu->mUnk_000.mScale, 0, alpha);
    }
}
