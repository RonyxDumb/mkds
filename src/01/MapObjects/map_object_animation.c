#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/MapObjects/mission_run_point_in_range_callback.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/map_object_model_load.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "01/MapObjects/mission_run_collision_shadow_offsets.h"
#include "01/MapObjects/mission_run_map_objects_reset.h"
#include "01/MapObjects/hanachan_move_and_followers.h"
#include "01/Race/mission_run_state.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/balloon_draw.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_koura_w.h"
#include "01/MapObjects/mission_run_hit_count.h"
#include "01/MapObjects/mission_run_counter_limit.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/mission_run_repeats_remaining.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "model_material_set.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "Main/Item/item_bomb.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Course/course_map_group_entry.h"
#include "01/MapObjects/mission_run_entry_index.h"
#include "01/MapObjects/item_bomb_node_placement.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/kuribo.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "01/MapObjects/periodic_effect.h"
#include "matrix_4x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "01/MapObjects/node_position_source.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "render_object_callback_link.h"
#include "01/MapObjects/item_bomb_release_and_set.h"
#include "01/MapObjects/item_bomb_is_stored.h"
#include "01/MapObjects/item_bomb_throw_or_release.h"
#include "Main/Graphics/effects.h"
#include "Main/Graphics/emitters.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "matrix_3x3_basic.h"
#include "particle_instance.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "sound_archive_load.h"
#include "01/MapObjects/map_object_model_nsbca_playing.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/bound.h"
#include "01/MapObjects/kuriking_state_shared.h"
#include "Main/System/init_after_startup.h"

Vec3 gItemKinokoUpNormal = {0, 0x1000, 0};
Vec3 gItemBombUpNormal = {0, 0x1000, 0};
MapObjectKindDescriptor gEmptyMapObjectKindDescriptor = {0,
                                                         {0, 0},
                                                         0xa0,
                                                         NULL,
                                                         CreateEmptyMapObjectKindData,
                                                         NULL,
                                                         NULL,
                                                         NULL,
                                                         CreateEmptyMapObjectUpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};
u16 gShadowScaleToggle;

void SetAnimationFrameCallback(MissionRunMapObject *mapObject, s32 frameIndex, MissionRunMapObjectCallback callback) {
    mapObject->mAnimationFrameCallbackFrameIndex = frameIndex;
    mapObject->mAnimationFrameCallback = callback;
}

void SetTwoAnimationFrameCallbacks(MissionRunMapObject *mapObject, s32 firstFrameIndex, MissionRunMapObjectCallback firstCallback,
                                   s32 secondFrameIndex, MissionRunMapObjectCallback secondCallback) {
    mapObject->mFirstCallbackFrameIndex = firstFrameIndex;
    mapObject->mFirstFrameCallback = firstCallback;
    mapObject->mSecondCallbackFrameIndex = secondFrameIndex;
    mapObject->mSecondFrameCallback = secondCallback;
}

void StartStateFrameCountCallback(MissionRunMapObject *mapObject, s32 frameCount, MissionRunMapObjectCallback callback) {
    mapObject->mStateFrameCount = frameCount;
    mapObject->mStateFrames = 0;
    if (callback == NULL) {
        callback = StopMapObjectState;
    }
    mapObject->mStateFrameCountCallback = callback;
}

void SetPointInRangeCallback(MissionRunMapObject *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             MissionRunMapObjectCallback callback) {
    MissionRunMapObjectCallback storedCallback;

    mapObject->mPointRadius = pointRadius;
    mapObject->mPointHalfAngle = pointHalfAngle;
    if (point != NULL) {
        mapObject->mPoint = *point;
    }
    storedCallback = callback;
    if (storedCallback == NULL) {
        storedCallback = StopMapObjectState;
    }
    mapObject->mPointInRangeCallback = storedCallback;
}

void SetStoppedCallback(MissionRunMapObject *mapObject, MissionRunMapObjectCallback callback) {
    if (callback == NULL) {
        callback = StopMapObjectState;
    }
    mapObject->mStoppedCallback = callback;
}

void SetCourseCollisionCallback(MissionRunMapObject *mapObject, MissionRunMapObjectCallback callback) {
    if (callback == NULL) {
        callback = StopMapObjectState;
    }
    mapObject->mCourseCollisionCallback = callback;
}

void SetUnusedCallback(MissionRunMapObject *mapObject, MissionRunMapObjectCallback callback) {
    if (callback == NULL) {
        callback = StopMapObjectState;
    }
    mapObject->mUnusedCallback = callback;
}

void SetPointInRangePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mPoint = *point;
    }
}

void StartAnimationNoEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep) {
    StartMapObjectModelNsbcaAnimation(mapObject->mNsbmd, (u16) animationEntry, frameStep, 0);
    mapObject->mAnimationEndCallback = NULL;
}

void StartAnimationWithEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep,
                                   MissionRunMapObjectCallback endCallback) {
    StartMapObjectModelNsbcaAnimation(mapObject->mNsbmd, (u16) animationEntry, frameStep, 1);
    if (endCallback == NULL) {
        endCallback = StopMapObjectState;
    }
    mapObject->mAnimationEndCallback = endCallback;
}

void SetAlphaLimitTargetAndPerCall(MissionRunMapObject *mapObject, s32 alphaLimitTarget, s32 alphaLimitPerCall) {
    mapObject->mAlphaLimitTarget = alphaLimitTarget;
    mapObject->mAlphaLimitPerCall = alphaLimitPerCall;
}

void SetScaleTargetAndPerCall(MissionRunMapObject *mapObject, s32 scaleTarget, s32 scalePerCall) {
    mapObject->mScaleTarget = scaleTarget;
    mapObject->mScalePerCall = scalePerCall;
}

void SetSpeedAndClearTarget(MissionRunMapObject *mapObject, s32 speed) {
    mapObject->mSpeed = speed;
    mapObject->mSpeedTarget = 0;
    mapObject->mSpeedPerCall = 0;
}

void SetSpeedTargetAndPerCall(MissionRunMapObject *mapObject, s32 speedTarget, s32 speedPerCall) {
    mapObject->mSpeedTarget = speedTarget;
    mapObject->mSpeedPerCall = speedPerCall;
}

void StopTurningMoveFollowsAngle(MissionRunMapObject *mapObject) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_NONE;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnToPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnAndMoveToPointSameRate(MissionRunMapObject *mapObject, s32 perCallTarget, s32 perCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = perCallTarget;
    mapObject->mAnglePerCallIncrement = perCallIncrement;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_TURN_TO_POINT;
    mapObject->mMoveAnglePerCallTarget = perCallTarget;
    mapObject->mMoveAnglePerCallIncrement = perCallIncrement;
}

void TurnFromPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_FROM_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void StopTurningMoveFromPoint(MissionRunMapObject *mapObject, s32 moveAnglePerCallTarget,
                              s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_NONE;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_TURN_FROM_POINT;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void TurnSidewaysMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                  s32 angleOffset) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_SIDEWAYS;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mAngleOffset = angleOffset;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnToPointMoveSideways(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                             s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement, s32 moveAngleOffset) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_TURN_SIDEWAYS;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
    mapObject->mMoveAngleOffset = moveAngleOffset;
}

void SpinAngleStopMoveAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_SPIN_ADD;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mAngleOffset = 0;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_KEEP;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void SpinTowardPointMoveToPoint(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    s32 angleState;

    if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_NEGATIVE) {
        angleState = MAP_OBJECT_ANGLE_SPIN_NEGATIVE;
    } else if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_POSITIVE) {
        angleState = MAP_OBJECT_ANGLE_SPIN_POSITIVE;
    } else {
        angleState = MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION;
    }
    mapObject->mAngleState = angleState;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mAngleOffset = 0;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_TURN_TO_POINT;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void TurnAndMoveToPointOwnRates(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mAngleOffset = 0;
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_TURN_TO_POINT;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void StopMoveAngleTurning(MissionRunMapObject *mapObject) {
    mapObject->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_KEEP;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void SetAnglePointAndMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mMoveAnglePoint = *point;
        mapObject->mAnglePoint = *point;
    }
}

void SetMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mMoveAnglePoint = *point;
    }
}

void SetAnglePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mAnglePoint = *point;
    }
}

void SetVelocity(MissionRunMapObject *mapObject, Vec3 *velocity) {
    if (velocity != NULL) {
        mapObject->mVelocity = *velocity;
    }
}

void SetShadowOffsetYAndScale(MissionRunMapObject *mapObject, s32 offsetY, s32 scaleXZ) {
    if (offsetY == 0) {
        mapObject->mShadowMode = MAP_OBJECT_SHADOW_ON_COURSE_Y_ZERO;
    } else {
        mapObject->mShadowMode = MAP_OBJECT_SHADOW_AT_OBJECT;
    }
    mapObject->mShadowOffsetX = mapObject->mShadowOffsetTargetX = 0;
    mapObject->mShadowOffsetY = mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetZ = mapObject->mShadowOffsetTargetZ = 0;
    mapObject->mShadowOffsetPerCall = 0;
    mapObject->mShadowScaleX = mapObject->mShadowScaleTargetX = scaleXZ;
    mapObject->mShadowScaleY = mapObject->mShadowScaleTargetY = TO_FIXED12(10);
    mapObject->mShadowScaleZ = mapObject->mShadowScaleTargetZ = scaleXZ;
    mapObject->mShadowScalePerCall = 0;
}

void SetShadowOffsetYAndScaleTarget(MissionRunMapObject *mapObject, int offsetY, u32 offsetPerCall, u32 scaleXZ,
                                    u32 scalePerCall) {
    if (offsetY == 0) {
        mapObject->mShadowMode = MAP_OBJECT_SHADOW_ON_COURSE_Y_ZERO;
    } else {
        mapObject->mShadowMode = MAP_OBJECT_SHADOW_AT_OBJECT;
    }
    mapObject->mShadowOffsetTargetX = 0;
    mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetTargetZ = 0;
    mapObject->mShadowOffsetPerCall = offsetPerCall;
    mapObject->mShadowScaleTargetX = scaleXZ;
    mapObject->mShadowScaleTargetY = (0x0000a000u);
    mapObject->mShadowScaleTargetZ = scaleXZ;
    mapObject->mShadowScalePerCall = scalePerCall;
}

void SetCollisionOffsetAndExtent(MissionRunMapObject *mapObject, s32 offsetY, s32 extentXZ, s32 extentY) {
    if (extentY == 0) {
        mapObject->mCollisionShape = MAP_OBJECT_COLLISION_SPHERE;
    } else {
        mapObject->mCollisionShape = MAP_OBJECT_COLLISION_CYLINDER;
    }
    mapObject->mOffset.x = mapObject->mOffsetTargetX = 0;
    mapObject->mOffset.y = mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffset.z = mapObject->mOffsetTargetZ = 0;
    mapObject->mOffsetPerCall = 0;
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = extentXZ;
    mapObject->mCollisionExtent.y = mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtent.z = mapObject->mCollisionExtentTargetZ = extentXZ;
    mapObject->mCollisionExtentPerCall = 0;
    mapObject->mPosWithOffset.x = mapObject->mMapObject.mPos.x + mapObject->mOffset.x;
    mapObject->mPosWithOffset.y = mapObject->mMapObject.mPos.y + mapObject->mOffset.y;
    mapObject->mPosWithOffset.z = mapObject->mMapObject.mPos.z + mapObject->mOffset.z;
}

void SetCollisionOffsetAndExtentTarget(MissionRunMapObject *mapObject, u32 offsetY, u32 offsetPerCall, u32 extentXZ,
                                       int extentY, u32 extentPerCall) {
    if (extentY == 0) {
        mapObject->mCollisionShape = MAP_OBJECT_COLLISION_SPHERE;
    } else {
        mapObject->mCollisionShape = MAP_OBJECT_COLLISION_CYLINDER;
    }
    mapObject->mOffsetTargetX = 0;
    mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffsetTargetZ = 0;
    mapObject->mOffsetPerCall = offsetPerCall;
    mapObject->mCollisionExtentTargetX = extentXZ;
    mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtentTargetZ = extentXZ;
    mapObject->mCollisionExtentPerCall = extentPerCall;
}

void SetShadowOffsetAndScale(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 scaleX,
                             u32 unusedScaleY, u32 scaleZ) {
    int *shadowTargetPtr;
    int *shadowOffsetTargetXPtr;
    mapObject->mShadowMode = MAP_OBJECT_SHADOW_ON_COURSE_OFFSETS;
    if ((mapObject->mMapObject.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    shadowOffsetTargetXPtr = &mapObject->mShadowOffsetTargetX;
    *shadowOffsetTargetXPtr = offsetX;
    mapObject->mShadowOffsetX = *shadowOffsetTargetXPtr;
    shadowTargetPtr = &mapObject->mShadowOffsetTargetY;
    *shadowTargetPtr = offsetY;
    mapObject->mShadowOffsetY = *shadowTargetPtr;
    shadowTargetPtr = &mapObject->mShadowOffsetTargetZ;
    *shadowTargetPtr = offsetZ;
    mapObject->mShadowOffsetZ = *shadowTargetPtr;
    mapObject->mShadowOffsetPerCall = 0;
    shadowTargetPtr = &mapObject->mShadowScaleTargetX;
    *shadowTargetPtr = scaleX;
    mapObject->mShadowScaleX = *shadowTargetPtr;
    shadowTargetPtr = &mapObject->mShadowScaleTargetY;
    *shadowTargetPtr = (0x0000a000u);
    mapObject->mShadowScaleY = *shadowTargetPtr;
    shadowTargetPtr = &mapObject->mShadowScaleTargetZ;
    *shadowTargetPtr = scaleZ;
    mapObject->mShadowScaleZ = *shadowTargetPtr;
    mapObject->mShadowScalePerCall = 0;
}

void SetShadowOffsetAndScaleTarget(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                   u32 offsetPerCall, u32 scaleX, u32 unusedScaleY, u32 scaleZ, u32 scalePerCall) {
    mapObject->mShadowMode = MAP_OBJECT_SHADOW_ON_COURSE_OFFSETS;
    if ((mapObject->mMapObject.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mShadowOffsetTargetX = offsetX;
    mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetTargetZ = offsetZ;
    mapObject->mShadowOffsetPerCall = offsetPerCall;
    mapObject->mShadowScaleTargetX = scaleX;
    mapObject->mShadowScaleTargetY = (0x0000a000u);
    mapObject->mShadowScaleTargetZ = scaleZ;
    mapObject->mShadowScalePerCall = scalePerCall;
}

void SetCollisionBoxOffsetAndExtent(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ, u32 extentX,
                                    u32 extentY, u32 extentZ) {
    int *offsetXPtr;
    int *targetXOrOffsetYPtr;
    int *targetYOrOffsetZPtr;
    int *targetZPtr;
    int *extentTargetPtr;
    mapObject->mCollisionShape = MAP_OBJECT_COLLISION_BOX;
    if ((mapObject->mMapObject.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    targetXOrOffsetYPtr = &mapObject->mOffsetTargetX;
    *targetXOrOffsetYPtr = offsetX;
    offsetXPtr = &mapObject->mOffset.x;
    *offsetXPtr = *targetXOrOffsetYPtr;
    targetYOrOffsetZPtr = &mapObject->mOffsetTargetY;
    *targetYOrOffsetZPtr = offsetY;
    targetXOrOffsetYPtr = &mapObject->mOffset.y;
    *targetXOrOffsetYPtr = *targetYOrOffsetZPtr;
    targetZPtr = &mapObject->mOffsetTargetZ;
    *targetZPtr = offsetZ;
    targetYOrOffsetZPtr = &mapObject->mOffset.z;
    *targetYOrOffsetZPtr = *targetZPtr;
    mapObject->mOffsetPerCall = 0;
    extentTargetPtr = &mapObject->mCollisionExtentTargetX;
    *extentTargetPtr = extentX;
    mapObject->mCollisionExtent.x = *extentTargetPtr;
    extentTargetPtr = &mapObject->mCollisionExtentTargetY;
    *extentTargetPtr = extentY;
    mapObject->mCollisionExtent.y = *extentTargetPtr;
    extentTargetPtr = &mapObject->mCollisionExtentTargetZ;
    *extentTargetPtr = extentZ;
    mapObject->mCollisionExtent.z = *extentTargetPtr;
    mapObject->mCollisionExtentPerCall = 0;
    mapObject->mPosWithOffset.x = mapObject->mMapObject.mPos.x + *offsetXPtr;
    mapObject->mPosWithOffset.y = mapObject->mMapObject.mPos.y + *targetXOrOffsetYPtr;
    mapObject->mPosWithOffset.z = mapObject->mMapObject.mPos.z + *targetYOrOffsetZPtr;
}

void SetCollisionBoxOffsetAndExtentTarget(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                          u32 offsetPerCall, u32 extentX, u32 extentY, u32 extentZ, u32 extentPerCall) {
    mapObject->mCollisionShape = MAP_OBJECT_COLLISION_BOX;
    if ((mapObject->mMapObject.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mOffsetTargetX = offsetX;
    mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffsetTargetZ = offsetZ;
    mapObject->mOffsetPerCall = offsetPerCall;
    mapObject->mCollisionExtentTargetX = extentX;
    mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtentTargetZ = extentZ;
    mapObject->mCollisionExtentPerCall = extentPerCall;
}

void ResetMissionRunMapObjects(void) {
    u16 objectIndex;
    MissionRunMapObject *obj;
    MissionRunMapObject *tableObj;
    MapObjectList *table;

    if (!(gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0)) {
        for (objectIndex = gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : (u8) 0;
             objectIndex <= (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunMapObjectLastIndex() : (u16) 0);
             objectIndex++) {
            obj = gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunMapObject(objectIndex) : 0;
            table = FindMapObjectKindUpdateList(0x1ff);
            StopMapObjectState(obj);
            obj->mGravityEnabled = FALSE;
            obj->mCourseCollisionMode = MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY;
            obj->mSpeed = obj->mSpeedTarget = obj->mSpeedPerCall = 0;
            obj->mAngleState = MAP_OBJECT_ANGLE_NONE;
            obj->mAnglePerCall = obj->mAnglePerCallTarget = obj->mAnglePerCallIncrement = 0;
            obj->mMoveAngleMode = MAP_OBJECT_MOVE_ANGLE_KEEP;
            obj->mMoveAnglePerCall = obj->mMoveAnglePerCallTarget = obj->mMoveAnglePerCallIncrement = 0;
            obj->mVelocity.x = obj->mVelocity.y = obj->mVelocity.z = 0;
            obj->mAlphaLimit = obj->mAlphaLimitTarget = TO_FIXED12(MAP_OBJECT_ALPHA_MAX);
            obj->mAlphaLimitPerCall = 0;
            if (objectIndex - (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) <
                table->mMapObjectCount) {
                tableObj =
                    table->mMapObjects[objectIndex -
                                       (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)];
                obj->mMapObject.mPos = tableObj->mMapObject.mCourseMapRow->mPosition;
                tableObj =
                    table->mMapObjects[objectIndex -
                                       (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)];
                obj->mAngle = DEG_TO_ANGLE(tableObj->mMapObject.mCourseMapRow->mRotationDegrees.y);
            }
        }
    }
    ResetBalloons();
}

u32 IncrementHitCountAndCheckLimit(MissionRunMapObject *mapObject) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunCountForHit();
    }
    mapObject->mCounter++;
    if (mapObject->mCounter >= mapObject->mPrm->mHead.mCounterLimit) {
        mapObject->mCounter = mapObject->mPrm->mHead.mCounterLimit;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            EliminateKartsUntilWinnerDecided();
        }
        return 1;
    }
    return 0;
}

BOOL DecrementCounterToNegativeLimit(MissionRunMapObject *mapObject) {
    s32 limit;

    mapObject->mCounter--;
    limit = -mapObject->mPrm->mHead.mCounterLimit;
    if (mapObject->mCounter <= limit) {
        mapObject->mCounter = limit;
        return TRUE;
    }
    return FALSE;
}

u16 GetAbsoluteCounter(MissionRunMapObject *mapObject) {
    s32 counter;
    counter = mapObject->mCounter;
    if (counter < 0) {
        counter = -counter;
    }
    return counter & 0xffff;
}

void SetRepeatsRemaining(MissionRunMapObject *mapObject, u16 repeatsRemaining) {
    mapObject->mRepeatsRemaining = repeatsRemaining;
}

u16 GetRepeatsRemaining(MissionRunMapObject *mapObject) {
    return mapObject->mRepeatsRemaining;
}

void SetKartCollisionCallback(MissionRunMapObject *mapObject, MissionRunMapObjectKartCollisionCallback kartCollisionCallback) {
    mapObject->mKartCollisionCallback = kartCollisionCallback;
}

void SetItemCollisionCallback(MissionRunMapObject *mapObject, MissionRunMapObjectItemCollisionCallback itemCollisionCallback) {
    mapObject->mItemCollisionCallback = itemCollisionCallback;
}

BOOL IsPointInRange(MissionRunMapObject *mapObject, Vec3 *point, s32 radius, s32 halfAngle) {
    if ((radius != 0 || halfAngle != 0) && (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, point, radius) != 0) &&
        (halfAngle == 0 || IsDirectionToPointWithinAngle(mapObject, mapObject->mMoveAngle, point, halfAngle) != 0)) {
        return TRUE;
    }
    return FALSE;
}

ItemBomb *FindItemBombInRange(MissionRunMapObject *mapObject, u32 radius, u32 halfAngle) {
    int bombCount;
    ItemBomb *bomb;
    int inRange;
    int index;
    bombCount = GetItemBombActiveCount();
    index = 0;
    if (0 < bombCount) {
        do {
            bomb = GetRestingItemBomb(index);
            if ((bomb != NULL) &&
                (inRange = IsPointInRange(mapObject, &bomb->mBouncingItemObject.mItemObject.mPos, radius, halfAngle),
                 inRange != 0)) {
                return bomb;
            }
            index = index + 1;
        } while (index < bombCount);
    }
    return NULL;
}

Kart *GetEntryKartInRange(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && IsPointInRange(mapObject, &kart->mPos, radius, halfAngle) != FALSE &&
        (kart->mDriveFlags & KART_DRIVE_SINKING) == 0) {
        return kart;
    }
    return NULL;
}

Kart *GetEntryKartInAngleRange(MissionRunMapObject *mapObject, s32 angleOffset, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mDriveFlags & KART_DRIVE_SINKING) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 || IsDirectionToPointWithinAngle(mapObject, mapObject->mAngle + angleOffset, &kart->mPos,
                                                                halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

Kart *GetEntryKartFacingObject(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mDriveFlags & KART_DRIVE_SINKING) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 ||
                IsDirectionToPointWithinAngle(mapObject, kart->mHeadingAngle + ANGLE_HALF_TURN, &kart->mPos,
                    halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

CourseMapGroupEntry *GetCurrentGroupEntry(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex);
    }
    return NULL;
}

s32 GetCurrentGroupEntryValue(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mValue;
    }
    return 0;
}

s32 GetCurrentGroupEntryPercent(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mExtraValue;
    }
    return 0;
}

CourseMapGroupEntry *GetNextGroupEntry(MissionRunMapObject *mapObject) {
    CourseMap *courseMap = gCourseMap;
    s32 nextEntryIndex;

    if (mapObject->mEntryGroupIndex < courseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= GetCourseMapEntryGroup(mapObject->mEntryGroupIndex)->mEntryCount) {
            nextEntryIndex = 0;
        }
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, nextEntryIndex);
    }
    return NULL;
}

void DecrementEntryIndexSkipZero(MissionRunMapObject *mapObject) {
    CourseMap *courseMap;
    CourseMapEntryGroup *entryGroup;
    s32 groupIndex;
    s32 entryIndex;

    courseMap = gCourseMap;
    groupIndex = mapObject->mEntryGroupIndex;
    if (groupIndex < courseMap->mEntryGroupCount) {
        entryGroup = &courseMap->mEntryGroups[(u16) groupIndex];
        entryIndex = mapObject->mEntryIndex - 1;
        if (entryIndex <= 0) {
            entryIndex = entryGroup->mEntryCount - 1;
        }
        mapObject->mEntryIndex = entryIndex;
    }
}

void IncrementEntryIndex(MissionRunMapObject *mapObject) {
    int nextEntryIndex;

    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= GetCourseMapEntryGroup(mapObject->mEntryGroupIndex)->mEntryCount) {
            nextEntryIndex = 0;
        }
        mapObject->mEntryIndex = nextEntryIndex;
    }
}

void IncrementEntryGroupIndex(MissionRunMapObject *mapObject, s32 groupSpan) {
    s32 firstGroupIndex;
    s32 nextGroupIndex;

    firstGroupIndex = mapObject->mMapObject.mCourseMapRow->mGroupIndex;
    nextGroupIndex = mapObject->mEntryGroupIndex + 1;
    if (nextGroupIndex >= firstGroupIndex + groupSpan) {
        nextGroupIndex = firstGroupIndex;
    }
    mapObject->mEntryGroupIndex = (u16) nextGroupIndex;
    mapObject->mEntryIndex = 0;
}

void *StartItemBombWithParkedItemBox(u16 forcedRow) {
    ItemBox *parkedMapObject;

    parkedMapObject = FindParkedMapObject(MAP_OBJECT_KIND_GROUP_ITEM_BOX);
    if (parkedMapObject != NULL) {
        SetItemBoxFramesSinceHitMax(parkedMapObject);
        parkedMapObject->mForcedRowHumanGhostPeer = forcedRow;
        parkedMapObject->mForcedRowCpu = forcedRow;
        parkedMapObject->mShortSpin = 1;
        return StartItemBombWithMapObject(parkedMapObject, 0xa000);
    }
    return NULL;
}

void *StartItemBombWithParkedKuribo(void) {
    void *parkedMapObject;

    parkedMapObject = FindParkedMapObject(MAP_OBJECT_KIND_KURIBO);
    if (parkedMapObject != NULL) {
        ResetKuriboForItemBomb(parkedMapObject);
        return StartItemBombWithMapObject(parkedMapObject, 0);
    }
    return NULL;
}

void StoreNodePositionAndPlaceItemBomb(NNSG3dRS *renderState) {
    MtxFx43 currentMatrix;
    MtxFx43 inverseViewMatrix;
    Vec3 bombPosition;
    MissionRunMapObject *mapObject;
    Camera *currentCamera;

    mapObject = renderState->mRenderObj->mPtrUser;
    if (renderState->mC[1] == mapObject->mNodeMatchValue) {
        currentCamera = GetCurrentCamera();
        NNS_G3dGetCurrentMtx(&currentMatrix, NULL);
        MTX_Inverse43(&currentCamera->mViewMatrix, &inverseViewMatrix);
        MTX_Concat43(&currentMatrix, &inverseViewMatrix, &currentMatrix);
        mapObject->mNodePosition.x = currentMatrix.mRows[3].x << 4;
        mapObject->mNodePosition.y = currentMatrix.mRows[3].y << 4;
        mapObject->mNodePosition.z = currentMatrix.mRows[3].z << 4;
        if (mapObject->mItemBomb != NULL) {
            bombPosition = mapObject->mNodePosition;
            VEC_MultAdd(mapObject->mBombOffset.x, &currentMatrix.mRows[0], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->mBombOffset.y, &currentMatrix.mRows[1], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->mBombOffset.z, &currentMatrix.mRows[2], &bombPosition, &bombPosition);
            PlaceItemBomb(mapObject->mItemBomb, &currentMatrix.mRows[0], &bombPosition);
        }
    }
}

void SetNodePositionSource(MissionRunMapObject *mapObject, u32 matchValue) {
    MapObjectModel **nsbmdPointer;
    mapObject->mNodeMatchValue = matchValue;
    mapObject->mShadowMode = MAP_OBJECT_SHADOW_AT_NODE;
    nsbmdPointer = &mapObject->mNsbmd;
    (*nsbmdPointer)->mAnimatedModel->mRenderObj.mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack(&(*nsbmdPointer)->mAnimatedModel->mRenderObj, StoreNodePositionAndPlaceItemBomb, 0, 6,
                                (u8) 3);
}

void SetNodePositionSourceAndBombOffset(MissionRunMapObject *mapObject, s32 matchValue, const Vec3 *offset) {
    mapObject->mNodeMatchValue = matchValue;
    mapObject->mBombOffset = *offset;
    mapObject->mNsbmd->mAnimatedModel->mRenderObj.mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack(&mapObject->mNsbmd->mAnimatedModel->mRenderObj, StoreNodePositionAndPlaceItemBomb, 0, 6,
                                3);
}

void ReleaseAndSetItemBomb(MissionRunMapObject *mapObject, void *itemBomb) {
    if (mapObject->mItemBomb != NULL) {
        ReleaseItemBomb(&mapObject->mItemBomb);
    }
    mapObject->mItemBomb = itemBomb;
}

u32 IsItemBombStored(MissionRunMapObject *mapObject) {
    if (mapObject->mItemBomb != NULL) {
        return 1;
    }
    return 0;
}

void ThrowOrReleaseStoredItemBomb(MissionRunMapObject *mapObject, Vec3 *velocity, s32 timer) {
    Vec3 zeroVelocity;
    s32 *zeroWords;

    if (mapObject->mItemBomb != NULL) {
        if (((ItemBomb *) mapObject->mItemBomb)->mBouncingItemObject.mItemObject.mPos.y < 0x64000) {
            ReleaseItemBomb(&mapObject->mItemBomb);
        } else if (velocity != NULL) {
            ThrowItemBombFromSlot(&mapObject->mItemBomb, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            ThrowItemBombFromSlot(&mapObject->mItemBomb, &zeroVelocity, timer);
        }
    }
}

void ThrowItemBombFromPosition(void *bomb, Vec3 *position, Vec3 *velocity, s32 timer) {
    Vec3 upNormal;
    Vec3 zeroVelocity;
    Vec3 *normalPointer;
    s32 *zeroWords;

    if (bomb != NULL && position != NULL) {
        upNormal = gItemBombUpNormal;
        normalPointer = &upNormal;
        PlaceItemBomb(bomb, normalPointer, position);
        if (velocity != NULL) {
            ThrowItemBombFromSlot(&bomb, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            ThrowItemBombFromSlot(&bomb, &zeroVelocity, timer);
        }
    }
}

void ThrowItemKinokoFromPosition(void *kinoko, Vec3 *position, Vec3 *velocity, s32 timer) {
    Vec3 upNormal;
    Vec3 zeroVelocity;
    Vec3 *normalPointer;
    s32 *zeroWords;

    if (kinoko != NULL && position != NULL) {
        upNormal = gItemKinokoUpNormal;
        normalPointer = &upNormal;
        ShowItemKinokoAt(kinoko, normalPointer, position);
        if (velocity != NULL) {
            StartBouncingItemKinoko(&kinoko, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            StartBouncingItemKinoko(&kinoko, &zeroVelocity, timer);
        }
    }
}

void ReleaseEffects(MissionRunMapObject *mapObject) {
    s32 effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
        }
    }
    mapObject->mUnk_0b8 = 0;
}

// Writes a point for one entry of the object's table; the entry's type (1-5) picks how, others write nothing.
void ComputeEffectPosition(MissionRunMapObject *mapObject, int effectIndex, Vec3 *position) {
    Camera *camera;
    s32 scaledX;
    s32 scaledY;
    s32 scaledZ;
    s32 offsetComponent;

    switch (mapObject->mEffects[effectIndex].mKind) {
        case MAP_OBJECT_EFFECT_ROTATED_OFFSET:
            position->x = mapObject->mMapObject.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mMapObject.mPos.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mMapObject.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            break;
        case MAP_OBJECT_EFFECT_ROTATED_OFFSET_CAMERA:
            // As case 1 with mUnk_024 of the object from GetCurrentCamera added, then halved.
            camera = GetCurrentCamera();
            position->x = mapObject->mMapObject.mPos.x + camera->mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mMapObject.mPos.y + camera->mPos.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mMapObject.mPos.z + camera->mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            position->x >>= 1;
            position->y >>= 1;
            position->z >>= 1;
            break;
        case MAP_OBJECT_EFFECT_SCALED_OFFSET:
            // The entry's mOffset is first multiplied per component by the object's mScale.
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.y;
            scaledY = MUL_FIXED12_NO_ROUND(offsetComponent, mapObject->mMapObject.mScale.y);
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.x;
            scaledX = MUL_FIXED12_NO_ROUND(offsetComponent, mapObject->mMapObject.mScale.x);
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.z;
            scaledZ = MUL_FIXED12_NO_ROUND(offsetComponent, mapObject->mMapObject.mScale.z);
            position->x = mapObject->mMapObject.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(scaledZ, FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(scaledX, FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mMapObject.mPos.y + scaledY;
            position->z = mapObject->mMapObject.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(scaledZ, FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(scaledX, FX_SinIdx((u16) mapObject->mAngle)));
            break;
        case MAP_OBJECT_EFFECT_ROW_HEIGHT:
            position->x = mapObject->mMapObject.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mMapObject.mCourseMapRow->mPosition.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mMapObject.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            break;
        case MAP_OBJECT_EFFECT_WATER_HEIGHT:
            position->x = mapObject->mMapObject.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mEffects[effectIndex].mOffset.y - GetHeightAboveWaterOrEfct(0);
            position->z = mapObject->mMapObject.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            break;
    }
}

void StartEffectInSlot(MissionRunMapObject *mapObject, s32 effectIndex, s32 offsetX, s32 offsetY, s32 offsetZ,
                       u32 effectId, s32 timer) {
    Vec3 position;

    mapObject->mEffects[effectIndex].mTimer = timer;
    if ((mapObject->mMapObject.mFlags & MAP_OBJECT_FLAG_MIRRORED) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mEffects[effectIndex].mOffset.x = offsetX << 4;
    mapObject->mEffects[effectIndex].mOffset.y = offsetY << 4;
    mapObject->mEffects[effectIndex].mOffset.z = offsetZ << 4;
    ComputeEffectPosition(mapObject, effectIndex, &position);
    if (effectId != 0) {
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
        }
        mapObject->mEffects[effectIndex].mEffect = StartEffect(effectId, &position);
    }
}

void StartEffectAtOffset(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                         u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = MAP_OBJECT_EFFECT_ROTATED_OFFSET;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtScaledOffset(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                               u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = MAP_OBJECT_EFFECT_SCALED_OFFSET;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtRowHeight(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                            u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = MAP_OBJECT_EFFECT_ROW_HEIGHT;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtWaterHeight(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                              u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = MAP_OBJECT_EFFECT_WATER_HEIGHT;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartModelEffectAtWaterHeight(MissionRunMapObject *mapObject, u32 modelEffectKind, int timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mOffset.x = mapObject->mMapObject.mPos.x;
            mapObject->mEffects[effectIndex].mOffset.y = -GetHeightAboveWaterOrEfct(0);
            mapObject->mEffects[effectIndex].mOffset.z = mapObject->mMapObject.mPos.z;
            if (mapObject->mEffects[effectIndex].mEffect != NULL) {
                StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
            }
            StartModelEffect(modelEffectKind, &mapObject->mEffects[effectIndex].mOffset, 1);
            mapObject->mEffects[effectIndex].mKind = MAP_OBJECT_EFFECT_MODEL;
            mapObject->mEffects[effectIndex].mTimer = timer;
            return;
        }
    }
}

void SetEffectDirection(ParticleEmitter *emitter, const Vec3s16 *direction) {
    emitter->mDirection = *direction;
}

void StartEffectWithRotatedDirection(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ,
                                     int emitterParamX, int emitterParamY, int emitterParamZ, int effectId, u32 timer) {
    int effectIndex;
    Vec3 position;
    Vec3s16 emitterParams;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = MAP_OBJECT_EFFECT_ROTATED_OFFSET;
            mapObject->mEffects[effectIndex].mTimer = timer;
            mapObject->mEffects[effectIndex].mOffset.x = offsetX << 4;
            mapObject->mEffects[effectIndex].mOffset.y = offsetY << 4;
            mapObject->mEffects[effectIndex].mOffset.z = offsetZ << 4;
            ComputeEffectPosition(mapObject, effectIndex, &position);
            if (effectId != 0) {
                if (mapObject->mEffects[effectIndex].mEffect != NULL) {
                    StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
                }
                emitterParams.x = (MUL_FIXED12_NO_ROUND(emitterParamZ, FX_SinIdx((u16) mapObject->mAngle))) +
                                  (MUL_FIXED12_NO_ROUND(emitterParamX, FX_CosIdx((u16) mapObject->mAngle)));
                emitterParams.y = emitterParamY;
                emitterParams.z = (MUL_FIXED12_NO_ROUND(emitterParamZ, FX_CosIdx((u16) mapObject->mAngle))) -
                                  (MUL_FIXED12_NO_ROUND(emitterParamX, FX_SinIdx((u16) mapObject->mAngle)));
                StartEffectWithCallback(effectId, &position, &emitterParams, SetEffectDirection);
            }
        }
    }
}

void StartMapObjectState(MissionRunMapObject *mapObject, int stateNumber, s32 (*nextFunc)(MissionRunMapObject *)) {
    mapObject->mStateFunction = NULL;
    mapObject->mNextStateFunction = nextFunc;
    mapObject->mStateNumber = stateNumber;
    mapObject->mStateFrames = 0;
    mapObject->mRepeatsRemaining = mapObject->mRepeatsRemaining > 0 ? mapObject->mRepeatsRemaining - 1 : 0;
    mapObject->mBounceEnabled = FALSE;
    mapObject->mGravityEnabled = TRUE;
    if (mapObject->mKeepCallbacks == FALSE) {
        mapObject->mAnimationFrameCallbackFrameIndex = 0;
        mapObject->mAnimationEndCallback = NULL;
        mapObject->mAnimationFrameCallback = NULL;
        mapObject->mFirstCallbackFrameIndex = 0;
        mapObject->mFirstFrameCallback = NULL;
        mapObject->mSecondCallbackFrameIndex = 0;
        mapObject->mSecondFrameCallback = NULL;
        mapObject->mStateFrameCount = 0;
        mapObject->mStateFrameCountCallback = NULL;
        mapObject->mPointInRangeCallback = NULL;
        mapObject->mOutOfRangeCallback = NULL;
        mapObject->mStoppedCallback = NULL;
        mapObject->mCourseCollisionCallback = NULL;
        ReleaseEffects(mapObject);
    }
}

void DisableMissionRunMapObjectGravity(MissionRunMapObject *mapObject) {
    mapObject->mGravityEnabled = FALSE;
}

u32 IsStateNumberBelow(MissionRunMapObject *mapObject, int stateNumberLimit) {
    if (mapObject->mStateNumber < stateNumberLimit) {
        return 1;
    }
    return 0;
}

BOOL IsNotRisingWithBelowZeroBit(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & COURSE_HIT_NOT_RISING_BIT) != 0 && mapObject->mVelocity.y <= 0) {
        return TRUE;
    }
    return FALSE;
}

void InitMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject, const char *nsbmdName,
                             const char *nsbcaName, const char *prmName) {
    if (mapObjectList != NULL && nsbmdName != NULL) {
        mapObject->mNsbmd = LoadMapObjectModelAnimated(mapObjectList, nsbmdName);
        if (nsbcaName != NULL) {
            LoadMapObjectModelNsbcaAnimation(mapObject->mNsbmd, nsbcaName);
        }
    }
    if (prmName != NULL) {
        mapObject->mPrm = LoadMissionRunFile(prmName);
    }
    mapObject->mAngle = DEG_TO_ANGLE(mapObject->mMapObject.mCourseMapRow->mRotationDegrees.y);
    mapObject->mAlphaLimit = TO_FIXED12(MAP_OBJECT_ALPHA_MAX);
    if (mapObject->mPrm != NULL) {
        SetMapObjectExtentX(&mapObject->mMapObject, mapObject->mPrm->mHead.mCollisionExtentXZ << 2);
        mapObject->mMapObject.mScale.x = mapObject->mPrm->mHead.mScale;
        mapObject->mMapObject.mScale.y = mapObject->mPrm->mHead.mScale;
        mapObject->mMapObject.mScale.z = mapObject->mPrm->mHead.mScale;
    }
    mapObject->mPosWithOffset = mapObject->mMapObject.mPos;
    mapObject->mBounceEnabled = FALSE;
    mapObject->mGravityEnabled = TRUE;
    mapObject->mEntryGroupIndex = mapObject->mMapObject.mCourseMapRow->mGroupIndex;
}

void LoadMissionRunMapObjectShadow(void *mapObjectList, MissionRunMapObject *mapObject, const char *shadowNsbmdName) {
    if (mapObjectList != NULL && shadowNsbmdName != NULL) {
        mapObject->mShadowNsbmd = LoadMapObjectModelShadow(mapObjectList, shadowNsbmdName);
        SetMapObjectModelPolygonId(mapObject->mShadowNsbmd, 0x3f);
        gShadowScaleToggle = 0;
    }
}

void ToggleShadowScale(void) {
    if (gShadowScaleToggle == 0) {
        gShadowScaleToggle++;
    } else {
        gShadowScaleToggle = 0;
    }
}

int StepIntTowardTarget(int target, int step, int current) {
    int next;
    if (current < target) {
        next = current + step;
        if (current + step >= target) {
            next = target;
        }
        return next;
    }
    if (current > target) {
        next = current - step;
        if (current - step <= target) {
            next = target;
        }
        return next;
    }
    return current;
}

u16 StepAngleTowardDirection(Vec3 *target, Vec3 *origin, s32 maxStep, s32 angle) {
    s32 angleDifference = (u16) (FX_Atan2Idx(target->x - origin->x, target->z - origin->z) - angle);
    s32 turn;

    if (maxStep < 0) {
        maxStep = -maxStep;
    }
    if (angleDifference > ANGLE_HALF_TURN) {
        angleDifference -= ANGLE_FULL_TURN;
    }
    turn = -maxStep;
    if (angleDifference >= turn) {
        if (angleDifference <= maxStep) {
            maxStep = angleDifference;
        }
        turn = maxStep;
    }
    return angle + turn;
}

u16 StepAngleSidewaysToPoint(Vec3 *targetPoint, Vec3 *origin, s32 signedMaxStep, s32 angleOffset, s32 angle) {
    s32 angleDifference = (u16) (FX_Atan2Idx(targetPoint->x - origin->x, targetPoint->z - origin->z) - angle);
    s32 maxTurn;
    s32 turn;
    s32 targetDifference;

    if (signedMaxStep < 0) {
        maxTurn = -signedMaxStep;
    } else {
        maxTurn = signedMaxStep;
    }
    if (angleDifference > ANGLE_HALF_TURN) {
        angleDifference -= ANGLE_FULL_TURN;
    }
    if (signedMaxStep < 0) {
        angleDifference += angleOffset;
        targetDifference = angleDifference - ANGLE_QUARTER_TURN;
    } else {
        angleDifference -= angleOffset;
        targetDifference = angleDifference + ANGLE_QUARTER_TURN;
    }
    turn = -maxTurn;
    if (targetDifference >= turn) {
        if (targetDifference <= maxTurn) {
            maxTurn = targetDifference;
        }
        turn = maxTurn;
    }
    return angle + turn;
}

void AdvanceMissionRunMapObject(u32 unused, MissionRunMapObject *mapObject) {
    Vec3 probePosition;
    Vec3 pushOut;
    Vec3 groundNormal;
    Vec3 wallNormal;
    Vec3 pushDirection;
    Vec3 effectPosition;
    s32 velocityScale;
    s32 moveX;
    s32 moveY;
    s32 moveZ;
    s32 currentFrame;
    s32 previousFrame;
    s32 effectIndex;
    s32 pairWordIndex;
    s64 speed;

    if (mapObject->mStateFunction == NULL && mapObject->mNextStateFunction != NULL) {
        mapObject->mStateFunction = mapObject->mNextStateFunction;
        mapObject->mNextStateFunction = NULL;
    }
    if (mapObject->mStateFunction != NULL && mapObject->mStateFunction(mapObject)) {
        mapObject->mStateFunction = NULL;
        mapObject->mUnk_154 = 0;
        mapObject->mStateFrames = 0;
        mapObject->mStateNumber = 0;
    }

    switch (mapObject->mAngleState) {
        case MAP_OBJECT_ANGLE_FOLLOW_MOVE_ANGLE:
            mapObject->mAngle = mapObject->mMoveAngle;
            break;
        case MAP_OBJECT_ANGLE_TURN_TO_POINT:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleTowardDirection(&mapObject->mAnglePoint, &mapObject->mMapObject.mPos,
                                                             mapObject->mAnglePerCall, mapObject->mAngle);
            }
            break;
        case MAP_OBJECT_ANGLE_TURN_FROM_POINT:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleTowardDirection(&mapObject->mMapObject.mPos, &mapObject->mAnglePoint,
                                                             mapObject->mAnglePerCall, mapObject->mAngle);
            }
            break;
        case MAP_OBJECT_ANGLE_TURN_SIDEWAYS:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleSidewaysToPoint(&mapObject->mAnglePoint, &mapObject->mMapObject.mPos,
                                                             mapObject->mAnglePerCall, mapObject->mAngleOffset,
                                                             mapObject->mAngle);
            }
            break;
        case MAP_OBJECT_ANGLE_SPIN_ADD:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle += mapObject->mAnglePerCall;
            }
            break;
        case MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION:
        case MAP_OBJECT_ANGLE_SPIN_NEGATIVE:
        case MAP_OBJECT_ANGLE_SPIN_POSITIVE:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION) {
                if (StepAngleTowardDirection(&mapObject->mAnglePoint, &mapObject->mMapObject.mPos,
                                             mapObject->mAnglePerCall, mapObject->mAngle) -
                        mapObject->mAngle >=
                    0) {
                    mapObject->mAngleState = MAP_OBJECT_ANGLE_SPIN_POSITIVE;
                } else {
                    mapObject->mAngleState = MAP_OBJECT_ANGLE_SPIN_NEGATIVE;
                }
            }
            if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_POSITIVE) {
                mapObject->mAngle += mapObject->mAnglePerCall;
            } else if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_NEGATIVE) {
                mapObject->mAngle -= mapObject->mAnglePerCall;
            }
            break;
    }

    switch (mapObject->mMoveAngleMode) {
        case MAP_OBJECT_MOVE_ANGLE_FOLLOW_ANGLE:
            mapObject->mMoveAngle = mapObject->mAngle;
            break;
        case MAP_OBJECT_MOVE_ANGLE_TURN_TO_POINT:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle =
                    StepAngleTowardDirection(&mapObject->mMoveAnglePoint, &mapObject->mMapObject.mPos,
                                             mapObject->mMoveAnglePerCall, mapObject->mMoveAngle);
            }
            break;
        case MAP_OBJECT_MOVE_ANGLE_TURN_FROM_POINT:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle =
                    StepAngleTowardDirection(&mapObject->mMapObject.mPos, &mapObject->mMoveAnglePoint,
                                             mapObject->mMoveAnglePerCall, mapObject->mMoveAngle);
            }
            break;
        case MAP_OBJECT_MOVE_ANGLE_TURN_SIDEWAYS:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle = StepAngleSidewaysToPoint(
                    &mapObject->mMoveAnglePoint, &mapObject->mMapObject.mPos, mapObject->mMoveAnglePerCall,
                    mapObject->mMoveAngleOffset, mapObject->mMoveAngle);
            }
            break;
    }

    if (mapObject->mSpeedPerCall > 0) {
        mapObject->mSpeed = StepIntTowardTarget(mapObject->mSpeedTarget, mapObject->mSpeedPerCall, mapObject->mSpeed);
    }
    if (mapObject->mOffsetPerCall > 0) {
        mapObject->mOffset.x =
            StepIntTowardTarget(mapObject->mOffsetTargetX, mapObject->mOffsetPerCall, mapObject->mOffset.x);
        mapObject->mOffset.y =
            StepIntTowardTarget(mapObject->mOffsetTargetY, mapObject->mOffsetPerCall, mapObject->mOffset.y);
        mapObject->mOffset.z =
            StepIntTowardTarget(mapObject->mOffsetTargetZ, mapObject->mOffsetPerCall, mapObject->mOffset.z);
    }
    if (mapObject->mCollisionExtentPerCall > 0) {
        mapObject->mCollisionExtent.x = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetX, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.x);
        mapObject->mCollisionExtent.y = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetY, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.y);
        mapObject->mCollisionExtent.z = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetZ, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.z);
    }
    if (mapObject->mShadowOffsetPerCall > 0) {
        mapObject->mShadowOffsetX = StepIntTowardTarget(mapObject->mShadowOffsetTargetX,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetX);
        mapObject->mShadowOffsetY = StepIntTowardTarget(mapObject->mShadowOffsetTargetY,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetY);
        mapObject->mShadowOffsetZ = StepIntTowardTarget(mapObject->mShadowOffsetTargetZ,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetZ);
    }
    if (mapObject->mShadowScalePerCall > 0) {
        mapObject->mShadowScaleX = StepIntTowardTarget(mapObject->mShadowScaleTargetX, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleX);
        mapObject->mShadowScaleY = StepIntTowardTarget(mapObject->mShadowScaleTargetY, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleY);
        mapObject->mShadowScaleZ = StepIntTowardTarget(mapObject->mShadowScaleTargetZ, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleZ);
    }

    if (mapObject->mGravityEnabled != FALSE) {
        mapObject->mVelocity.y -= mapObject->mPrm->mHead.mGravity;
    }
    if (-mapObject->mPrm->mHead.mStopSpeedLimit < *(s32 *) &mapObject->mVelocity &&
        *(s32 *) &mapObject->mVelocity < mapObject->mPrm->mHead.mStopSpeedLimit &&
        -mapObject->mPrm->mHead.mStopSpeedLimit < mapObject->mVelocity.z &&
        mapObject->mVelocity.z < mapObject->mPrm->mHead.mStopSpeedLimit) {
        mapObject->mVelocity.x = 0;
        mapObject->mVelocity.z = 0;
    } else if (mapObject->mCollisionBits & COURSE_HIT_GROUND) {
        velocityScale = mapObject->mPrm->mHead.mGroundHitVelocityScale;
        mapObject->mVelocity.x = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.x, velocityScale);
        mapObject->mVelocity.y = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.y, velocityScale);
        mapObject->mVelocity.z = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.z, velocityScale);
    } else {
        velocityScale = mapObject->mPrm->mHead.mNoGroundHitVelocityScale;
        mapObject->mVelocity.x = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.x, velocityScale);
        mapObject->mVelocity.y = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.y, velocityScale);
        mapObject->mVelocity.z = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.z, velocityScale);
    }

    pairWordIndex = ((u16) mapObject->mMoveAngle >> 4) * 2;
    speed = mapObject->mSpeed;
    moveY = mapObject->mVelocity.y;
    moveZ = mapObject->mVelocity.z + (s32) ((speed * FX_SinCosTable_[pairWordIndex + 1]) >> 12);
    moveX = mapObject->mVelocity.x + (s32) ((speed * FX_SinCosTable_[pairWordIndex]) >> 12);
    mapObject->mMapObject.mPos.x += moveX;
    mapObject->mMapObject.mPos.y += moveY;
    mapObject->mMapObject.mPos.z += moveZ;

    probePosition.x = mapObject->mMapObject.mPos.x;
    probePosition.y = mapObject->mMapObject.mPos.y + 0x14000;
    probePosition.z = mapObject->mMapObject.mPos.z;
    mapObject->mCollisionBits = 0;
    if (CollideSphereWithCourse(
            &probePosition, NULL, 0, 0x14000,
            mapObject->mCourseCollisionMode == MAP_OBJECT_COURSE_COLLISION_ALT_FILTER ? (u16) 4 : (u16) 1, -2, &pushOut,
            &groundNormal, &wallNormal, &mapObject->mCollisionBits, NULL, NULL, NULL, NULL)) {
        if (mapObject->mCourseCollisionMode == MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY_NO_WALL ||
            mapObject->mCourseCollisionMode == MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY) {
            mapObject->mMapObject.mPos.y += pushOut.y;
        } else {
            mapObject->mMapObject.mPos.x += pushOut.x;
            mapObject->mMapObject.mPos.y += pushOut.y;
            mapObject->mMapObject.mPos.z += pushOut.z;
        }
    }
    if (mapObject->mCourseCollisionMode != MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY_NO_WALL &&
        (mapObject->mCollisionBits & COURSE_HIT_WALL)) {
        if (LENGTH_SQUARED(wallNormal) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&wallNormal, &pushDirection);
        }
        pushDirection.y = 0;
        VEC_MultAdd(mapObject->mPrm->mHead.mWallPushVelocity, &pushDirection, &mapObject->mVelocity,
                    &mapObject->mVelocity);
    }

    if (mapObject->mCollisionBits & COURSE_HIT_GROUND) {
        if (mapObject->mVelocity.y > 0) {
            mapObject->mCollisionBits &= ~COURSE_HIT_GROUND;
        } else if (mapObject->mBounceEnabled != FALSE) {
            mapObject->mVelocity.y = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.y, -mapObject->mPrm->mHead.mBounceScale);
            if (mapObject->mVelocity.y < mapObject->mPrm->mHead.mStopSpeedLimit) {
                mapObject->mBounceEnabled = FALSE;
                mapObject->mVelocity.y = 0;
            }
        } else {
            mapObject->mVelocity.y = 0;
        }
    }
    if (mapObject->mMapObject.mPos.y < 0) {
        mapObject->mMapObject.mPos.y = 0;
        mapObject->mCollisionBits |= gMapObjectBelowZeroCollisionBit;
    }
    if (mapObject->mAlphaLimitPerCall > 0) {
        mapObject->mAlphaLimit =
            StepIntTowardTarget(mapObject->mAlphaLimitTarget, mapObject->mAlphaLimitPerCall, mapObject->mAlphaLimit);
        if (mapObject->mAlphaLimit == mapObject->mAlphaLimitTarget) {
            mapObject->mAlphaLimitPerCall = 0;
        }
    }
    if (mapObject->mScalePerCall > 0) {
        mapObject->mMapObject.mScale.x = mapObject->mMapObject.mScale.y = mapObject->mMapObject.mScale.z =
            StepIntTowardTarget(mapObject->mScaleTarget, mapObject->mScalePerCall, mapObject->mMapObject.mScale.x);
    }
    if (mapObject->mCollisionShape == MAP_OBJECT_COLLISION_BOX) {
        MTX_RotY33_(&mapObject->mMapObject.mMatrix.mAxes, FX_SinIdx((u16) mapObject->mAngle),
                    FX_CosIdx((u16) mapObject->mAngle));
        MTX_MultVec33(&mapObject->mOffset, &mapObject->mMapObject.mMatrix.mAxes, &mapObject->mPosWithOffset);
        VEC_Add(&mapObject->mPosWithOffset, &mapObject->mMapObject.mPos, &mapObject->mPosWithOffset);
    } else {
        mapObject->mPosWithOffset.x = mapObject->mMapObject.mPos.x + mapObject->mOffset.x;
        mapObject->mPosWithOffset.y = mapObject->mMapObject.mPos.y + mapObject->mOffset.y;
        mapObject->mPosWithOffset.z = mapObject->mMapObject.mPos.z + mapObject->mOffset.z;
    }
    mapObject->mMapObject.mAngle = mapObject->mAngle;

    if (mapObject->mNsbmd != NULL) {
        previousFrame = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        AdvanceMapObjectModelNsbcaAnimation(mapObject->mNsbmd);
        currentFrame = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (mapObject->mAnimationFrameCallbackFrameIndex != 0) {
            if (previousFrame < mapObject->mAnimationFrameCallbackFrameIndex &&
                mapObject->mAnimationFrameCallbackFrameIndex <= currentFrame) {
                ClearAndRunCallback(mapObject, &mapObject->mAnimationFrameCallback);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mAnimationFrameCallbackFrameIndex <= currentFrame ||
                        previousFrame < mapObject->mAnimationFrameCallbackFrameIndex)) {
                ClearAndRunCallback(mapObject, &mapObject->mAnimationFrameCallback);
            }
        }
        if (mapObject->mFirstCallbackFrameIndex != 0) {
            if (previousFrame < mapObject->mFirstCallbackFrameIndex &&
                mapObject->mFirstCallbackFrameIndex <= currentFrame) {
                mapObject->mFirstFrameCallback(mapObject);
            } else if (currentFrame < (u32) previousFrame && (mapObject->mFirstCallbackFrameIndex <= currentFrame ||
                                                              previousFrame < mapObject->mFirstCallbackFrameIndex)) {
                mapObject->mFirstFrameCallback(mapObject);
            }
        }
        if (mapObject->mSecondCallbackFrameIndex != 0) {
            if (previousFrame < mapObject->mSecondCallbackFrameIndex &&
                mapObject->mSecondCallbackFrameIndex <= currentFrame) {
                mapObject->mSecondFrameCallback(mapObject);
            } else if (currentFrame < (u32) previousFrame && (mapObject->mSecondCallbackFrameIndex <= currentFrame ||
                                                              previousFrame < mapObject->mSecondCallbackFrameIndex)) {
                mapObject->mSecondFrameCallback(mapObject);
            }
        }
        if (!IsMapObjectModelNsbcaPlaying(mapObject->mNsbmd)) {
            ClearAndRunCallback(mapObject, &mapObject->mAnimationEndCallback);
        }
    }

    mapObject->mStateFrames++;
    if (mapObject->mStateFrameCount != 0 && mapObject->mStateFrames == mapObject->mStateFrameCount) {
        mapObject->mStateFrameCount = 0;
        mapObject->mStateFrames = 0;
        ClearAndRunCallback(mapObject, &mapObject->mStateFrameCountCallback);
    }
    if (mapObject->mPointInRangeCallback != NULL &&
        IsPointInRange(mapObject, &mapObject->mPoint, mapObject->mPointRadius, mapObject->mPointHalfAngle)) {
        ClearAndRunCallback(mapObject, &mapObject->mPointInRangeCallback);
    }
    if (mapObject->mOutOfRangeCallback != NULL &&
        !IsPointInRange(mapObject, &mapObject->mOutOfRangePoint, mapObject->mOutOfRangeRadius,
                        mapObject->mOutOfRangeHalfAngle)) {
        ClearAndRunCallback(mapObject, &mapObject->mOutOfRangeCallback);
    }
    if (mapObject->mStoppedCallback != NULL && mapObject->mVelocity.y == 0 &&
        -mapObject->mPrm->mHead.mStopSpeedLimit < mapObject->mSpeed &&
        mapObject->mPrm->mHead.mStopSpeedLimit > mapObject->mSpeed &&
        -mapObject->mPrm->mHead.mStopSpeedLimit < mapObject->mVelocity.x &&
        mapObject->mPrm->mHead.mStopSpeedLimit > mapObject->mVelocity.x &&
        -mapObject->mPrm->mHead.mStopSpeedLimit < mapObject->mVelocity.z &&
        mapObject->mPrm->mHead.mStopSpeedLimit > mapObject->mVelocity.z &&
        (mapObject->mCollisionBits & COURSE_HIT_GROUND)) {
        ClearAndRunCallback(mapObject, &mapObject->mStoppedCallback);
    }
    if (mapObject->mCourseCollisionCallback != NULL && mapObject->mVelocity.y <= 0 &&
        (mapObject->mCollisionBits & COURSE_HIT_GROUND)) {
        ClearAndRunCallback(mapObject, &mapObject->mCourseCollisionCallback);
    }

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        ComputeEffectPosition(mapObject, effectIndex, &effectPosition);
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            if (mapObject->mEffects[effectIndex].mTimer > 0 && --mapObject->mEffects[effectIndex].mTimer == 0) {
                StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
            } else {
                PlaceEffect(mapObject->mEffects[effectIndex].mEffect, &effectPosition);
            }
        }
    }
    if (mapObject->mTimer > 0) {
        mapObject->mTimer--;
    }
}

void DrawMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject) {
    s32 materialIndex;
    s32 alphaLimit;
    NNSG3dResMdl *resMdl;
    s32 alpha;
    s32 value;
    Vec3 shiftedPosition;
    MtxFx33 rotationMatrix;

    alphaLimit = FROM_FIXED12(mapObject->mAlphaLimit);
    shiftedPosition.x = mapObject->mMapObject.mPos.x >> 4;
    shiftedPosition.y = mapObject->mMapObject.mPos.y >> 4;
    shiftedPosition.z = mapObject->mMapObject.mPos.z >> 4;
    alpha = ComputeViewDepthAlpha(&shiftedPosition);
    if (alpha >= alphaLimit) {
        alpha = alphaLimit;
    }
    if (alpha > 0) {
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        if (alpha >= 0x1f) {
            NNS_G3dMdlSetMdlXLDepthUpdateAll(mapObject->mNsbmd->mAnimatedModel->mResMdl, 1);
            SetMapObjectModelPolygonId(mapObject->mNsbmd, 3);
        } else if (mapObject->mShadowMode <= MAP_OBJECT_SHADOW_ON_COURSE_Y_ZERO) {
            NNS_G3dMdlSetMdlXLDepthUpdateAll(mapObject->mNsbmd->mAnimatedModel->mResMdl, 1);
            SetMapObjectModelPolygonId(mapObject->mNsbmd, 3);
        } else {
            resMdl = mapObject->mNsbmd->mAnimatedModel->mResMdl;
            NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
            for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
                SetMapObjectModelMaterialPolygonId(mapObject->mNsbmd, AllocPolygonIdWrapping(), materialIndex);
            }
        }
        value = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &value, 1);
        NNS_G3dGeBufferOP_N(0x19, SetTranslationMatrixPos(&mapObject->mMapObject.mPos), 0xc);
        if (mapObject->mMapObject.mAngle != 0) {
            MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(mapObject->mMapObject.mAngle),
                        COS_OF_ANGLE(mapObject->mMapObject.mAngle));
            NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        }
        NNS_G3dGeBufferOP_N(0x1b, &mapObject->mMapObject.mScale.x, 3);
        SetMapObjectModelAlpha(mapObject->mNsbmd, alpha);
        SetMapObjectModelMirror(mapObject->mNsbmd, mapObject->mMapObject.mFlags & MAP_OBJECT_FLAG_MIRRORED, 0);
        DrawMapObjectModel(mapObjectList, mapObject->mNsbmd, mapObject);
    }
}

void DrawMissionRunMapObjectShadow(void *mapObjectList, MissionRunMapObject *mapObject, s32 invertDepth) {
    s32 shadowAlpha;
    s32 value;
    Vec3 shadowPosition;

    shadowAlpha = FROM_FIXED12(mapObject->mAlphaLimit);
    if (mapObject->mShadowMode == MAP_OBJECT_SHADOW_AT_OBJECT) {
        shadowPosition.x = mapObject->mMapObject.mPos.x;
        shadowPosition.y = mapObject->mMapObject.mPos.y;
        shadowPosition.z = mapObject->mMapObject.mPos.z;
    } else if (mapObject->mShadowMode == MAP_OBJECT_SHADOW_AT_NODE) {
        shadowPosition.x = mapObject->mNodePosition.x;
        shadowPosition.y = mapObject->mMapObject.mCourseMapRow->mPosition.y;
        shadowPosition.z = mapObject->mNodePosition.z;
    } else {
        if (shadowAlpha >= 4) {
            s32 adjustedDepth =
                shadowAlpha - ((mapObject->mMapObject.mPos.y - mapObject->mMapObject.mCourseMapRow->mPosition.y) >> 15);

            if (adjustedDepth <= 4) {
                adjustedDepth = 4;
            }
            shadowAlpha = (u16) adjustedDepth;
        }
        shadowPosition.x = mapObject->mMapObject.mPos.x;
        shadowPosition.y = mapObject->mMapObject.mCourseMapRow->mPosition.y;
        shadowPosition.z = mapObject->mMapObject.mPos.z;
    }
    if (shadowAlpha > 0x10) {
        shadowAlpha = 0x10;
    }
    if (invertDepth != 0) {
        shadowAlpha = 0x14 - shadowAlpha;
    }
    if (shadowAlpha > 0) {
        MtxFx33 rotationMatrix;
        Vec3 shadowOffset;
        Vec3 shadowScale;
        s32 offsetX;
        s32 offsetY;
        s32 offsetZ;

        value = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &value, 1);
        NNS_G3dGeBufferOP_N(0x19, SetTranslationMatrixPos(&shadowPosition), 0xc);
        MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE((u16) mapObject->mAngle), COS_OF_ANGLE((u16) mapObject->mAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        offsetZ = mapObject->mShadowOffsetZ >> 4;
        offsetY = mapObject->mShadowOffsetY >> 4;
        offsetX = mapObject->mShadowOffsetX >> 4;
        shadowOffset.x = offsetX;
        shadowOffset.y = offsetY;
        shadowOffset.z = offsetZ;
        NNS_G3dGeBufferOP_N(0x1c, &shadowOffset, 3);
        NNS_G3dGeBufferOP_N(0x1b, &mapObject->mShadowScaleX, 3);
        if (gShadowScaleToggle == 0) {
            shadowScale.x = 0x1333;
            shadowScale.y = 0x1000;
            shadowScale.z = 0x1333;
            NNS_G3dGeBufferOP_N(0x1b, &shadowScale, 3);
        }
        SetMapObjectModelPolygonId(mapObject->mShadowNsbmd, 3);
        SetMapObjectModelAlpha(mapObject->mShadowNsbmd, shadowAlpha);
        DrawMapObjectModel(mapObjectList, mapObject->mShadowNsbmd, mapObject);
    }
}

s32 ComputeSphereHitOnMissionRunMapObject(MissionRunMapObject *mapObject, Vec3 *sphereCenter, s32 sphereRadius,
                                          Vec3 *overlapOffset) {
    s32 diffX;
    s32 diffY;
    s32 diffZ;

    switch (mapObject->mCollisionShape) {
        case MAP_OBJECT_COLLISION_SPHERE:
            sphereRadius += mapObject->mCollisionExtent.x;
            diffX = sphereCenter->x - mapObject->mPosWithOffset.x;
            diffY = sphereCenter->y - mapObject->mPosWithOffset.y;
            diffZ = sphereCenter->z - mapObject->mPosWithOffset.z;
            if ((s64) diffZ * diffZ + SQUARE_SUM2(diffX, diffY) < (s64) sphereRadius * sphereRadius) {
                ComputeSphereOverlapOffset(sphereCenter, &mapObject->mPosWithOffset, sphereRadius, overlapOffset);
                return 1;
            }
            return 0;
        case MAP_OBJECT_COLLISION_CYLINDER:
            return ComputeSphereHitOnRotatedCylinder(sphereCenter, &mapObject->mPosWithOffset,
                                                     &mapObject->mMapObject.mMatrix.mRows[0],
                                                     mapObject->mCollisionExtent.x, mapObject->mCollisionExtent.y,
                                                     mapObject->mCollisionExtent.y, sphereRadius, overlapOffset);
        case MAP_OBJECT_COLLISION_BOX:
            return ComputeSphereHitOnRotatedBox(sphereCenter, &mapObject->mPosWithOffset,
                                                &mapObject->mMapObject.mMatrix.mRows[0], &mapObject->mCollisionExtent,
                                                &mapObject->mCollisionExtent, sphereRadius, overlapOffset);
        default:
            return 0;
    }
}

s32 CollideKartWithMissionRunMapObject(MissionRunMapObject *mapObject, Kart *kart, u8 *firstResponsePointer,
                                       u8 *responsePointer) {
    Vec3 awayDirection;
    s64 pushStrength;
    u32 mode;
    MissionRunMapObjectKartCollisionCallback collisionCallback;

    mode = *firstResponsePointer;
    mapObject->mKartResponse = *responsePointer;
    mapObject->mMapObject.mPosStep.x = 0;
    mapObject->mMapObject.mPosStep.y = 0;
    mapObject->mMapObject.mPosStep.z = 0;
    if (mode == 1) {
        awayDirection.x = mapObject->mMapObject.mPos.x - kart->mPos.x;
        awayDirection.y = 0;
        awayDirection.z = mapObject->mMapObject.mPos.z - kart->mPos.z;
        if ((s64) awayDirection.z * awayDirection.z + SQUARE_SUM2(awayDirection.x, awayDirection.y) >= 16) {
            Vec3NormalizeAndGetLengthUnchecked(&awayDirection, &awayDirection);
            pushStrength = -mapObject->mPrm->mHead.mKartPushPosStep;
            mapObject->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(awayDirection.x, pushStrength);
            mapObject->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(awayDirection.y, pushStrength);
            mapObject->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(awayDirection.z, pushStrength);
            VEC_MultAdd(mapObject->mPrm->mHead.mKartPushVelocity, &awayDirection, &mapObject->mVelocity,
                        &mapObject->mVelocity);
        }
        collisionCallback = mapObject->mKartCollisionCallback;
        mapObject->mKartCollisionCallback = NULL;
        if (collisionCallback) {
            collisionCallback(mapObject, kart);
        }
    }
    if (mapObject->mTimer == 0) {
        mapObject->mTimer = MAP_OBJECT_KART_HIT_COOLDOWN_FRAMES;
    }
    return mapObject->mKartResponse;
}

s32 CollideItemWithMissionRunMapObject(MissionRunMapObject *mapObject, ItemObject *itemObject, u8 *firstResponsePointer,
                                       u8 *responsePointer) {
    Vec3 awayDirection;
    MissionRunMapObjectItemCollisionCallback collisionCallback;

    mapObject->mItemResponse = *responsePointer;
    awayDirection.x = mapObject->mMapObject.mPos.x - itemObject->mPos.x;
    awayDirection.y = 0;
    awayDirection.z = mapObject->mMapObject.mPos.z - itemObject->mPos.z;
    if ((s64) awayDirection.z * awayDirection.z + SQUARE_SUM2(awayDirection.x, awayDirection.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&awayDirection, &awayDirection);
        VEC_MultAdd(mapObject->mPrm->mHead.mItemPushVelocity, &awayDirection, &mapObject->mVelocity,
                    &mapObject->mVelocity);
    }
    collisionCallback = mapObject->mItemCollisionCallback;
    mapObject->mItemCollisionCallback = NULL;
    if (collisionCallback) {
        collisionCallback(mapObject, itemObject);
    }
    return mapObject->mItemResponse;
}

MapObjectList *CreateEmptyMapObjectUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, NULL, NULL);
}

const u32 gMapObjectBelowZeroCollisionBit = 0x800;
