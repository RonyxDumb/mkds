#include "01/MapObjects/bomb_king.h"
#include "Main/Item/item_object_bounce_hit_release_fade.h"
#include "01/MapObjects/bomb_king_sound_and_jump_collision.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/map_object_sound.h"
#include "01/MapObjects/bomb_king_sound_callbacks.h"
#include "01/MapObjects/item_bomb_throw_in_ring.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/item_bomb_throw_or_release.h"
#include "01/MapObjects/item_bomb_is_stored.h"
#include "01/MapObjects/item_bomb_node_placement.h"
#include "Main/Item/item_bomb.h"
#include "fixed_vector_math.h"
#include "01/MapObjects/bomb_king_effect_and_sound.h"
#include "01/MapObjects/bomb_king_jump_fall_and_land.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "Main/Kart/camera.h"
#include "01/MapObjects/bomb_king_jump_throw_bombs.h"
#include "01/MapObjects/bomb_king_jump_states.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "01/MapObjects/mission_run_entry_index.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "01/MapObjects/bomb_king_walk_and_throw_states.h"
#include "01/MapObjects/item_bomb_release_and_set.h"
#include "01/MapObjects/mission_run_point_in_range_callback.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Kart/kart_drift.h"
#include "01/MapObjects/bomb_king_bounce_and_stopped.h"
#include "01/MapObjects/bomb_king_item_hit.h"
#include "01/MapObjects/mission_run_hit_count.h"
#include "01/MapObjects/bomb_king_kart_eliminated.h"
#include "01/MapObjects/mission_run_map_objects_reset.h"
#include "Main/System/heap.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/mission_run_collision_shadow_offsets.h"
#include "particle_instance.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/System/heap_call.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "01/MapObjects/hanachan_move_and_followers.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/Sound/sound_handle_start_and_distance_change.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Item/item_object_bounce_hit_release_fade.h"

const u32 gBombKingSkipKindSoundFlag = 0x40000000;
const u16 gBombKingSkipListCallbackFlag = 8;
const u16 gBombKingJumpFlag = 0x20;
const u16 gBombKingDisabledFlag = 1;
const u16 gBombKingSkipViewTestFlag = 2;
SoundStartParams gBombKingEndSoundParams = {0x23d, NULL, 0xc, 0};
MapObjectKindDescriptor gBombKingKindDescriptor = {0,
                                                   {0, 0},
                                                   0x30c,
                                                   InitBombKingMapObject,
                                                   CreateBombKingKindData,
                                                   CreateBombKingDrawList,
                                                   NULL,
                                                   NULL,
                                                   CreateBombKingUpdateList,
                                                   NULL,
                                                   {NULL, NULL, NULL, NULL}};

u16 GetAbsoluteCounterWrapper(MissionRunMapObject *mapObject) {
    return GetAbsoluteCounter(mapObject);
}

void BombKingJumpKartCollisionCallback(MissionRunMapObject *mapObject, Kart *kart) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT;
    mapObject->mMapObject.mDistanceSquaredAndFlags |= gBombKingSkipKindSoundFlag;
}

void BombKingFirstSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x237);
}

void BombKingSecondSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mMapObject, 0x237);
}

void SetBombKingSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 1, BombKingFirstSoundCallback, 0x1f, BombKingSecondSoundCallback);
}

void ThrowStoredItemBomb(MissionRunMapObject *mapObject) {
    Vec3 velocity;

    if (IsItemBombStored(mapObject)) {
        velocity.x = (MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mStoredBombThrowSpeed,
                                           FX_SinIdx((u16) mapObject->mMoveAngle)));
        velocity.y = mapObject->mPrm->mBombKing.mStoredBombThrowVelocityY;
        velocity.z = (MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mStoredBombThrowSpeed,
                                           FX_CosIdx((u16) mapObject->mMoveAngle)));
        ThrowOrReleaseStoredItemBomb(mapObject, &velocity, mapObject->mPrm->mBombKing.mStoredBombThrowTimer);
    }
}

void ThrowItemBombsInRing(MissionRunMapObject *mapObject) {
    RandomState64 *random;
    s32 angle;
    s32 bombIndex;
    Vec3 pos;

    random = GetMapObjectRandom();
    random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
    angle = RANDOM_HIGH16(random);
    for (bombIndex = 0; bombIndex < 3; bombIndex++) {
        Vec3 velocity = {0, 0, 0};
        angle += 0x5555;
        if (GetAbsoluteCounter(mapObject) == 0) {
            pos.x = mapObject->mMapObject.mPos.x +
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mRingRadiusCounterZero, SIN_OF_ANGLE((u16) angle));
            pos.y = mapObject->mMapObject.mPos.y + mapObject->mPrm->mBombKing.mRingOffsetYCounterZero;
            pos.z = mapObject->mMapObject.mPos.z +
                    MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mRingRadiusCounterZero, COS_OF_ANGLE((u16) angle));
        } else {
            pos.x =
                mapObject->mMapObject.mPos.x +
                MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mRingRadiusCounterNonZero, SIN_OF_ANGLE((u16) angle));
            pos.y = mapObject->mMapObject.mPos.y + mapObject->mPrm->mBombKing.mRingOffsetYCounterNonZero;
            pos.z =
                mapObject->mMapObject.mPos.z +
                MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mRingRadiusCounterNonZero, COS_OF_ANGLE((u16) angle));
        }
        if (bombIndex == 0) {
            ThrowItemBombFromPosition(StartItemBomb(), &pos, &velocity, mapObject->mPrm->mBombKing.mRingBombTimer);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos, &velocity,
                                      mapObject->mPrm->mBombKing.mRingParkedBombTimer);
        }
    }
    StartEffectAtRowHeight(mapObject, 0x2000, 0, 0x3ae, 0x410, 0);
    StartMapObjectSound(&mapObject->mMapObject, 0x236);
}

void StartBombKingEffectAndSound(MissionRunMapObject *mapObject) {
    StartEffectAtRowHeight(mapObject, (0x00002000u), 0, (0x000003aeu), (0x00000410u), 0);
    StartMapObjectSound(&mapObject->mMapObject, (0x00000236u));
}

void ThrowItemBombsInRingAndCenter(MissionRunMapObject *mapObject) {
    RandomState64 *random;
    s32 angle;
    s32 bombIndex;
    Vec3 pos;

    random = GetMapObjectRandom();
    random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
    angle = RANDOM_HIGH16(random);
    for (bombIndex = 0; bombIndex < 3; bombIndex++) {
        Vec3 velocity = {0, 0, 0};
        angle += 0x5555;
        pos.x = mapObject->mMapObject.mPos.x +
                MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mJumpRingRadius, SIN_OF_ANGLE((u16) angle));
        pos.y = mapObject->mMapObject.mPos.y;
        pos.z = mapObject->mMapObject.mPos.z +
                MUL_FIXED12_NO_ROUND(mapObject->mPrm->mBombKing.mJumpRingRadius, COS_OF_ANGLE((u16) angle));
        ThrowItemBombFromPosition(StartItemBomb(), &pos, &velocity, mapObject->mPrm->mBombKing.mJumpRingBombTimer);
    }
    {
        Vec3 centerPos;
        Vec3 centerVelocity = {0, 0, 0};
        centerPos.x = mapObject->mMapObject.mPos.x;
        centerPos.y = mapObject->mMapObject.mPos.y;
        centerPos.z = mapObject->mMapObject.mPos.z;
        ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &centerPos, &centerVelocity,
                                  mapObject->mPrm->mBombKing.mJumpCenterParkedBombTimer);
    }
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartBombKingJumpLandState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpLandAnimationEntry,
                                  mapObject->mPrm->mBombKing.mJumpLandFrameStep, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK, 0x1000);
    mapObject->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_HUD_XLU;
    SetKartCollisionCallback(mapObject, NULL);
}

void StartBombKingJumpFallState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mBombKing.mJumpFallVelocityY;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpFallAnimationEntry,
                                mapObject->mPrm->mBombKing.mJumpFallFrameStep);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetCourseCollisionCallback(mapObject, StartBombKingJumpLandState);
    mapObject->mGravityEnabled = TRUE;
    StartMapObjectSound(&mapObject->mMapObject, 0x23a);
    SetKartCollisionCallback(mapObject, BombKingJumpKartCollisionCallback);
}

void StartBombKingJumpThrowBombsState(MissionRunMapObject *mapObject) {
    ThrowItemBombsInRingAndCenter(mapObject);
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpThrowBombsAnimationEntry,
                                mapObject->mPrm->mBombKing.mJumpThrowBombsFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mJumpThrowBombsFrameCount,
                                 &StartBombKingJumpFallState);
    mapObject->mGravityEnabled = FALSE;
}

void StartBombKingJumpToEntryState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpToEntryAnimationEntry,
                                mapObject->mPrm->mBombKing.mJumpToEntryFrameStep);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mBombKing.mJumpToEntryAnglePerCallTarget,
                                mapObject->mPrm->mBombKing.mJumpToEntryAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mBombKing.mJumpToEntrySpeedTarget,
                             mapObject->mPrm->mBombKing.mJumpToEntrySpeedPerCall);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mJumpToEntryFrameCount,
                                 StartBombKingJumpThrowBombsState);
    mapObject->mGravityEnabled = FALSE;
}

void StartBombKingJumpState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mBombKing.mJumpVelocityY;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpAnimationEntry,
                                mapObject->mPrm->mBombKing.mJumpFrameStep);
    SetVelocity(mapObject, &velocity);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mBombKing.mJumpSpeedTarget,
                             mapObject->mPrm->mBombKing.mJumpSpeedPerCall);
    SetCourseCollisionCallback(mapObject, StartBombKingJumpLandState);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mJumpFrameCount, StartBombKingJumpToEntryState);
    StartMapObjectSound(&mapObject->mMapObject, 0x239);
    mapObject->mMapObject.mFlags |= gBombKingJumpFlag;
}

void StartBombKingJumpWaitState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpWaitAnimationEntry,
                                mapObject->mPrm->mBombKing.mJumpWaitFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mJumpWaitFrameCount, &StartBombKingJumpState);
    StartMapObjectSound(&mapObject->mMapObject, 0x238);
}

void StartBombKingJumpCycle(MissionRunMapObject *mapObject) {
    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mJumpCycleAnimationEntry,
                                mapObject->mPrm->mBombKing.mJumpCycleFrameStep);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mBombKing.mJumpCycleAnglePerCallTarget,
                                mapObject->mPrm->mBombKing.mJumpCycleAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mBombKing.mJumpCycleSpeedTarget,
                             mapObject->mPrm->mBombKing.mJumpCycleSpeedPerCall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mJumpCycleFrameCount,
                                 &StartBombKingJumpWaitState);
    SetBombKingSoundCallbacks(mapObject);
}

void StartBombKingThrowBombsState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mBombKing.mThrowBombsAnimationEntry,
                                  mapObject->mPrm->mBombKing.mThrowBombsFrameStep, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mBombKing.mThrowBombsFrameIndex, ThrowItemBombsInRing);
}

void StoreNewItemBombAndStartThrow(MissionRunMapObject *mapObject) {
    void *bomb;

    if (IsItemBombStored(mapObject) == 0) {
        bomb = StartItemBomb();
        if (bomb != NULL) {
            ReleaseAndSetItemBomb(mapObject, (bomb));
        }
    }
    if (IsItemBombStored(mapObject) != 0) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mBombKing.mStoredBombThrowAnimationEntry,
                                      mapObject->mPrm->mBombKing.mStoredBombThrowFrameStep, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->mBombKing.mStoredBombThrowFrameIndex,
                                  ThrowStoredItemBomb);
    }
    StartMapObjectSound(&mapObject->mMapObject, 0x23c);
}

void StartBombKingChaseState(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetEntryKartInRange(mapObject, mapObject->mPrm->mBombKing.mKartRadius,
                               mapObject->mPrm->mBombKing.mKartHalfAngle);
    if (kart != NULL) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mChaseAnimationEntry,
                                    mapObject->mPrm->mBombKing.mChaseFrameStep);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mBombKing.mChaseAnglePerCall,
                                    mapObject->mPrm->mBombKing.mChaseAnglePerCall);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mBombKing.mChaseSpeed);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->mBombKing.mKartPointRadius,
                                mapObject->mPrm->mBombKing.mKartPointHalfAngle, &kart->mPos,
                                &StoreNewItemBombAndStartThrow);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mChaseFrameCount, 0);
        SetBombKingSoundCallbacks(mapObject);
    } else {
        StopMapObjectState(mapObject);
    }
}

void StartItemBombThrow(MissionRunMapObject *mapObject) {
    if (IsItemBombStored(mapObject) != 0) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mBombKing.mStoredBombThrowAnimationEntry,
                                      mapObject->mPrm->mBombKing.mStoredBombThrowFrameStep, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->mBombKing.mStoredBombThrowFrameIndex,
                                  ThrowStoredItemBomb);
        StartMapObjectSound(&mapObject->mMapObject, 0x23c);
    }
}

void StartBombKingStoreFoundItemBombState(MissionRunMapObject *mapObject) {
    ItemBomb *bomb;
    Kart *kart;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->mBombKing.mBombPointRadius,
                               mapObject->mPrm->mBombKing.mBombPointHalfAngle);
    if (bomb != NULL) {
        kart = GetEntryKartInRange(mapObject, mapObject->mPrm->mBombKing.mKartRadius,
                                   mapObject->mPrm->mBombKing.mKartHalfAngle);
        if (kart != NULL) {
            ParkItemBomb(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            StartMapObjectState(mapObject, 3, NULL);
            StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mStoreFoundBombAnimationEntry,
                                        mapObject->mPrm->mBombKing.mStoreFoundBombFrameStep);
            TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mBombKing.mStoreFoundBombAnglePerCall,
                                        mapObject->mPrm->mBombKing.mStoreFoundBombAnglePerCall);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mBombKing.mStoreFoundBombSpeed);
            SetPointInRangeCallback(mapObject, mapObject->mPrm->mBombKing.mKartPointRadius,
                                    mapObject->mPrm->mBombKing.mKartPointHalfAngle, &kart->mPos, &StartItemBombThrow);
            SetBombKingSoundCallbacks(mapObject);
        } else {
            ParkItemBomb(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            StartItemBombThrow(mapObject);
        }
    }
}

void StartBombKingWalkToBombState(MissionRunMapObject *mapObject) {
    ItemBomb *bomb;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->mBombKing.mFindBombRadius,
                               mapObject->mPrm->mBombKing.mFindBombHalfAngle);
    if (bomb != NULL) {
        StartMapObjectState(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mChaseAnimationEntry,
                                    mapObject->mPrm->mBombKing.mChaseFrameStep);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mBombKing.mWalkToBombAnglePerCall,
                                    mapObject->mPrm->mBombKing.mWalkToBombAnglePerCall);
        SetAnglePointAndMoveAnglePoint(mapObject, &bomb->mBouncingItemObject.mItemObject.mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mBombKing.mWalkToBombSpeed);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->mBombKing.mBombPointRadius,
                                mapObject->mPrm->mBombKing.mBombPointHalfAngle,
                                &bomb->mBouncingItemObject.mItemObject.mPos, &StartBombKingStoreFoundItemBombState);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mWalkToBombFrameCount, 0);
        SetBombKingSoundCallbacks(mapObject);
    }
}

void StartBombKingRandomState(MissionRunMapObject *mapObject) {
    u32 randomLimit;
    RandomState64 *rng;
    u32 randomValue;

    randomLimit = (u16) mapObject->mPrm->mBombKing.mRandomLimit;
    if (randomLimit == 0x10000) {
        rng = GetMapObjectRandom();
        rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
        randomValue = (u16) RANDOM_BELOW(rng, 0x10000);
    } else {
        rng = GetMapObjectRandom();
        if ((u16) randomLimit == 0) {
            randomValue = 0;
        } else {
            rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
            if ((u16) randomLimit == 0) {
                randomValue = RANDOM_HIGH32(rng);
            } else {
                randomValue = RANDOM_BELOW(rng, (s64) (u16) randomLimit);
            }
        }
        randomValue = (u16) randomValue;
    }
    if (randomValue != 0) {
        StartBombKingThrowBombsState(mapObject);
    } else {
        StartBombKingChaseState(mapObject);
    }
}

void StartBombKingWalkState(MissionRunMapObject *mapObject) {
    BombKingPrm *prm;

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 2, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mWalkAnimationEntry,
                                mapObject->mPrm->mBombKing.mWalkFrameStep);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mBombKing.mWalkAnglePerCall,
                                mapObject->mPrm->mBombKing.mWalkAnglePerCall);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mBombKing.mWalkSpeed);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mBombKing.mWalkFrameCount, &StartBombKingRandomState);
    prm = &mapObject->mPrm->mBombKing;
    SetPointInRangeCallback(mapObject, prm->mWalkPointRadius, prm->mWalkPointHalfAngle,
                            &GetCurrentGroupEntry(mapObject)->mPos, &StartBombKingThrowBombsState);
    SetBombKingSoundCallbacks(mapObject);
}

int StartBombKingBounceEffects(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & COURSE_HIT_GROUND) != 0) {
        if (mapObject->mVelocity.y > 0x3333) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
        }
        if (mapObject->mVelocity.y > 0) {
            StartMapObjectSound(&mapObject->mMapObject, 0x23b);
        }
    }
    return 0;
}

int SwitchToBounceEffectsOnCollision(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & COURSE_HIT_GROUND) != 0) {
        mapObject->mStateFunction = StartBombKingBounceEffects;
    }
    return 0;
}

void StartBombKingStoppedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mBombKing.mStoppedAnimationEntry,
                                  mapObject->mPrm->mBombKing.mStoppedFrameStep, NULL);
    SetItemCollisionCallback(mapObject, &BombKingItemHitCallback);
}

void StartBombKingBounceState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &SwitchToBounceEffectsOnCollision);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mBounceAnimationEntry,
                                mapObject->mPrm->mBombKing.mBounceFrameStep);
    SetStoppedCallback(mapObject, &StartBombKingStoppedState);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, &BombKingItemBounceCallback);
}

void StartBombKingStoppedStateAfterHits(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mBombKing.mStoppedAfterHitsAnimationEntry,
                                  mapObject->mPrm->mBombKing.mStoppedAfterHitsFrameStep, NULL);
    SetItemCollisionCallback(mapObject, &BombKingItemHitCallback);
}

void StartBombKingBounceStateAfterHits(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &SwitchToBounceEffectsOnCollision);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mBounceAnimationEntry,
                                mapObject->mPrm->mBombKing.mBounceFrameStep);
    SetStoppedCallback(mapObject, &StartBombKingStoppedStateAfterHits);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, &BombKingItemBounceCallback);
}

void StartBombKingItemHitState(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartBombKingBounceStateAfterHits(mapObject);
    } else {
        StartBombKingBounceState(mapObject);
    }
    IncrementHitCountAndCheckLimit(mapObject);
}

void StartBombKingKartEliminatedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mKartEliminatedAnimationEntry,
                                mapObject->mPrm->mBombKing.mKartEliminatedFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartBombKingNotEliminatedEffects(MissionRunMapObject *mapObject) {
    SoundStartParams soundRequest;

    StartMapObjectState(mapObject, 8, NULL);
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x421, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40c, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40e, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40d, 0);
    StartEffectAtOffset(mapObject, 0, 0x2000, 0, 0x40f, 0);
    soundRequest = gBombKingEndSoundParams;
    soundRequest.mPositionSource = &mapObject->mMapObject.mPos;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mMapObject.mPos);
    StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
    mapObject->mMapObject.mFlags |= gBombKingSkipViewTestFlag;
    mapObject->mMapObject.mFlags |= gBombKingSkipListCallbackFlag;
    mapObject->mMapObject.mFlags |= gBombKingDisabledFlag;
}

void StartBombKingKartNotEliminatedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mBombKing.mStoppedAfterHitsAnimationEntry,
                                mapObject->mPrm->mBombKing.mStoppedAfterHitsFrameStep);
    StartStateFrameCountCallback(mapObject, 0x3c, &StartBombKingNotEliminatedEffects);
}

void BombKingStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

s32 StopStateWhenRaceStarted(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

void StartBombKingWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, StopStateWhenRaceStarted);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mHead.mWaitForRaceStartFrameStep);
}

void StartBombKingStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHead.mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mHead.mStartupSecondFrameStep, &StartBombKingWaitForRaceStart);
    SetAnimationFrameCallback(mapObject, ((u32) mapObject->mPrm->mBombKing.mThrowBombsFrameIndex),
                              ThrowItemBombsInRing);
}

void StartBombKingStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 &StartBombKingStartupSecond);
    StartMapObjectSound(&mapObject->mMapObject, 0x00000235u);
}

void StartBombKingChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupSecondFrameStep);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mBombKing.mThrowBombsFrameIndex, StartBombKingEffectAndSound);
}

void StartBombKingChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstFrameCount,
                                 &StartBombKingChainStartupSecond);
}

void InitBombKingObjects(MapObjectList *list) {
    int objectIndex;
    MissionRunMapObject *mapObject;

    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (mapObject = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            Vec3 offset = {0, 0, 0};
            offset.x = mapObject->mPrm->mBombKing.mBombOffsetX;
            offset.y = mapObject->mPrm->mBombKing.mBombOffsetY;
            SetNodePositionSourceAndBombOffset(mapObject, 5, (&offset));
            if (GetRaceUseChainCameras() != 0) {
                StartBombKingChainStartupFirst(mapObject);
            } else {
                StartBombKingStartupFirst(mapObject);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) BombKingStandingsEndCallback);
}

void UpdateBombKing(u32 unused, MissionRunMapObject *mapObject) {
    int result;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        result = IsWinnerDecided();
    } else {
        result = 0;
    }
    if (result != 0) {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                result = IsKartEliminated((u16) gRaceSetup->mEntryIndex);
            } else {
                result = 0;
            }
            if (result != 0) {
                StartBombKingKartEliminatedState(mapObject);
            } else {
                StartBombKingKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsStateNumberBelow(mapObject, 3) != 0) {
            if (GetAbsoluteCounter(mapObject) >= 2) {
                StartBombKingJumpCycle(mapObject);
            }
        }
        if (IsStateNumberBelow(mapObject, 3) != 0) {
            StartBombKingWalkToBombState(mapObject);
        }
        if (IsStateNumberBelow(mapObject, 2) != 0) {
            StartBombKingWalkState(mapObject);
        }
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitBombKingMapObject(MissionRunMapObject *mapObject) {
    CreateParkedMapObjects(MAP_OBJECT_KIND_GROUP_ITEM_BOX, 0xa, mapObject);
    mapObject->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mMapObject.mSound->mSoundSource, 0xc, &mapObject->mMapObject.mPos);
    mapObject->mMapObject.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void SetBombKingEffectScale(ParticleEmitter *emitter) {
    emitter->mSizeScale = TO_FIXED12(2);
}

void BombKingItemBounceCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    if (itemObject->mKind == ITEM_OBJECT_KIND_BOMB) {
        if (IsItemBombGrowing(itemObject) == FALSE) {
            StartEffectWithCallback(0x3a, &itemObject->mPos, NULL, SetBombKingEffectScale);
        }
    }
    mapObject->mItemResponse = ITEM_HIT_TYPE_BOUNCE;
    SetItemCollisionCallback(mapObject, BombKingItemBounceCallback);
}

void BombKingItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    Vec3 velocity;
    s64 scale;

    if (IsItemBombStored(mapObject) != 0) {
        ThrowOrReleaseStoredItemBomb(mapObject, NULL, 0);
    }
    mapObject->mItemResponse = ITEM_HIT_TYPE_FADE_OUT;
    SetItemCollisionCallback(mapObject, BombKingItemHitCallback);
    if (IsStateNumberBelow(mapObject, 7) != 0) {
        velocity.x = mapObject->mMapObject.mPos.x - itemObject->mPos.x;
        velocity.y = 0;
        velocity.z = mapObject->mMapObject.mPos.z - itemObject->mPos.z;
        if (LENGTH_SQUARED(velocity) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&velocity, &velocity);
        }
        scale = mapObject->mPrm->mBombKing.mHitPushScale;
        velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, scale);
        velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, scale);
        velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, scale);
        velocity.y = mapObject->mPrm->mBombKing.mHitVelocityY;
        SetVelocity(mapObject, &velocity);
        StartBombKingItemHitState(mapObject);
    }
}
void InitBombKing(MapObjectList *list) {
    MissionRunMapObject *mapObject;
    BombKingPrm *prm;
    int objectIndex;

    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (mapObject = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(mapObject);
            }
            InitMissionRunMapObject(list, mapObject, "bomb_king.nsbmd", "bomb_king.nsbca", "bomb_king.prm");
            LoadMissionRunMapObjectShadow(list, mapObject, "sh_circle.nsbmd");
            prm = &mapObject->mPrm->mBombKing;
            SetCollisionOffsetAndExtent(mapObject, prm->mHead.mCollisionOffsetY, prm->mHead.mCollisionExtentXZ,
                                        prm->mCollisionExtentY);
            SetShadowOffsetYAndScale(mapObject, 0, 0x23000);
            SetItemCollisionCallback(mapObject, BombKingItemHitCallback);
        }
    }
}

void DrawBombKing(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

MapObjectKindData *CreateBombKingKindData(void) {
    u32 soundId = 0x23eu;
    void *kartCollisionCallback = &CollideKartWithMissionRunMapObject;
    void *itemCollisionCallback = &CollideItemWithMissionRunMapObject;
    void *sphereHitCallback = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollisionCallback, itemCollisionCallback, sphereHitCallback, 0x2u,
                                               0x1u, soundId, 0x0u);
}

MapObjectList *CreateBombKingDrawList(void) {
    return CreateMapObjectDrawList1(InitBombKing, DrawBombKing, ToggleShadowScale);
}

MapObjectList *CreateBombKingUpdateList(void) {
    return CreateMapObjectUpdateList(InitBombKingObjects, UpdateBombKing, NULL);
}
