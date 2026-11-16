#include "Main/MapObjects/koopa_block_kind_descriptor.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/System/state_machine_init.h"
#include "Main/System/heap_call.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_distance_squared_change.h"
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
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/collision_hit_link.h"
#include "Main/MapObjects/group_item_box.h"
#include "Main/MapObjects/mkd_ef_bubble.h"

const u16 gKoopaBlockFlag = 1;
const MapObjectKindDescriptor gKoopaBlockKindDescriptor = {0,
                                                           {0, 0},
                                                           0x170,
                                                           InitKoopaBlock,
                                                           CreateKoopaBlockKindData,
                                                           CreateKoopaBlockDrawList,
                                                           NULL,
                                                           NULL,
                                                           CreateKoopaBlockUpdateList,
                                                           NULL,
                                                           {NULL, NULL, NULL, NULL}};

StateCallbacks gKoopaBlockStateTable[3] = {{KoopaBlockAccelerateNop, UpdateKoopaBlockAccelerate},
                                           {EnterKoopaBlockCruise, UpdateKoopaBlockCruise},
                                           {KoopaBlockDecelerateNop, UpdateKoopaBlockDecelerate}};

#pragma thumb off

void UpdateKoopaBlockDecelerate(void *stateObject) {
    KoopaBlock *koopaBlock = stateObject;
    GroupFollower *follower;
    s32 progress;
    s32 speed;
    u16 angle;
    s32 sine;

    follower = &koopaBlock->mFollower;
    progress = GetGroupFollowerProgress(follower);
    angle = MUL_FIXED12_NO_ROUND(progress, 0x40000);
    sine = FX_SinIdx(angle);
    speed = MUL_FIXED12_NO_ROUND(-sine, koopaBlock->mFollowSpeed);
    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep =
        MUL_FIXED12_NO_ROUND(speed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
}

void DrawAllKoopaBlocks(void *viewMatrix) {
    DrawVisibleMapObjects(&gKoopaBlockDrawList->mList, viewMatrix, DrawMapObjectModelAtPos);
}

BOOL IsKoopaBlockKind(u32 kind) {
    switch (kind) {
        case MAP_OBJECT_KIND_KOOPA_BLOCK:
            return 1;
        default:
            return 0;
    }
}

s32 GetKoopaBlockProgress(KoopaBlock *koopaBlock) {
    s32 progress;
    GroupFollower *follower;

    follower = &koopaBlock->mFollower;
    progress = GetGroupFollowerProgress(follower);
    if (follower->mForward == 0) {
        progress = 0x1000 - progress;
    }
    return progress;
}

#pragma thumb on
void CreateKoopaBlock(void) {
    void *file;

    file = FormatFindMapObjFileBuffer_from_thumb("koopa_block.nsbmd");
    CreateNsbmd(&gKoopaBlock, file, NULL);
    StructML_SomeFn_1(gKoopaBlock, 0x3f, 2, 0x294a);
    SetMapObjectsModel(&gKoopaBlockDrawList->mList, gKoopaBlock);
}

void InitKoopaBlock(KoopaBlock *koopaBlock, CourseMapRow *courseRow) {
    StateDualHandler_Create(&koopaBlock->mCollisionMapObject.mMapObject.mStateMachine, gKoopaBlockStateTable, 3, koopaBlock);
    koopaBlock->mFollowSpeed = TO_FIXED12(courseRow->mSettings[0]) / 100;
    InitGroupFollower(&koopaBlock->mFollower, courseRow, koopaBlock->mFollowSpeed);
    koopaBlock->mPauseTimer = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mPrevMatrix =
        koopaBlock->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    koopaBlock->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mTracksNormal = FALSE;
    koopaBlock->mCollisionMapObject.mCollisionData.mHalfSizeX =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.x, 0x190000);
    koopaBlock->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.y, 0x64000) >> 1;
    koopaBlock->mCollisionMapObject.mCollisionData.mPositiveHalfSizeZ =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    koopaBlock->mCollisionMapObject.mCollisionData.mNegativeHalfSizeZ =
        MUL_FIXED12_NO_ROUND(koopaBlock->mCollisionMapObject.mMapObject.mScale.z, 0xaf000);
    koopaBlock->mCollisionMapObject.mCollisionData.mAxis0Flag = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mHitFlagWords.x = 1;
    koopaBlock->mCollisionMapObject.mCollisionData.mHitFlagWords.y = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mHitFlagWords.z = 0;
    koopaBlock->mCollisionMapObject.mCollisionData.mFloorThreshold = FIXED12_RATIO(1, 2);
    SetupGroupFollowerAtEntry(&koopaBlock->mFollower, 0, 1);
    GetGroupFollowerLinearPosStep(&koopaBlock->mFollower, &koopaBlock->mCollisionMapObject.mMapObject.mPos,
                                  &koopaBlock->mCollisionMapObject.mMapObject.mPosStep);
    koopaBlock->mCollisionMapObject.mCollisionData.mPreviousPos = koopaBlock->mCollisionMapObject.mMapObject.mPos;
    koopaBlock->mCollisionMapObject.mCollisionData.mShape = COLLISION_SHAPE_BOX;
    koopaBlock->mCollisionMapObject.mCollisionData.mCollisionFlag = 0;
    koopaBlock->mCollisionMapObject.mMapObject.mFlags |= gKoopaBlockFlag;
    koopaBlock->mCollisionMapObject.mMapObject.mFlags &= ~2;
    koopaBlock->mCollisionMapObject.mMapObject.mFlags &= ~8;
    koopaBlock->mCollisionMapObject.mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = KOOPA_BLOCK_STATE_ACCELERATE;
    koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    koopaBlock->mCollisionMapObject.mMapObject.mFarDistanceSquared = gSoundFalloffs[3].mFarDistanceSquared;
}
