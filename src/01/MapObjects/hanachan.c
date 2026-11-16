#include "01/MapObjects/hanachan.h"
#include "01/MapObjects/hanachan_sound_and_item_hit.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/mission_run_repeats_and_counter.h"
#include "01/MapObjects/mission_run_frame_callbacks.h"
#include "Main/MapObjects/map_object_model_frame.h"
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
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "01/MapObjects/hanachan_move_and_followers.h"
#include "01/MapObjects/item_bomb_node_placement.h"
#include "01/MapObjects/mission_run_group_entry_queries.h"
#include "01/MapObjects/mission_run_counter_limit.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/mission_run_entry_index.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "fixed_vector_math.h"
#include "01/MapObjects/hanachan_move_state_start.h"
#include "01/MapObjects/hanachan_kart_eliminated.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/king_teresa.h"
#include "Main/Sound/sound_handle_start.h"
#include "Main/Sound/sound_handle_pool.h"
#include "01/MapObjects/mission_run_map_objects_reset.h"
#include "Main/System/heap.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "01/MapObjects/mission_run_collision_shadow_offsets.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/System/heap_call.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"

const u32 gHanachanSkipKindSoundFlag = 0x40000000;
SoundStartParams gHanachanEndSoundParams = {0x250, NULL, 0xd, 0};
MapObjectKindDescriptor gHanachanKindDescriptor = {0,
                                                   {0, 0},
                                                   0x30c,
                                                   InitHanachanMapObject,
                                                   CreateHanachanKindData,
                                                   CreateHanachanDrawList,
                                                   NULL,
                                                   NULL,
                                                   CreateHanachanUpdateList,
                                                   NULL,
                                                   {NULL, NULL, NULL, NULL}};
MapObjectKindDescriptor gHanachanFollowerKindDescriptor = {0,
                                                           {0, 0},
                                                           0x30c,
                                                           InitHanachanFollowerMapObject,
                                                           CreateHanachanFollowerKindData,
                                                           CreateHanachanFollowerDrawList,
                                                           NULL,
                                                           NULL,
                                                           CreateHanachanFollowerUpdateList,
                                                           NULL,
                                                           {NULL, NULL, NULL, NULL}};

void HanachanItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    mapObject->mItemResponse = 0;
    SetItemCollisionCallback(mapObject, HanachanItemHitCallback);
}

void HanachanFirstSoundCallback(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartMapObjectSound(&mapObject->mMapObject, 0x248);
    } else if (GetAbsoluteCounter(mapObject) >= 1) {
        StartMapObjectSound(&mapObject->mMapObject, 0x249);
    } else {
        StartMapObjectSound(&mapObject->mMapObject, 0x24a);
    }
}

void HanachanSecondSoundCallback(MissionRunMapObject *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartMapObjectSound(&mapObject->mMapObject, 0x248);
    } else if (GetAbsoluteCounter(mapObject) >= 1) {
        StartMapObjectSound(&mapObject->mMapObject, 0x249);
    } else {
        StartMapObjectSound(&mapObject->mMapObject, 0x24a);
    }
}

void SetHanachanSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0xc, HanachanFirstSoundCallback, 0x20, HanachanSecondSoundCallback);
}

void PlaceHanachanFollowerBehindXz(MissionRunMapObject *mapObject) {
    MissionRunMapObject *previousObject = mapObject->mPreviousObject;
    int distance;
    u16 oppositeAngle = (previousObject->mAngle + 0x8000);

    switch (mapObject->mFollowerIndex) {
        case HANACHAN_FOLLOWER_FIRST:
            distance = mapObject->mPrm->mHanachan.mFollowerFirstDistance;
            break;
        case HANACHAN_FOLLOWER_SECOND:
            distance = mapObject->mPrm->mHanachan.mFollowerSecondDistance;
            break;
        case HANACHAN_FOLLOWER_THIRD:
            distance = mapObject->mPrm->mHanachan.mFollowerThirdDistance;
            break;
        case HANACHAN_FOLLOWER_FOURTH:
            distance = mapObject->mPrm->mHanachan.mFollowerFourthDistance;
            break;
    }
    mapObject->mMapObject.mPos.x =
        previousObject->mMapObject.mPos.x + MUL_FIXED12_NO_ROUND(distance, SIN_OF_ANGLE(oppositeAngle));
    mapObject->mMapObject.mPos.z =
        mapObject->mPreviousObject->mMapObject.mPos.z + MUL_FIXED12_NO_ROUND(distance, COS_OF_ANGLE(oppositeAngle));
}

void TurnHanachanFollowerToPrevious(MissionRunMapObject *mapObject) {
    int diff;
    int step;
    int limit;
    s32 currentAngle;

    mapObject->mTurnDelayFrames = mapObject->mTurnDelayFrames - 1;
    if (mapObject->mTurnDelayFrames <= 0) {
        mapObject->mTurnDelayFrames = 0;
        currentAngle = mapObject->mAngle;
        diff = (u16) (mapObject->mPreviousObject->mAngle - currentAngle);
        if (diff > 0x8000) {
            diff -= 0x10000;
        }
        limit = mapObject->mAnglePerCall;
        step = diff < -limit ? -limit : (diff > limit ? limit : diff);
        mapObject->mAngle = (u16) (currentAngle + step);
        mapObject->mMoveAngle = mapObject->mAngle;
    }
}

void PlaceHanachanFollowerBehind(MissionRunMapObject *mapObject) {
    MissionRunMapObject *previousObject = mapObject->mPreviousObject;
    int distance;
    u16 oppositeAngle = (previousObject->mAngle + 0x8000);

    switch (mapObject->mFollowerIndex) {
        case HANACHAN_FOLLOWER_FIRST:
            distance = mapObject->mPrm->mHanachan.mFollowerFirstDistance;
            break;
        case HANACHAN_FOLLOWER_SECOND:
            distance = mapObject->mPrm->mHanachan.mFollowerSecondDistance;
            break;
        case HANACHAN_FOLLOWER_THIRD:
            distance = mapObject->mPrm->mHanachan.mFollowerThirdDistance;
            break;
        case HANACHAN_FOLLOWER_FOURTH:
            distance = mapObject->mPrm->mHanachan.mFollowerFourthDistance;
            break;
    }
    mapObject->mMapObject.mPos.x =
        previousObject->mMapObject.mPos.x + MUL_FIXED12_NO_ROUND(distance, SIN_OF_ANGLE(oppositeAngle));
    mapObject->mMapObject.mPos.y = mapObject->mPreviousObject->mMapObject.mPos.y;
    mapObject->mMapObject.mPos.z =
        mapObject->mPreviousObject->mMapObject.mPos.z + MUL_FIXED12_NO_ROUND(distance, COS_OF_ANGLE(oppositeAngle));
}

void CopyHanachanFollowerPreviousAngle(MissionRunMapObject *mapObject) {
    mapObject->mAngle = mapObject->mPreviousObject->mAngle;
    mapObject->mMoveAngle = mapObject->mAngle;
}

void AdvanceHanachanCounter(MissionRunMapObject *mapObject) {
    ReleaseEffects(mapObject);
    StartEffectAtOffset(mapObject, 0, mapObject->mOffset.y >> 4, 0, 0x427, 0xf);
    StartEffectAtOffset(mapObject, 0, mapObject->mOffset.y >> 4, 0, 0x426, 0xf);
    StartMapObjectSound(&mapObject->mMapObject, 0x24d);
    DecrementCounterToNegativeLimit(mapObject);
    if (GetAbsoluteCounter(mapObject) == 2) {
        StartMapObjectSound(&mapObject->mMapObject, 0x24c);
    } else if (GetAbsoluteCounter(mapObject) >= 3) {
        mapObject->mCounter = 0;
    }
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, GetAbsoluteCounter(mapObject));
}

void AdvanceHanachanCounterForAll(MissionRunMapObject *mapObject) {
    MapObjectList *list;
    int objectIndex;
    MissionRunMapObject *follower;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (follower = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            StartStateFrameCountCallback(follower, (follower->mFollowerIndex * 15), AdvanceHanachanCounter);
        }
    }
    AdvanceHanachanCounter(mapObject);
}

void StartHanachanFollowerMoveState(MissionRunMapObject *mapObject) {
    s32 frameOffset;
    float frameIndexValue;
    ModelAnimation *modelAnimation;

    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mMoveAnimationEntry,
                                mapObject->mPrm->mHanachan.mMoveFrameStep);
    frameOffset = mapObject->mPrm->mHanachan.mFollowerAnimationFrameOffset * mapObject->mFollowerIndex;
    if (frameOffset > 0) {
        frameIndexValue = 0.5f + TO_FIXED12(frameOffset);
    } else {
        frameIndexValue = TO_FIXED12(frameOffset) - 0.5f;
    }
    modelAnimation = mapObject->mNsbmd->mAnimations[0];
    modelAnimation->mHead.mFrameIndex = frameIndexValue;
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mHead.mFrameIndex;
}

void StartHanachanAnimationScaled(MissionRunMapObject *mapObject, int speedPercent) {
    MapObjectList *list;
    int objectIndex;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && list->mMapObjects[objectIndex] != NULL;
             objectIndex++) {
            StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mMoveAnimationEntry,
                                        (mapObject->mPrm->mHanachan.mMoveFrameStep * speedPercent / 100));
        }
    }
}

void SetHanachanFollowersTurnTiming(MissionRunMapObject *mapObject, int speedPercent) {
    MapObjectList *list;
    int objectIndex;
    MissionRunMapObject *follower;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (follower = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            follower->mTurnDelayFrames =
                follower->mPrm->mHanachan.mFollowerTurnDelay * follower->mFollowerIndex * 100 / speedPercent;
            follower->mAnglePerCall = mapObject->mPrm->mHanachan.mFollowerAnglePerCall * speedPercent / 100;
        }
    }
}

void SetHanachanSpeedAndTurnToNextEntry(MissionRunMapObject *mapObject, int speedPercent) {
    HanachanPrm *prm;

    prm = &mapObject->mPrm->mHanachan;
    SetSpeedTargetAndPerCall(mapObject, (prm->mMoveSpeedTarget * speedPercent / 100), prm->mMoveSpeedPerCall);
    prm = &mapObject->mPrm->mHanachan;
    TurnToPointMoveFollowsAngle(mapObject, prm->mMoveAnglePerCallTarget * speedPercent / 100,
                                prm->mMoveAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetNextGroupEntry(mapObject)->mPos);
}

void StartHanachanMoveAnimation(MissionRunMapObject *mapObject) {
    mapObject->mStateNumber = 1;
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mMoveAnimationEntry,
                                mapObject->mPrm->mHanachan.mMoveFrameStep);
}

int UpdateHanachanMoveState(MissionRunMapObject *mapObject) {
    int speedPercent;
    s32 entryPercent;
    s32 *unusedPointer;

    if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos, mapObject->mPrm->mHanachan.mMoveRangeRadius,
                       0)) {
        if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
            speedPercent = 0x1000 - mapObject->mPrm->mHanachan.mOneBalloonSpeedReduction;
            entryPercent = GetCurrentGroupEntryPercent(mapObject);
            speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, speedPercent);
        } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
            speedPercent = 0x1000 - mapObject->mPrm->mHanachan.mTwoBalloonSpeedReduction;
            entryPercent = GetCurrentGroupEntryPercent(mapObject);
            speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, speedPercent);
        } else {
            speedPercent = GetCurrentGroupEntryPercent(mapObject);
        }
        if (GetCurrentGroupEntryValue(mapObject) >= 1) {
            AdvanceHanachanCounterForAll(mapObject);
        }
        if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) == FALSE &&
            mapObject->mKartRangeCooldown == 0 && IsStateNumberBelow(mapObject, HANACHAN_STATE_KART_IN_RANGE) != 0) {
            if (GetEntryKartInAngleRange(mapObject, mapObject->mPrm->mHanachan.mFirstKartRangeAngleOffset,
                                         mapObject->mPrm->mHanachan.mFirstKartRangeRadius,
                                         mapObject->mPrm->mHanachan.mFirstKartRangeHalfAngle)) {
                mapObject->mKartRangeCooldown = mapObject->mPrm->mHanachan.mKartRangeCooldown;
                mapObject->mStateNumber = HANACHAN_STATE_KART_IN_RANGE;
                StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHanachan.mFirstKartRangeAnimationEntry,
                                              mapObject->mPrm->mHanachan.mFirstKartRangeFrameStep,
                                              StartHanachanMoveAnimation);
                speedPercent -= mapObject->mPrm->mHanachan.mKartRangeSpeedPercentReduction;
                StartMapObjectSound(&mapObject->mMapObject, 0x24b);
            } else if (GetEntryKartInAngleRange(mapObject, mapObject->mPrm->mHanachan.mSecondKartRangeAngleOffset,
                                                mapObject->mPrm->mHanachan.mSecondKartRangeRadius,
                                                mapObject->mPrm->mHanachan.mSecondKartRangeHalfAngle)) {
                mapObject->mKartRangeCooldown = mapObject->mPrm->mHanachan.mKartRangeCooldown;
                mapObject->mStateNumber = HANACHAN_STATE_KART_IN_RANGE;
                StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHanachan.mSecondKartRangeAnimationEntry,
                                              mapObject->mPrm->mHanachan.mSecondKartRangeFrameStep,
                                              StartHanachanMoveAnimation);
                speedPercent -= mapObject->mPrm->mHanachan.mKartRangeSpeedPercentReduction;
                StartMapObjectSound(&mapObject->mMapObject, 0x24b);
            }
        }
        SetHanachanSpeedAndTurnToNextEntry(mapObject, speedPercent);
        SetHanachanFollowersTurnTiming(mapObject, speedPercent);
        IncrementEntryIndex(mapObject);
        if (mapObject->mEntryIndex == 0) {
            IncrementEntryGroupIndex(mapObject, 4);
        }
    }
    if (mapObject->mKartRangeCooldown > 0) {
        mapObject->mKartRangeCooldown = mapObject->mKartRangeCooldown - 1;
    }
    if (IsStateNumberBelow(mapObject, 5)) {
        if (GetAbsoluteCounter(mapObject) == 2) {
            mapObject->mEffectStepCounter =
                mapObject->mEffectStepCounter + 1 >= 6 ? 0 : mapObject->mEffectStepCounter + 1;
            if (mapObject->mEffectStepCounter == 0) {
                StartEffectAtOffset(mapObject, 0, 0, 0, 0x3f9, 0x1c);
            }
            mapObject->mSoundStepCounter =
                mapObject->mSoundStepCounter + 1 >= 0x12 ? 0 : mapObject->mSoundStepCounter + 1;
            if (mapObject->mSoundStepCounter == 0) {
                StartMapObjectSound(&mapObject->mMapObject, 0x24f);
            }
        } else if (GetAbsoluteCounter(mapObject) == 1) {
            mapObject->mEffectStepCounter =
                mapObject->mEffectStepCounter + 1 >= 0x12 ? 0 : mapObject->mEffectStepCounter + 1;
            if (mapObject->mEffectStepCounter == 0) {
                StartEffectAtOffset(mapObject, 0, 0, 0, 0x3f8, 0x1c);
                StartMapObjectSound(&mapObject->mMapObject, 0x24e);
            }
        }
    }
    return 0;
}

void StartHanachanMoveState(MissionRunMapObject *mapObject) {
    u32 entryPercent;
    StartMapObjectState(mapObject, 1, &UpdateHanachanMoveState);
    SetStoppedCallback(mapObject, 0);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mMoveAnimationEntry,
                                mapObject->mPrm->mHanachan.mMoveFrameStep);
    entryPercent = GetCurrentGroupEntryPercent(mapObject);
    SetHanachanSpeedAndTurnToNextEntry(mapObject, entryPercent);
    entryPercent = GetCurrentGroupEntryPercent(mapObject);
    SetHanachanFollowersTurnTiming(mapObject, entryPercent);
    SetHanachanSoundCallbacks(mapObject);
}

void StartHanachanMoveStateByBalloons(MissionRunMapObject *mapObject) {
    s32 speedPercent;
    s32 scaleFactor;
    s32 entryPercent;

    if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
        scaleFactor = 0x1000 - mapObject->mPrm->mHanachan.mOneBalloonSpeedReduction;
        entryPercent = GetCurrentGroupEntryPercent(mapObject);
        speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, scaleFactor);
    } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
        scaleFactor = 0x1000 - mapObject->mPrm->mHanachan.mTwoBalloonSpeedReduction;
        entryPercent = GetCurrentGroupEntryPercent(mapObject);
        speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, scaleFactor);
    } else {
        speedPercent = GetCurrentGroupEntryPercent(mapObject);
    }
    StartMapObjectState(mapObject, 1, UpdateHanachanMoveState);
    SetStoppedCallback(mapObject, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mMoveAnimationEntry,
                                mapObject->mPrm->mHanachan.mMoveFrameStep);
    SetHanachanSpeedAndTurnToNextEntry(mapObject, speedPercent);
    SetHanachanFollowersTurnTiming(mapObject, speedPercent);
    StartHanachanAnimationScaled(mapObject, speedPercent);
    SetHanachanSoundCallbacks(mapObject);
}

void StartHanachanKartEliminatedState(MissionRunMapObject *mapObject) {
    int objectIndex;
    MapObjectList *list;
    MissionRunMapObject *follower;

    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mKartEliminatedAnimationEntry,
                                mapObject->mPrm->mHanachan.mKartEliminatedFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (follower = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            StartMapObjectState(follower, 1, NULL);
            StartAnimationNoEndCallback(follower, follower->mPrm->mHanachan.mKartEliminatedAnimationEntry,
                                        follower->mPrm->mHanachan.mKartEliminatedFrameStep);
        }
    }
}

void StartHanachanKartNotEliminatedState(MissionRunMapObject *mapObject) {
    int objectIndex;
    MapObjectList *list;
    MissionRunMapObject *follower;
    SoundStartParams soundRequest;

    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHanachan.mKartNotEliminatedAnimationEntry,
                                mapObject->mPrm->mHanachan.mKartNotEliminatedFrameStep);
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (follower = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            StartMapObjectState(follower, 1, NULL);
            StartAnimationNoEndCallback(follower, follower->mPrm->mHanachan.mKartNotEliminatedAnimationEntry,
                                        follower->mPrm->mHanachan.mKartNotEliminatedFrameStep);
            SetMapObjectModelNsbtpFrameIndex((follower->mNsbmd), 0);
        }
    }
    soundRequest = gHanachanEndSoundParams;
    soundRequest.mPositionSource = &mapObject->mMapObject.mPos;
    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mMapObject.mPos);
    StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
}

void HanachanStandingsEndCallback(void) {
    MapObjectList *list;
    MissionRunMapObject *follower;
    int objectIndex;

    ResetMissionRunMapObjects();
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (objectIndex = 0;
             objectIndex < list->mMapObjectCount && (follower = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            PlaceHanachanFollowerBehind(follower);
            CopyHanachanFollowerPreviousAngle(follower);
        }
    }
}

s32 UpdateHanachanWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartHanachanMoveState(mapObject);
    }
    return 0;
}

void StartHanachanWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateHanachanWaitForRaceStart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mHead.mWaitForRaceStartFrameStep);
}

void StartHanachanStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHead.mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mHead.mStartupSecondFrameStep, &StartHanachanWaitForRaceStart);
}

void StartHanachanStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 &StartHanachanStartupSecond);
}

void StartHanachanChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupSecondFrameStep);
}

void StartHanachanChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstFrameCount,
                                 &StartHanachanChainStartupSecond);
}

s32 UpdateFollowerWaitForRaceStart(MissionRunMapObject *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartHanachanFollowerMoveState(mapObject);
    }
    return 0;
}

s32 UpdateFollowerStartupEffects(MissionRunMapObject *mapObject) {
    int nsbcaFrameIndex;
    nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
    if (nsbcaFrameIndex == 0x33) {
        ReleaseEffects(mapObject);
        StartEffectAtOffset(mapObject, (0xfffff666u), 0, (0x00000400u), (0x00000434u), 0);
    } else {
        nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (nsbcaFrameIndex == 0x66) {
            ReleaseEffects(mapObject);
            StartEffectAtOffset(mapObject, (0x0000099au), 0, (0x00000400u), (0x00000434u), 0);
        }
    }
    return 0;
}

void StartFollowerWaitForRaceStart(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateFollowerWaitForRaceStart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mHead.mWaitForRaceStartFrameStep);
}

void StartHanachanFollowerStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, UpdateFollowerStartupEffects);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHead.mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mHead.mStartupSecondFrameStep, &StartFollowerWaitForRaceStart);
}

void StartHanachanFollowerStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 &StartHanachanFollowerStartupSecond);
}

void StartFollowerChainStartupSecond(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupSecondFrameStep);
}

void StartFollowerChainStartupFirst(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstFrameCount,
                                 &StartFollowerChainStartupSecond);
}

void StartHanachanFollowerWaitAnimState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mHead.mWaitForRaceStartFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 &StartHanachanFollowerStartupSecond);
}

void InitHanachanObjects(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *mapObject;

    if (mapObjectList != NULL) {
        for (objectIndex = 0; objectIndex < mapObjectList->mMapObjectCount &&
                              (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            mapObject->mKeepCallbacks = TRUE;
            if (GetRaceUseChainCameras() != 0) {
                StartHanachanChainStartupFirst(mapObject);
            } else {
                StartHanachanStartupFirst(mapObject);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) HanachanStandingsEndCallback);
}

void UpdateHanachan(u32 unused, MissionRunMapObject *mapObject) {
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
                StartHanachanKartEliminatedState(mapObject);
            } else {
                StartHanachanKartNotEliminatedState(mapObject);
            }
        }
    } else {
        if (IsStateNumberBelow(mapObject, 1) != 0) {
            StartHanachanMoveStateByBalloons(mapObject);
        }
    }
    if (CollideSphereWithMapObjects(&mapObject->mPosWithOffset, &mapObject->mMapObject.mPosStep,
                                    mapObject->mPrm->mHanachan.mCollisionRadius,
                                    mapObject->mMapObject.mCollisionSlotIndex, 9, NULL) == 2) {
        StartMapObjectSound(&mapObject->mMapObject, 0x253);
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitHanachanFollowerObjects(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *mapObject;

    if (mapObjectList != NULL) {
        for (objectIndex = 0; objectIndex < mapObjectList->mMapObjectCount &&
                              (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (GetRaceUseChainCameras() != 0) {
                StartFollowerChainStartupFirst(mapObject);
            } else if (objectIndex == 0) {
                StartHanachanFollowerStartupFirst(mapObject);
            } else {
                StartHanachanFollowerWaitAnimState(mapObject);
            }
        }
    }
}

void UpdateHanachanFollower(u32 unused, MissionRunMapObject *mapObject) {
    int collisionResult;
    PlaceHanachanFollowerBehindXz(mapObject);
    TurnHanachanFollowerToPrevious(mapObject);
    collisionResult = CollideSphereWithMapObjects(&mapObject->mPosWithOffset, &mapObject->mMapObject.mPosStep,
                                                  mapObject->mPrm->mHanachan.mCollisionRadius,
                                                  mapObject->mMapObject.mCollisionSlotIndex, 9, NULL);
    if (collisionResult == 2) {
        StartMapObjectSound(&mapObject->mMapObject, 0x253);
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitHanachanMapObject(MissionRunMapObject *mapObject) {
    MissionRunMapObject *firstFollower;
    MissionRunMapObject *secondFollower;
    MissionRunMapObject *thirdFollower;
    MissionRunMapObject *fourthFollower;

    firstFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mMapObject, 0x1fe);
    secondFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mMapObject, 0x1fe);
    thirdFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mMapObject, 0x1fe);
    fourthFollower = (MissionRunMapObject *) CreateMapObjectFromObject(&mapObject->mMapObject, 0x1fe);
    firstFollower->mPreviousObject = mapObject;
    secondFollower->mPreviousObject = firstFollower;
    thirdFollower->mPreviousObject = secondFollower;
    fourthFollower->mPreviousObject = thirdFollower;
    mapObject->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mMapObject.mSound->mSoundSource, 0xd, &mapObject->mMapObject.mPos);
    mapObject->mMapObject.mFarDistanceSquared = gSoundFalloffs[13].mFarDistanceSquared;
}

void InitHanachanFollowerMapObject(MissionRunMapObject *mapObject) {
    mapObject->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mMapObject.mSound->mSoundSource, 0xd, &mapObject->mMapObject.mPos);
    mapObject->mMapObject.mFarDistanceSquared = gSoundFalloffs[13].mFarDistanceSquared;
}

void HanachanKartHitCallback(MissionRunMapObject *mapObject, Kart *kart) {
    s32 moveAngle;
    s32 diff;

    if (kart->mItemEffect == KART_ITEM_EFFECT_STAR) {
        if (mapObject->mTimer > 0) {
            mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY;
        } else {
            moveAngle = mapObject->mMoveAngle;
            diff = (u16) (FX_Atan2Idx(kart->mPos.x - mapObject->mMapObject.mPos.x,
                                      kart->mPos.z - mapObject->mMapObject.mPos.z) -
                          moveAngle);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                mapObject->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(mapObject->mPrm->mHanachan.mStarHitSideSpeed,
                                                                        SIN_OF_ANGLE((u16) moveAngle + 0x4000));
                mapObject->mMapObject.mPosStep.y = 0;
                mapObject->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(
                    mapObject->mPrm->mHanachan.mStarHitSideSpeed, COS_OF_ANGLE((u16) mapObject->mMoveAngle + 0x4000));
            } else {
                mapObject->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(mapObject->mPrm->mHanachan.mStarHitSideSpeed,
                                                                        SIN_OF_ANGLE((u16) moveAngle - 0x4000));
                mapObject->mMapObject.mPosStep.y = 0;
                mapObject->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(
                    mapObject->mPrm->mHanachan.mStarHitSideSpeed, COS_OF_ANGLE((u16) mapObject->mMoveAngle - 0x4000));
            }
            mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY;
            StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK,
                                        0x1000);
            mapObject->mMapObject.mDistanceSquaredAndFlags |= gHanachanSkipKindSoundFlag;
            StartSoundFullVolumeWrapper(kart, 0x252);
        }
    } else {
        mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_FLIP_DOUBLE;
        StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_DISTANCE_MASK,
                                    0x1000);
        mapObject->mMapObject.mDistanceSquaredAndFlags |= gHanachanSkipKindSoundFlag;
        StartSoundFullVolumeWrapper(kart, 0x251);
    }
    SetKartCollisionCallback(mapObject, HanachanKartHitCallback);
}

void InitHanachan(MapObjectList *mapObjectList) {
    MissionRunMapObject *obj;
    s32 objectIndex;

    if (mapObjectList != NULL) {
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, "hanachan.nsbmd", "hanachan.nsbca", "hanachan.prm");
            LoadMissionRunMapObjectShadow(mapObjectList, obj, "sh_circle.nsbmd");
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, "hanachan.nsbtp");
            SetCollisionOffsetAndExtent(obj, obj->mPrm->mHead.mCollisionOffsetY, obj->mPrm->mHead.mCollisionExtentXZ,
                                        obj->mPrm->mHead.mCollisionExtentXZ);
            SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
            SetKartCollisionCallback(obj, HanachanKartHitCallback);
            SetItemCollisionCallback(obj, HanachanItemHitCallback);
            obj->mKartRangeCooldown = obj->mPrm->mHanachan.mKartRangeCooldown;
        }
    }
}

void InitHanachanFollower(MapObjectList *mapObjectList) {
    void *firstNsbca;
    void *secondNsbca;
    void *firstNsbtp;
    MissionRunMapObject *obj;
    MissionRunMapObject *sourceObject;

    firstNsbca = LoadMissionRunFile("hanachan_1.nsbca");
    secondNsbca = LoadMissionRunFile("hanachan_2.nsbca");
    firstNsbtp = LoadMissionRunFile("hanachan_1.nsbtp");
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        sourceObject =
            GetMissionRunMapObject(gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0);
    } else {
        sourceObject = NULL;
    }

    obj = mapObjectList->mMapObjects[0];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, "hanachan_1.nsbmd", NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, firstNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mFollowerIndex = HANACHAN_FOLLOWER_FIRST;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mHanachan.mFollowerFirstCollisionOffsetY,
                                obj->mPrm->mHead.mCollisionExtentXZ, sourceObject->mPrm->mHead.mCollisionExtentXZ);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[1];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, "hanachan_2.nsbmd", NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, secondNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mFollowerIndex = HANACHAN_FOLLOWER_SECOND;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mHanachan.mFollowerSecondCollisionOffsetY,
                                obj->mPrm->mHead.mCollisionExtentXZ, sourceObject->mPrm->mHead.mCollisionExtentXZ);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[2];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, "hanachan_3.nsbmd", NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, firstNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mFollowerIndex = HANACHAN_FOLLOWER_THIRD;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mHanachan.mFollowerThirdCollisionOffsetY,
                                obj->mPrm->mHead.mCollisionExtentXZ, sourceObject->mPrm->mHead.mCollisionExtentXZ);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xc000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);

    obj = mapObjectList->mMapObjects[3];
    obj->mPrm = sourceObject->mPrm;
    obj->mShadowNsbmd = sourceObject->mShadowNsbmd;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunMapObject(obj);
    }
    InitMissionRunMapObject(mapObjectList, obj, "hanachan_4.nsbmd", NULL, NULL);
    InitMapObjectModelNsbcaAnimation(obj->mNsbmd, secondNsbca);
    InitMapObjectModelNsbtpAnimation(obj->mNsbmd, firstNsbtp);
    obj->mFollowerIndex = HANACHAN_FOLLOWER_FOURTH;
    SetCollisionOffsetAndExtent(obj, obj->mPrm->mHanachan.mFollowerFourthCollisionOffsetY,
                                obj->mPrm->mHead.mCollisionExtentXZ, sourceObject->mPrm->mHead.mCollisionExtentXZ);
    SetShadowOffsetYAndScale(obj, 0x5000, 0xd000);
    SetKartCollisionCallback(obj, HanachanKartHitCallback);
    SetItemCollisionCallback(obj, HanachanItemHitCallback);
}

void DrawHanachan(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

MapObjectKindData *CreateHanachanKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

MapObjectList *CreateHanachanDrawList(void) {
    return CreateMapObjectDrawList1(InitHanachan, DrawHanachan, NULL);
}

MapObjectList *CreateHanachanUpdateList(void) {
    return CreateMapObjectUpdateList(InitHanachanObjects, UpdateHanachan, NULL);
}

MapObjectKindData *CreateHanachanFollowerKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, 0x0u, 0x0u);
}

MapObjectList *CreateHanachanFollowerDrawList(void) {
    return CreateMapObjectDrawList1(InitHanachanFollower, DrawHanachan, ToggleShadowScale);
}

MapObjectList *CreateHanachanFollowerUpdateList(void) {
    return CreateMapObjectUpdateList(InitHanachanFollowerObjects, UpdateHanachanFollower, NULL);
}
