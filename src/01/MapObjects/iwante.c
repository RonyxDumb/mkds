#include "01/MapObjects/iwante.h"
#include "01/MapObjects/mission_run_repeats_remaining.h"

#include "01/MapObjects/map_object_animation.h"
#include "Main/System/heap.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/MapObjects/mission_run_map_objects_reset.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "01/MapObjects/mission_run_entry_index.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/mission_run_point_in_range_callback.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "Main/Kart/camera.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/System/heap_call.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "fixed_vector_math.h"
#include "01/MapObjects/king_teresa.h"
#include "Main/MapObjects/bound.h"

MapObjectKindDescriptor gIwanteKindDescriptor = {0,
                                                 {0, 0},
                                                 0x30c,
                                                 InitIwanteSoundSource,
                                                 CreateIwanteKindData,
                                                 CreateIwanteDrawList,
                                                 NULL,
                                                 NULL,
                                                 CreateIwanteUpdateList,
                                                 NULL,
                                                 {NULL, NULL, NULL, NULL}};
SoundStartParams gIwanteEndSoundParams = {0x217, NULL, 0xc, 0};
MapObjectKindDescriptor gIwanteHandsKindDescriptor = {0,
                                                      {0, 0},
                                                      0x30c,
                                                      NULL,
                                                      CreateEmptyMapObjectKindData,
                                                      NULL,
                                                      NULL,
                                                      NULL,
                                                      CreateIwanteHandsUpdateList,
                                                      NULL,
                                                      {NULL, NULL, NULL, NULL}};

void InitIwanteSoundSource(MissionRunMapObject *mapObject) {
    mapObject->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mMapObject.mSound->mSoundSource, 0xc, &mapObject->mMapObject.mPos);
    mapObject->mMapObject.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void IwanteKartResponse2Callback(MissionRunMapObject *mapObject, Kart *kart) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_BUMP;
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
}

void IwanteKartHitCallback(MissionRunMapObject *mapObject, Kart *kart) {
    if (mapObject->mTimer > 0) {
        mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_BUMP;
        SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
        return;
    }
    mapObject->mMapObject.mPosStep.x =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mIwante.mKartHitCarryVelocity, SIN_OF_ANGLE((u16) mapObject->mMoveAngle));
    mapObject->mMapObject.mPosStep.y = 0;
    mapObject->mMapObject.mPosStep.z =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mIwante.mKartHitCarryVelocity, COS_OF_ANGLE((u16) mapObject->mMoveAngle));
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
    SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
}

void IwanteKartResponse11Callback(MissionRunMapObject *mapObject, Kart *kart) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT;
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    mapObject->mMapObject.mDistanceSquaredAndFlags =
        mapObject->mMapObject.mDistanceSquaredAndFlags | gIwanteSkipKindSoundFlag;
}

void SetIwanteHandsApproachPoint(void) {
    Vec3 pos;
    MissionRunMapObject *mapObject;
    IwantePrm *prm;
    Kart *kart;
    u16 angle;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        mapObject = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2));
    } else {
        mapObject = NULL;
    }
    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
        prm = &mapObject->mPrm->mIwante;
        angle = FX_Atan2Idx(kart->mPos.z - mapObject->mMapObject.mPos.z, kart->mPos.x - mapObject->mMapObject.mPos.x) -
                prm->mApproachAngleOffset;
    } else {
        prm = &mapObject->mPrm->mIwante;
        angle = prm->mApproachAngleOffset +
                FX_Atan2Idx(kart->mPos.z - mapObject->mMapObject.mPos.z, kart->mPos.x - mapObject->mMapObject.mPos.x);
    }
    pos.x = mapObject->mMapObject.mPos.x + MUL_FIXED12_NO_ROUND(prm->mApproachPointRadius, COS_OF_ANGLE(angle));
    pos.y = mapObject->mMapObject.mPos.y;
    pos.z = mapObject->mMapObject.mPos.z +
            MUL_FIXED12_NO_ROUND(mapObject->mPrm->mIwante.mApproachPointRadius, SIN_OF_ANGLE(angle));
    SetAnglePointAndMoveAnglePoint(mapObject, &pos);
}

void SetIwanteHandsPoints(void) {
    Vec3 firstMovePoint;
    Vec3 secondMovePoint;
    Vec3 anglePoint;
    MissionRunMapObject *angleObject;
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        angleObject = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2));
    } else {
        angleObject = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand =
            GetMissionRunMapObject((u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    anglePoint.x = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mIwante.mHandsAnglePointDistance,
                                         FX_SinIdx((u16) angleObject->mAngle)));
    anglePoint.y = angleObject->mMapObject.mPos.y;
    anglePoint.z = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mIwante.mHandsAnglePointDistance,
                                         FX_CosIdx((u16) angleObject->mAngle)));
    firstMovePoint.x = -(s32) (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mIwante.mHandsMovePointDistance,
                                                    FX_CosIdx((u16) angleObject->mAngle)));
    firstMovePoint.y = angleObject->mMapObject.mPos.y;
    firstMovePoint.z = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mIwante.mHandsMovePointDistance,
                                             FX_SinIdx((u16) angleObject->mAngle)));
    secondMovePoint.x = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mIwante.mHandsMovePointDistance,
                                              FX_CosIdx((u16) angleObject->mAngle)));
    secondMovePoint.y = angleObject->mMapObject.mPos.y;
    secondMovePoint.z = -(s32) (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mIwante.mHandsMovePointDistance,
                                                     FX_SinIdx((u16) angleObject->mAngle)));
    SetAnglePoint(firstHand, &anglePoint);
    SetAnglePoint(secondHand, &anglePoint);
    SetMoveAnglePoint(firstHand, &firstMovePoint);
    SetMoveAnglePoint(secondHand, &secondMovePoint);
}

void SetIwanteNoneCollision(MissionRunMapObject *mapObject) {
    mapObject->mHandShape = IWANTE_HAND_SHAPE_NONE;
    SetItemCollisionCallback(mapObject, &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtent(mapObject, 0, 0, 0, 0, 0, 0);
    SetShadowOffsetAndScale(mapObject, 0x0002a000u, 0, 0x00007000u, 0x00026000u, 0x00001000u, 0x00022000u);
}

void SetIwanteNoChainCameraWalkA(MissionRunMapObject *mapObject) {
    mapObject->mHandShape = IWANTE_HAND_SHAPE_WALK_A;
    SetItemCollisionCallback(mapObject, &IwanteItemHitCallback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x0001e000u, 0xffff5000u, 0x00002000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00002000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00002000u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00002000u);
}

void SetIwanteWalkACollision(MissionRunMapObject *mapObject) {
    mapObject->mHandShape = IWANTE_HAND_SHAPE_WALK_A;
    SetItemCollisionCallback(mapObject, &IwanteItemHitCallback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x00028000u, 0xffff5000u, 0x00001000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00000800u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00001000u);
}

void SetIwanteWalkBCollision(MissionRunMapObject *mapObject) {
    mapObject->mHandShape = IWANTE_HAND_SHAPE_WALK_B;
    SetItemCollisionCallback(mapObject, &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0x00015000u, 0x00028000u, 0x0001c000u, 0x00001000u, 0x00013000u,
                                         0x00028000u, 0x00028000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0x00012000u, 0, 0x0001c000u, 0x00001000u, 0x00011000u, 0x00001000u,
                                  0x00024000u, 0x00001000u);
}

void SetIwanteHitReactionCollision(MissionRunMapObject *mapObject) {
    mapObject->mHandShape = IWANTE_HAND_SHAPE_HIT_REACTION;
    SetItemCollisionCallback(mapObject, &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0, 0x00028000u, 0xfffd1000u, 0x00002000u, 0x0001b99au, 0x00028000u,
                                         0x0002f000u, 0x00002000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0, 0, 0xfffd1000u, 0x00002000u, 0x0001b99au, 0x00001000u, 0x0002f000u,
                                  0x00002000u);
}

void SetIwanteWalkAHitCollision(MissionRunMapObject *mapObject) {
    mapObject->mHandShape = IWANTE_HAND_SHAPE_WALK_A;
    SetItemCollisionCallback(mapObject, &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x00028000u, 0xffff5000u, 0x00002000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00001000u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00001000u);
}

void StartIwanteHandWalk(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mWalkAnimationEntry,
                                mapObject->mPrm->mIwante.mWalkFrameStep);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
}

void StartIwanteHandWalkWithEffects(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mWalkWithEffectsAnimationEntry,
                                mapObject->mPrm->mIwante.mWalkWithEffectsFrameStep);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
}

void StartIwanteHandWalkBWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mWalkBAnimationEntry,
                                mapObject->mPrm->mIwante.mWalkBFrameStep);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
}

void StartIwanteHandWalkAWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mWalkAAnimationEntry,
                                mapObject->mPrm->mIwante.mWalkAFrameStep);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
}

void StartIwanteHandChangeToWalkBWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mChangeToWalkBAnimationEntry,
                                  mapObject->mPrm->mIwante.mChangeToWalkBFrameStep, StartIwanteHandWalkBWalk);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
    SetIwanteWalkBCollision(mapObject);
    StartMapObjectSound(&mapObject->mMapObject, 0x215);
}

void StartIwanteHandChangeToWalkAWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mChangeToWalkAAnimationEntry,
                                  mapObject->mPrm->mIwante.mChangeToWalkAFrameStep, StartIwanteHandWalkAWalk);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x2000, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x2000, 0x42e, 0);
}

void StartIwanteHandWalkBHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mWalkBAnimationEntry,
                                mapObject->mPrm->mIwante.mWalkBFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartIwanteHandWalkAHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mWalkAAnimationEntry,
                                mapObject->mPrm->mIwante.mWalkAFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042eu, 0);
}

void StopIwanteHandOnCourseHit(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StopMapObjectState(mapObject);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    mapObject->mGravityEnabled = TRUE;
}

u32 AdvanceIwanteHandVerticalSound(MissionRunMapObject *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x0000021du);
    return 0;
}

void StartIwanteHandMoveVerticalBack(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = -mapObject->mPrm->mIwante.mMoveVerticalVelocityY;
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandVerticalSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mMoveVerticalAnimationEntry,
                                mapObject->mPrm->mIwante.mMoveVerticalFrameStep);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
    SetCourseCollisionCallback(mapObject, StopIwanteHandOnCourseHit);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandMoveVertical(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mIwante.mMoveVerticalVelocityY;
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandVerticalSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mMoveVerticalAnimationEntry,
                                mapObject->mPrm->mIwante.mMoveVerticalFrameStep);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mIwante.mWalkTurnPerCallTarget, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mWalkSpeedTarget, 0x270f000);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mMoveVerticalFrameCount,
                                 StartIwanteHandMoveVerticalBack);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandChangeToWalkB(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mChangeToWalkBAnimationEntry,
                                  mapObject->mPrm->mIwante.mChangeToWalkBFrameStep, &StartIwanteHandWalkBHold);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetIwanteWalkBCollision(mapObject);
    StartMapObjectSound(&mapObject->mMapObject, 0x00000215u);
}

void StartIwanteHandChangeToWalkA(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mChangeToWalkAAnimationEntry,
                                  mapObject->mPrm->mIwante.mChangeToWalkAFrameStep, &StartIwanteHandWalkAHold);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042eu, 0);
}

void StartIwanteHandLand(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mLandAnimationEntry,
                                mapObject->mPrm->mIwante.mLandFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mLandFrameCount, NULL);
}

void StartIwanteHandFall(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mIwante.mFallVelocityY;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mFallAnimationEntry,
                                mapObject->mPrm->mIwante.mFallFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFromPoint(mapObject, mapObject->mPrm->mIwante.mFallMoveAnglePerCallTarget,
                             mapObject->mPrm->mIwante.mFallMoveAnglePerCallIncrement);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mFallSpeedTarget,
                             mapObject->mPrm->mIwante.mFallSpeedPerCall);
    SetCourseCollisionCallback(mapObject, StartIwanteHandLand);
    mapObject->mGravityEnabled = TRUE;
}

void StartIwanteHandReachMovePoint(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mReachAnimationEntry,
                                mapObject->mPrm->mIwante.mReachFrameStep);
    StopTurningMoveFromPoint(mapObject, mapObject->mPrm->mIwante.mReachMoveAnglePerCallTarget,
                             mapObject->mPrm->mIwante.mReachMoveAnglePerCallIncrement);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mReachSpeedTarget,
                             mapObject->mPrm->mIwante.mReachSpeedPerCall);
    SetVelocity(mapObject, &velocity);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mIwante.mReachPointRadius, 0, &mapObject->mMoveAnglePoint,
                            StartIwanteHandFall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mFallDelayFrameCount, StartIwanteHandFall);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandMoveToPoints(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mIwante.mMoveToPointsVelocityY;
    SetIwanteHandsPoints();
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mMoveToPointsAnimationEntry,
                                mapObject->mPrm->mIwante.mMoveToPointsFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFromPoint(mapObject, mapObject->mPrm->mIwante.mMoveToPointsMoveAnglePerCallTarget,
                             mapObject->mPrm->mIwante.mMoveToPointsMoveAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &mapObject->mMoveAnglePoint);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mMoveToPointsSpeedTarget,
                             mapObject->mPrm->mIwante.mMoveToPointsSpeedPerCall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mMoveToPointsFrameCount,
                                 StartIwanteHandReachMovePoint);
}

int AdvanceIwanteHandSidewaysStop(MissionRunMapObject *mapObject) {
    if (mapObject->mSpeed > 0) {
        StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x219);
    } else {
        ReleaseEffects(mapObject);
        SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
        mapObject->mStateFunction = NULL;
    }
    return 0;
}

s32 AdvanceIwanteHandSidewaysSound(MissionRunMapObject *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x219);
    return 0;
}

void StartIwanteHandSidewaysStop(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandSidewaysStop);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mSidewaysStopAnimationEntry,
                                mapObject->mPrm->mIwante.mSidewaysStopFrameStep);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mSidewaysStopSpeedTarget,
                             mapObject->mPrm->mIwante.mSidewaysStopSpeedPerCall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mSidewaysStopFrameCount,
                                 StartIwanteHandMoveToPoints);
    StartEffectAtOffset(mapObject, 0x1000, 0, 0x2000, 0x433, 0);
}

void StartIwanteHandMoveSideways(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 zeroVector = {0, 0, 0};

    if ((mapObject->mMapObject.mFlags & MAP_OBJECT_FLAG_MIRRORED) == 0) {
        mapObject->mMoveAngle = mapObject->mAngle + 0x4000;
    } else {
        mapObject->mMoveAngle = mapObject->mAngle - 0x4000;
    }
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandSidewaysSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mMoveSidewaysAnimationEntry,
                                mapObject->mPrm->mIwante.mMoveSidewaysFrameStep);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mMoveSidewaysSpeedTarget,
                             mapObject->mPrm->mIwante.mMoveSidewaysSpeedPerCall);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mMoveSidewaysFrameCount,
                                 StartIwanteHandSidewaysStop);
    SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
    StartEffectAtOffset(mapObject, 0x1000, 0, 0x2000, 0x433, 0);
}

void StartIwanteHandLandBeforeSideways(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mLandBeforeSidewaysAnimationEntry,
                                mapObject->mPrm->mIwante.mLandBeforeSidewaysFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mLandBeforeSidewaysFrameCount,
                                 StartIwanteHandMoveSideways);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x414, 0);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x415, 0);
    StartMapObjectSound(&mapObject->mMapObject, 0x218);
}

void StartIwanteHandLandOnKart(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mLandOnKartAnimationEntry,
                                mapObject->mPrm->mIwante.mLandOnKartFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mLandOnKartFrameCount,
                                 StartIwanteHandMoveToPoints);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x414, 0);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x415, 0);
    StartMapObjectSound(&mapObject->mMapObject, 0x218);
}

void StartIwanteHandFallOnKart(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mIwante.mFallOnKartVelocityY;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mFallOnKartAnimationEntry,
                                mapObject->mPrm->mIwante.mFallOnKartFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mFallOnKartSpeedTarget,
                             mapObject->mPrm->mIwante.mFallOnKartSpeedPerCall);
    if (GetAbsoluteCounter(
            gRaceSetup->mMode == MODE_MISSION_RUN
                ? GetMissionRunMapObject(
                      (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                : 0) >= 1) {
        SetCourseCollisionCallback(mapObject, StartIwanteHandLandBeforeSideways);
    } else {
        SetCourseCollisionCallback(mapObject, StartIwanteHandLandOnKart);
    }
    mapObject->mGravityEnabled = TRUE;
    SetKartCollisionCallback(mapObject, IwanteKartResponse11Callback);
}

s32 AdvanceIwanteHandKartSound(MissionRunMapObject *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x21c);
    return 0;
}

void StartIwanteHandMoveToKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandKartSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mMoveToKartAnimationEntry,
                                mapObject->mPrm->mIwante.mMoveToKartFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mMoveToKartSpeedTarget,
                             mapObject->mPrm->mIwante.mMoveToKartSpeedPerCall);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mIwante.mMoveToKartPointRadius, 0, &kart->mPos,
                            StartIwanteHandFallOnKart);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mFallDelayFrameCount, StartIwanteHandFallOnKart);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandTurnToKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mIwante.mTurnToKartVelocityY;
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandKartSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mTurnToKartAnimationEntry,
                                mapObject->mPrm->mIwante.mTurnToKartFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mTurnToKartSpeedTarget,
                             mapObject->mPrm->mIwante.mTurnToKartSpeedPerCall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mTurnToKartFrameCount, StartIwanteHandMoveToKart);
}

void StartIwanteHandLandOnKartAndStop(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mLandOnKartAndStopAnimationEntry,
                                mapObject->mPrm->mIwante.mLandOnKartAndStopFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mIwante.mLandOnKartAndStopFrameCount, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x414, 0);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x415, 0);
    StartMapObjectSound(&mapObject->mMapObject, 0x218);
}

void StartIwanteHandDirectFallOnKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mIwante.mDirectFallOnKartVelocityY;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mDirectFallOnKartAnimationEntry,
                                mapObject->mPrm->mIwante.mDirectFallOnKartFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mIwante.mDirectFallOnKartSpeedTarget,
                             mapObject->mPrm->mIwante.mDirectFallOnKartSpeedPerCall);
    SetCourseCollisionCallback(mapObject, StartIwanteHandLandOnKartAndStop);
    SetKartCollisionCallback(mapObject, IwanteKartResponse11Callback);
}

void StartIwanteHandHitThirdAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mHitThirdAnimationEntry,
                                  mapObject->mPrm->mIwante.mHitThirdFrameStep, &StartIwanteHandMoveToPoints);
    SetIwanteWalkBCollision(mapObject);
}

void StartIwanteHandHitSecondAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mHitSecondAnimationEntry,
                                  mapObject->mPrm->mIwante.mHitSecondFrameStep, &StartIwanteHandHitThirdAnimation);
    SetIwanteWalkAHitCollision(mapObject);
}

s32 AdvanceIwanteHandHitCollisionSound(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & COURSE_HIT_GROUND) != 0) {
        StartMapObjectSound(&mapObject->mMapObject, 0x218);
        mapObject->mStateFunction = NULL;
    }
    return 0;
}

s32 AdvanceIwanteHandHitCollision(MissionRunMapObject *mapObject) {
    if (mapObject->mCollisionBits & COURSE_HIT_GROUND) {
        mapObject->mStateFunction = (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandHitCollisionSound;
    }
    return 0;
}

void StartIwanteHandHitReaction(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &AdvanceIwanteHandHitCollision);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mHitReactionAnimationEntry,
                                  mapObject->mPrm->mIwante.mHitReactionFrameStep, StartIwanteHandHitSecondAnimation);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mGravityEnabled = TRUE;
    SetIwanteHitReactionCollision(mapObject);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartMapObjectSound(&mapObject->mMapObject, 0x00000216u);
}

void StartIwanteHandHitHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mHitHoldAnimationEntry,
                                mapObject->mPrm->mIwante.mHitHoldFrameStep);
}

void StartIwanteHandHitReactionHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &AdvanceIwanteHandHitCollision);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mHitReactionHoldAnimationEntry,
                                  mapObject->mPrm->mIwante.mHitReactionHoldFrameStep, &StartIwanteHandHitHold);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mGravityEnabled = TRUE;
    SetIwanteHitReactionCollision(mapObject);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartMapObjectSound(&mapObject->mMapObject, 0x00000216u);
}

void HideIwanteAtEndReached(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x1000, 0xffffdccd, 0x3ef, 0);
    StartEffectAtOffset(mapObject, 0, 0x1000, 0xffffdccd, 0x3ee, 0);
    StartEffectAtOffset(mapObject, 0, 0x1000, 0xffffdccd, 0x3f0, 0);
    StartEffectAtOffset(mapObject, 0, 0x1000, 0xffffdccd, 0x3f1, 0);
    StartEffectAtOffset(mapObject, 0, 0x1000, 0xffffdccd, 0x3f2, 0);
    {
        SoundStartParams soundParams = gIwanteEndSoundParams;

        soundParams.mPositionSource = &mapObject->mMapObject.mPos;
        soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mMapObject.mPos);
        StartSndHandleSoundUnchecked(&soundParams, GetSecondSndHandleSlot());
    }
    mapObject->mMapObject.mFlags |= gIwanteSkipViewTestFlag;
    mapObject->mMapObject.mFlags |= gIwanteSkipListCallbackFlag;
    mapObject->mMapObject.mFlags |= gIwanteDisabledFlag;
}

void StartIwanteHideAtEndReached(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mHideAtEndReachedAnimationEntry,
                                mapObject->mPrm->mIwante.mHideAtEndReachedFrameStep);
    StartStateFrameCountCallback(mapObject, 0x3c, &HideIwanteAtEndReached);
}

void StartIwanteKartEliminatedHold(MissionRunMapObject *mapObject) {
    if (mapObject->mHandShape == IWANTE_HAND_SHAPE_WALK_A) {
        StartMapObjectState(mapObject, 8, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mIwante.mKartEliminatedHoldAnimationEntry,
                                    mapObject->mPrm->mIwante.mKartEliminatedHoldFrameStep);
        StopTurningMoveFollowsAngle(mapObject);
        SetSpeedAndClearTarget(mapObject, 0);
        return;
    }
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mIwante.mChangeToWalkAAnimationEntry,
                                  mapObject->mPrm->mIwante.mChangeToWalkAFrameStep, &StartIwanteKartEliminatedHold);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042eu, 0);
}

void IwanteStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

s32 AdvanceIwanteHandsStopAfterPoints(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    firstHand = gRaceSetup->mMode == MODE_MISSION_RUN
                    ? GetMissionRunMapObject(
                          (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                    : 0;
    secondHand = gRaceSetup->mMode == MODE_MISSION_RUN
                     ? GetMissionRunMapObject(
                           (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                     : 0;
    if (IsStateNumberBelow(firstHand, 3) != 0 && IsStateNumberBelow(secondHand, 3) != 0) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

s32 AdvanceIwanteHandsRestartWhenIdle(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    firstHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                     ? GetMissionRunMapObject(
                           (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                     : 0);
    secondHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                      ? GetMissionRunMapObject(
                            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                      : 0);
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        StartIwanteHandsFallOrMoveToPoints(mapObject);
    }
    return 0;
}

void StartIwanteHandsFallOrMoveToPoints(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (GetRepeatsRemaining(mapObject)) {
        StartMapObjectState(mapObject, 3, AdvanceIwanteHandsRestartWhenIdle);
        StopTurningMoveFollowsAngle(mapObject);
        firstHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                         ? GetMissionRunMapObject(
                               (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                         : 0);
        secondHand =
            (gRaceSetup->mMode == MODE_MISSION_RUN
                 ? GetMissionRunMapObject(
                       (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                 : 0);
        StartIwanteHandDirectFallOnKart(firstHand);
        StartIwanteHandDirectFallOnKart(secondHand);
    } else {
        StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStopAfterPoints);
        StopTurningMoveFollowsAngle(mapObject);
        firstHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                         ? GetMissionRunMapObject(
                               (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                         : 0);
        secondHand =
            (gRaceSetup->mMode == MODE_MISSION_RUN
                 ? GetMissionRunMapObject(
                       (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                 : 0);
        StartIwanteHandMoveToPoints(firstHand);
        StartIwanteHandMoveToPoints(secondHand);
    }
}

s32 AdvanceIwanteHandsStartFromPrm(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    firstHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                     ? GetMissionRunMapObject(
                           (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                     : 0);
    secondHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                      ? GetMissionRunMapObject(
                            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                      : 0);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    SetIwanteHandsPoints();
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        SetRepeatsRemaining(mapObject, mapObject->mPrm->mIwante.mHandsRepeatCount);
        StartIwanteHandsFallOrMoveToPoints(mapObject);
    }
    return 0;
}

void StartIwanteHandsChangeToWalkB(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStartFromPrm);
    StopTurningMoveFollowsAngle(mapObject);
    firstHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                     ? GetMissionRunMapObject(
                           (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                     : 0);
    secondHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                      ? GetMissionRunMapObject(
                            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                      : 0);
    StartIwanteHandChangeToWalkB(firstHand);
    StartIwanteHandChangeToWalkB(secondHand);
}

s32 AdvanceIwanteHandsRepeatVertical(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    firstHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                     ? GetMissionRunMapObject(
                           (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                     : 0);
    secondHand = (gRaceSetup->mMode == MODE_MISSION_RUN
                      ? GetMissionRunMapObject(
                            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                      : 0);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    SetIwanteHandsPoints();
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        mapObject->mHandOrder = mapObject->mHandOrder == IWANTE_HAND_SECOND ? IWANTE_HAND_FIRST : IWANTE_HAND_SECOND;
        StartIwanteHandsMoveVertical(mapObject);
    }
    return 0;
}

void StartIwanteHandsMoveVertical(MissionRunMapObject *mapObject) {
    Kart *kart;
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (GetRepeatsRemaining(mapObject)) {
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        StartMapObjectState(mapObject, 3, AdvanceIwanteHandsRepeatVertical);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mIwante.mHandsTurnPerCallTarget, 0x270f000);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            firstHand = GetMissionRunMapObject(
                (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
        } else {
            firstHand = NULL;
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            secondHand = GetMissionRunMapObject(
                (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
        } else {
            secondHand = NULL;
        }
        if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
            StartIwanteHandMoveVertical(firstHand);
            StartIwanteHandWalkWithEffects(secondHand);
        } else {
            StartIwanteHandWalkWithEffects(firstHand);
            StartIwanteHandMoveVertical(secondHand);
        }
    } else {
        StartIwanteHandsChangeToWalkB(mapObject);
    }
}

int AdvanceIwanteHandsStartMoveVertical(MissionRunMapObject *mapObject) {
    Kart *kart;
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetIwanteHandsPoints();
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        SetRepeatsRemaining(mapObject, 4);
        StartIwanteHandsMoveVertical(mapObject);
    }
    return 0;
}

void StartIwanteHandsChangeToWalkA(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStartMoveVertical);
    StopTurningMoveFollowsAngle(mapObject);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    StartIwanteHandChangeToWalkA(firstHand);
    StartIwanteHandChangeToWalkA(secondHand);
}

int AdvanceIwanteHandsApproachUntilIdle(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    SetIwanteHandsApproachPoint();
    SetIwanteHandsPoints();
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

int AdvanceIwanteHandsToggleState(MissionRunMapObject *mapObject) {
    Kart *kart;
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
        if (IsStateNumberBelow(firstHand, 3)) {
            mapObject->mHandOrder = IWANTE_HAND_FIRST;
            StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachUntilIdle);
            TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mIwante.mHandsTurnPerCallTarget, 0x270f000);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            StartIwanteHandChangeToWalkAWalk(firstHand);
            StartIwanteHandChangeToWalkBWalk(secondHand);
        }
    } else if (IsStateNumberBelow(secondHand, 3)) {
        mapObject->mHandOrder = IWANTE_HAND_SECOND;
        StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachUntilIdle);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mIwante.mHandsTurnPerCallTarget, 0x270f000);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        StartIwanteHandChangeToWalkBWalk(firstHand);
        StartIwanteHandChangeToWalkAWalk(secondHand);
    }
    return 0;
}

void StartIwanteHandsTurnToKart(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsToggleState);
    StopTurningMoveFollowsAngle(mapObject);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
        StartIwanteHandTurnToKart(firstHand);
        StartIwanteHandWalkAHold(secondHand);
    } else {
        StartIwanteHandWalkAHold(firstHand);
        StartIwanteHandTurnToKart(secondHand);
    }
}

int AdvanceIwanteHandsApproachKart(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    SetIwanteHandsApproachPoint();
    SetIwanteHandsPoints();
    if (IsPointInRange(mapObject, &mapObject->mAnglePoint, 0, mapObject->mPrm->mIwante.mApproachKartObjectRadius) &&
        IsPointInRange(firstHand, &firstHand->mMoveAnglePoint, mapObject->mPrm->mIwante.mApproachKartHandRadius, 0) &&
        IsPointInRange(secondHand, &secondHand->mMoveAnglePoint, mapObject->mPrm->mIwante.mApproachKartHandRadius, 0)) {
        StartIwanteHandsTurnToKart(mapObject);
    }
    return 0;
}

void StartIwanteHandsApproachKart(MissionRunMapObject *mapObject) {
    Kart *kart;
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachKart);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mIwante.mHandsTurnPerCallTarget, 0x270f000);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
        StartIwanteHandWalk(firstHand);
        StartIwanteHandWalkWithEffects(secondHand);
    } else {
        StartIwanteHandWalkWithEffects(firstHand);
        StartIwanteHandWalk(secondHand);
    }
}

int AdvanceIwanteHandsStopAfterToggle(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

void StartIwanteHandsToggleState(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStopAfterToggle);
    StopTurningMoveFollowsAngle(mapObject);
    mapObject->mHandOrder = (mapObject->mHandOrder == IWANTE_HAND_FIRST) ? IWANTE_HAND_SECOND : IWANTE_HAND_FIRST;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
        StartIwanteHandChangeToWalkB(firstHand);
        StartIwanteHandWalkAHold(secondHand);
    } else {
        StartIwanteHandWalkAHold(firstHand);
        StartIwanteHandChangeToWalkB(secondHand);
    }
}

void StartIwanteHandsToggleStateHold(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStopAfterToggle);
    StopTurningMoveFollowsAngle(mapObject);
    mapObject->mHandOrder = (mapObject->mHandOrder == IWANTE_HAND_FIRST) ? IWANTE_HAND_SECOND : IWANTE_HAND_FIRST;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (mapObject->mHandOrder == IWANTE_HAND_SECOND) {
        StartIwanteHandWalkBHold(firstHand);
        StartIwanteHandChangeToWalkA(secondHand);
    } else {
        StartIwanteHandChangeToWalkA(firstHand);
        StartIwanteHandWalkBHold(secondHand);
    }
}

void StartIwanteHandsFromPrm(MissionRunMapObject *mapObject) {
    SetRepeatsRemaining(mapObject, mapObject->mPrm->mIwante.mHandsRepeatCount);
    StartIwanteHandsFallOrMoveToPoints(mapObject);
}

int AdvanceIwanteHandsNextByHitCount(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (IsStateNumberBelow(firstHand, 3) && IsStateNumberBelow(secondHand, 3)) {
        if (GetAbsoluteCounter(
                ((gRaceSetup->mMode == MODE_MISSION_RUN
                      ? GetMissionRunMapObject(
                            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                      : 0))) == 1) {
            StartIwanteHandsToggleStateHold(mapObject);
        } else if (GetAbsoluteCounter(
                       ((gRaceSetup->mMode == MODE_MISSION_RUN
                             ? GetMissionRunMapObject((
                                   u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) +
                                         2))
                             : 0))) == 2) {
            StartIwanteHandsFromPrm(mapObject);
        } else {
            StopMapObjectState(mapObject);
        }
    }
    return 0;
}

void StartIwanteHandsHitReaction(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstHand;
    MissionRunMapObject *secondHand;

    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsNextByHitCount);
    StopTurningMoveFollowsAngle(mapObject);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        firstHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)));
    } else {
        firstHand = NULL;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        secondHand = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1));
    } else {
        secondHand = NULL;
    }
    if (GetAbsoluteCounter(
            ((gRaceSetup->mMode == MODE_MISSION_RUN
                  ? GetMissionRunMapObject(
                        (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                  : 0))) >= 2) {
        StartIwanteHandHitReactionHold(firstHand);
        StartIwanteHandHitReactionHold(secondHand);
    } else {
        StartIwanteHandHitReaction(firstHand);
        StartIwanteHandHitReaction(secondHand);
    }
}

u32 AdvanceIwanteHandsWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartIwanteHandsToggleState(mapObject);
    }
    return 0;
}

void StartIwanteHandsWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandsWaitForRaceStart);
}

void ApplyIwanteHandsHit(MissionRunMapObject *mapObject) {
    StartIwanteHandsHitReaction(mapObject);
    IncrementHitCountAndCheckLimit(mapObject);
}

void StartIwanteCourseHitEffects(MissionRunMapObject *mapObject) {
    StartEffectAtRowHeight(mapObject, 0x00002ccdu, 0, 0, 0x00000411u, 0);
    StartEffectAtRowHeight(mapObject, 0x00002ccdu, 0, 0, 0x00000412u, 0);
}

void StartIwanteNoChainCameraEffects(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mHead.mWaitForRaceStartFrameStep);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042eu, 0);
}

void StartIwanteNoChainCameraAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHead.mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mHead.mStartupSecondFrameStep, &StartIwanteNoChainCameraEffects);
    SetIwanteNoChainCameraWalkA(mapObject);
    StartMapObjectSound(&mapObject->mMapObject, 0x0000021bu);
}

void StartIwanteNoChainCameraWait(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 &StartIwanteNoChainCameraAnimation);
}

void StartIwanteChainCameraCourseWait(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupSecondFrameStep);
    SetCourseCollisionCallback(mapObject, StartIwanteCourseHitEffects);
}

void StartIwanteChainCameraHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupFirstFrameStep);
    DisableMissionRunMapObjectGravity(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstFrameCount,
                                 &StartIwanteChainCameraCourseWait);
}

void IwanteItemResponse2Callback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
    SetItemCollisionCallback(mapObject, IwanteItemResponse2Callback);
}

// Item hit on a hand: knocks both hands back and counts one hit on the third object.
void IwanteItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    int diff;
    int limit;
    Vec3 velocity;

    diff = (u16) (FX_Atan2Idx(itemObject->mPos.x - mapObject->mMapObject.mPos.x,
                              itemObject->mPos.z - mapObject->mMapObject.mPos.z) -
                  mapObject->mAngle);
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    limit = mapObject->mPrm->mIwante.mItemHitHalfAngle;
    if (diff <= limit && diff >= -limit && IsStateNumberBelow(mapObject, 7)) {
        velocity.x =
            (MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mIwante.mItemHitVelocity, FX_SinIdx((u16) mapObject->mAngle)));
        velocity.y = mapObject->mPrm->mIwante.mItemHitVelocityY;
        velocity.z =
            (MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mIwante.mItemHitVelocity, FX_CosIdx((u16) mapObject->mAngle)));
        SetVelocity((gRaceSetup->mMode == MODE_MISSION_RUN
                         ? GetMissionRunMapObject(
                               (u16) (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0))
                         : 0),
                    &velocity);
        SetVelocity((gRaceSetup->mMode == MODE_MISSION_RUN
                         ? GetMissionRunMapObject((
                               u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 1))
                         : 0),
                    &velocity);
        StartEffect(0x3eb, &itemObject->mPos);
        StartEffect(0x3ec, &itemObject->mPos);
        StartEffect(0x3ed, &itemObject->mPos);
        mapObject->mMapObject.mDistanceSquaredAndFlags |= gMapObjectItemHitReportFlag;
        ApplyIwanteHandsHit(
            gRaceSetup->mMode == MODE_MISSION_RUN
                ? GetMissionRunMapObject(
                      (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                : 0);
        SetItemCollisionCallback(mapObject, IwanteItemResponse2Callback);
        mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
    } else {
        mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
        SetItemCollisionCallback(mapObject, IwanteItemHitCallback);
    }
}

// IwanteHands: the model-less third Mission Run object (index MissionRunGetCurrentKartCount() + 2) that steers both
// stone hands.
void InitIwanteHandsObjects(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *obj;

    if (mapObjectList != NULL) {
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            InitMissionRunMapObject(NULL, obj, NULL, NULL, "iwante_l.prm");
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            StartIwanteHandsWaitForRaceStart(obj);
        }
    }
}

void UpdateIwanteHands(u32 mapObjectList, MissionRunMapObject *mapObject) {
    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) == 0 && IsStateNumberBelow(mapObject, 1)) {
        if (GetAbsoluteCounter(
                (gRaceSetup->mMode == MODE_MISSION_RUN
                     ? GetMissionRunMapObject(
                           (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                     : 0)) < 2) {
            StartIwanteHandsApproachKart(mapObject);
        } else {
            StartIwanteHandsChangeToWalkA(mapObject);
        }
    }
    AdvanceMissionRunMapObject(mapObjectList, mapObject);
}

// With chain cameras the hands start moved in y by a prm value and held; otherwise they wait before moving.
void InitIwanteObjects(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *obj;

    if (mapObjectList != NULL) {
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (GetRaceUseChainCameras()) {
                obj->mMapObject.mPos.y += obj->mPrm->mIwante.mChainCameraPosYOffset;
                StartIwanteChainCameraHold(obj);
            } else {
                StartIwanteNoChainCameraWait(obj);
            }
            SetIwanteNoneCollision(obj);
            SetKartCollisionCallback(obj, IwanteKartResponse2Callback);
        }
    }
    SetStandingsEndCallback((void (*)(void)) IwanteStandingsEndCallback);
}

void UpdateIwante(u32 mapObjectList, MissionRunMapObject *mapObject) {
    s32 frameIndex;

    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecidedAndEndReached() : 0) &&
        IsStateNumberBelow(mapObject, 3)) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
            StartIwanteKartEliminatedHold(mapObject);
        } else {
            StartIwanteHideAtEndReached(mapObject);
        }
    }
    if (mapObject->mHandShape == 1) {
        frameIndex = mapObject->mModelAnimationFrameIndex + 1;
        if (frameIndex >= GetMapObjectModelNsbtpFrameCount(mapObject->mNsbmd) - 1) {
            frameIndex = GetMapObjectModelNsbtpFrameCount(mapObject->mNsbmd) - 1;
        }
        mapObject->mModelAnimationFrameIndex = frameIndex;
    } else {
        frameIndex = mapObject->mModelAnimationFrameIndex - 1;
        if (frameIndex <= 0) {
            frameIndex = 0;
        }
        mapObject->mModelAnimationFrameIndex = frameIndex;
    }
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, mapObject->mModelAnimationFrameIndex);
    AdvanceMissionRunMapObject(mapObjectList, mapObject);
}

// Iwante: the two stone hands of Mission Run.
void InitIwante(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *obj;

    if (mapObjectList != NULL) {
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, "iwante_l.nsbmd", "iwante_l.nsbca", "iwante_l.prm");
            LoadMissionRunMapObjectShadow(mapObjectList, obj, "sh_iwante.nsbmd");
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, "iwante_l.nsbtp");
            obj->mCollisionShape = MAP_OBJECT_COLLISION_BOX;
            if (objectIndex == 0) {
                obj->mMapObject.mFlags |= gMapObjectMirrorFlag;
            } else if (objectIndex == 1) {
                obj->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_MIRRORED;
            }
        }
    }
}

void DrawIwante(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

MapObjectKindData *CreateIwanteKindData(void) {
    u32 soundId = 0x21au;
    u32 collideItemSoundId = 0x216u;
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, soundId,
                                               collideItemSoundId);
}

MapObjectList *CreateIwanteDrawList(void) {
    return CreateMapObjectDrawList1(InitIwante, DrawIwante, ToggleShadowScale);
}

MapObjectList *CreateIwanteUpdateList(void) {
    return CreateMapObjectUpdateList(InitIwanteObjects, UpdateIwante, NULL);
}

MapObjectList *CreateIwanteHandsUpdateList(void) {
    return CreateMapObjectUpdateList(InitIwanteHandsObjects, UpdateIwanteHands, NULL);
}

const u32 gIwanteSkipKindSoundFlag = 0x40000000;
const u16 gIwanteSkipListCallbackFlag = 8;
const u16 gIwanteSkipViewTestFlag = 2;
const u16 gIwanteDisabledFlag = 1;
