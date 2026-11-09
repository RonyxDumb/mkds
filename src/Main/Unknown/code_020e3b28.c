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

void func_020e4380(Unk020e3ef4 *object) {
    if (object->mUnk_000.mMapObject.mStateMachine.mStateFrames > object->mUnk_148) {
        object->mUnk_000.mMapObject.mStateMachine.mNextState = 0;
        object->mUnk_000.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void DrawAllKind203MapObjects(void *viewMatrix) {
    DrawVisibleMapObjects(data_0217b7e4, viewMatrix, DrawMapObjectModelAtPos);
}

BOOL func_020e4320(s32 kind) {
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

void func_020e4184(BridgeDrawList *list) {
    Unk020e3ef4 *object;
    s32 objectIndex;
    s32 modelIndex;
    s32 objectCount;
    s32 j;
    s32 l;
    u32 *loadedFlagSlot;
    u32 modelLoaded[5];

    for (modelIndex = 0; modelIndex < 5; modelIndex++) {
        modelLoaded[modelIndex] = 0;
    }
    objectCount = list->mMapObjectList.mMapObjectCount;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = list->mMapObjectList.mMapObjects[objectIndex];
        loadedFlagSlot = &modelLoaded[object->mUnk_158];
        if (modelLoaded[object->mUnk_158] == 0) {
            switch (object->mUnk_158) {
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
    l = list->mMapObjectList.mMapObjectCount;
    for (j = 0; j < l; j++) {
        object = list->mMapObjectList.mMapObjects[j];
        switch (object->mUnk_158) {
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

void func_020e410c(BridgeDrawList *list) {
    Unk020e3ef4 *object;
    s32 index;
    s32 previousIndex;
    s32 count;
    u32 z;
    u32 z2;
    Vec3 offset;
    void **objects;
    Unk020e3ef4 *p;

    objects = list->mMapObjectList.mMapObjects;
    previousIndex = -1;
    z = 0;
    z2 = 0;
    count = list->mMapObjectList.mMapObjectCount;
    for (index = 0; index < count; index++) {
        object = objects[index];
        if (object->mUnk_000.mMapObject.mKind == 0xcb) {
            if (previousIndex < 0) {
                object->mUnk_000.mCollisionData.mUnk_138 = z;
            } else {
                p = objects[previousIndex];
                VEC_Subtract(&p->mUnk_000.mMapObject.mPos, &object->mUnk_000.mMapObject.mPos, &offset);
                offset.y = z2;
                object->mUnk_154 = VEC_Mag(&offset);
                p = objects[previousIndex];
                object->mUnk_154 -= p->mUnk_000.mMapObject.mExtent.x;
            }
            previousIndex = index;
        }
    }
}

void func_020e3ef4(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    InitStateMachine(&object->mUnk_000.mMapObject.mStateMachine, (UnkFunc *const *) data_0216c168, 4, object);
    object->mUnk_000.mCollisionData.mUnk_e8 = object->mUnk_000.mMapObject.mPos;
    object->mUnk_000.mCollisionData.mPrevMatrix = object->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    object->mUnk_000.mCollisionData.mInitialMatrix = object->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    object->mUnk_000.mCollisionData.mAngleChangeVector.x = 0;
    object->mUnk_000.mCollisionData.mAngleChangeVector.y = 0;
    object->mUnk_000.mCollisionData.mAngleChangeVector.z = 0;
    object->mUnk_000.mCollisionData.mUnk_130 = kindInfo->mUnk_00 != 0 ? 0 : 1;
    object->mUnk_144 = courseRow->mUnk_2c;
    object->mUnk_146 = courseRow->mUnk_2a;
    object->mUnk_148 = courseRow->mUnk_2e;
    object->mUnk_14a = courseRow->mUnk_28 * 0x80 / 100;
    if (courseRow->mUnk_30 != 0) {
        object->mUnk_14a = -object->mUnk_14a;
    }
    object->mUnk_000.mMapObject.mAngle = 0;
    if (object->mUnk_144 != 0) {
        object->mUnk_150 = 0x1000 / object->mUnk_144;
    } else {
        object->mUnk_150 = 0;
    }
    object->mUnk_14c = 0;
    object->mUnk_000.mCollisionData.mUnk_100 = ((s64) kindInfo->mUnk_04 * object->mUnk_000.mMapObject.mScale.x) >> 12;
    object->mUnk_000.mCollisionData.mHalfSizeY =
        (s32) (((s64) kindInfo->mUnk_08 * object->mUnk_000.mMapObject.mScale.y) >> 12) >> 1;
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
    object->mUnk_158 = kindInfo->mUnk_0c;
    if (object->mUnk_158 == 1 && courseRow->mUnk_32 == 0) {
        object->mUnk_158 = 2;
    }
    object->mUnk_000.mMapObject.mFlags &= ~2;
    object->mUnk_000.mMapObject.mFlags &= ~8;
    object->mUnk_000.mMapObject.mAlpha = 0x1f;
    if (kindInfo->mUnk_0c == 0) {
        object->mUnk_15c = courseRow->mUnk_0c.x > 0 ? 0x175 : 0x176;
    } else {
        object->mUnk_15c = kindInfo->mUnk_18;
    }
    if (object->mUnk_15c != -1) {
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
    data_0217b7c4 = drawList;
    *drawList = data_02158ce8;
    SetDrawListSlot(&data_0217b7c4);
    return data_0217b7c4;
}

void *CreateBridgeUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b7c8 = updateList;
    *updateList = data_02158cc0;
    SetUpdateListSlot(&data_0217b7c8);
    return data_0217b7c8;
}

void UpdateBridge(s32 a, Bridge *bridge) {
    s16 sine;
    s32 angleDelta;
    u16 x;
    u16 y;

    sine = gPairsByAngle[(bridge->mSwingAngle >> 4) * 2];
    x = bridge->mSwingAmplitude + (s32) (((s64) sine * bridge->mSwingAmplitude) >> 12);
    y = 0x10000 - x;
    angleDelta = y - bridge->mAngleX;
    if (angleDelta > 0x8000) {
        angleDelta -= 0x10000;
    }
    if (angleDelta < -0x8000) {
        angleDelta += 0x10000;
    }
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.x =
        ((s64) bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[0].x * angleDelta) >> 12;
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.y =
        ((s64) bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[0].y * angleDelta) >> 12;
    bridge->mUnk_000.mCollisionData.mAngleChangeVector.z =
        ((s64) bridge->mUnk_000.mMapObject.mMatrix.mUnk_00[0].z * angleDelta) >> 12;
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
    if (bridge->mAnimationFrameIndex > data_0217b7c4->mAnimationFrameCount) {
        bridge->mAnimationFrameIndex = data_0217b7c4->mAnimationFrameCount;
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
    DrawVisibleMapObjects(&data_0217b7c4->mMapObjectList, viewMatrix, DrawBridge);
}
