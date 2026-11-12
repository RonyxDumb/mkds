#include "Main/MapObjects/pukupuku_init.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"

#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/System/heap_call.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"

#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/pukupuku.h"

const MapObjectDrawList gRotaryDrawListData = {
    {NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateRotary, NULL, NULL, NULL, 1, NULL, 0, NULL}, 0};
const MapObjectKindData gRotaryBridgeKindData = {NULL, NULL, 5, 0x50000, 0x866000, 0, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const MapObjectKindData gRotaryRoomKindData = {NULL, NULL, 5, 0x1d8000, 0x19000, 0, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const MapObjectList gRotaryUpdateListData = {
    NULL, 0, {0, 0}, (void (*)(MapObjectList *)) InitRotaryObjects, NULL, (UnkFunc *) UpdateRotary, NULL, 0, NULL, 0, NULL};
const MapObjectKindData gRotaryGearTestCylinderKindData = {NULL, NULL, 5, 0x12c000, 0x32000, 0, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};
StateCallbacks gPukupukuStateTable[4] = {{EnterPukupukuState0, UpdatePukupukuState0}, {EnterPukupukuState1, UpdatePukupukuState1}, {EnterPukupukuState2, UpdatePukupukuState2}, {EnterPukupukuState3, UpdatePukupukuState3}};

#pragma thumb on

void InitPukupuku(Pukupuku *pukupuku, Vec3 *position) {
    InitStateMachine(&pukupuku->mPushedObject.mMapObject.mStateMachine, gPukupukuStateTable, 4, pukupuku);
    pukupuku->mPushedObject.mMapObject.mPos.y =
        pukupuku->mPushedObject.mMapObject.mPos.y +
        MUL_FIXED12_NO_ROUND(pukupuku->mPushedObject.mMapObject.mScale.y, 0xa000);
    pukupuku->mInitialPos = pukupuku->mPushedObject.mMapObject.mPos;
    pukupuku->mJumpsUntilHighJump = 4;
    pukupuku->mPushedObject.mMapObject.mPosStep.x = 0;
    pukupuku->mPushedObject.mMapObject.mPosStep.y = 0;
    pukupuku->mPushedObject.mMapObject.mPosStep.z = 0;
    InitPushedMotion(&pukupuku->mPushedObject, pukupuku->mPushedObject.mMapObject.mPos.y - 0x1e000, 0x400, 0x400,
                     0x4000, 0x1800);
    pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = 0;
    pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&pukupuku->mShadowMatrix, position,
                        MUL_FIXED12_NO_ROUND(pukupuku->mPushedObject.mMapObject.mScale.x, 0x12000), 0xd);
    pukupuku->mInitialGroundY = position->y;
    {
        Vec3 *secondRow = &pukupuku->mShadowMatrix.mMatrix.mRows[1];
        pukupuku->mGroundSlopeX = -FX_Div(secondRow->x, secondRow->y);
        pukupuku->mGroundSlopeZ = -FX_Div(secondRow->z, secondRow->y);
    }
}

#pragma thumb off

MapObjectKindData *CreateRotaryGearTestCylinderKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gRotaryGearTestCylinderKindData;
    kindData->mHeightRangeMax = 0x2bc000;
    return kindData;
}

MapObjectKindData *CreateRotaryRoomKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gRotaryRoomKindData;
    return kindData;
}

MapObjectKindData *CreateRotaryBridgeKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gRotaryBridgeKindData;
    return kindData;
}

MapObjectDrawList *CreateRotaryDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gRotaryDrawList = drawList;
    *drawList = gRotaryDrawListData;
    SetDrawListSlot(&gRotaryDrawList);
    return gRotaryDrawList;
}

MapObjectList *CreateRotaryUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gRotaryUpdateList = updateList;
    *updateList = gRotaryUpdateListData;
    SetUpdateListSlot(&gRotaryUpdateList);
    return gRotaryUpdateList;
}

void UpdateRotary(u32 unused, Rotary *object) {
    s32 previousAngle;
    s32 angleChange;
    previousAngle = object->mCollisionMapObject.mMapObject.mAngle;
    AdvanceStateMachine(&object->mCollisionMapObject.mMapObject.mStateMachine);
    angleChange = object->mCollisionMapObject.mMapObject.mAngle - previousAngle;
    if (angleChange > 0x8000) {
        angleChange -= 0x10000;
    }
    if (angleChange < -0x8000) {
        angleChange += 0x10000;
    }
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.x =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mMatrix.mRows[1].x, angleChange);
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.y =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mMatrix.mRows[1].y, angleChange);
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.z =
        MUL_FIXED12_NO_ROUND(object->mCollisionMapObject.mMapObject.mMatrix.mRows[1].z, angleChange);
    object->mCollisionMapObject.mCollisionData.mPrevMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    MTX_RotY33_(&object->mCollisionMapObject.mMapObject.mMatrix.mAxes,
                FX_SinIdx(object->mCollisionMapObject.mMapObject.mAngle),
                FX_CosIdx(object->mCollisionMapObject.mMapObject.mAngle));
    MTX_Concat33(&object->mCollisionMapObject.mMapObject.mMatrix.mAxes,
                 &object->mCollisionMapObject.mCollisionData.mInitialMatrix,
                 &object->mCollisionMapObject.mMapObject.mMatrix.mAxes);
    VEC_MultAdd(-object->mCollisionMapObject.mCollisionData.mHalfSizeY,
                &object->mCollisionMapObject.mMapObject.mMatrix.mRows[1], &object->mCollisionMapObject.mMapObject.mPos,
                &object->mCollisionMapObject.mCollisionData.mCenterPos);
    if (object->mCollisionMapObject.mMapObject.mStateMachine.mState == ROTARY_STATE_PAUSE) {
        return;
    }
    if (object->mSoundId == -1) {
        return;
    }
    StartMapObjectSoundWhileRequested(&object->mCollisionMapObject.mMapObject, object->mSoundId);
}
