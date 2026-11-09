#include "Main/Unknown/code_020e44e4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

#pragma thumb on

void InitPukupuku(Pukupuku *pukupuku, Vec3 *position) {
    InitStateMachine(&pukupuku->mPushedObject.mMapObject.mStateMachine, data_0216c1ec, 4, pukupuku);
    pukupuku->mPushedObject.mMapObject.mPos.y =
        pukupuku->mPushedObject.mMapObject.mPos.y +
        MUL_FIXED12_NO_ROUND(pukupuku->mPushedObject.mMapObject.mScale.y, 0xa000);
    pukupuku->mInitialPos = pukupuku->mPushedObject.mMapObject.mPos;
    pukupuku->mJumpsUntilHighJump = 4;
    pukupuku->mPushedObject.mMapObject.mUnk_10.x = 0;
    pukupuku->mPushedObject.mMapObject.mUnk_10.y = 0;
    pukupuku->mPushedObject.mMapObject.mUnk_10.z = 0;
    InitPushedMotion(&pukupuku->mPushedObject, pukupuku->mPushedObject.mMapObject.mPos.y - 0x1e000, 0x400, 0x400,
                     0x4000, 0x1800);
    pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 0;
    pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&pukupuku->mShadowMatrix, position,
                        MUL_FIXED12_NO_ROUND(pukupuku->mPushedObject.mMapObject.mScale.x, 0x12000), 0xd);
    pukupuku->mInitialGroundY = position->y;
    {
        Vec3 *secondRow = &pukupuku->mShadowMatrix.mMatrix.mUnk_00[1];
        pukupuku->mGroundSlopeX = -FX_Div(secondRow->x, secondRow->y);
        pukupuku->mGroundSlopeZ = -FX_Div(secondRow->z, secondRow->y);
    }
}

#pragma thumb off

MapObjectKindData *CreateRotaryGearTestCylinderKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158f70;
    kindData->mUnk_38 = 0x2bc000;
    return kindData;
}

MapObjectKindData *CreateRotaryRoomKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158f30;
    return kindData;
}

MapObjectKindData *CreateRotaryBridgeKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158ef0;
    return kindData;
}

MapObjectDrawList *CreateRotaryDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gRotaryDrawList = drawList;
    *drawList = data_02158ec4;
    SetDrawListSlot(&gRotaryDrawList);
    return gRotaryDrawList;
}

MapObjectList *CreateRotaryUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gRotaryUpdateList = updateList;
    *updateList = data_02158e9c;
    SetUpdateListSlot(&gRotaryUpdateList);
    return gRotaryUpdateList;
}

void UpdateRotary(u32 unused, Rotary *object) {
    s32 previousAngle;
    s32 angleChange;
    previousAngle = object->mUnk_000.mMapObject.mAngle;
    AdvanceStateMachine(&object->mUnk_000.mMapObject.mStateMachine);
    angleChange = object->mUnk_000.mMapObject.mAngle - previousAngle;
    if (angleChange > 0x8000) {
        angleChange -= 0x10000;
    }
    if (angleChange < -0x8000) {
        angleChange += 0x10000;
    }
    object->mUnk_000.mCollisionData.mAngleChangeVector.x =
        MUL_FIXED12_NO_ROUND(object->mUnk_000.mMapObject.mMatrix.mUnk_00[1].x, angleChange);
    object->mUnk_000.mCollisionData.mAngleChangeVector.y =
        MUL_FIXED12_NO_ROUND(object->mUnk_000.mMapObject.mMatrix.mUnk_00[1].y, angleChange);
    object->mUnk_000.mCollisionData.mAngleChangeVector.z =
        MUL_FIXED12_NO_ROUND(object->mUnk_000.mMapObject.mMatrix.mUnk_00[1].z, angleChange);
    object->mUnk_000.mCollisionData.mPrevMatrix = object->mUnk_000.mMapObject.mMatrix.mUnk_00_m;
    MTX_RotY33_(&object->mUnk_000.mMapObject.mMatrix.mUnk_00_m,
                gPairsByAngle[(object->mUnk_000.mMapObject.mAngle >> 4) * 2],
                gPairsByAngle[(object->mUnk_000.mMapObject.mAngle >> 4) * 2 + 1]);
    MTX_Concat33(&object->mUnk_000.mMapObject.mMatrix.mUnk_00_m, &object->mUnk_000.mCollisionData.mInitialMatrix,
                 &object->mUnk_000.mMapObject.mMatrix.mUnk_00_m);
    VEC_MultAdd(-object->mUnk_000.mCollisionData.mHalfSizeY, &object->mUnk_000.mMapObject.mMatrix.mUnk_00[1],
                &object->mUnk_000.mMapObject.mPos, &object->mUnk_000.mCollisionData.mCenterPos);
    if (object->mUnk_000.mMapObject.mStateMachine.mState == 3) {
        return;
    }
    if (object->mSoundId == -1) {
        return;
    }
    StartMapObjectSoundWhileRequested(&object->mUnk_000.mMapObject, object->mSoundId);
}
