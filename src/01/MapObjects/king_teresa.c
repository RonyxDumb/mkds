#include "01/MapObjects/king_teresa.h"
#include "01/code_0218f900.h"
#include "01/MapObjects/iwante.h"
#include "01/code_02188cd8.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "Main/MapObjects/map_object_model_frame.h"
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
#include "01/code_0218f000.h"
#include "01/code_02187d14.h"
#include "01/code_02188de0.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "Main/System/heap.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_participant_record.h"
#include "01/Race/mission_run_state.h"
#include "01/code_02187cd4.h"
#include "01/code_02188484.h"
#include "01/unk_021a6000.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "01/unk_021a7000.h"
#include "01/MapObjects/coin.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "01/code_02181000.h"
#include "01/code_021882b8.h"
#include "01/code_02188e24.h"
#include "Main/System/heap_call.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/data_0217c000.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/data_0210b000.h"
#include "01/code_02187000.h"
#include "01/code_02182000.h"
#include "01/code_02188950.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/data_0217a000.h"

MapObjectKindDescriptor gKingTeresaKindDescriptor = {0,
                                                     {0, 0},
                                                     0x30c,
                                                     InitKingTeresaMapObject,
                                                     CreateKingTeresaKindData,
                                                     CreateKingTeresaDrawList,
                                                     NULL,
                                                     NULL,
                                                     CreateKingTeresaUpdateList,
                                                     NULL,
                                                     {NULL, NULL, NULL, NULL}};

u16 IsIwanteWalkB(MissionRunMapObject *mapObject) {
    return mapObject->mHandShape == IWANTE_HAND_SHAPE_WALK_B;
}

void KingTeresaKartCollisionCallback(MissionRunMapObject *mapObject) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_NONE;
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
}

void ShowKingTeresaWithEffects(MissionRunMapObject *mapObject) {
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mShowHideAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mShowHideFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mShowAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mShowAlphaLimitPerCall);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41b, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41c, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41d, 0);
    StartMapObjectSound(&mapObject->mMapObject, 0x22e);
    mapObject->mMapObject.mFlags &= ~1;
}

void HideKingTeresaWithEffects(MissionRunMapObject *mapObject) {
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mShowHideAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mShowHideFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mHideAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mHideAlphaLimitPerCall);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41e, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41f, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x420, 0);
    StartMapObjectSound(&mapObject->mMapObject, 0x22d);
    mapObject->mMapObject.mFlags = mapObject->mMapObject.mFlags | gKingTeresaHiddenFlag;
}

void SetKingTeresaVelocityWithKartTurn(MissionRunMapObject *mapObject) {
    Vec3 kartStep;
    Vec3 offsetFromKart;
    u32 headingChange;
    s32 repeatIndex;
    s32 sine;
    s32 cosine;
    s64 offsetZ;
    s64 offsetX;
    VEC_Subtract(gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunKartPos() : 0,
                 gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunPrevKartPos() : 0, &kartStep);
    kartStep.y = 0;
    headingChange = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        headingChange = GetMissionRunPrevKartHeadingAngle();
    }
    headingChange = (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunKartHeadingAngle() : 0) - headingChange;
    VEC_Subtract(&mapObject->mMapObject.mPos, gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunKartPos() : 0,
                 &offsetFromKart);
    for (repeatIndex = 0; repeatIndex < 1; repeatIndex++) {
        cosine = FX_CosIdx((u16) headingChange);
        offsetX = offsetFromKart.x;
        sine = FX_SinIdx((u16) headingChange);
        offsetZ = offsetFromKart.z;
    }
    kartStep.x += (s32) (offsetZ * sine >> 12) + (s32) (offsetX * cosine >> 12) - offsetFromKart.x;
    kartStep.z += (s32) (offsetZ * cosine >> 12) - (s32) (offsetX * sine >> 12) - offsetFromKart.z;
    SetVelocity(mapObject, &kartStep);
}

void SetKingTeresaVelocityToKartStep(MissionRunMapObject *mapObject) {
    Vec3 kartStep;
    VEC_Subtract(gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunKartPos() : 0,
                 gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunPrevKartPos() : 0, &kartStep);
    kartStep.y = 0;
    SetVelocity(mapObject, &kartStep);
}

s32 AdvanceKingTeresaFollowKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetPointInRangePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    return 0;
}

s32 AdvanceKingTeresaFollowKartClearFog(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetPointInRangePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    ClearFadeFogHoldFrames();
    return 0;
}

void StartKingTeresaTurnAwayFromKart(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mTurnAwayAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mTurnAwayFrameStep);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mTurnAwaySpeedTarget,
                             mapObject->mPrm->mKingTeresa.mTurnAwaySpeedPerCall);
    TurnFromPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mTurnAwayAnglePerCallTarget,
                                  mapObject->mPrm->mKingTeresa.mTurnAwayAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mTurnAwayFrameCount, NULL);
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
}

void StartKingTeresaCoinsFadeOut(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mCoinsFadeOutAnimationEntry,
                                  mapObject->mPrm->mKingTeresa.mCoinsFadeOutFrameStep, StartKingTeresaTurnAwayFromKart);
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartCoinsFadeOut();
}

void StartKingTeresaTurnTowardKart(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mTurnTowardKartAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mTurnTowardKartFrameStep);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mTurnTowardKartSpeedTarget,
                             mapObject->mPrm->mKingTeresa.mTurnTowardKartSpeedPerCall);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mTurnTowardKartAnglePerCallTarget,
                                mapObject->mPrm->mKingTeresa.mTurnTowardKartAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mTurnTowardKartFrameCount,
                                 StartKingTeresaCoinsFadeOut);
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartMapObjectSound(&mapObject->mMapObject, 0x229);
}

s32 AdvanceKingTeresaFollowForwardPoint(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        VEC_MultAdd(mapObject->mPrm->mKingTeresa.mForwardPointDistance, &kart->mEasedTurnedForward, &kart->mPos,
                    &targetPoint);
        SetAnglePointAndMoveAnglePoint(mapObject, &targetPoint);
        SetPointInRangePoint(mapObject, &targetPoint);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    ClearFadeFogHoldFrames();
    return 0;
}

s32 AdvanceKingTeresaFaceKart(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    return 0;
}

void StartKingTeresaMoveToForwardPoint(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    VEC_MultAdd(mapObject->mPrm->mKingTeresa.mForwardPointDistance, &kart->mEasedTurnedForward, &kart->mPos,
                &targetPoint);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFaceKart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mMoveToForwardPointAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mMoveToForwardPointFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mMoveToForwardPointAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mMoveToForwardPointAlphaLimitPerCall);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mMoveToForwardPointSpeedTarget,
                             mapObject->mPrm->mKingTeresa.mMoveToForwardPointSpeedPerCall);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mMoveToForwardPointAnglePerCallTarget,
                                mapObject->mPrm->mKingTeresa.mMoveToForwardPointAnglePerCallIncrement);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mKingTeresa.mMoveToForwardPointPointRadius, 0, &targetPoint,
                            StartKingTeresaTurnTowardKart);
    if (gKingTeresaState != 2) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 2;
    SetKartCollisionCallback(mapObject, KingTeresaBossTransferCallback);
    mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
}

s32 AdvanceKingTeresaApproachKart(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        VEC_MultAdd(-mapObject->mPrm->mKingTeresa.mApproachKartDistance, &kart->mEasedTurnedForward, &kart->mPos,
                    &targetPoint);
        SetAnglePointAndMoveAnglePoint(mapObject, &targetPoint);
        SetPointInRangePoint(mapObject, &targetPoint);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    return 0;
}

void StartKingTeresaApproachKart(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    VEC_MultAdd(-mapObject->mPrm->mKingTeresa.mApproachKartDistance, &kart->mEasedTurnedForward, &kart->mPos,
                &targetPoint);
    StartMapObjectState(mapObject, 3, AdvanceKingTeresaApproachKart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mApproachAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mApproachFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mApproachAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mApproachAlphaLimitPerCall);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mApproachSpeedTarget,
                             mapObject->mPrm->mKingTeresa.mApproachSpeedPerCall);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mApproachAnglePerCallTarget,
                                mapObject->mPrm->mKingTeresa.mApproachAnglePerCallIncrement);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mKingTeresa.mApproachPointRadius, 0, &targetPoint,
                            StartKingTeresaMoveToForwardPoint);
    if (gKingTeresaState != 1) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 1;
}

s32 AdvanceKingTeresaWaitToApproach(MissionRunMapObject *mapObject) {
    Kart *kart;
    float scaledTimerGap;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetPointInRangePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityWithKartTurn(mapObject);
    if (GetEntryKartInRange(mapObject, mapObject->mPrm->mKingTeresa.mWaitToApproachKartRadius, 0) == NULL) {
        mapObject->mMoveAngleOffset = mapObject->mPrm->mKingTeresa.mWaitToApproachMoveAngleOffset;
    } else {
        mapObject->mMoveAngleOffset = 0;
    }
    mapObject->mAlphaLimitPerCall = mapObject->mPrm->mKingTeresa.mWaitToApproachAlphaLimitPerCall;
    if (mapObject->mPrm->mKingTeresa.mWaitToApproachEndTimer -
            (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) >
        0) {
        scaledTimerGap = 0.5f + TO_FIXED12(mapObject->mPrm->mKingTeresa.mWaitToApproachEndTimer -
                                           (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0));
    } else {
        scaledTimerGap = TO_FIXED12(mapObject->mPrm->mKingTeresa.mWaitToApproachEndTimer -
                                    (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0)) -
                         0.5f;
    }
    mapObject->mAlphaLimitTarget = (s32) scaledTimerGap / mapObject->mPrm->mKingTeresa.mWaitToApproachAlphaLimitDivisor;
    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) <=
            mapObject->mPrm->mKingTeresa.mApproachTimerLimit &&
        GetEntryKartFacingObject(mapObject, 0, mapObject->mPrm->mKingTeresa.mApproachFacingHalfAngle) != NULL) {
        SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
        mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
        StartKingTeresaApproachKart(mapObject);
    } else if ((gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) >
               mapObject->mPrm->mKingTeresa.mWaitToApproachEndTimer) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

void StartKingTeresaWaitToApproach(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceKingTeresaWaitToApproach);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mWaitToApproachAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mWaitToApproachFrameStep);
    SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mKingTeresa.mWaitToApproachSpeed);
    TurnToPointMoveSideways(mapObject, mapObject->mPrm->mKingTeresa.mWaitToApproachAnglePerCallTarget, 0x270f000,
                            mapObject->mPrm->mKingTeresa.mWaitToApproachMoveAnglePerCallTarget, 0x270f000, 0);
    if (gKingTeresaState != 0) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 0;
}

void ShowKingTeresaNearKart(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 nearKartPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    VEC_MultAdd(-mapObject->mPrm->mKingTeresa.mApproachKartDistance, &kart->mEasedTurnedForward, &kart->mPos,
                &nearKartPoint);
    mapObject->mMapObject.mPos.x = nearKartPoint.x;
    mapObject->mMapObject.mPos.y =
        mapObject->mMapObject.mCourseMapRow->mPosition.y + mapObject->mPrm->mKingTeresa.mPosOffsetY;
    mapObject->mMapObject.mPos.z = nearKartPoint.z;
    mapObject->mMoveAngle =
        (u16) (FX_Atan2Idx(kart->mPos.x - mapObject->mMapObject.mPos.x, kart->mPos.z - mapObject->mMapObject.mPos.z) +
               0x4000);
    mapObject->mAngle = mapObject->mMoveAngle;
    StartKingTeresaWaitToApproach(mapObject);
    SetBossCoinShownCount(0);
    mapObject->mMapObject.mFlags &= ~1;
}

void StartKingTeresaHitReaction(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mHitReactionAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mHitReactionFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mHitReactionAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mHitReactionAlphaLimitPerCall);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mHitReactionSpeedTarget,
                             mapObject->mPrm->mKingTeresa.mHitReactionSpeedPerCall);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mHitReactionAnglePerCallTarget,
                                mapObject->mPrm->mKingTeresa.mHitReactionAnglePerCallIncrement);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mHitReactionFrameCount, NULL);
}

u32 ClearFadeFogHoldFramesWrapper(void) {
    ClearFadeFogHoldFrames();
    return 0;
}

void StartKingTeresaMoveToGroupEntry(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 1, (s32(*)(MissionRunMapObject *)) ClearFadeFogHoldFramesWrapper);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mMoveToGroupEntryFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mMoveToGroupEntryAlphaLimitPerCall);
    if (mapObject->mMoveStage == 1) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage1SpeedTarget,
                                 mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage1SpeedPerCall);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage1AnglePerCallTarget,
                                    mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage1AnglePerCallIncrement);
    } else if (mapObject->mMoveStage == 2) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage2SpeedTarget,
                                 mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage2SpeedPerCall);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage2AnglePerCallTarget,
                                    mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage2AnglePerCallIncrement);
    } else if (mapObject->mMoveStage == 3) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage3SpeedTarget,
                                 mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage3SpeedPerCall);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage3AnglePerCallTarget,
                                    mapObject->mPrm->mKingTeresa.mMoveToGroupEntryStage3AnglePerCallIncrement);
    }
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mKingTeresa.mMoveToGroupEntryPointRadius,
                            mapObject->mPrm->mKingTeresa.mMoveToGroupEntryPointHalfAngle,
                            &GetCurrentGroupEntry(mapObject)->mPos, NULL);
    if (gKingTeresaState != 5) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 5;
}

void ShowKingTeresaAtGroupEntry(MissionRunMapObject *mapObject) {
    RandomState64 *rng;
    GetKart((u16) gRaceSetup->mEntryIndex);
    rng = GetMapObjectRandom();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    mapObject->mMapObject.mPos.x = (&GetCurrentGroupEntry(mapObject)->mPos)->x;
    mapObject->mMapObject.mPos.y =
        mapObject->mPrm->mKingTeresa.mPosOffsetY + (&GetCurrentGroupEntry(mapObject)->mPos)->y;
    mapObject->mMapObject.mPos.z = (&GetCurrentGroupEntry(mapObject)->mPos)->z;
    StartMapObjectState(mapObject, 5, (s32(*)(MissionRunMapObject *)) ClearFadeFogHoldFramesWrapper);
    ShowKingTeresaWithEffects(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mShowFrameCount, NULL);
    if (gKingTeresaState != 5) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 5;
}

void StartKingTeresaHideForNextGroup(MissionRunMapObject *mapObject) {
    int currentValue;
    u32 nextValue;

    StartMapObjectState(mapObject, 5, (s32(*)(MissionRunMapObject *)) ClearFadeFogHoldFramesWrapper);
    HideKingTeresaWithEffects(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mHideFrameCount, ShowKingTeresaAtGroupEntry);
    SetBossCoinShownCount(0);
    IncrementEntryGroupIndex(mapObject, mapObject->mPrm->mKingTeresa.mNextGroupSpan);
    currentValue = mapObject->mMoveStage;
    if (currentValue == 1) {
        nextValue = 2;
    } else if (currentValue == 2) {
        nextValue = 3;
    } else if (currentValue == 3) {
        nextValue = 3;
    } else {
        nextValue = 1;
    }
    mapObject->mMoveStage = nextValue;
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
    mapObject->mCollisionExtentTargetZ = mapObject->mPrm->mHead.mCollisionExtentXZ;
    mapObject->mCollisionExtent.z = mapObject->mCollisionExtentTargetZ;
    mapObject->mCollisionExtentTargetX = mapObject->mCollisionExtent.z;
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX;
}

u32 AdvanceKingTeresaSinkToCourseRow(MissionRunMapObject *mapObject) {
    int newY;
    int lowestY;
    lowestY = mapObject->mMapObject.mCourseMapRow->mPosition.y + mapObject->mPrm->mKingTeresa.mSinkMinOffsetY;
    newY = mapObject->mMapObject.mPos.y - mapObject->mPrm->mKingTeresa.mSinkStepY;
    if (newY <= lowestY) {
        newY = lowestY;
    }
    mapObject->mMapObject.mPos.y = newY;
    ClearFadeFogHoldFrames();
    return 0;
}

void StartKingTeresaShowBossCoins(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, (s32(*)(MissionRunMapObject *)) AdvanceKingTeresaSinkToCourseRow);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mShowBossCoinsAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mShowBossCoinsFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mShowBossCoinsAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mShowBossCoinsAlphaLimitPerCall);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mShowBossCoinsFrameCount,
                                 StartKingTeresaHideForNextGroup);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x431, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x430, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x432, 0);
    if (gKingTeresaState != 4) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 4;
    SetKartCollisionCallback(mapObject, KingTeresaParkBossCoinsCallback);
    mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
    SetBossCoinShownCount(mapObject->mPrm->mKingTeresa.mShowBossCoinsShownCountMax <
                                  (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunBossCount() : 0)
                              ? mapObject->mPrm->mKingTeresa.mShowBossCoinsShownCountMax
                              : (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunBossCount() : 0));
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = mapObject->mCollisionExtent.z =
        mapObject->mCollisionExtentTargetZ = mapObject->mPrm->mHead.mCollisionExtentXZ / 2;
}

void StartKingTeresaStopForBossCoins(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mStopForBossCoinsAnimationEntry,
                                  mapObject->mPrm->mKingTeresa.mStopForBossCoinsFrameStep,
                                  StartKingTeresaShowBossCoins);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetBossCoinShownCount(0);
    StartMapObjectSound(&mapObject->mMapObject, 0x00000230u);
}

void StartKingTeresaCoinsFadeIn(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
    SetFadeFogHoldFramesToLimit();
    StartCoinsFadeIn();
}

void StartKingTeresaHideThenCoinsFadeIn(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, (s32(*)(MissionRunMapObject *)) AdvanceKingTeresaFollowKart);
    HideKingTeresaWithEffects(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mHideFrameCount, StartKingTeresaCoinsFadeIn);
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
}

void HideKingTeresaWithoutEffects(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mShowHideAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mShowHideFrameStep);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mKingTeresa.mHideAlphaLimitTarget,
                                  mapObject->mPrm->mKingTeresa.mHideAlphaLimitPerCall);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
    mapObject->mMapObject.mFlags |= gKingTeresaHiddenFlag;
}

void StartKingTeresaState1ShadowOffset(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
}

void StartKingTeresaHideThenState1(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKart);
    HideKingTeresaWithEffects(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mKingTeresa.mHideFrameCount,
                                 StartKingTeresaState1ShadowOffset);
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
}

void StartKingTeresaKartEliminatedHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mKartEliminatedAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mKartEliminatedFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    if (gKingTeresaState != 6) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 6;
    SetFadeFogHoldFramesToLimit();
}

void HideKingTeresaAtEndReached(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mWinnerDecidedAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mWinnerDecidedFrameStep);
    StartEffect(0x3fe, &mapObject->mMapObject.mPos);
    StartEffect(0x3fd, &mapObject->mMapObject.mPos);
    if (gKingTeresaState != 7) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 7;
    mapObject->mMapObject.mFlags |= gKingTeresaSkipViewTestFlag;
    mapObject->mMapObject.mFlags |= gKingTeresaSkipListCallbackFlag;
    mapObject->mMapObject.mFlags |= gKingTeresaHiddenFlag;
}

s32 AdvanceKingTeresaEndReachedSound(MissionRunMapObject *mapObject) {
    if (mapObject->mStateFrames == 50) {
        SoundStartParams soundParams = {0x22f, 0, 0xe, 0};
        soundParams.mPositionSource = &mapObject->mMapObject.mPos;
        soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mMapObject.mPos);
        StartSndHandleSoundUnchecked(&soundParams, GetSecondSndHandleSlot());
    }
    return 0;
}

void ShowKingTeresaAtEndReached(MissionRunMapObject *mapObject) {
    mapObject->mMapObject.mPos.y += mapObject->mPrm->mKingTeresa.mPosOffsetY;
    mapObject->mAlphaLimit = mapObject->mAlphaLimitTarget = 0x1f000;
    mapObject->mAlphaLimitPerCall = 0;
    StartMapObjectState(mapObject, 8, AdvanceKingTeresaEndReachedSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mWinnerDecidedAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mWinnerDecidedFrameStep);
    StartStateFrameCountCallback(mapObject, 0x3c, HideKingTeresaAtEndReached);
    if (gKingTeresaState != 7) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 7;
    mapObject->mMapObject.mFlags &= ~1;
}

void StartKingTeresaWinnerDecidedHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mKingTeresa.mWinnerDecidedAnimationEntry,
                                mapObject->mPrm->mKingTeresa.mWinnerDecidedFrameStep);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void KingTeresaStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

void StartKingTeresaSecondAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mHead.mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mHead.mStartupSecondFrameStep, StartKingTeresaHideThenState1);
}

void StartKingTeresaFirstAnimation(MissionRunMapObject *mapObject) {
    mapObject->mMapObject.mPos.y += mapObject->mPrm->mKingTeresa.mPosOffsetY;
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mStartupFirstFrameCount,
                                 StartKingTeresaSecondAnimation);
}

void ShowKingTeresaAfterWait(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    ShowKingTeresaWithEffects(mapObject);
}

void StartKingTeresaZeroAlphaWait(MissionRunMapObject *mapObject) {
    mapObject->mMapObject.mPos.y += mapObject->mPrm->mKingTeresa.mPosOffsetY;
    mapObject->mAlphaLimitTarget = 0;
    mapObject->mAlphaLimit = mapObject->mAlphaLimitTarget;
    mapObject->mAlphaLimit = 0;
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mHead.mChainStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mHead.mChainStartupFirstFrameCount,
                                 ShowKingTeresaAfterWait);
}

void InitKingTeresaMapObject(MissionRunMapObject *mapObject) {
    mapObject->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&mapObject->mMapObject.mSound->mSoundSource, 0xe, &mapObject->mMapObject.mPos);
    mapObject->mMapObject.mFarDistanceSquared = gSoundFalloffs[14].mFarDistanceSquared;
}

void KingTeresaParkBossCoinsCallback(MissionRunMapObject *mapObject, Kart *kart) {
    mapObject->mMapObject.mPosStep.x =
        MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mHead.mKartPushPosStep, FX_SinIdx(kart->mHeadingAngle));
    mapObject->mMapObject.mPosStep.y = 0;
    mapObject->mMapObject.mPosStep.z =
        MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mHead.mKartPushPosStep, FX_CosIdx(kart->mHeadingAngle));
    ParkBossCoins(mapObject->mPrm->mKingTeresa.mParkBossCoinCount);
    StartKingTeresaHideForNextGroup(mapObject);
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_NONE;
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartKingTeresaHideThenCoinsFadeIn(mapObject);
    mapObject->mMoveStage = 0;
    StartMapObjectSound(&mapObject->mMapObject, 0x22c);
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = mapObject->mCollisionExtent.z =
        mapObject->mCollisionExtentTargetZ = mapObject->mPrm->mHead.mCollisionExtentXZ;
}

void KingTeresaHitReactionCallback(MissionRunMapObject *mapObject) {
    int isBelowFive;
    isBelowFive = IsStateNumberBelow(mapObject, 5);
    if (isBelowFive != 0) {
        StartKingTeresaHitReaction(mapObject);
    }
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
    SetKartCollisionCallback(mapObject, KingTeresaHitReactionCallback);
    if (mapObject->mTimer == 0) {
        StartMapObjectSound(&mapObject->mMapObject, 0x00000234u);
    }
}

void KingTeresaBossTransferCallback(MissionRunMapObject *mapObject, Kart *kart) {
    AddPendingBossTransferInMissionRun((u16) mapObject->mPrm->mKingTeresa.mBossTransferAmount);
    mapObject->mMapObject.mPosStep.x = 0;
    mapObject->mMapObject.mPosStep.y = mapObject->mPrm->mKingTeresa.mBossTransferPosStepY;
    mapObject->mMapObject.mPosStep.z = 0;
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY;
    mapObject->mStateFunction = AdvanceKingTeresaFollowForwardPoint;
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartCameraWobbleAtDistance(mapObject->mMapObject.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    StartKartHitReaction(kart);
    SetShadowOffsetYAndScale(mapObject, 0, 0x32000);
    mapObject->mMoveStage = 1;
    if (!(gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0)) {
        StartFadeFog();
    }
}

void InitKingTeresaObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    MissionRunMapObject *mapObject;
    KingTeresaPrm *prm;

    if (mapObjectList != NULL) {
        for (objectIndex = 0; objectIndex < mapObjectList->mMapObjectCount &&
                              (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (GetRaceUseChainCameras() != 0) {
                StartKingTeresaZeroAlphaWait(mapObject);
            } else {
                StartKingTeresaFirstAnimation(mapObject);
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                prm = &mapObject->mPrm->mKingTeresa;
                SetMissionRunTimerValues(prm->mTimerStart, prm->mTimerMax, prm->mTimerCountUpAdd,
                                         prm->mTimerBossTransferAdd);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) KingTeresaStandingsEndCallback);
}

void UpdateKingTeresa(u32 unused, MissionRunMapObject *mapObject) {
    Kart *kart;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (IsStateNumberBelow(mapObject, 5) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                StartKingTeresaKartEliminatedHold(mapObject);
            } else if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecidedAndEndReached() : 0) {
                ShowKingTeresaAtEndReached(mapObject);
            } else {
                StartKingTeresaWinnerDecidedHold(mapObject);
            }
        }
    } else {
        if (mapObject->mMoveStage != 0) {
            if (IsStateNumberBelow(mapObject, 5) != 0) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                if (kart->mState == KART_STATE_NORMAL && (kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) == 0 &&
                    GetEntryKartInRange(mapObject, 0, mapObject->mPrm->mKingTeresa.mStopKartInRangeHalfAngle) != NULL &&
                    GetEntryKartFacingObject(mapObject, 0, mapObject->mPrm->mKingTeresa.mStopKartFacingHalfAngle) !=
                        NULL &&
                    GetEntryKartInRange(mapObject, mapObject->mPrm->mKingTeresa.mStopKartInRangeRadius, 0) != NULL) {
                    StartKingTeresaStopForBossCoins(mapObject);
                }
            }
            if (IsStateNumberBelow(mapObject, 3) != 0) {
                if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos,
                                   mapObject->mPrm->mKingTeresa.mMoveToGroupEntryPointRadius, 0) != 0) {
                    IncrementEntryIndex(mapObject);
                }
                SetKartCollisionCallback(mapObject, KingTeresaHitReactionCallback);
                mapObject->mMapObject.mFlags &= ~0x40;
                SetBossCoinShownCount(0);
                StartKingTeresaMoveToGroupEntry(mapObject);
            }
        } else {
            kart = GetKart((u16) gRaceSetup->mEntryIndex);
            if (kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) {
                if (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunCount() : 0) {
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        SetMissionRunTimer(mapObject->mPrm->mKingTeresa.mTimerMax);
                    }
                } else {
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        SetMissionRunTimer(0);
                    }
                }
                if ((mapObject->mMapObject.mFlags & 1) == 0) {
                    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                    mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
                    HideKingTeresaWithoutEffects(mapObject);
                }
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) {
                if (IsStateNumberBelow(mapObject, 3) != 0) {
                    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) <
                        mapObject->mPrm->mKingTeresa.mShowNearKartTimerLimit) {
                        if (mapObject->mMapObject.mFlags & 1) {
                            SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                            mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
                            ShowKingTeresaNearKart(mapObject);
                        } else {
                            SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                            mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
                            StartKingTeresaWaitToApproach(mapObject);
                        }
                    } else if ((mapObject->mMapObject.mFlags & 1) == 0) {
                        SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                        mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
                        HideKingTeresaWithoutEffects(mapObject);
                    }
                }
            }
        }
        if (gKingTeresaState == 0) {
            StartKingTeresaAlphaSound(mapObject->mMapObject.mSound);
        } else if (IsKingTeresaState0Or2Or5() != 0) {
            StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x22a);
        } else if (gKingTeresaState == 4) {
            StartMapObjectSoundWhileRequested(&mapObject->mMapObject, 0x22b);
        }
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitKingTeresa(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *mapObject;
    KingTeresaPrm *prm;

    if (mapObjectList != NULL) {
        for (objectIndex = 0; objectIndex < mapObjectList->mMapObjectCount &&
                              (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(mapObject);
            }
            InitMissionRunMapObject(mapObjectList, mapObject, "king_teresa.nsbmd", "king_teresa.nsbca",
                                    "king_teresa.prm");
            LoadMissionRunMapObjectShadow(mapObjectList, mapObject, "sh_circle.nsbmd");
            prm = &mapObject->mPrm->mKingTeresa;
            SetCollisionOffsetAndExtent(mapObject, prm->mHead.mCollisionOffsetY, prm->mHead.mCollisionExtentXZ,
                                        prm->mCollisionExtentY);
            SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
            SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
            SetNodePositionSource(mapObject, 0);
            mapObject->mMapObject.mFlags |= gKingTeresaNoPushOutFlag;
            mapObject->mCourseCollisionMode = MAP_OBJECT_COURSE_COLLISION_PUSH_Y_ONLY;
        }
    }
}

void DrawKingTeresa(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    if (mapObject->mMoveStage == 0) {
        DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
        return;
    }
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 1);
}

MapObjectKindData *CreateKingTeresaKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    return CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x0u, 0x0u, 0x0u);
}

MapObjectList *CreateKingTeresaDrawList(void) {
    return CreateMapObjectDrawList1(InitKingTeresa, DrawKingTeresa, ToggleShadowScale);
}

MapObjectList *CreateKingTeresaUpdateList(void) {
    return CreateMapObjectUpdateList(InitKingTeresaObjects, UpdateKingTeresa, NULL);
}

const u16 gMapObjectMirrorFlag = 0x400;
const u32 gMapObjectItemHitReportFlag = 0x80000000;
const u16 gKingTeresaSkipViewTestFlag = 2;
const u16 gKingTeresaNoPushOutFlag = 0x40;
const u16 gKingTeresaSkipListCallbackFlag = 8;
const u16 gKingTeresaHiddenFlag = 1;
