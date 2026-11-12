#include "Main/MapObjects/bridge.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/jg.h"
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
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/choropu_state.h"

#pragma thumb off

const Vec3 gChoropuZeroVector = {0, 0, 0};
struct MapObjectList *gChoropuUpdateList;
struct MapObjectDrawList *gChoropuDrawList;
struct NsbmdModel *gChoropu;
struct ModelAnimation *gBridgeNsbca;
struct MapObjectDrawList *gChoropuShadowDrawList;
struct BridgeDrawList *gBridgeDrawList;
struct MapObjectList *gBridgeUpdateList;
struct Nsbmd *gRotaryRoom;
struct Nsbmd *gBridge;
struct Nsbmd *gGearWhite;
struct Nsbmd *gGearBlack;
struct MapObjectList *gRotaryUpdateList;
struct Nsbmd *gRotaryBridge;
void *gRotaryDrawList;
struct Nsbmd *gTestCylinder;

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

    file = FindCourseMapObjFile("bridge.nsbmd");
    CreateNsbmd(&gBridge, file, NULL);
    CreateModelAnimation(0, gBridge, &gBridgeNsbca, file, FindCourseMapObjFile("bridge.nsbca"));
    gBridgeDrawList->mAnimationFrameCount = GetModelAnimationFrameCountFixed(gBridgeNsbca);
    SetNsbmdPolygonIdLightEmiAll(gBridge, 0x3f, 2, 0x294a);
    SetMapObjectsModel(&gBridgeDrawList->mMapObjectList, gBridge);
}

void InitBridge(Bridge *bridge, struct CourseMapRow *courseRow) {
    bridge->mCollisionMapObject.mCollisionData.mUnk_e8 = bridge->mCollisionMapObject.mMapObject.mPos;
    bridge->mCollisionMapObject.mCollisionData.mPrevMatrix = bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    bridge->mCollisionMapObject.mCollisionData.mInitialMatrix = bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    bridge->mCollisionMapObject.mCollisionData.mUnk_130 = 1;
    bridge->mSwingAmplitude = ((courseRow->mSettings[0] * 0x10000) / 0x168) >> 1;
    bridge->mSwingAnglePerFrame = (0x10000 / courseRow->mSettings[1]) >> 1;
    bridge->mPeakPauseFrameCount = courseRow->mSettings[2];
    bridge->mTroughPauseFrameCount = courseRow->mSettings[3];
    bridge->mPauseTimer = 0;
    bridge->mSwingAngle = 0;
    if (gRaceSetup->mMode == MODE_WIFI) {
        bridge->mSwingAnglePerFrame = 0;
        bridge->mSwingAngle = ((courseRow->mSettings[4] * 0x10000) / 0x168) >> 1;
    }
    bridge->mCollisionMapObject.mCollisionData.mUnk_100 =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.x, 0x5a000);
    bridge->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.y, 0x1e000) >> 1;
    bridge->mCollisionMapObject.mCollisionData.mPositiveHalfSizeZ =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.z, 0x15e000);
    bridge->mCollisionMapObject.mCollisionData.mNegativeHalfSizeZ =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.z, 0x32000);
    bridge->mCollisionMapObject.mCollisionData.mUnk_110 = 0;
    bridge->mCollisionMapObject.mCollisionData.mUnk_114.x = 1;
    bridge->mCollisionMapObject.mCollisionData.mUnk_114.y = 0;
    bridge->mCollisionMapObject.mCollisionData.mUnk_114.z = 1;
    bridge->mCollisionMapObject.mCollisionData.mUnk_120 = 0x800;
    bridge->mCollisionMapObject.mCollisionData.mUnk_134 = COLLISION_SHAPE_BOX;
    bridge->mCollisionMapObject.mCollisionData.mUnk_138 = 0;
    bridge->mCollisionMapObject.mMapObject.mFlags |= gBridgeInitFlag;
    bridge->mCollisionMapObject.mMapObject.mFlags &= ~2;
    bridge->mCollisionMapObject.mMapObject.mFlags &= ~8;
    bridge->mCollisionMapObject.mMapObject.mAlpha = 0x1f;
    if (courseRow->mRotationDegrees.y < 0) {
        CreateMapObjectSoundSourceFalloff4(&bridge->mCollisionMapObject.mMapObject);
    }
}

#pragma thumb off

void *CreateChoropuKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gChoropuKindData;
    return kindData;
}

void *CreateChoropuDrawList(void) {
    MapObjectDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gChoropuDrawList = drawList;
    *drawList = gChoropuDrawListData;
    SetDrawListSlot(&gChoropuDrawList);
    return gChoropuDrawList;
}

void *CreateChoropuShadowDrawList(void) {
    MapObjectDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gChoropuShadowDrawList = drawList;
    *drawList = gChoropuShadowDrawListData;
    SetDrawListSlot(&gChoropuShadowDrawList);
    return gChoropuShadowDrawList;
}

void *CreateChoropuUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gChoropuUpdateList = updateList;
    *updateList = gChoropuUpdateListData;
    SetUpdateListSlot(&gChoropuUpdateList);
    return gChoropuUpdateList;
}

void SetupDrawChoropu(void) {
    QueueNsbmdModelMaterial(gChoropu);
}

void DrawChoropu(s32 unused, Choropu *choropu, s32 unusedArg, u16 alpha) {
    MtxFx43 *matrix;

    switch (choropu->mMapObject.mStateMachine.mState) {
        case 4:
            gChoropu->mFrameIndex = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mMapObject.mPos);
            DrawNsbmdModelWithMatrixAndMaxAlpha(gChoropu, matrix, &choropu->mMapObject.mScale, 0, alpha);
            break;
        case 5:
            break;
        case 6:
        case 7:
            gChoropu->mFrameIndex = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mMapObject.mPos);
            DrawNsbmdModelWithMatrixAndAngle(gChoropu, matrix, choropu->mSpinAngle, &choropu->mMapObject.mScale, 0,
                                             alpha);
            break;
        default:
            gChoropu->mFrameIndex = 0;
            matrix = SetViewTransposeMatrixPos(&choropu->mMapObject.mPos);
            DrawNsbmdModelWithMatrixAndMaxAlpha(gChoropu, matrix, &choropu->mMapObject.mScale, 0, alpha);
    }
}
