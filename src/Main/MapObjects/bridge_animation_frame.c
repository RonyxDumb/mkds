#include "Main/MapObjects/bridge_animation_frame.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/bridge.h" // Bridge
#include "Main/MapObjects/rotary.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/bridge.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/System/state_machine_init.h"
#include "code_02147cd8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/pukupuku_init.h"
#include "Main/MapObjects/rotary_state.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const MapObjectList gBridgeUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateBridge, NULL, 0, NULL, 0, NULL};
const BridgeDrawList gBridgeDrawListData = {
    {NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateBridge, NULL, NULL, NULL, 1, NULL, 0, NULL}, 0, 0};
const MapObjectKindData gBridgeKindData = {NULL, NULL, 5, 0x5a000, 0x1e000, 0x15e000, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};

MapObjectKindData *CreateBridgeKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gBridgeKindData;
    return kindData;
}

MapObjectList *CreateBridgeDrawList(void) {
    BridgeDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(BridgeDrawList));
    gBridgeDrawList = drawList;
    *drawList = gBridgeDrawListData;
    SetDrawListSlot(&gBridgeDrawList);
    return &gBridgeDrawList->mMapObjectList;
}

MapObjectList *CreateBridgeUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    gBridgeUpdateList = updateList;
    *updateList = gBridgeUpdateListData;
    SetUpdateListSlot(&gBridgeUpdateList);
    return gBridgeUpdateList;
}

void UpdateBridge(s32 unused, Bridge *bridge) {
    s16 sine;
    s32 angleDelta;
    u16 swingMagnitude;
    u16 angle;

    sine = FX_SinIdx(bridge->mSwingAngle);
    swingMagnitude = bridge->mSwingAmplitude + MUL_FIXED12_NO_ROUND(sine, bridge->mSwingAmplitude);
    angle = 0x10000 - swingMagnitude;
    angleDelta = angle - bridge->mAngleX;
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
    bridge->mAngleX = angle;
    bridge->mCollisionMapObject.mCollisionData.mPrevMatrix = bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    MTX_RotX33_(&bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes, FX_SinIdx(angle), FX_CosIdx(angle));
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
    if (bridge->mSwingAngle >= ANGLE_QUARTER_TURN &&
        bridge->mSwingAngle < bridge->mSwingAnglePerFrame + ANGLE_QUARTER_TURN) {
        bridge->mPauseTimer = bridge->mPeakPauseFrameCount;
    } else if (bridge->mSwingAngle >= ANGLE_MINUS_QUARTER_TURN &&
               bridge->mSwingAngle < bridge->mSwingAnglePerFrame + ANGLE_MINUS_QUARTER_TURN) {
        bridge->mPauseTimer = bridge->mTroughPauseFrameCount;
    }
    angle = 0x10000 - bridge->mAngleX;
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
    DrawNsbmdWithMatrixAndMaxAlpha(object->mModel, &object->mMapObject.mMatrix, &object->mMapObject.mScale, alpha);
}

void DrawAllBridges(void *viewMatrix) {
    DrawVisibleMapObjects(&gBridgeDrawList->mMapObjectList, viewMatrix, DrawBridge);
}

u32 GetFirstBridgeAnimationFrame(void) {
    Bridge *firstBridge = gBridgeDrawList->mMapObjectList.mMapObjects[0];

    return FROM_FIXED12(firstBridge->mAnimationFrameIndex);
}
