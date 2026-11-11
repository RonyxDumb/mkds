#include "01/code_0218f9d4.h"
#include "01/code_0218820c.h"

#include "01/code_02185ef4.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "01/code_02190000.h"
#include "01/code_02191000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020a128c.h"
#include "01/code_02192000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/code_02188e88.h"
#include "01/code_021882b8.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02187e78.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188de0.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "code_02147cd8.h"

void InitIwanteSoundSource(Unk02188950 *mapObject) {
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) mapObject->mUnk_000.mSound, 0xc, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void IwanteKartResponse2Callback(Unk02188950 *mapObject) {
    mapObject->mUnk_2d8 = 2;
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
}

void IwanteKartHitCallback(Unk02188950 *mapObject) {
    if (mapObject->mTimer > 0) {
        mapObject->mUnk_2d8 = 2;
        SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
        return;
    }
    mapObject->mUnk_000.mPosStep.x =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_144, SIN_OF_ANGLE((u16) mapObject->mMoveAngle));
    mapObject->mUnk_000.mPosStep.y = 0;
    mapObject->mUnk_000.mPosStep.z =
        MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_144, COS_OF_ANGLE((u16) mapObject->mMoveAngle));
    mapObject->mUnk_2d8 = 0xd;
    SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
}

void IwanteKartResponse11Callback(Unk02188950 *mapObject) {
    mapObject->mUnk_2d8 = 0xb;
    SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
    mapObject->mUnk_000.mDistanceSquaredAndFlags =
        mapObject->mUnk_000.mDistanceSquaredAndFlags | (*(u32 *) &data_ov001_021a65d4);
}

void SetIwanteHandsApproachPoint(void) {
    Vec3 pos;
    Unk02188950 *mapObject;
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
    if (mapObject->mUnk_0a8 == 4) {
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
    Unk02188950 *angleObject;
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void SetIwanteNoneCollision(Unk02188950 *mapObject) {
    mapObject->mUnk_0a8 = 0;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtent(mapObject, 0, 0, 0, 0, 0, 0);
    SetShadowOffsetAndScale(mapObject, 0x0002a000u, 0, 0x00007000u, 0x00026000u, 0x00001000u, 0x00022000u);
}

void SetIwanteNoChainCameraWalkA(Unk02188950 *mapObject) {
    mapObject->mUnk_0a8 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemHitCallback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x0001e000u, 0xffff5000u, 0x00002000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00002000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00002000u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00002000u);
}

void SetIwanteWalkACollision(Unk02188950 *mapObject) {
    mapObject->mUnk_0a8 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemHitCallback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x00028000u, 0xffff5000u, 0x00001000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00000800u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00001000u);
}

void SetIwanteWalkBCollision(Unk02188950 *mapObject) {
    mapObject->mUnk_0a8 = 2;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0x00015000u, 0x00028000u, 0x0001c000u, 0x00001000u, 0x00013000u,
                                         0x00028000u, 0x00028000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0x00012000u, 0, 0x0001c000u, 0x00001000u, 0x00011000u, 0x00001000u,
                                  0x00024000u, 0x00001000u);
}

void SetIwanteHitReactionCollision(Unk02188950 *mapObject) {
    mapObject->mUnk_0a8 = 3;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0, 0x00028000u, 0xfffd1000u, 0x00002000u, 0x0001b99au, 0x00028000u,
                                         0x0002f000u, 0x00002000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0, 0, 0xfffd1000u, 0x00002000u, 0x0001b99au, 0x00001000u, 0x0002f000u,
                                  0x00002000u);
}

void SetIwanteWalkAHitCollision(Unk02188950 *mapObject) {
    mapObject->mUnk_0a8 = 1;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &IwanteItemResponse2Callback);
    SetCollisionBoxOffsetAndExtentTarget(mapObject, 0xffffc000u, 0x00028000u, 0xffff5000u, 0x00002000u, 0x00024000u,
                                         0x00028000u, 0x00011000u, 0x00001000u);
    SetShadowOffsetAndScaleTarget(mapObject, 0xffff8000u, 0, 0xffffa000u, 0x00001000u, 0x00020000u, 0x00001000u,
                                  0x00014000u, 0x00001000u);
}

void StartIwanteHandWalk(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_27c, mapObject->mPrm->mUnk_280);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
}

void StartIwanteHandWalkWithEffects(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_254, mapObject->mPrm->mUnk_258);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
}

void StartIwanteHandWalkBWalk(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_28c, mapObject->mPrm->mUnk_290);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
}

void StartIwanteHandWalkAWalk(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_294, mapObject->mPrm->mUnk_298);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
}

void StartIwanteHandChangeToWalkBWalk(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2ac, mapObject->mPrm->mUnk_2b0,
                                  StartIwanteHandWalkBWalk);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    SetIwanteWalkBCollision(mapObject);
    StartMapObjectSound(&mapObject->mUnk_000, 0x215);
}

void StartIwanteHandChangeToWalkAWalk(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2b4, mapObject->mPrm->mUnk_2b8,
                                  StartIwanteHandWalkAWalk);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x2000, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x2000, 0x42e, 0);
}

void StartIwanteHandWalkBHold(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_28c, mapObject->mPrm->mUnk_290);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartIwanteHandWalkAHold(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_294, mapObject->mPrm->mUnk_298);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042eu, 0);
}

void StopIwanteHandOnCourseHit(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StopMapObjectState(mapObject);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    mapObject->mGravityEnabled = TRUE;
}

u32 AdvanceIwanteHandVerticalSound(Unk02188950 *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x0000021du);
    return 0;
}

void StartIwanteHandMoveVerticalBack(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = -mapObject->mPrm->mUnk_2a4;
    StartMapObjectState(mapObject, 3, (s32(*)(Unk02188950 *)) AdvanceIwanteHandVerticalSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_29c, mapObject->mPrm->mUnk_2a0);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
    SetCourseCollisionCallback(mapObject, StopIwanteHandOnCourseHit);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandMoveVertical(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};
    velocity.y = mapObject->mPrm->mUnk_2a4;
    StartMapObjectState(mapObject, 3, (s32(*)(Unk02188950 *)) AdvanceIwanteHandVerticalSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_29c, mapObject->mPrm->mUnk_2a0);
    SetVelocity(mapObject, &velocity);
    TurnAndMoveToPointSameRate(mapObject, mapObject->mPrm->mUnk_2c8, 0x270f000);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_2cc, 0x270f000);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_2a8, StartIwanteHandMoveVerticalBack);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42d, 0);
    StartEffectAtOffset(mapObject, 0, 0x44cd, 0x400, 0x42e, 0);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandChangeToWalkB(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2ac, mapObject->mPrm->mUnk_2b0,
                                  (UnkFunc *) &StartIwanteHandWalkBHold);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetIwanteWalkBCollision(mapObject);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000215u);
}

void StartIwanteHandChangeToWalkA(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_2b4, mapObject->mPrm->mUnk_2b8,
                                  (UnkFunc *) &StartIwanteHandWalkAHold);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    SetIwanteWalkACollision(mapObject);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00002000u, 0x0000042eu, 0);
}

void StartIwanteHandLand(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1c0, mapObject->mPrm->mUnk_1c4);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1c8, NULL);
}

void StartIwanteHandFall(Unk02188950 *mapObject) {
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

void StartIwanteHandReachMovePoint(Unk02188950 *mapObject) {
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

void StartIwanteHandMoveToPoints(Unk02188950 *mapObject) {
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

int AdvanceIwanteHandSidewaysStop(Unk02188950 *mapObject) {
    if (mapObject->mSpeed > 0) {
        StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x219);
    } else {
        ReleaseEffects(mapObject);
        SetKartCollisionCallback(mapObject, IwanteKartResponse2Callback);
        mapObject->mUnk_158 = NULL;
    }
    return 0;
}

s32 AdvanceIwanteHandSidewaysSound(Unk02188950 *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x219);
    return 0;
}

void StartIwanteHandSidewaysStop(Unk02188950 *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, (s32(*)(Unk02188950 *)) AdvanceIwanteHandSidewaysStop);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_148, mapObject->mPrm->mUnk_14c);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_150, mapObject->mPrm->mUnk_154);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_160, StartIwanteHandMoveToPoints);
    StartEffectAtOffset(mapObject, 0x1000, 0, 0x2000, 0x433, 0);
}

void StartIwanteHandMoveSideways(Unk02188950 *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 zeroVector = {0, 0, 0};

    if ((mapObject->mUnk_000.mFlags & 0x400) == 0) {
        mapObject->mMoveAngle = mapObject->mAngle + 0x4000;
    } else {
        mapObject->mMoveAngle = mapObject->mAngle - 0x4000;
    }
    StartMapObjectState(mapObject, 3, (s32(*)(Unk02188950 *)) AdvanceIwanteHandSidewaysSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_128, mapObject->mPrm->mUnk_12c);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_130, mapObject->mPrm->mUnk_134);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_140, StartIwanteHandSidewaysStop);
    SetKartCollisionCallback(mapObject, IwanteKartHitCallback);
    StartEffectAtOffset(mapObject, 0x1000, 0, 0x2000, 0x433, 0);
}

void StartIwanteHandLandBeforeSideways(Unk02188950 *mapObject) {
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

void StartIwanteHandLandOnKart(Unk02188950 *mapObject) {
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

void StartIwanteHandFallOnKart(Unk02188950 *mapObject) {
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

s32 AdvanceIwanteHandKartSound(Unk02188950 *mapObject) {
    StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x21c);
    return 0;
}

void StartIwanteHandMoveToKart(Unk02188950 *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    StartMapObjectState(mapObject, 3, (s32(*)(Unk02188950 *)) AdvanceIwanteHandKartSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0d0, mapObject->mPrm->mUnk_0d4);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0d8, mapObject->mPrm->mUnk_0dc);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0e8, 0, &kart->mPos, StartIwanteHandFallOnKart);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0ec, StartIwanteHandFallOnKart);
    mapObject->mGravityEnabled = FALSE;
}

void StartIwanteHandTurnToKart(Unk02188950 *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_0a4;
    StartMapObjectState(mapObject, 3, (s32(*)(Unk02188950 *)) AdvanceIwanteHandKartSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_08c, mapObject->mPrm->mUnk_090);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_094, mapObject->mPrm->mUnk_098);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0a8, StartIwanteHandMoveToKart);
}

void StartIwanteHandLandOnKartAndStop(Unk02188950 *mapObject) {
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

void StartIwanteHandDirectFallOnKart(Unk02188950 *mapObject) {
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

void StartIwanteHandHitThirdAnimation(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_234, mapObject->mPrm->mUnk_238,
                                  (UnkFunc *) &StartIwanteHandMoveToPoints);
    SetIwanteWalkBCollision(mapObject);
}

void StartIwanteHandHitSecondAnimation(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_22c, mapObject->mPrm->mUnk_230,
                                  (UnkFunc *) &StartIwanteHandHitThirdAnimation);
    SetIwanteWalkAHitCollision(mapObject);
}

s32 AdvanceIwanteHandHitCollisionSound(Unk02188950 *mapObject) {
    if ((mapObject->mCollisionBits & 0x001e34ef) != 0) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x218);
        mapObject->mUnk_158 = NULL;
    }
    return 0;
}

s32 AdvanceIwanteHandHitCollision(Unk02188950 *mapObject) {
    if (mapObject->mCollisionBits & 0x1e34ef) {
        mapObject->mUnk_158 = (s32(*)(Unk02188950 *)) AdvanceIwanteHandHitCollisionSound;
    }
    return 0;
}

void StartIwanteHandHitReaction(Unk02188950 *mapObject) {
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

void StartIwanteHandHitHold(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_24c, mapObject->mPrm->mUnk_250);
}

void StartIwanteHandHitReactionHold(Unk02188950 *mapObject) {
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

void HideIwanteAtEndReached(Unk02188950 *mapObject) {
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
    mapObject->mUnk_000.mFlags |= data_ov001_021a65c8;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65cc;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65d0;
}

void StartIwanteHideAtEndReached(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, &HideIwanteAtEndReached);
}

void StartIwanteKartEliminatedHold(Unk02188950 *mapObject) {
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

s32 AdvanceIwanteHandsStopAfterPoints(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

s32 AdvanceIwanteHandsRestartWhenIdle(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void StartIwanteHandsFallOrMoveToPoints(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

s32 AdvanceIwanteHandsStartFromPrm(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void StartIwanteHandsChangeToWalkB(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

s32 AdvanceIwanteHandsRepeatVertical(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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
        mapObject->mUnk_0a8 = mapObject->mUnk_0a8 == 4 ? 5 : 4;
        StartIwanteHandsMoveVertical(mapObject);
    }
    return 0;
}

void StartIwanteHandsMoveVertical(Unk02188950 *mapObject) {
    Kart *kart;
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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
        if (mapObject->mUnk_0a8 == 4) {
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

int AdvanceIwanteHandsStartMoveVertical(Unk02188950 *mapObject) {
    Kart *kart;
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void StartIwanteHandsChangeToWalkA(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

int AdvanceIwanteHandsApproachUntilIdle(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

int AdvanceIwanteHandsToggleState(Unk02188950 *mapObject) {
    Kart *kart;
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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
    if (mapObject->mUnk_0a8 == 4) {
        if (IsStateNumberBelow(firstHand, 3)) {
            mapObject->mUnk_0a8 = 5;
            StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachUntilIdle);
            TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_2c4, 0x270f000);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            StartIwanteHandChangeToWalkAWalk(firstHand);
            StartIwanteHandChangeToWalkBWalk(secondHand);
        }
    } else if (IsStateNumberBelow(secondHand, 3)) {
        mapObject->mUnk_0a8 = 4;
        StartMapObjectState(mapObject, 3, AdvanceIwanteHandsApproachUntilIdle);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_2c4, 0x270f000);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        StartIwanteHandChangeToWalkBWalk(firstHand);
        StartIwanteHandChangeToWalkAWalk(secondHand);
    }
    return 0;
}

void StartIwanteHandsTurnToKart(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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
    if (mapObject->mUnk_0a8 == 4) {
        StartIwanteHandTurnToKart(firstHand);
        StartIwanteHandWalkAHold(secondHand);
    } else {
        StartIwanteHandWalkAHold(firstHand);
        StartIwanteHandTurnToKart(secondHand);
    }
}

int AdvanceIwanteHandsApproachKart(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void StartIwanteHandsApproachKart(Unk02188950 *mapObject) {
    Kart *kart;
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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
    if (mapObject->mUnk_0a8 == 4) {
        StartIwanteHandWalk(firstHand);
        StartIwanteHandWalkWithEffects(secondHand);
    } else {
        StartIwanteHandWalkWithEffects(firstHand);
        StartIwanteHandWalk(secondHand);
    }
}

int AdvanceIwanteHandsStopAfterToggle(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void StartIwanteHandsToggleState(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStopAfterToggle);
    StopTurningMoveFollowsAngle(mapObject);
    mapObject->mUnk_0a8 = (mapObject->mUnk_0a8 == 5) ? 4 : 5;
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
    if (mapObject->mUnk_0a8 == 4) {
        StartIwanteHandChangeToWalkB(firstHand);
        StartIwanteHandWalkAHold(secondHand);
    } else {
        StartIwanteHandWalkAHold(firstHand);
        StartIwanteHandChangeToWalkB(secondHand);
    }
}

void StartIwanteHandsToggleStateHold(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceIwanteHandsStopAfterToggle);
    StopTurningMoveFollowsAngle(mapObject);
    mapObject->mUnk_0a8 = (mapObject->mUnk_0a8 == 5) ? 4 : 5;
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
    if (mapObject->mUnk_0a8 == 4) {
        StartIwanteHandWalkBHold(firstHand);
        StartIwanteHandChangeToWalkA(secondHand);
    } else {
        StartIwanteHandChangeToWalkA(firstHand);
        StartIwanteHandWalkBHold(secondHand);
    }
}

void StartIwanteHandsFromPrm(Unk02188950 *mapObject) {
    SetRepeatsRemaining(mapObject, ((u16) mapObject->mPrm->mUnk_1ec));
    StartIwanteHandsFallOrMoveToPoints(mapObject);
}

int AdvanceIwanteHandsNextByHitCount(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

void StartIwanteHandsHitReaction(Unk02188950 *mapObject) {
    Unk02188950 *firstHand;
    Unk02188950 *secondHand;

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

u32 AdvanceIwanteHandsWaitForRaceStart(Unk02188950 *mapObject) {
    int raceStarted;
    raceStarted = IsRaceStarted();
    if (raceStarted == 1) {
        StartIwanteHandsToggleState(mapObject);
    }
    return 0;
}

void StartIwanteHandsWaitForRaceStart(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(Unk02188950 *)) AdvanceIwanteHandsWaitForRaceStart);
}

void ApplyIwanteHandsHit(Unk02188950 *mapObject) {
    StartIwanteHandsHitReaction(mapObject);
    IncrementHitCountAndCheckLimit(mapObject);
}

void StartIwanteCourseHitEffects(Unk02188950 *mapObject) {
    StartEffectAtRowHeight(mapObject, 0x00002ccdu, 0, 0, 0x00000411u, 0);
    StartEffectAtRowHeight(mapObject, 0x00002ccdu, 0, 0, 0x00000412u, 0);
}

void StartIwanteNoChainCameraEffects(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_064, mapObject->mPrm->mUnk_068);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042du, 0);
    StartEffectAtOffset(mapObject, 0, 0x000044cdu, 0x00000400u, 0x0000042eu, 0);
}

void StartIwanteNoChainCameraAnimation(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  (UnkFunc *) &StartIwanteNoChainCameraEffects);
    SetIwanteNoChainCameraWalkA(mapObject);
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000021bu);
}

void StartIwanteNoChainCameraWait(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, &StartIwanteNoChainCameraAnimation);
}

void StartIwanteChainCameraCourseWait(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_040, mapObject->mPrm->mUnk_044);
    SetCourseCollisionCallback(mapObject, StartIwanteCourseHitEffects);
}

void StartIwanteChainCameraHold(Unk02188950 *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    DisableMissionRunMapObjectGravity(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, &StartIwanteChainCameraCourseWait);
}

void IwanteItemResponse2Callback(Unk02188950 *mapObject) {
    mapObject->mUnk_2e0 = 2;
    SetItemCollisionCallback(mapObject, (UnkFunc *) IwanteItemResponse2Callback);
}

// Item hit on a hand: knocks both hands back and counts one hit on the third object.
void IwanteItemHitCallback(Unk02188950 *mapObject, Unk0218fd20 *itemObject) {
    int diff;
    int limit;
    Vec3 velocity;

    diff = (u16) (FX_Atan2Idx(itemObject->mUnk_50.x - mapObject->mUnk_000.mPos.x,
                              itemObject->mUnk_50.z - mapObject->mUnk_000.mPos.z) -
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
        StartEffect(0x3eb, &itemObject->mUnk_50);
        StartEffect(0x3ec, &itemObject->mUnk_50);
        StartEffect(0x3ed, &itemObject->mUnk_50);
        mapObject->mUnk_000.mDistanceSquaredAndFlags |= gMapObjectItemHitReportFlag;
        ApplyIwanteHandsHit(
            gRaceSetup->mMode == MODE_MISSION_RUN
                ? GetMissionRunMapObject(
                      (u16) ((gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) + 2))
                : 0);
        SetItemCollisionCallback(mapObject, (UnkFunc *) IwanteItemResponse2Callback);
        mapObject->mUnk_2e0 = 2;
    } else {
        mapObject->mUnk_2e0 = 2;
        SetItemCollisionCallback(mapObject, (UnkFunc *) IwanteItemHitCallback);
    }
}

// IwanteHands: the model-less third Mission Run object (index MissionRunGetCurrentKartCount() + 2) that steers both
// stone hands.
void InitIwanteHandsObjects(MapObjectList *mapObjectList) {
    int i;
    Unk02188950 *obj;
    int zero;

    if (mapObjectList != NULL) {
        zero = 0;
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
            InitMissionRunMapObject((void *) zero, obj, (const char *) zero, (const char *) zero, data_ov001_021a7eb0);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            StartIwanteHandsWaitForRaceStart(obj);
        }
    }
}

void UpdateIwanteHands(u32 mapObjectList, Unk02188950 *mapObject) {
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
    int i;
    Unk02188950 *obj;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
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

void UpdateIwante(u32 mapObjectList, Unk02188950 *mapObject) {
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
        frameIndex = mapObject->mUnk_134 + 1;
        if (frameIndex >= GetMapObjectModelNsbtpFrameCount(mapObject->mNsbmd) - 1) {
            frameIndex = GetMapObjectModelNsbtpFrameCount(mapObject->mNsbmd) - 1;
        }
        mapObject->mUnk_134 = frameIndex;
    } else {
        frameIndex = mapObject->mUnk_134 - 1;
        if (frameIndex <= 0) {
            frameIndex = 0;
        }
        mapObject->mUnk_134 = frameIndex;
    }
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, mapObject->mUnk_134);
    AdvanceMissionRunMapObject(mapObjectList, mapObject);
}

// Iwante: the two stone hands of Mission Run.
void InitIwante(MapObjectList *mapObjectList) {
    int i;
    Unk02188950 *obj;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (obj = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(obj);
            }
            InitMissionRunMapObject(mapObjectList, obj, gIwanteLNsbmdName, gIwanteLNsbcaName, gIwanteLPrmName);
            LoadMissionRunMapObjectShadow(mapObjectList, obj, gShIwanteNsbmdName);
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, gIwanteLNsbtpName);
            obj->mCollisionShape = 1;
            if (i == 0) {
                obj->mUnk_000.mFlags |= gMapObjectMirrorFlag;
            } else if (i == 1) {
                obj->mUnk_000.mFlags &= 0xfffffbff;
            }
        }
    }
}

void DrawIwante(void *mapObjectList, Unk02188950 *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
}

void CreateIwanteKindData(void) {
    u32 soundId = 0x21au;
    u32 collideItemSoundId = 0x216u;
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData = CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x1u, soundId,
                                                         collideItemSoundId);
}

void *CreateIwanteDrawList(void) {
    return CreateMapObjectDrawList1(InitIwante, DrawIwante, ToggleShadowScale);
}

void *CreateIwanteUpdateList(void) {
    return CreateMapObjectUpdateList(InitIwanteObjects, UpdateIwante, NULL);
}

void *CreateIwanteHandsUpdateList(void) {
    return CreateMapObjectUpdateList(InitIwanteHandsObjects, UpdateIwanteHands, NULL);
}
