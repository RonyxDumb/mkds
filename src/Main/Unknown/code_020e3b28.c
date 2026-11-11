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

void UpdateRotaryState3(Rotary *object) {
    if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mPauseFrameCount) {
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_RAMP_UP;
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void DrawAllKind203MapObjects(void *viewMatrix) {
    DrawVisibleMapObjects(gRotaryDrawList, viewMatrix, DrawMapObjectModelAtPos);
}

BOOL IsRotaryKind(s32 kind) {
    switch (kind) {
        case MAP_OBJECT_KIND_ROTARY_GEAR:
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
    Rotary *object;
    s32 objectIndex;
    s32 modelIndex;
    s32 objectCount;
    s32 assignIndex;
    s32 assignCount;
    u32 *loadedFlagSlot;
    u32 modelLoaded[ROTARY_MODEL_COUNT];

    for (modelIndex = 0; modelIndex < ROTARY_MODEL_COUNT; modelIndex++) {
        modelLoaded[modelIndex] = 0;
    }
    objectCount = list->mMapObjectList.mMapObjectCount;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = list->mMapObjectList.mMapObjects[objectIndex];
        loadedFlagSlot = &modelLoaded[object->mModelIndex];
        if (modelLoaded[object->mModelIndex] == 0) {
            switch (object->mModelIndex) {
                case ROTARY_MODEL_TEST_CYLINDER:
                    CreateNsbmd(&gTestCylinder, FindCourseMapObjFile(gTestCylinderNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gTestCylinder, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_GEAR_BLACK:
                    CreateNsbmd(&gGearBlack, FindCourseMapObjFile(gGearBlackNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gGearBlack, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_GEAR_WHITE:
                    CreateNsbmd(&gGearWhite, FindCourseMapObjFile(gGearWhiteNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gGearWhite, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_ROOM:
                    CreateNsbmd(&gRotaryRoom, FindCourseMapObjFile(gRotaryRoomNsbmdName), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gRotaryRoom, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_BRIDGE:
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
            case ROTARY_MODEL_TEST_CYLINDER:
                object->mCollisionMapObject.mModel = gTestCylinder;
                break;
            case ROTARY_MODEL_GEAR_BLACK:
                object->mCollisionMapObject.mModel = gGearBlack;
                break;
            case ROTARY_MODEL_GEAR_WHITE:
                object->mCollisionMapObject.mModel = gGearWhite;
                break;
            case ROTARY_MODEL_ROOM:
                object->mCollisionMapObject.mModel = gRotaryRoom;
                break;
            case ROTARY_MODEL_BRIDGE:
                object->mCollisionMapObject.mModel = gRotaryBridge;
                break;
        }
    }
}

void InitRotaryObjects(BridgeDrawList *list) {
    Rotary *object;
    s32 index;
    s32 previousIndex;
    s32 count;
    u32 zeroFlag;
    u32 zeroHeight;
    Vec3 offset;
    void **objects;
    Rotary *previousObject;

    objects = list->mMapObjectList.mMapObjects;
    previousIndex = -1;
    zeroFlag = 0;
    zeroHeight = 0;
    count = list->mMapObjectList.mMapObjectCount;
    for (index = 0; index < count; index++) {
        object = objects[index];
        if (object->mCollisionMapObject.mMapObject.mKind == MAP_OBJECT_KIND_ROTARY_GEAR) {
            if (previousIndex < 0) {
                object->mCollisionMapObject.mCollisionData.mUnk_138 = zeroFlag;
            } else {
                previousObject = objects[previousIndex];
                VEC_Subtract(&previousObject->mCollisionMapObject.mMapObject.mPos,
                             &object->mCollisionMapObject.mMapObject.mPos, &offset);
                offset.y = zeroHeight;
                object->mGearRadius = VEC_Mag(&offset);
                previousObject = objects[previousIndex];
                object->mGearRadius -= previousObject->mCollisionMapObject.mMapObject.mExtent.x;
            }
            previousIndex = index;
        }
    }
}

// Rotary: turns up to full speed, keeps that speed, slows down, pauses, then turns the other way; the course row sets
// the timings.
void InitRotary(Rotary *object, struct CourseMapRow *courseRow, RotaryKindInfo *kindInfo) {
    InitStateMachine(&object->mCollisionMapObject.mMapObject.mStateMachine, gRotaryStateTable, 4, object);
    object->mCollisionMapObject.mCollisionData.mUnk_e8 = object->mCollisionMapObject.mMapObject.mPos;
    object->mCollisionMapObject.mCollisionData.mPrevMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    object->mCollisionMapObject.mCollisionData.mInitialMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_130 = kindInfo->mUnk_00 != 0 ? 0 : 1;
    object->mRampFrameCount = courseRow->mSettings[2];
    object->mSteadyFrameCount = courseRow->mSettings[1];
    object->mPauseFrameCount = courseRow->mSettings[3];
    object->mAnglePerFrame = courseRow->mSettings[0] * 0x80 / 100;
    if (courseRow->mSettings[4] != 0) {
        object->mAnglePerFrame = -object->mAnglePerFrame;
    }
    object->mCollisionMapObject.mMapObject.mAngle = 0;
    if (object->mRampFrameCount != 0) {
        object->mSpeedFractionPerFrame = 0x1000 / object->mRampFrameCount;
    } else {
        object->mSpeedFractionPerFrame = 0;
    }
    object->mSpeedFraction = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_100 =
        MUL_FIXED12_NO_ROUND(kindInfo->mRadius, object->mCollisionMapObject.mMapObject.mScale.x);
    object->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(kindInfo->mHeight, object->mCollisionMapObject.mMapObject.mScale.y) >> 1;
    if (kindInfo->mUnk_00 != 0) {
        object->mCollisionMapObject.mCollisionData.mUnk_110 = FALSE;
        object->mCollisionMapObject.mCollisionData.mUnk_114.x = 1;
    } else {
        object->mCollisionMapObject.mCollisionData.mUnk_110 = TRUE;
        object->mCollisionMapObject.mCollisionData.mUnk_114.x = 0;
    }
    object->mCollisionMapObject.mCollisionData.mUnk_114.z = 0;
    object->mCollisionMapObject.mCollisionData.mUnk_120 = kindInfo->mUnk_10;
    object->mCollisionMapObject.mCollisionData.mUnk_134 = COLLISION_SHAPE_CYLINDER;
    object->mCollisionMapObject.mCollisionData.mUnk_138 = kindInfo->mCollisionFlag;
    object->mCollisionMapObject.mMapObject.mFlags |= data_02158d58;
    object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_RAMP_UP;
    object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    object->mModelIndex = kindInfo->mModelIndex;
    if (object->mModelIndex == ROTARY_MODEL_GEAR_BLACK && courseRow->mSettings[5] == 0) {
        object->mModelIndex = ROTARY_MODEL_GEAR_WHITE;
    }
    object->mCollisionMapObject.mMapObject.mFlags &= ~2;
    object->mCollisionMapObject.mMapObject.mFlags &= ~8;
    object->mCollisionMapObject.mMapObject.mAlpha = 0x1f;
    if (kindInfo->mModelIndex == 0) {
        object->mSoundId = courseRow->mRotationDegrees.x > 0 ? 0x175 : 0x176;
    } else {
        object->mSoundId = kindInfo->mSoundId;
    }
    if (object->mSoundId != -1) {
        CreateMapObjectSoundSourceFalloff3(&object->mCollisionMapObject.mMapObject);
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

    sine = FX_SinIdx(bridge->mSwingAngle);
    swingMagnitude = bridge->mSwingAmplitude + MUL_FIXED12_NO_ROUND(sine, bridge->mSwingAmplitude);
    y = 0x10000 - swingMagnitude;
    angleDelta = y - bridge->mAngleX;
    if (angleDelta > 0x8000) {
        angleDelta -= 0x10000;
    }
    if (angleDelta < -0x8000) {
        angleDelta += 0x10000;
    }
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.x =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mMatrix.mRows[0].x, angleDelta);
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.y =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mMatrix.mRows[0].y, angleDelta);
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.z =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mMatrix.mRows[0].z, angleDelta);
    bridge->mAngleX = y;
    bridge->mCollisionMapObject.mCollisionData.mPrevMatrix = bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    MTX_RotX33_(&bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes, FX_SinIdx(y), FX_CosIdx(y));
    MTX_Concat33(&bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes,
                 &bridge->mCollisionMapObject.mCollisionData.mInitialMatrix,
                 &bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes);
    VEC_MultAdd(-bridge->mCollisionMapObject.mCollisionData.mHalfSizeY,
                &bridge->mCollisionMapObject.mMapObject.mMatrix.mRows[1], &bridge->mCollisionMapObject.mMapObject.mPos,
                &bridge->mCollisionMapObject.mCollisionData.mCenterPos);
    if (bridge->mPauseTimer != 0) {
        bridge->mPauseTimer--;
        return;
    }
    if (bridge->mCollisionMapObject.mMapObject.mSound != NULL) {
        StartMapObjectSoundWhileRequested(&bridge->mCollisionMapObject.mMapObject, 0x189);
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

void DrawBridge(CollisionMapObject *object, void *viewMatrix, u32 alpha) {
    Bridge *bridge = (Bridge *) object;
    ModelAnimation *animation;

    object->mMapObject.mMatrix.mRows[3].x = object->mMapObject.mPos.x >> 4;
    object->mMapObject.mMatrix.mRows[3].y = object->mMapObject.mPos.y >> 4;
    object->mMapObject.mMatrix.mRows[3].z = object->mMapObject.mPos.z >> 4;
    animation = gBridgeNsbca;
    animation->mHead.mFrameIndex = bridge->mAnimationFrameIndex;
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
    DrawNsbmdWithMatrixAndMaxAlpha(object->mModel, &object->mMapObject.mMatrix, &object->mMapObject.mScale.x, alpha);
}

void DrawAllBridges(void *viewMatrix) {
    DrawVisibleMapObjects(&gBridgeDrawList->mMapObjectList, viewMatrix, DrawBridge);
}
