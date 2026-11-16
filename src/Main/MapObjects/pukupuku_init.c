#include "Main/MapObjects/pukupuku_init.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"

#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/heap_call.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"

#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/pukupuku.h"
#include "Main/MapObjects/bridge.h"

#pragma thumb on

const MapObjectDrawList gRotaryDrawListData = {
    {NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateRotary, NULL, NULL, NULL, 1, NULL, 0, NULL}, 0};
const MapObjectKindData gRotaryRoomKindData = {NULL, NULL, 5, 0x1d8000, 0x19000, 0, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const MapObjectKindData gRotaryBridgeKindData = {NULL, NULL, 5, 0x50000, 0x866000, 0, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const MapObjectList gRotaryUpdateListData = {
    NULL, 0, {0, 0}, (void (*)(MapObjectList *)) InitRotaryObjects, NULL, UpdateRotary, NULL, 0,
    NULL, 0, NULL};
const MapObjectKindData gRotaryGearTestCylinderKindData = {NULL, NULL, 5, 0x12c000, 0x32000, 0, NULL, 1,
                                                           0,    0,    0, 0,        0,       0, 0,    0};
#pragma thumb off

MapObjectKindData *CreateRotaryGearTestCylinderKindData(void) {
    MapObjectKindData *kindData;
    kindData = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*kindData));
    *kindData = gRotaryGearTestCylinderKindData;
    kindData->mHeightRangeMax = PUKUPUKU_HEIGHT_RANGE_MAX;
    return kindData;
}

MapObjectKindData *CreateRotaryRoomKindData(void) {
    MapObjectKindData *kindData;
    kindData = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*kindData));
    *kindData = gRotaryRoomKindData;
    return kindData;
}

MapObjectKindData *CreateRotaryBridgeKindData(void) {
    MapObjectKindData *kindData;
    kindData = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*kindData));
    *kindData = gRotaryBridgeKindData;
    return kindData;
}

MapObjectDrawList *CreateRotaryDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(MapObjectDrawList));
    gRotaryDrawList = drawList;
    *drawList = gRotaryDrawListData;
    SetDrawListSlot(&gRotaryDrawList);
    return gRotaryDrawList;
}

MapObjectList *CreateRotaryUpdateList(void) {
    MapObjectList *updateList;
    updateList = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(MapObjectList));
    gRotaryUpdateList = updateList;
    *updateList = gRotaryUpdateListData;
    SetUpdateListSlot(&gRotaryUpdateList);
    return gRotaryUpdateList;
}

void UpdateRotary(u32 unused, Rotary *object) {
    s32 previousAngle;
    s32 angleChange;
    previousAngle = object->mCollisionMapObject.mMapObject.mAngle;
    StateDualHandler_Execute(&object->mCollisionMapObject.mMapObject.mStateMachine);
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
    MTX_RotY33__from_thumb(&object->mCollisionMapObject.mMapObject.mMatrix.mAxes,
                FX_SinIdx(object->mCollisionMapObject.mMapObject.mAngle),
                FX_CosIdx(object->mCollisionMapObject.mMapObject.mAngle));
    MTX_Concat33(&object->mCollisionMapObject.mMapObject.mMatrix.mAxes,
                 &object->mCollisionMapObject.mCollisionData.mInitialMatrix,
                 &object->mCollisionMapObject.mMapObject.mMatrix.mAxes);
    VecFx32_AddScale1(-object->mCollisionMapObject.mCollisionData.mHalfSizeY,
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
