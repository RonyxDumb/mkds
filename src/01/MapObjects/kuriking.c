#include "01/MapObjects/kuriking.h"
#include "01/MapObjects/kuriking_collision_and_shadow_targets.h"
#include "01/MapObjects/mission_run_map_object.h"
#include "signed_int_divide.h"
#include "01/MapObjects/kuriking_sound_callbacks.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/MapObjects/kuriking_sound_callbacks_setup.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "01/MapObjects/kuriking_update_states.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/kuriking_face_kart_state.h"
#include "Main/Course/course_map_group_entry.h"
#include "01/MapObjects/kuriking_walk_state_starters.h"
#include "01/MapObjects/mission_run_point_in_range_callback.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/map_object_model_load.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/effects.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_kinoko.h"
#include "01/MapObjects/item_bomb_node_placement.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "vector_math.h"
#include "01/MapObjects/kuriking_turn_to_entry_state.h"
#include "01/MapObjects/kuriking_state_shared.h"
#include "01/MapObjects/mission_run_counter_limit.h"
#include "01/MapObjects/bomb_king_sound_and_jump_collision.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/camera.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Item/item_koura_w.h"
#include "01/MapObjects/mission_run_map_objects_reset.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/System/heap.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const u16 gKurikingSkipViewTestFlag = 2;
const u16 gKurikingJumpFlag = 0x20;
const u16 gKurikingDisabledFlag = 1;
const u16 gKurikingSkipListCallbackFlag = 8;
MapObjectKindDescriptor gKurikingKindDescriptor = {
    0,
    {0, 0},
    0x30c,
    InitKurikingMapObject,
    CreateKurikingKindData,
    CreateKurikingDrawList,
    NULL,
    NULL,
    CreateKurikingUpdateList,
    NULL,
    {NULL, NULL, NULL, NULL},
};

void SetKurikingCollisionAndShadow(MissionRunMapObject *mapObject) {
    s32 *shadowScaleTarget;
    KurikingPrm *prm;
    prm = &mapObject->mPrm->mKuriking;
    SetCollisionOffsetAndExtent(mapObject, prm->mHead.mCollisionOffsetY, prm->mHead.mCollisionExtentXZ,
                                prm->mCollisionExtentY);
    SetShadowOffsetYAndScale(mapObject, 0, mapObject->mPrm->mHead.mCollisionExtentXZ);
    shadowScaleTarget = &mapObject->mShadowScaleTargetX;
    *shadowScaleTarget = 0x00011800u;
    mapObject->mShadowScaleX = *shadowScaleTarget;
    shadowScaleTarget = &mapObject->mShadowScaleTargetZ;
    *shadowScaleTarget = 0x0000c000u;
    mapObject->mShadowScaleZ = *shadowScaleTarget;
}

void SetDoubledCollisionAndShadowTargets(MissionRunMapObject *mapObject) {
    u32 offsetPerCall;
    u32 extentPerCall;
    int extentXZ;
    KurikingPrm *prm;
    int offsetY;
    prm = &mapObject->mPrm->mKuriking;
    extentXZ = prm->mHead.mCollisionExtentXZ;
    offsetY = prm->mHead.mCollisionOffsetY;
    offsetPerCall = _s32_div_f(offsetY, 0x14);
    extentPerCall = _s32_div_f(extentXZ, 0x14);
    SetCollisionOffsetAndExtentTarget(mapObject, offsetY << 1, offsetPerCall, extentXZ << 1,
                                      prm->mCollisionExtentY << 1, extentPerCall);
    SetShadowOffsetYAndScaleTarget(mapObject, 0, 0, 0, 0x00000e00u);
    mapObject->mShadowScaleTargetX = 0x00023000u;
    mapObject->mShadowScaleTargetZ = 0x00018000u;
}

void SetTripledCollisionAndShadowTargets(MissionRunMapObject *mapObject) {
    u32 offsetPerCall;
    u32 extentPerCall;
    int extentXZ;
    KurikingPrm *prm;
    int offsetY;
    prm = &mapObject->mPrm->mKuriking;
    extentXZ = prm->mHead.mCollisionExtentXZ;
    offsetY = prm->mHead.mCollisionOffsetY;
    offsetPerCall = _s32_div_f(offsetY, 0x14);
    extentPerCall = _s32_div_f(extentXZ, 0x14);
    SetCollisionOffsetAndExtentTarget(mapObject, offsetY * 3, offsetPerCall, extentXZ * 3, prm->mCollisionExtentY * 3,
                                      extentPerCall);
    SetShadowOffsetYAndScaleTarget(mapObject, 0, 0, 0, 0x00000e00u);
    mapObject->mShadowScaleTargetX = 0x00034800u;
    mapObject->mShadowScaleTargetZ = 0x00024000u;
}

void KurikingFirstSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x223);
}

void KurikingSecondSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x223);
}

void SetKurikingSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0x20, KurikingFirstSoundCallback, 0x40, KurikingSecondSoundCallback);
}

s32 UpdateKurikingKartInRangeState(MissionRunMapObject *mapObject) {
    SetAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    return 0;
}

s32 UpdateKurikingWalkState(MissionRunMapObject *mapObject) {
    SetAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    return 0;
}

s32 UpdateKurikingTurnToEntryState(MissionRunMapObject *mapObject) {
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    return 0;
}

u32 UpdateKurikingFaceKartState(MissionRunMapObject *mapObject) {
    CourseMapGroupEntry *currentGroupEntry;
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetMoveAnglePoint(mapObject, &currentGroupEntry->mPos);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetPointInRangePoint(mapObject, &currentGroupEntry->mPos);
    return 0;
}

void StartKurikingKartInRangeState(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);

    StartMapObjectState(mapObject, 2, UpdateKurikingKartInRangeState);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mKartInRangeAnimationEntry,
                                mapObject->mPrm->mKuriking.mKartInRangeFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mKartInRangeNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mKartInRangeFrameStep, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mKartInRangeSpeedTarget,
                             mapObject->mPrm->mKuriking.mKartInRangeSpeedPerCall);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mKartInRangeAnglePerCallTarget,
                                mapObject->mPrm->mKuriking.mKartInRangeAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKuriking.mKartInRangeFrameCount, NULL);
    SetKurikingSoundCallbacks(mapObject);
}

void SetKurikingWalkByCounter(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) == 0) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mWalkCounterZeroSpeedTarget,
                                 mapObject->mPrm->mKuriking.mWalkCounterZeroSpeedPerCall);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mWalkCounterZeroAnglePerCallTarget,
                                    mapObject->mPrm->mKuriking.mWalkCounterZeroAnglePerCallIncrement);
    } else if (GetAbsoluteCounter(mapObject) == 1) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mWalkCounterOneSpeedTarget,
                                 mapObject->mPrm->mKuriking.mWalkCounterOneSpeedPerCall);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mWalkCounterOneAnglePerCallTarget,
                                    mapObject->mPrm->mKuriking.mWalkCounterOneAnglePerCallIncrement);
    } else {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mWalkCounterOtherSpeedTarget,
                                 mapObject->mPrm->mKuriking.mWalkCounterOtherSpeedPerCall);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mWalkCounterOtherAnglePerCallTarget,
                                    mapObject->mPrm->mKuriking.mWalkCounterOtherAnglePerCallIncrement);
    }
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKuriking.mWalkFrameCount, NULL);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mKuriking.mWalkPointRadius, 0,
                            &GetCurrentGroupEntry(mapObject)->mPos, NULL);
}

void StartKurikingWalkState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, UpdateKurikingWalkState);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mWalkAnimationEntry,
                                mapObject->mPrm->mKuriking.mWalkFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mWalkNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mWalkFrameStep, 0);
    SetKurikingWalkByCounter(mapObject);
    SetKurikingSoundCallbacks(mapObject);
}

void ThrowBombsAndKinoko(MissionRunMapObject *mapObject) {
    KurikingPrm *prm;
    RandomState64 *random;
    u32 firstRange;
    u32 secondRange;
    u32 firstRangeLow;
    u32 secondRangeLow;
    u32 firstScaledDraw;
    u32 secondScaledDraw;
    u16 firstResult;
    u16 secondResult;
    s32 kinokoIndex;
    s32 angle;
    s32 radius;
    s32 throwIndex;

    prm = &mapObject->mPrm->mKuriking;
    angle = mapObject->mAngle - prm->mThrowAngleStep * (mapObject->mThrowCount / 2);
    firstRange = prm->mKinokoRandomLimit;
    if (firstRange == 0x10000) {
        random = GetMapObjectRandom();
        random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
        firstResult = (random->mValue >> 32) * 0x10000 >> 32;
    } else {
        random = GetMapObjectRandom();
        if ((u16) firstRange == 0) {
            firstScaledDraw = 0;
        } else {
            random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
            firstRangeLow = (u16) firstRange;
            if (firstRangeLow == 0) {
                firstScaledDraw = random->mValue >> 32;
            } else {
                firstScaledDraw = ((s64) (random->mValue >> 32) * firstRangeLow) >> 32;
            }
        }
        firstResult = firstScaledDraw;
    }
    if (firstResult == 0) {
        secondRange = mapObject->mThrowCount;
        if (secondRange == 0x10000) {
            random = GetMapObjectRandom();
            random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
            secondResult = (random->mValue >> 32) * 0x10000 >> 32;
        } else {
            random = GetMapObjectRandom();
            if ((u16) secondRange == 0) {
                secondScaledDraw = 0;
            } else {
                random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
                secondRangeLow = (u16) secondRange;
                if (secondRangeLow == 0) {
                    secondScaledDraw = random->mValue >> 32;
                } else {
                    secondScaledDraw = ((s64) (random->mValue >> 32) * secondRangeLow) >> 32;
                }
            }
            secondResult = secondScaledDraw;
        }
        kinokoIndex = secondResult;
    } else {
        kinokoIndex = -1;
    }
    radius = mapObject->mPrm->mKuriking.mThrowRadius;
    for (throwIndex = 0; throwIndex < mapObject->mThrowCount; throwIndex++) {
        Vec3 pos;
        Vec3 vel = {0, 0, 0};

        pos.x = mapObject->mMapObject.mPos.x + (MUL_FIXED12_NO_ROUND(radius, FX_SinIdx((u16) angle)));
        pos.y = mapObject->mMapObject.mPos.y + mapObject->mPrm->mKuriking.mThrowOffsetY;
        pos.z = mapObject->mMapObject.mPos.z + (MUL_FIXED12_NO_ROUND(radius, FX_CosIdx((u16) angle)));
        vel.x = MUL_FIXED12_NO_ROUND(mapObject->mPrm->mKuriking.mThrowSpeed, FX_SinIdx((u16) angle));
        vel.y = mapObject->mPrm->mKuriking.mThrowVelocityY;
        vel.z = MUL_FIXED12_NO_ROUND(mapObject->mPrm->mKuriking.mThrowSpeed, FX_CosIdx((u16) angle));
        if (throwIndex == kinokoIndex) {
            ThrowItemKinokoFromPosition(StartItemKinokoOrZero(), &pos, &vel,
                                        mapObject->mPrm->mKuriking.mThrowKinokoTimer);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedKuribo(), &pos, &vel,
                                      mapObject->mPrm->mKuriking.mThrowBombTimer);
        }
        angle += mapObject->mPrm->mKuriking.mThrowAngleStep;
        StartEffect(0x3f7, &pos);
        StartEffect(0x3f6, &pos);
    }
    StartMapObjectSound(&mapObject->mMapObject, 0x222);
}

void StartKurikingTurnToEntryState(MissionRunMapObject *mapObject) {
    CourseMapGroupEntry *currentGroupEntry;
    KurikingPrm *prm;
    StartMapObjectState(mapObject, 2, &UpdateKurikingTurnToEntryState);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mTurnToEntryAnimationEntry,
                                mapObject->mPrm->mKuriking.mTurnToEntryFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mTurnToEntryNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mTurnToEntryFrameStep, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mTurnToEntrySpeedTarget,
                             mapObject->mPrm->mKuriking.mTurnToEntrySpeedPerCall);
    prm = &mapObject->mPrm->mKuriking;
    TurnAndMoveToPointOwnRates(mapObject, prm->mTurnToEntryAnglePerCallTarget, prm->mTurnToEntryAnglePerCallIncrement,
                               prm->mTurnToEntryMoveAnglePerCallTarget, prm->mTurnToEntryMoveAnglePerCallIncrement);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetAnglePoint(mapObject, &currentGroupEntry->mPos);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetMoveAnglePoint(mapObject, &currentGroupEntry->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKuriking.mTurnToEntryFrameCount, &StartKurikingWalkState);
    SetKurikingSoundCallbacks(mapObject);
}

void StartKurikingThrowBombsState(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 2, (s32(*)(MissionRunMapObject *)) UpdateKurikingFaceKartState);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mKuriking.mThrowBombsAnimationEntry,
                                  mapObject->mPrm->mKuriking.mThrowBombsFrameStep, StartKurikingTurnToEntryState);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mThrowBombsNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mThrowBombsFrameStep, 0);
    SetSpeedTargetAndPerCall(mapObject, 0, mapObject->mPrm->mKuriking.mFaceKartSpeedPerCall);
    SpinTowardPointMoveToPoint(mapObject, 0, mapObject->mPrm->mKuriking.mFaceKartAnglePerCallIncrement,
                               mapObject->mPrm->mKuriking.mFaceKartMoveAnglePerCallTarget,
                               mapObject->mPrm->mKuriking.mFaceKartMoveAnglePerCallIncrement);
    SetAnglePoint(mapObject, &kart->mPos);
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mKuriking.mThrowBombsFrameIndex, ThrowBombsAndKinoko);
}

void StartKurikingFaceKartState(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 2, (s32(*)(MissionRunMapObject *)) UpdateKurikingFaceKartState);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mFaceKartAnimationEntry,
                                mapObject->mPrm->mKuriking.mFaceKartFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mFaceKartNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mFaceKartFrameStep, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mFaceKartSpeedTarget,
                             mapObject->mPrm->mKuriking.mFaceKartSpeedPerCall);
    SpinTowardPointMoveToPoint(mapObject, mapObject->mPrm->mKuriking.mFaceKartAnglePerCallTarget,
                               mapObject->mPrm->mKuriking.mFaceKartAnglePerCallIncrement,
                               mapObject->mPrm->mKuriking.mFaceKartMoveAnglePerCallTarget,
                               mapObject->mPrm->mKuriking.mFaceKartMoveAnglePerCallIncrement);
    SetAnglePoint(mapObject, &kart->mPos);
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKuriking.mFaceKartFrameCount,
                                 StartKurikingThrowBombsState);
    mapObject->mThrowCount = GetCurrentGroupEntryValue(mapObject);
    SetKurikingSoundCallbacks(mapObject);
}

void StartKurikingJumpLandState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mKuriking.mJumpLandAnimationEntry,
                                  mapObject->mPrm->mKuriking.mJumpLandFrameStep, NULL);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mJumpLandNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mJumpLandFrameStep, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_HUD_XLU;
}

void StartKurikingJumpState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mKuriking.mJumpVelocityY;
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mJumpAnimationEntry,
                                mapObject->mPrm->mKuriking.mJumpFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mJumpNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mJumpFrameStep, 0);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mJumpSpeedTarget,
                             mapObject->mPrm->mKuriking.mJumpSpeedPerCall);
    SetCourseCollisionCallback(mapObject, StartKurikingJumpLandState);
    StartMapObjectSound(&mapObject->mMapObject, 0x226);
    mapObject->mMapObject.mFlags |= gKurikingJumpFlag;
}

void StartKurikingJumpAnimationState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mKuriking.mJumpAnimationStateAnimationEntry,
                                  mapObject->mPrm->mKuriking.mJumpAnimationStateFrameStep, StartKurikingJumpState);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mJumpAnimationStateNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mJumpAnimationStateFrameStep, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartKurikingTurnToRowState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mTurnToRowAnimationEntry,
                                mapObject->mPrm->mKuriking.mTurnToRowFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mTurnToRowNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mTurnToRowFrameStep, 0);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mTurnToRowAnglePerCallTarget,
                                mapObject->mPrm->mKuriking.mTurnToRowAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &mapObject->mMapObject.mCourseMapRow->mPosition);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mTurnToRowSpeedTarget,
                             mapObject->mPrm->mKuriking.mTurnToRowSpeedPerCall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKuriking.mTurnToRowFrameCount,
                                 StartKurikingJumpAnimationState);
    SetKurikingSoundCallbacks(mapObject);
}

int UpdateKurikingGrowSound(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) == 1) {
        StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x220);
    } else if (GetAbsoluteCounter(mapObject) == 2) {
        StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x221);
    }
    return 0;
}

void StartKurikingGrowState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateKurikingGrowSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mGrowAnimationEntry,
                                mapObject->mPrm->mKuriking.mGrowFrameStep);
    StartMapObjectModelNsbtaAnimation(mapObject->mNsbmd, mapObject->mPrm->mKuriking.mGrowNsbtaEntryIndex,
                                      mapObject->mPrm->mKuriking.mGrowFrameStep, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mGrowSpeedTarget,
                             mapObject->mPrm->mKuriking.mGrowSpeedPerCall);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mGrowAnglePerCallTarget,
                                mapObject->mPrm->mKuriking.mGrowAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKuriking.mGrowFrameCount, StartKurikingWalkState);
    SetScaleTargetAndPerCall(mapObject,
                             (mapObject->mMapObject.mScale.x + mapObject->mPrm->mKuriking.mGrowScaleIncrease),
                             mapObject->mPrm->mKuriking.mGrowScalePerCall);
    SetSpeedAndClearTarget(mapObject, 0);
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, GetAbsoluteCounter(mapObject));
    if (GetAbsoluteCounter(mapObject) == 0) {
        SetDoubledCollisionAndShadowTargets(mapObject);
        StartEffectAtScaledOffset(mapObject, 0, 0x1800, 0, 0x419, 0);
    } else if (GetAbsoluteCounter(mapObject) == 1) {
        SetTripledCollisionAndShadowTargets(mapObject);
        StartEffectAtScaledOffset(mapObject, 0, 0x1800, 0, 0x41a, 0);
    }
}

void GrowKuriking(MissionRunMapObject *mapObject) {
    StartKurikingGrowState(mapObject);
    DecrementCounterToNegativeLimit(mapObject);
}

void StartKurikingChaseKartState(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mChaseKartAnimationEntry,
                                mapObject->mPrm->mKuriking.mChaseKartFrameStep);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKuriking.mChaseKartAnglePerCallTarget,
                                mapObject->mPrm->mKuriking.mChaseKartAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKuriking.mChaseKartSpeedTarget,
                             mapObject->mPrm->mKuriking.mChaseKartSpeedPerCall);
}

void StartKurikingEndEffects(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartEffect(0x418, &mapObject->mMapObject.mPos);
    StartEffect(0x417, &mapObject->mMapObject.mPos);
    StartEffect(0x416, &mapObject->mMapObject.mPos);
    {
        SoundStartParams soundRequest = {0x225, 0, 0xf, 0};

        soundRequest.mPositionSource = &mapObject->mMapObject.mPos;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(soundRequest.mPositionSource);
        StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
    }
    mapObject->mMapObject.mFlags |= gKurikingSkipViewTestFlag;
    mapObject->mMapObject.mFlags |= gKurikingSkipListCallbackFlag;
    mapObject->mMapObject.mFlags |= gKurikingDisabledFlag;
}

void StartKurikingKartNotEliminatedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKuriking.mKartNotEliminatedAnimationEntry,
                                mapObject->mPrm->mKuriking.mKartNotEliminatedFrameStep);
    StartStateFrameCountCallback(mapObject, 0x3c, &StartKurikingEndEffects);
}

void KurikingStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

s32 KurikingStopStateWhenRaceStarted(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

s32 UpdateKurikingStartupEffects(MissionRunMapObject *mapObject) {
    int nsbcaFrameIndex;
    nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
    if (nsbcaFrameIndex == 0x4d) {
        ReleaseEffects(mapObject);
        StartEffectAtRowHeight(mapObject, (0xfffff99au), 0, (0xfffff99au), (0x0000042bu), 0);
        StartMapObjectSound(&mapObject->mMapObject, (0x0000021eu));
    } else {
        nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (nsbcaFrameIndex == 0x68) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, (0xfffff99au), 0, (0xfffff99au), (0x0000042cu), 0);
            StartMapObjectSound(&mapObject->mMapObject, (0x0000021fu));
        }
    }
    return 0;
}

void StartKurikingWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, KurikingStopStateWhenRaceStarted);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mHead.mWaitForRaceStartFrameStep);
}

void StartKurikingStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateKurikingStartupEffects);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHead.mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mHead.mStartupSecondFrameStep, &StartKurikingWaitForRaceStart);
}

void StartKurikingStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 &StartKurikingStartupSecond);
}

void StartKurikingChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupSecondFrameStep);
}

void StartKurikingChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstFrameCount,
                                 &StartKurikingChainStartupSecond);
}

void InitKurikingMapObject(MissionRunMapObject *mapObject) {
    CreateParkedMapObjects(MAP_OBJECT_KIND_KURIBO, 0x32, mapObject);
    mapObject->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mMapObject.mSound->mSoundSource, 0xf, &mapObject->mMapObject.mPos);
    mapObject->mMapObject.mFarDistanceSquared = gSoundFalloffs[15].mFarDistanceSquared;
}

void KurikingKartHitSoundCallback(MissionRunMapObject *mapObject, Kart *kart) {
    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
    if (mapObject->mTimer == 0) {
        StartSoundFullVolumeWrapper(kart, 0x224);
    }
}

void KurikingKartHitCallback(MissionRunMapObject *mapObject, Kart *kart) {
    mapObject->mMapObject.mPosStep.x =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mKuriking.mKartHitSpeed, FX_SinIdx((u16) mapObject->mMoveAngle));
    mapObject->mMapObject.mPosStep.y = 0;
    mapObject->mMapObject.mPosStep.z =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mKuriking.mKartHitSpeed, FX_CosIdx((u16) mapObject->mMoveAngle));
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
    if (mapObject->mTimer == 0) {
        StartSoundFullVolumeWrapper(kart, 0x224);
    }
}

void InitKurikingObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    MissionRunMapObject *obj;

    if (mapObjectList != NULL) {
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            StartMapObjectModelNsbtaAnimation(obj->mNsbmd, obj->mPrm->mKuriking.mStartupNsbtaEntryIndex,
                                              obj->mPrm->mHead.mStartupFirstFrameStep, 0);
            if (GetRaceUseChainCameras()) {
                StartKurikingChainStartupFirst(obj);
            } else {
                StartKurikingStartupFirst(obj);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) KurikingStandingsEndCallback);
}

void UpdateKuriking(u32 unused, MissionRunMapObject *mapObject) {
    s32 var;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (IsStateNumberBelow(mapObject, 1)) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                StartKurikingChaseKartState(mapObject);
            } else {
                StartKurikingKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos,
                           mapObject->mPrm->mKuriking.mWalkPointRadius, 0)) {
            var = GetCurrentGroupEntryValue(mapObject);
            if (var >= 200) {
                if (IsStateNumberBelow(mapObject, 8)) {
                    GrowKuriking(mapObject);
                    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
                }
            } else if (var >= 100) {
                if (IsStateNumberBelow(mapObject, 7)) {
                    StartKurikingTurnToRowState(mapObject);
                    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
                }
            } else if (var >= 1) {
                if (IsStateNumberBelow(mapObject, 1)) {
                    StartKurikingFaceKartState(mapObject);
                    SetKartCollisionCallback(mapObject, KurikingKartHitSoundCallback);
                }
            }
            IncrementEntryIndex(mapObject);
            if (mapObject->mEntryIndex == 0) {
                IncrementEntryGroupIndex(mapObject, 3);
            }
        }
        if (IsStateNumberBelow(mapObject, 2)) {
            if (GetEntryKartInRange(mapObject, mapObject->mPrm->mKuriking.mKartRadius,
                                    mapObject->mPrm->mKuriking.mKartHalfAngle)) {
                StartKurikingKartInRangeState(mapObject);
                SetKartCollisionCallback(mapObject, KurikingKartHitCallback);
            }
        }
        if (IsStateNumberBelow(mapObject, 1)) {
            StartKurikingWalkState(mapObject);
            SetKartCollisionCallback(mapObject, KurikingKartHitCallback);
        }
        mapObject->mCourseCollisionMode = MAP_OBJECT_COURSE_COLLISION_ALT_FILTER;
    }
    AdvanceMissionRunMapObject(unused, mapObject);
    AdvanceMapObjectModelNsbtaAnimation(mapObject->mNsbmd);
    var = mapObject->mModelAnimationFrameIndex + 1;
    if (var >= GetAbsoluteCounter(mapObject) * 30) {
        var = GetAbsoluteCounter(mapObject) * 30;
    }
    mapObject->mModelAnimationFrameIndex = var;
    var = mapObject->mModelAnimationFrameIndex;
    if (var >= GetMapObjectModelNsbmaFrameCount(mapObject->mNsbmd) - 1) {
        var = GetMapObjectModelNsbmaFrameCount(mapObject->mNsbmd) - 1;
    }
    mapObject->mModelAnimationFrameIndex = var;
    SetMapObjectModelNsbmaFrameIndex(mapObject->mNsbmd, (u16) mapObject->mModelAnimationFrameIndex);
}

void InitKuriking(MapObjectList *mapObjectList) {
    s32 objectIndex;
    MissionRunMapObject *obj;

    if (mapObjectList != NULL) {
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, ("kuriking.nsbmd"), ("kuriking.nsbca"), ("kuriking.prm"));
            LoadMissionRunMapObjectShadow(mapObjectList, obj, ("sh_circle.nsbmd"));
            LoadMapObjectModelNsbtaAnimation(obj->mNsbmd, "kuriking.nsbta");
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, "kuriking.nsbtp");
            LoadMapObjectModelNsbmaAnimation(obj->mNsbmd, "kuriking.nsbma");
            SetKurikingCollisionAndShadow(obj);
            SetKartCollisionCallback(obj, KurikingKartHitSoundCallback);
        }
    }
}

void DrawKuriking(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

MapObjectKindData *CreateKurikingKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

MapObjectList *CreateKurikingDrawList(void) {
    return CreateMapObjectDrawList1(InitKuriking, DrawKuriking, ToggleShadowScale);
}

MapObjectList *CreateKurikingUpdateList(void) {
    return CreateMapObjectUpdateList(InitKurikingObjects, UpdateKuriking, NULL);
}
