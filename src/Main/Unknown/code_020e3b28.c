#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea000.h"

#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f9c6c.h"

#pragma thumb off

void UpdateRotaryState3(Unk020e3ef4 *object) {
    if (object->mUnk_000.mMapObject.mStateMachine.mStateFrames > object->mPauseFrameCount) {
        object->mUnk_000.mMapObject.mStateMachine.mNextState = 0;
        object->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void DrawAllKind203MapObjects(void *viewMatrix) {
    DrawVisibleMapObjects(gRotaryDrawList, viewMatrix, DrawMapObjectModelAtPos);
}

BOOL IsRotaryKind(s32 kind) {
    switch (kind) {
        case 0xcb:
        case 0xce:
        case 0xd0:
        case 0xd1:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void CreateRotary(BridgeDrawList *list) {
    Unk020e3ef4 *object;
    s32 objectIndex;
    s32 modelIndex;
    s32 objectCount;
    s32 assignIndex;
    s32 assignCount;
    u32 *loadedFlagSlot;
    u32 modelLoaded[5];

    for (modelIndex = 0; modelIndex < 5; modelIndex++) {
        modelLoaded[modelIndex] = 0;
    }
    objectCount = list->mMapObjectList.mMapObjectCount;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = list->mMapObjectList.mMapObjects[objectIndex];
        loadedFlagSlot = &modelLoaded[object->mModelIndex];
        if (modelLoaded[object->mModelIndex] == 0) {
            switch (object->mModelIndex) {
                case 0:
                    CreateNsbmd(&gTestCylinder, FindCourseMapObjFile(gTestCylinderNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gTestCylinder, 0x3f, 2, 0x294a);
                    break;
                case 1:
                    CreateNsbmd(&gGearBlack, FindCourseMapObjFile(gGearBlackNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gGearBlack, 0x3f, 2, 0x294a);
                    break;
                case 2:
                    CreateNsbmd(&gGearWhite, FindCourseMapObjFile(gGearWhiteNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gGearWhite, 0x3f, 2, 0x294a);
                    break;
                case 3:
                    CreateNsbmd(&gRotaryRoom, FindCourseMapObjFile(gRotaryRoomNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gRotaryRoom, 0x3f, 2, 0x294a);
                    break;
                case 4:
                    CreateNsbmd(&gRotaryBridge, FindCourseMapObjFile(gRotaryBridgeNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gRotaryBridge, 0x3f, 2, 0x294a);
                    break;
            }
            *loadedFlagSlot = 1;
        }
    }
    assignCount = list->mMapObjectList.mMapObjectCount;
    for (assignIndex = 0; assignIndex < assignCount; assignIndex++) {
        object = list->mMapObjectList.mMapObjects[assignIndex];
        switch (object->mModelIndex) {
            case 0:
                object->mModel = gTestCylinder;
                break;
            case 1:
                object->mModel = gGearBlack;
                break;
            case 2:
                object->mModel = gGearWhite;
                break;
            case 3:
                object->mModel = gRotaryRoom;
                break;
            case 4:
                object->mModel = gRotaryBridge;
                break;
        }
    }
}

void InitRotaryObjects(BridgeDrawList *list) {
    Unk020e3ef4 *object;
    s32 index;
    s32 previousIndex;
    s32 count;
    u32 zeroFlag;
    u32 zeroHeight;
    Vec3 offset;
    void **objects;
    Unk020e3ef4 *previousObject;

    objects = list->mMapObjectList.mMapObjects;
    previousIndex = -1;
    zeroFlag = 0;
    zeroHeight = 0;
    count = list->mMapObjectList.mMapObjectCount;
    for (index = 0; index < count; index++) {
        object = objects[index];
        if (object->mUnk_000.mMapObject.mKind == 0xcb) {
            if (previousIndex < 0) {
                object->mUnk_000.mCollisionData.mUnk_138 = zeroFlag;
            } else {
                previousObject = objects[previousIndex];
                VEC_Subtract(&previousObject->mUnk_000.mMapObject.mPos, &object->mUnk_000.mMapObject.mPos, &offset);
                offset.y = zeroHeight;
                object->mUnk_154 = VEC_Mag(&offset);
                previousObject = objects[previousIndex];
                object->mUnk_154 -= previousObject->mUnk_000.mMapObject.mExtent.x;
            }
            previousIndex = index;
        }
    }
}

// Rotary: turns up to full speed, keeps that speed, slows down, pauses, then turns the other way; the course row sets
// the timings.
void InitRotary(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    InitStateMachine(&object->mUnk_000.mMapObject.mStateMachine, gRotaryStateTable, 4, object);
    object->mUnk_000.mCollisionData.mUnk_e8 = object->mUnk_000.mMapObject.mPos;
    object->mUnk_000.mCollisionData.mPrevMatrix = object->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    object->mUnk_000.mCollisionData.mInitialMatrix = object->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    object->mUnk_000.mCollisionData.mAngleChangeVector.x = 0;
    object->mUnk_000.mCollisionData.mAngleChangeVector.y = 0;
    object->mUnk_000.mCollisionData.mAngleChangeVector.z = 0;
    object->mUnk_000.mCollisionData.mUnk_130 = kindInfo->mUnk_00 != 0 ? 0 : 1;
    object->mRampFrameCount = courseRow->mUnk_2c;
    object->mSteadyFrameCount = courseRow->mUnk_2a;
    object->mPauseFrameCount = courseRow->mUnk_2e;
    object->mAnglePerFrame = courseRow->mUnk_28 * 0x80 / 100;
    if (courseRow->mUnk_30 != 0) {
        object->mAnglePerFrame = -object->mAnglePerFrame;
    }
    object->mUnk_000.mMapObject.mAngle = 0;
    if (object->mRampFrameCount != 0) {
        object->mSpeedFractionPerFrame = 0x1000 / object->mRampFrameCount;
    } else {
        object->mSpeedFractionPerFrame = 0;
    }
    object->mSpeedFraction = 0;
    object->mUnk_000.mCollisionData.mUnk_100 =
        MUL_FIXED12_NO_ROUND(kindInfo->mUnk_04, object->mUnk_000.mMapObject.mScale.x);
    object->mUnk_000.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(kindInfo->mUnk_08, object->mUnk_000.mMapObject.mScale.y) >> 1;
    if (kindInfo->mUnk_00 != 0) {
        object->mUnk_000.mCollisionData.mUnk_110 = FALSE;
        object->mUnk_000.mCollisionData.mUnk_114.x = 1;
    } else {
        object->mUnk_000.mCollisionData.mUnk_110 = TRUE;
        object->mUnk_000.mCollisionData.mUnk_114.x = 0;
    }
    object->mUnk_000.mCollisionData.mUnk_114.z = 0;
    object->mUnk_000.mCollisionData.mUnk_120 = kindInfo->mUnk_10;
    object->mUnk_000.mCollisionData.mUnk_134 = COLLISION_SHAPE_CYLINDER;
    object->mUnk_000.mCollisionData.mUnk_138 = kindInfo->mUnk_14;
    object->mUnk_000.mMapObject.mFlags |= data_02158d58;
    object->mUnk_000.mMapObject.mStateMachine.mNextState = 0;
    object->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    object->mModelIndex = kindInfo->mUnk_0c;
    if (object->mModelIndex == 1 && courseRow->mUnk_32 == 0) {
        object->mModelIndex = 2;
    }
    object->mUnk_000.mMapObject.mFlags &= ~2;
    object->mUnk_000.mMapObject.mFlags &= ~8;
    object->mUnk_000.mMapObject.mAlpha = 0x1f;
    if (kindInfo->mUnk_0c == 0) {
        object->mSoundId = courseRow->mUnk_0c.x > 0 ? 0x175 : 0x176;
    } else {
        object->mSoundId = kindInfo->mUnk_18;
    }
    if (object->mSoundId != -1) {
        CreateMapObjectSoundSourceFalloff3(&object->mUnk_000.mMapObject);
    }
}

#pragma thumb off

void *CreateBridgeKindData(void) {
    Unk020e03f8 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158d18;
    return kindData;
}

void *CreateBridgeDrawList(void) {
    BridgeDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x30);
    gBridgeDrawList = drawList;
    *drawList = data_02158ce8;
    SetDrawListSlot(&gBridgeDrawList);
    return gBridgeDrawList;
}

void *CreateBridgeUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gBridgeUpdateList = updateList;
    *updateList = data_02158cc0;
    SetUpdateListSlot(&gBridgeUpdateList);
    return gBridgeUpdateList;
}

void UpdateBridge(s32 unused, Bridge *bridge) {
    s16 sine;
    s32 angleDelta;
    u16 swingMagnitude;
    u16 y;

    sine = gPairsByAngle[(bridge->mSwingAngle >> 4) * 2];
    swingMagnitude = bridge->mSwingAmplitude + MUL_FIXED12_NO_ROUND(sine, bridge->mSwingAmplitude);
    y = 0x10000 - swingMagnitude;
    angleDelta = y - bridge->mAngleX;
    if (angleDelta > 0x8000) {
        angleDelta -= 0x10000;
    }
    if (angleDelta < -0x8000) {
        angleDelta += 0x10000;
    }
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.x =
        MUL_FIXED12_NO_ROUND(bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[0].x, angleDelta);
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.y =
        MUL_FIXED12_NO_ROUND(bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[0].y, angleDelta);
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.z =
        MUL_FIXED12_NO_ROUND(bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[0].z, angleDelta);
    bridge->mAngleX = y;
    bridge->mUnk_000.mCollisionData.mPrevMatrix = bridge->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    MTX_RotX33_(&bridge->mUnk_000.mMapObject.mMatrix.mUnk_00_m, gPairsByAngle[(y >> 4) * 2],
                gPairsByAngle[(y >> 4) * 2 + 1]);
    MTX_Concat33(&bridge->mUnk_000.mMapObject.mMatrix.mUnk_00_m, &bridge->mUnk_000.mCollisionData.mInitialMatrix,
                 &bridge->mUnk_000.mMapObject.mMatrix.mUnk_00_m);
    VEC_MultAdd(-bridge->mUnk_000.mCollisionData.mHalfSizeY, &bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[1],
                &bridge->mUnk_000.mMapObject.mPos, &bridge->mUnk_000.mCollisionData.mCenterPos);
    if (bridge->mPauseTimer != 0) {
        bridge->mPauseTimer--;
        return;
    }
    if (bridge->mUnk_000.mMapObject.mSound != NULL) {
        StartMapObjectSoundWhileRequested(&bridge->mUnk_000.mMapObject, 0x189);
    }
    bridge->mSwingAngle += bridge->mSwingAnglePerFrame;
    if (bridge->mSwingAngle >= 0x4000 && bridge->mSwingAngle < bridge->mSwingAnglePerFrame + 0x4000) {
        bridge->mPauseTimer = bridge->mPeakPauseFrameCount;
    } else if (bridge->mSwingAngle >= 0xc000 && bridge->mSwingAngle < bridge->mSwingAnglePerFrame + 0xc000) {
        bridge->mPauseTimer = bridge->mTroughPauseFrameCount;
    }
    y = 0x10000 - bridge->mAngleX;
    bridge->mAnimationFrameIndex = (s32) ((((s64) (s32) (u16) (0x10000 - bridge->mAngleX) * 0x1680000) + 0x80000) >> 20)
                                   << 1;
    if (bridge->mAnimationFrameIndex > gBridgeDrawList->mAnimationFrameCount) {
        bridge->mAnimationFrameIndex = gBridgeDrawList->mAnimationFrameCount;
    }
    if (bridge->mAnimationFrameIndex < 0) {
        bridge->mAnimationFrameIndex = 0;
    }
}

void DrawBridge(Unk020e3ef4 *object, void *viewMatrix, u32 alpha) {
    ModelAnimation *animation;

    object->mUnk_000.mMapObject.mMatrix.mUnk_00[3].x = object->mUnk_000.mMapObject.mPos.x >> 4;
    object->mUnk_000.mMapObject.mMatrix.mUnk_00[3].y = object->mUnk_000.mMapObject.mPos.y >> 4;
    object->mUnk_000.mMapObject.mMatrix.mUnk_00[3].z = object->mUnk_000.mMapObject.mPos.z >> 4;
    animation = gBridgeNsbca;
    animation->mHead.mFrameIndex = object->mUnk_154;
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
    DrawNsbmdWithMatrixAndMaxAlpha(object->mModel, &object->mUnk_000.mMapObject.mMatrix,
                                   &object->mUnk_000.mMapObject.mScale.x, alpha);
}

void DrawAllBridges(void *viewMatrix) {
    DrawVisibleMapObjects(&gBridgeDrawList->mMapObjectList, viewMatrix, DrawBridge);
}
