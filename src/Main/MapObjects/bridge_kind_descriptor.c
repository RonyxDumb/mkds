#include "Main/MapObjects/bridge_kind_descriptor.h"
#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/bridge.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/jg.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/choropu_state.h"

const u16 gBridgeInitFlag = 1;
const MapObjectKindDescriptor gBridgeKindDescriptor = {0,
                                                       {0, 0},
                                                       0x158,
                                                       InitBridge,
                                                       CreateBridgeKindData,
                                                       CreateBridgeDrawList,
                                                       NULL,
                                                       NULL,
                                                       CreateBridgeUpdateList,
                                                       NULL,
                                                       {NULL, NULL, NULL, NULL}};

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
    bridge->mCollisionMapObject.mCollisionData.mPreviousPos = bridge->mCollisionMapObject.mMapObject.mPos;
    bridge->mCollisionMapObject.mCollisionData.mPrevMatrix = bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    bridge->mCollisionMapObject.mCollisionData.mInitialMatrix = bridge->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    bridge->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    bridge->mCollisionMapObject.mCollisionData.mTracksNormal = 1;
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
    bridge->mCollisionMapObject.mCollisionData.mHalfSizeX =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.x, 0x5a000);
    bridge->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.y, 0x1e000) >> 1;
    bridge->mCollisionMapObject.mCollisionData.mPositiveHalfSizeZ =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.z, 0x15e000);
    bridge->mCollisionMapObject.mCollisionData.mNegativeHalfSizeZ =
        MUL_FIXED12_NO_ROUND(bridge->mCollisionMapObject.mMapObject.mScale.z, 0x32000);
    bridge->mCollisionMapObject.mCollisionData.mAxis0Flag = 0;
    bridge->mCollisionMapObject.mCollisionData.mHitFlagWords.x = 1;
    bridge->mCollisionMapObject.mCollisionData.mHitFlagWords.y = 0;
    bridge->mCollisionMapObject.mCollisionData.mHitFlagWords.z = 1;
    bridge->mCollisionMapObject.mCollisionData.mFloorThreshold = FIXED12_RATIO(1, 2);
    bridge->mCollisionMapObject.mCollisionData.mShape = COLLISION_SHAPE_BOX;
    bridge->mCollisionMapObject.mCollisionData.mCollisionFlag = 0;
    bridge->mCollisionMapObject.mMapObject.mFlags |= gBridgeInitFlag;
    bridge->mCollisionMapObject.mMapObject.mFlags &= ~2;
    bridge->mCollisionMapObject.mMapObject.mFlags &= ~8;
    bridge->mCollisionMapObject.mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    if (courseRow->mRotationDegrees.y < 0) {
        CreateMapObjectSoundSourceFalloff4(&bridge->mCollisionMapObject.mMapObject);
    }
}

#pragma thumb off
