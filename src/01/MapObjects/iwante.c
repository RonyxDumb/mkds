#include "01/MapObjects/iwante.h"
#include "01/code_0218820c.h"

#include "01/MapObjects/map_object_animation.h"
#include "01/code_0218f000.h"
#include "Main/System/heap.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/Race/mission_run_state.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_0219b250.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/code_02190000.h"
#include "01/code_02191000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/code_02192000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/code_021882b8.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/data_0210b000.h"
#include "01/code_02187e78.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188de0.h"
#include "01/code_02188e24.h"
#include "Main/Kart/camera.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "code_02147cd8.h"
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
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) mapObject->mUnk_000.mSound, 0xc, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void IwanteKartResponse2Callback(MissionRunMapObject *mapObject) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_BUMP;
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
}

void IwanteKartHitCallback(MissionRunMapObject *mapObject) {
    if (mapObject->mTimer > 0) {
        mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_BUMP;
        SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
        return;
    }
    mapObject->mUnk_000.mPosStep.x =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_144, SIN_OF_ANGLE((u16) mapObject->mMoveAngle));
    mapObject->mUnk_000.mPosStep.y = 0;
    mapObject->mUnk_000.mPosStep.z =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_144, COS_OF_ANGLE((u16) mapObject->mMoveAngle));
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
    SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
}

void IwanteKartResponse11Callback(MissionRunMapObject *mapObject) {
    mapObject->mKartResponse = KART_MAP_OBJECT_RESPONSE_SCALE_EFFECT;
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    mapObject->mUnk_000.mDistanceSquaredAndFlags =
        mapObject->mUnk_000.mDistanceSquaredAndFlags | gIwanteSkipKindSoundFlag;
}

void SetIwanteHandsApproachPoint(void) {
    Vec3 pos;
    MissionRunMapObject *mapObject;
    MissionRunPrm *prm;
    Kart *kart;
    u16 angle;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        mapObject = GetMissionRunMapObject(
            (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2));
    } else {
        mapObject = NULL;
    }
    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
        prm = mapObject->mPrm;
        angle = FX_Atan2Idx(kart->mPos.z - mapObject->mUnk_000.mPos.z, kart->mPos.x - mapObject->mUnk_000.mPos.x) -
                prm->mUnk_26c;
    } else {
        prm = mapObject->mPrm;
        angle = prm->mUnk_26c +
                FX_Atan2Idx(kart->mPos.z - mapObject->mUnk_000.mPos.z, kart->mPos.x - mapObject->mUnk_000.mPos.x);
    }
    pos.x = mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(prm->mUnk_270, COS_OF_ANGLE(angle));
    pos.y = mapObject->mUnk_000.mPos.y;
    pos.z = mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_270, SIN_OF_ANGLE(angle));
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
    anglePoint.x = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mUnk_274, FX_SinIdx((u16) angleObject->mAngle)));
    anglePoint.y = angleObject->mUnk_000.mPos.y;
    anglePoint.z = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mUnk_274, FX_CosIdx((u16) angleObject->mAngle)));
    firstMovePoint.x = -(s32) (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mUnk_278, FX_CosIdx((u16) angleObject->mAngle)));
    firstMovePoint.y = angleObject->mUnk_000.mPos.y;
    firstMovePoint.z = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mUnk_278, FX_SinIdx((u16) angleObject->mAngle)));
    secondMovePoint.x = (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mUnk_278, FX_CosIdx((u16) angleObject->mAngle)));
    secondMovePoint.y = angleObject->mUnk_000.mPos.y;
    secondMovePoint.z =
        -(s32) (MUL_FIXED12_NO_ROUND(angleObject->mPrm->mUnk_278, FX_SinIdx((u16) angleObject->mAngle)));
    SetAnglePoint(firstHand, &anglePoint);
    SetAnglePoint(secondHand, &anglePoint);
    SetMoveAnglePoint(firstHand, &firstMovePoint);
    SetMoveAnglePoint(secondHand, &secondMovePoint);
}

void SetIwanteNoneCollision(MissionRunMapObject *mapObject) {
    mapObject->mUnk_0a8 = IWANTE_HAND_SHAPE_NONE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtent(mapObject, 0, 0, 0, 0, 0, 0);
    SetShadowOffsetAndScale(mapObject, 0x0002a000u, 0, 0x00007000u, 0x00026000u, 0x00001000u, 0x00022000u);
}

void SetIwanteNoChainCameraWalkA(MissionRunMapObject *mapObject) {
    mapObject->mUnk_0a8 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemHitCallback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x0001e000u, 0xffff5000u, 0x00002000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00002000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00002000u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00002000u);
}

void SetIwanteWalkACollision(MissionRunMapObject *mapObject) {
    mapObject->mUnk_0a8 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemHitCallback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x00028000u, 0xffff5000u, 0x00001000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00000800u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00001000u);
}

void SetIwanteWalkBCollision(MissionRunMapObject *mapObject) {
    mapObject->mUnk_0a8 = 2;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0x00015000u, 0x00028000u, 0x0001c000u, 0x00001000u, 0x00013000u,
                                         0x00028000u, 0x00028000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0x00012000u, 0, 0x0001c000u, 0x00001000u, 0x00011000u, 0x00001000u,
                                  0x00024000u, 0x00001000u);
}

void SetIwanteHitReactionCollision(MissionRunMapObject *mapObject) {
    mapObject->mUnk_0a8 = 3;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0, 0x00028000u, 0xfffd1000u, 0x00002000u, 0x0001b99au, 0x00028000u,
                                         0x0002f000u, 0x00002000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0, 0, 0xfffd1000u, 0x00002000u, 0x0001b99au, 0x00001000u, 0x0002f000u,
                                  0x00002000u);
}

void SetIwanteWalkAHitCollision(MissionRunMapObject *mapObject) {
    mapObject->mUnk_0a8 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x00028000u, 0xffff5000u, 0x00002000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00001000u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00001000u);
}

void StartIwanteHandWalk(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_27c, mapObject->mPrm->mUnk_280);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
}

void StartIwanteHandWalkWithEffects(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_254, mapObject->mPrm->mUnk_258);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
}

void StartIwanteHandWalkBWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_28c, mapObject->mPrm->mUnk_290);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
}

void StartIwanteHandWalkAWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_294, mapObject->mPrm->mUnk_298);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
}

void StartIwanteHandChangeToWalkBWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2ac, mapObject->mPrm->mUnk_2b0,
                                  StartIwanteHandWalkBWalk);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    SetIwanteWalkBCollision(mapObject);
    StartMapObjectSound(&mapObject->mUnk_000, 0x215);
}

void StartIwanteHandChangeToWalkAWalk(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2b4, mapObject->mPrm->mUnk_2b8,
                                  StartIwanteHandWalkAWalk);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x2000, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x2000, 0x42e, 0);
}

void StartIwanteHandWalkBHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_28c, mapObject->mPrm->mUnk_290);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartIwanteHandWalkAHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_294, mapObject->mPrm->mUnk_298);
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
    StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x0000021du);
    return 0;
}

void StartIwanteHandMoveVerticalBack(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = -mapObject->mPrm->mUnk_2a4;
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandVerticalSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_29c, mapObject->mPrm->mUnk_2a0);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
    SetCourseCollisionCallback(mapObject, StopIwanteHandOnCourseHit);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandMoveVertical(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mUnk_2a4;
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandVerticalSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_29c, mapObject->mPrm->mUnk_2a0);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_2a8, StartIwanteHandMoveVerticalBack);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandChangeToWalkB(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2ac, mapObject->mPrm->mUnk_2b0,
                                  (UnkFunc *) &StartIwanteHandWalkBHold);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetIwanteWalkBCollision(mapObject);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000215u);
}

void StartIwanteHandChangeToWalkA(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2b4, mapObject->mPrm->mUnk_2b8,
                                  (UnkFunc *) &StartIwanteHandWalkAHold);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042eu, 0);
}

void StartIwanteHandLand(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1c0, mapObject->mPrm->mUnk_1c4);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1c8, NULL);
}

void StartIwanteHandFall(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mUnk_1bc;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1a4, mapObject->mPrm->mUnk_1a8);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFromPoint(mapObject, mapObject->mPrm->mUnk_1b4, mapObject->mPrm->mUnk_1b8);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1ac, mapObject->mPrm->mUnk_1b0);
    SetCourseCollisionCallback(mapObject, StartIwanteHandLand);
    mapObject->mGravityEnabled = TRUE;
}

void StartIwanteHandReachMovePoint(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_184, mapObject->mPrm->mUnk_188);
    StopTurningMoveFromPoint(mapObject, mapObject->mPrm->mUnk_194, mapObject->mPrm->mUnk_198);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_18c, mapObject->mPrm->mUnk_190);
    SetVelocity(mapObject, &velocity);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_19c, 0, &mapObject->mMoveAnglePoint, StartIwanteHandFall);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0ec, StartIwanteHandFall);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandMoveToPoints(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mUnk_17c;
    SetIwanteHandsPoints();
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFromPoint(mapObject, mapObject->mPrm->mUnk_174, mapObject->mPrm->mUnk_178);
    SetAnglePointAndMoveAnglePoint(mapObject, &mapObject->mMoveAnglePoint);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_16c, mapObject->mPrm->mUnk_170);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_180, StartIwanteHandReachMovePoint);
}

int AdvanceIwanteHandSidewaysStop(MissionRunMapObject *mapObject) {
    if (mapObject->mSpeed > 0) {
        StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x219);
    } else {
        ReleaseEffects(mapObject);
        SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
        mapObject->mStateFunction = NULL;
    }
    return 0;
}

s32 AdvanceIwanteHandSidewaysSound(MissionRunMapObject *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x219);
    return 0;
}

void StartIwanteHandSidewaysStop(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandSidewaysStop);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_148, mapObject->mPrm->mUnk_14c);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_150, mapObject->mPrm->mUnk_154);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_160, StartIwanteHandMoveToPoints);
    StartEffectAtOffset(mapObject, 0x1000, 0, 0x2000, 0x433, 0);
}

void StartIwanteHandMoveSideways(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 zeroVector = {0, 0, 0};

    if ((mapObject->mUnk_000.mFlags & 0x400) == 0) {
        mapObject->mMoveAngle = mapObject->mAngle + 0x4000;
    } else {
        mapObject->mMoveAngle = mapObject->mAngle - 0x4000;
    }
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandSidewaysSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_128, mapObject->mPrm->mUnk_12c);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_130, mapObject->mPrm->mUnk_134);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_140, StartIwanteHandSidewaysStop);
    SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
    StartEffectAtOffset(mapObject, 0x1000, 0, 0x2000, 0x433, 0);
}

void StartIwanteHandLandBeforeSideways(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_118, mapObject->mPrm->mUnk_11c);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_120, StartIwanteHandMoveSideways);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x414, 0);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x415, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x218);
}

void StartIwanteHandLandOnKart(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_10c, mapObject->mPrm->mUnk_110);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_114, StartIwanteHandMoveToPoints);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x414, 0);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x415, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x218);
}

void StartIwanteHandFallOnKart(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_108;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0f0, mapObject->mPrm->mUnk_0f4);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0f8, mapObject->mPrm->mUnk_0fc);
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
    StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x21c);
    return 0;
}

void StartIwanteHandMoveToKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandKartSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0d0, mapObject->mPrm->mUnk_0d4);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0d8, mapObject->mPrm->mUnk_0dc);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0e8, 0, &kart->mPos, StartIwanteHandFallOnKart);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0ec, StartIwanteHandFallOnKart);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandTurnToKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_0a4;
    StartMapObjectState(mapObject, 3, (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandKartSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_08c, mapObject->mPrm->mUnk_090);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_094, mapObject->mPrm->mUnk_098);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0a8, StartIwanteHandMoveToKart);
}

void StartIwanteHandLandOnKartAndStop(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_210, mapObject->mPrm->mUnk_214);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_218, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x414, 0);
    StartEffectAtRowHeight(mapObject, 0x1000, 0, 0x2000, 0x415, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x218);
}

void StartIwanteHandDirectFallOnKart(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_1e4;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1cc, mapObject->mPrm->mUnk_1d0);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1d4, mapObject->mPrm->mUnk_1d8);
    SetCourseCollisionCallback(mapObject, StartIwanteHandLandOnKartAndStop);
    SetKartCollisionCallback(mapObject, IwanteKartResponse11Callback);
}

void StartIwanteHandHitThirdAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_234, mapObject->mPrm->mUnk_238,
                                  (UnkFunc *) &StartIwanteHandMoveToPoints);
    SetIwanteWalkBCollision(mapObject);
}

void StartIwanteHandHitSecondAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_22c, mapObject->mPrm->mUnk_230,
                                  (UnkFunc *) &StartIwanteHandHitThirdAnimation);
    SetIwanteWalkAHitCollision(mapObject);
}

s32 AdvanceIwanteHandHitCollisionSound(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & 0x001e34ef) != 0) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x218);
        mapObject->mStateFunction = NULL;
    }
    return 0;
}

s32 AdvanceIwanteHandHitCollision(MissionRunMapObject *mapObject) {
    if (mapObject->mCollisionBits & 0x1e34ef) {
        mapObject->mStateFunction = (s32(*)(MissionRunMapObject *)) AdvanceIwanteHandHitCollisionSound;
    }
    return 0;
}

void StartIwanteHandHitReaction(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &AdvanceIwanteHandHitCollision);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_21c, mapObject->mPrm->mUnk_220,
                                  StartIwanteHandHitSecondAnimation);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mGravityEnabled = TRUE;
    SetIwanteHitReactionCollision(mapObject);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000216u);
}

void StartIwanteHandHitHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_24c, mapObject->mPrm->mUnk_250);
}

void StartIwanteHandHitReactionHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &AdvanceIwanteHandHitCollision);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_23c, mapObject->mPrm->mUnk_240,
                                  (UnkFunc *) &StartIwanteHandHitHold);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mGravityEnabled = TRUE;
    SetIwanteHitReactionCollision(mapObject);
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000216u);
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

        soundParams.mPositionSource = &mapObject->mUnk_000.mPos;
        soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mUnk_000.mPos);
        StartSndHandleSoundUnchecked(&soundParams, GetSecondSndHandleSlot());
    }
    mapObject->mUnk_000.mFlags |= gIwanteSkipViewTestFlag;
    mapObject->mUnk_000.mFlags |= gIwanteSkipListCallbackFlag;
    mapObject->mUnk_000.mFlags |= gIwanteDisabledFlag;
}

void StartIwanteHideAtEndReached(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, &HideIwanteAtEndReached);
}

void StartIwanteKartEliminatedHold(MissionRunMapObject *mapObject) {
    if (mapObject->mUnk_0a8 == 1) {
        StartMapObjectState(mapObject, 8, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
        StopTurningMoveFollowsAngle(mapObject);
        SetSpeedAndClearTarget(mapObject, 0);
        return;
    }
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2b4, mapObject->mPrm->mUnk_2b8,
                                  (UnkFunc *) &StartIwanteKartEliminatedHold);
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
        SetRepeatsRemaining(mapObject, ((u16) mapObject->mPrm->mUnk_1ec));
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
        mapObject->mUnk_0a8 = mapObject->mUnk_0a8 == IWANTE_HAND_SECOND ? IWANTE_HAND_FIRST : IWANTE_HAND_SECOND;
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
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_2c4, 0x270f000);
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
        if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
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
    if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
        if (IsStateNumberBelow(firstHand, 3)) {
            mapObject->mUnk_0a8 = IWANTE_HAND_FIRST;
            StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachUntilIdle);
            TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_2c4, 0x270f000);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            StartIwanteHandChangeToWalkAWalk(firstHand);
            StartIwanteHandChangeToWalkBWalk(secondHand);
        }
    } else if (IsStateNumberBelow(secondHand, 3)) {
        mapObject->mUnk_0a8 = IWANTE_HAND_SECOND;
        StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachUntilIdle);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_2c4, 0x270f000);
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
    if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
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
    if (IsPointInRange(mapObject, &mapObject->mAnglePoint, 0, mapObject->mPrm->mUnk_2bc) &&
        IsPointInRange(firstHand, &firstHand->mMoveAnglePoint, mapObject->mPrm->mUnk_2c0, 0) &&
        IsPointInRange(secondHand, &secondHand->mMoveAnglePoint, mapObject->mPrm->mUnk_2c0, 0)) {
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
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_2c4, 0x270f000);
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
    if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
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
    mapObject->mUnk_0a8 = (mapObject->mUnk_0a8 == IWANTE_HAND_FIRST) ? IWANTE_HAND_SECOND : IWANTE_HAND_FIRST;
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
    if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
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
    mapObject->mUnk_0a8 = (mapObject->mUnk_0a8 == IWANTE_HAND_FIRST) ? IWANTE_HAND_SECOND : IWANTE_HAND_FIRST;
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
    if (mapObject->mUnk_0a8 == IWANTE_HAND_SECOND) {
        StartIwanteHandWalkBHold(firstHand);
        StartIwanteHandChangeToWalkA(secondHand);
    } else {
        StartIwanteHandChangeToWalkA(firstHand);
        StartIwanteHandWalkBHold(secondHand);
    }
}

void StartIwanteHandsFromPrm(MissionRunMapObject *mapObject) {
    SetRepeatsRemaining(mapObject, ((u16) mapObject->mPrm->mUnk_1ec));
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
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mWaitForRaceStartAnimationEntry,
                                mapObject->mPrm->mWaitForRaceStartFrameStep);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042eu, 0);
}

void StartIwanteNoChainCameraAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mStartupSecondAnimationEntry,
                                  mapObject->mPrm->mStartupSecondFrameStep,
                                  (UnkFunc *) &StartIwanteNoChainCameraEffects);
    SetIwanteNoChainCameraWalkA(mapObject);
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000021bu);
}

void StartIwanteNoChainCameraWait(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mStartupFirstAnimationEntry,
                                mapObject->mPrm->mStartupFirstFrameStep);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mStartupFirstFrameCount,
                                 &StartIwanteNoChainCameraAnimation);
}

void StartIwanteChainCameraCourseWait(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mChainStartupSecondAnimationEntry,
                                mapObject->mPrm->mChainStartupSecondFrameStep);
    SetCourseCollisionCallback(mapObject, StartIwanteCourseHitEffects);
}

void StartIwanteChainCameraHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mChainStartupFirstAnimationEntry,
                                mapObject->mPrm->mChainStartupFirstFrameStep);
    DisableMissionRunMapObjectGravity(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mChainStartupFirstFrameCount,
                                 &StartIwanteChainCameraCourseWait);
}

void IwanteItemResponse2Callback(MissionRunMapObject *mapObject) {
    mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
    SetItemCollisionCallback(mapObject, (UnkFunc *) IwanteItemResponse2Callback);
}

// Item hit on a hand: knocks both hands back and counts one hit on the third object.
void IwanteItemHitCallback(MissionRunMapObject *mapObject, ItemObject *itemObject) {
    int diff;
    int limit;
    Vec3 velocity;

    diff = (u16) (FX_Atan2Idx(itemObject->mPos.x - mapObject->mUnk_000.mPos.x,
                              itemObject->mPos.z - mapObject->mUnk_000.mPos.z) -
                  mapObject->mAngle);
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    limit = mapObject->mPrm->mUnk_088;
    if (diff <= limit && diff >= -limit && IsStateNumberBelow(mapObject, 7)) {
        velocity.x = (MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mUnk_224, FX_SinIdx((u16) mapObject->mAngle)));
        velocity.y = mapObject->mPrm->mUnk_228;
        velocity.z = (MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mUnk_224, FX_CosIdx((u16) mapObject->mAngle)));
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
        mapObject->mUnk_000.mDistanceSquaredAndFlags |= gMapObjectItemHitReportFlag;
        ApplyIwanteHandsHit(
            gRaceSetup->mMode == MODE_MISSION_RUN
                ? GetMissionRunMapObject(
                      (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                : 0);
        SetItemCollisionCallback(mapObject, (UnkFunc *) IwanteItemResponse2Callback);
        mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
    } else {
        mapObject->mItemResponse = ITEM_MAP_OBJECT_RESPONSE_PUSH_FADE_OUT;
        SetItemCollisionCallback(mapObject, (UnkFunc *) IwanteItemHitCallback);
    }
}

// IwanteHands: the model-less third Mission Run object (index MissionRunGetCurrentKartCount() + 2) that steers both
// stone hands.
void InitIwanteHandsObjects(MapObjectList *mapObjectList) {
    int objectIndex;
    MissionRunMapObject *obj;
    int zero;

    if (mapObjectList != NULL) {
        zero = 0;
        for (objectIndex = 0;
             objectIndex < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            InitMissionRunMapObject((void *) zero, obj, (const char *) zero, (const char *) zero, "iwante_l.prm");
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
                obj->mUnk_000.mPos.y += obj->mPrm->mUnk_080;
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
    if (mapObject->mUnk_0a8 == 1) {
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
                obj->mUnk_000.mFlags |= gMapObjectMirrorFlag;
            } else if (objectIndex == 1) {
                obj->mUnk_000.mFlags &= 0xfffffbff;
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
