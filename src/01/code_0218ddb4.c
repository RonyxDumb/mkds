#include "01/code_0218ddb4.h"
#include "01/code_02187d14.h"
#include "01/code_02188de0.h"

#include "01/code_02185ef4.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02187cd4.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02188000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181bd0.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_0218f900.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02181000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_020a128c.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
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
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02187000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "01/code_02182000.h"
#include "01/code_02188950.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217a000.h"

void HideKingTeresaWithEffects(MissionRunMapObject *mapObject) {
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_198, mapObject->mPrm->mUnk_19c);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1a0, mapObject->mPrm->mUnk_1a4);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41e, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41f, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x420, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x22d);
    mapObject->mUnk_000.mFlags = mapObject->mUnk_000.mFlags | data_ov001_021a65bc;
}

void SetKingTeresaVelocityWithKartTurn(MissionRunMapObject *mapObject) {
    Vec3 kartStep;
    Vec3 offsetFromKart;
    u32 headingChange;
    s32 i;
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
    VEC_Subtract(&mapObject->mUnk_000.mPos, gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunKartPos() : 0,
                 &offsetFromKart);
    for (i = 0; i < 1; i++) {
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
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetPointInRangePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    return 0;
}

s32 AdvanceKingTeresaFollowKartClearFog(MissionRunMapObject *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
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
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1fc, mapObject->mPrm->mUnk_200);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_204, mapObject->mPrm->mUnk_208);
    TurnFromPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_20c, mapObject->mPrm->mUnk_210);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_214, NULL);
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
}

void StartKingTeresaCoinsFadeOut(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_1f4, mapObject->mPrm->mUnk_1f8,
                                  StartKingTeresaTurnAwayFromKart);
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartCoinsFadeOut();
}

void StartKingTeresaTurnTowardKart(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1d8, mapObject->mPrm->mUnk_1dc);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1e0, mapObject->mPrm->mUnk_1e4);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_1e8, mapObject->mPrm->mUnk_1ec);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StopMoveAngleTurning(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1f0, StartKingTeresaCoinsFadeOut);
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartMapObjectSound(&mapObject->mUnk_000, 0x229);
}

s32 AdvanceKingTeresaFollowForwardPoint(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
        VEC_MultAdd(mapObject->mPrm->mUnk_21c, &kart->mEasedTurnedForward, &kart->mPos, &targetPoint);
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
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityToKartStep(mapObject);
    return 0;
}

void StartKingTeresaMoveToForwardPoint(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    VEC_MultAdd(mapObject->mPrm->mUnk_21c, &kart->mEasedTurnedForward, &kart->mPos, &targetPoint);
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFaceKart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0ec, mapObject->mPrm->mUnk_0f0);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0f4, mapObject->mPrm->mUnk_0f8);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0fc, mapObject->mPrm->mUnk_100);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_218, 0, &targetPoint,
                            (UnkFunc *) StartKingTeresaTurnTowardKart);
    if (gKingTeresaState != 2) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 2;
    SetKartCollisionCallback(mapObject, KingTeresaBossTransferCallback);
    mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
}

s32 AdvanceKingTeresaApproachKart(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 targetPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
        VEC_MultAdd(-mapObject->mPrm->mUnk_0e8, &kart->mEasedTurnedForward, &kart->mPos, &targetPoint);
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
    VEC_MultAdd(-mapObject->mPrm->mUnk_0e8, &kart->mEasedTurnedForward, &kart->mPos, &targetPoint);
    StartMapObjectState(mapObject, 3, AdvanceKingTeresaApproachKart);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0c4, mapObject->mPrm->mUnk_0c8);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0cc, mapObject->mPrm->mUnk_0d0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0d4, mapObject->mPrm->mUnk_0d8);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_0dc, mapObject->mPrm->mUnk_0e0);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0e4, 0, &targetPoint,
                            (UnkFunc *) StartKingTeresaMoveToForwardPoint);
    if (gKingTeresaState != 1) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 1;
}

s32 AdvanceKingTeresaWaitToApproach(MissionRunMapObject *mapObject) {
    Kart *kart;
    float scaledTimerGap;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetPointInRangePoint(mapObject, &kart->mPos);
    }
    SetKingTeresaVelocityWithKartTurn(mapObject);
    if (GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_0b8, 0) == NULL) {
        mapObject->mUnk_1c4 = mapObject->mPrm->mUnk_0c0;
    } else {
        mapObject->mUnk_1c4 = 0;
    }
    mapObject->mAlphaLimitPerCall = mapObject->mPrm->mUnk_09c;
    if (mapObject->mPrm->mUnk_1cc - (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) > 0) {
        scaledTimerGap =
            0.5f +
            ((mapObject->mPrm->mUnk_1cc - (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0)) << 12);
    } else {
        scaledTimerGap =
            ((mapObject->mPrm->mUnk_1cc - (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0)) << 12) -
            0.5f;
    }
    mapObject->mAlphaLimitTarget = (s32) scaledTimerGap / mapObject->mPrm->mUnk_1d4;
    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) <= mapObject->mPrm->mUnk_1d0 &&
        GetEntryKartFacingObject(mapObject, 0, mapObject->mPrm->mUnk_0bc) != NULL) {
        SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
        mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
        StartKingTeresaApproachKart(mapObject);
    } else if ((gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) > mapObject->mPrm->mUnk_1cc) {
        StopMapObjectState(mapObject);
    }
    return 0;
}

void StartKingTeresaWaitToApproach(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceKingTeresaWaitToApproach);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_090, mapObject->mPrm->mUnk_094);
    SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_0a0);
    TurnToPointMoveSideways(mapObject, mapObject->mPrm->mUnk_0b0, 0x270f000, mapObject->mPrm->mUnk_0a8, 0x270f000, 0);
    if (gKingTeresaState != 0) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 0;
}

void ShowKingTeresaNearKart(MissionRunMapObject *mapObject) {
    Kart *kart;
    Vec3 nearKartPoint;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    VEC_MultAdd(-mapObject->mPrm->mUnk_0e8, &kart->mEasedTurnedForward, &kart->mPos, &nearKartPoint);
    mapObject->mUnk_000.mPos.x = nearKartPoint.x;
    mapObject->mUnk_000.mPos.y = mapObject->mUnk_000.mCourseMapRow->mPosition.y + mapObject->mPrm->mUnk_080;
    mapObject->mUnk_000.mPos.z = nearKartPoint.z;
    mapObject->mMoveAngle =
        (u16) (FX_Atan2Idx(kart->mPos.x - mapObject->mUnk_000.mPos.x, kart->mPos.z - mapObject->mUnk_000.mPos.z) +
               0x4000);
    mapObject->mAngle = mapObject->mMoveAngle;
    StartKingTeresaWaitToApproach(mapObject);
    SetBossCoinShownCount(0);
    mapObject->mUnk_000.mFlags &= ~1;
}

void StartKingTeresaHitReaction(MissionRunMapObject *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 3, AdvanceKingTeresaFollowKartClearFog);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_144, mapObject->mPrm->mUnk_148);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_14c, mapObject->mPrm->mUnk_150);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_154, mapObject->mPrm->mUnk_158);
    TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_15c, mapObject->mPrm->mUnk_160);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_164, NULL);
}

u32 ClearFadeFogHoldFramesWrapper(void) {
    ClearFadeFogHoldFrames();
    return 0;
}

void StartKingTeresaMoveToGroupEntry(MissionRunMapObject *mapObject) {
    GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(mapObject, 1, (s32(*)(MissionRunMapObject *)) ClearFadeFogHoldFramesWrapper);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_118, mapObject->mPrm->mUnk_11c);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_120, mapObject->mPrm->mUnk_124);
    if (mapObject->mUnk_0a8 == 1) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_128, mapObject->mPrm->mUnk_12c);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_130, mapObject->mPrm->mUnk_134);
    } else if (mapObject->mUnk_0a8 == 2) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_220, mapObject->mPrm->mUnk_224);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_228, mapObject->mPrm->mUnk_22c);
    } else if (mapObject->mUnk_0a8 == 3) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_230, mapObject->mPrm->mUnk_234);
        TurnToPointMoveFollowsAngle(mapObject, mapObject->mPrm->mUnk_238, mapObject->mPrm->mUnk_23c);
    }
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_138, mapObject->mPrm->mUnk_13c,
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
    mapObject->mUnk_000.mPos.x = (&GetCurrentGroupEntry(mapObject)->mPos)->x;
    mapObject->mUnk_000.mPos.y = mapObject->mPrm->mUnk_080 + (&GetCurrentGroupEntry(mapObject)->mPos)->y;
    mapObject->mUnk_000.mPos.z = (&GetCurrentGroupEntry(mapObject)->mPos)->z;
    StartMapObjectState(mapObject, 5, (s32(*)(MissionRunMapObject *)) ClearFadeFogHoldFramesWrapper);
    ShowKingTeresaWithEffects(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1b4, NULL);
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
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1a8, ShowKingTeresaAtGroupEntry);
    SetBossCoinShownCount(0);
    IncrementEntryGroupIndex(mapObject, mapObject->mPrm->mUnk_140);
    currentValue = mapObject->mUnk_0a8;
    if (currentValue == 1) {
        nextValue = 2;
    } else if (currentValue == 2) {
        nextValue = 3;
    } else if (currentValue == 3) {
        nextValue = 3;
    } else {
        nextValue = 1;
    }
    mapObject->mUnk_0a8 = nextValue;
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
    mapObject->mCollisionExtentTargetZ = mapObject->mPrm->mUnk_00c;
    mapObject->mCollisionExtent.z = mapObject->mCollisionExtentTargetZ;
    mapObject->mCollisionExtentTargetX = mapObject->mCollisionExtent.z;
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX;
}

u32 AdvanceKingTeresaSinkToCourseRow(MissionRunMapObject *mapObject) {
    int newY;
    int lowestY;
    lowestY = mapObject->mUnk_000.mCourseMapRow->mPosition.y + mapObject->mPrm->mUnk_084;
    newY = mapObject->mUnk_000.mPos.y - mapObject->mPrm->mUnk_088;
    if (newY <= lowestY) {
        newY = lowestY;
    }
    mapObject->mUnk_000.mPos.y = newY;
    ClearFadeFogHoldFrames();
    return 0;
}

void StartKingTeresaShowBossCoins(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, (s32(*)(MissionRunMapObject *)) AdvanceKingTeresaSinkToCourseRow);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_170, mapObject->mPrm->mUnk_174);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_178, mapObject->mPrm->mUnk_17c);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_194, StartKingTeresaHideForNextGroup);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x431, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x430, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x432, 0);
    if (gKingTeresaState != 4) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 4;
    SetKartCollisionCallback(mapObject, KingTeresaParkBossCoinsCallback);
    mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
    SetBossCoinShownCount(mapObject->mPrm->mUnk_18c <
                                  (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunBossCount() : 0)
                              ? mapObject->mPrm->mUnk_18c
                              : (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunBossCount() : 0));
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = mapObject->mCollisionExtent.z =
        mapObject->mCollisionExtentTargetZ = mapObject->mPrm->mUnk_00c / 2;
}

void StartKingTeresaStopForBossCoins(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_168, mapObject->mPrm->mUnk_16c,
                                  StartKingTeresaShowBossCoins);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetBossCoinShownCount(0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x00000230u);
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
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1a8, StartKingTeresaCoinsFadeIn);
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
}

void HideKingTeresaWithoutEffects(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_198, mapObject->mPrm->mUnk_19c);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1a0, mapObject->mPrm->mUnk_1a4);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65bc;
}

void StartKingTeresaState1ShadowOffset(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 1, NULL);
    SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
}

void StartKingTeresaHideThenState1(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 5, AdvanceKingTeresaFollowKart);
    HideKingTeresaWithEffects(mapObject);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1a8, StartKingTeresaState1ShadowOffset);
    if (gKingTeresaState != 3) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 3;
}

void StartKingTeresaKartEliminatedHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
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
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartEffect(0x3fe, &mapObject->mUnk_000.mPos);
    StartEffect(0x3fd, &mapObject->mUnk_000.mPos);
    if (gKingTeresaState != 7) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 7;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65b4;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65b8;
    mapObject->mUnk_000.mFlags |= data_ov001_021a65bc;
}

s32 AdvanceKingTeresaEndReachedSound(MissionRunMapObject *mapObject) {
    if (mapObject->mStateFrames == 50) {
        SoundStartParams soundParams = {0x22f, 0, 0xe, 0};
        soundParams.mPositionSource = &mapObject->mUnk_000.mPos;
        soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&mapObject->mUnk_000.mPos);
        StartSndHandleSoundUnchecked(&soundParams, GetSecondSndHandleSlot());
    }
    return 0;
}

void ShowKingTeresaAtEndReached(MissionRunMapObject *mapObject) {
    mapObject->mUnk_000.mPos.y += mapObject->mPrm->mUnk_080;
    mapObject->mAlphaLimit = mapObject->mAlphaLimitTarget = 0x1f000;
    mapObject->mAlphaLimitPerCall = 0;
    StartMapObjectState(mapObject, 8, AdvanceKingTeresaEndReachedSound);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StartStateFrameCountCallback(mapObject, 0x3c, HideKingTeresaAtEndReached);
    if (gKingTeresaState != 7) {
        gPreviousKingTeresaState = gKingTeresaState;
    }
    gKingTeresaState = 7;
    mapObject->mUnk_000.mFlags &= ~1;
}

void StartKingTeresaWinnerDecidedHold(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void KingTeresaStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

void StartKingTeresaSecondAnimation(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_058, mapObject->mPrm->mUnk_05c,
                                  StartKingTeresaHideThenState1);
}

void StartKingTeresaFirstAnimation(MissionRunMapObject *mapObject) {
    mapObject->mUnk_000.mPos.y += mapObject->mPrm->mUnk_080;
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_04c, mapObject->mPrm->mUnk_050);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_054, StartKingTeresaSecondAnimation);
}

void ShowKingTeresaAfterWait(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, NULL);
    ShowKingTeresaWithEffects(mapObject);
}

void StartKingTeresaZeroAlphaWait(MissionRunMapObject *mapObject) {
    mapObject->mUnk_000.mPos.y += mapObject->mPrm->mUnk_080;
    mapObject->mAlphaLimitTarget = 0;
    mapObject->mAlphaLimit = mapObject->mAlphaLimitTarget;
    mapObject->mAlphaLimit = 0;
    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_034, mapObject->mPrm->mUnk_038);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_03c, ShowKingTeresaAfterWait);
}

void InitKingTeresaMapObject(MissionRunMapObject *mapObject) {
    mapObject->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&mapObject->mUnk_000.mSound->mSoundSource, 0xe, &mapObject->mUnk_000.mPos);
    mapObject->mUnk_000.mFarDistanceSquared = gSoundFalloffs[14].mFarDistanceSquared;
}

void KingTeresaParkBossCoinsCallback(MissionRunMapObject *mapObject, Kart *kart) {
    mapObject->mUnk_000.mPosStep.x = MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mUnk_024, FX_SinIdx(kart->mHeadingAngle));
    mapObject->mUnk_000.mPosStep.y = 0;
    mapObject->mUnk_000.mPosStep.z = MUL_FIXED12_NO_ROUND(-mapObject->mPrm->mUnk_024, FX_CosIdx(kart->mHeadingAngle));
    ParkBossCoins(mapObject->mPrm->mUnk_190);
    StartKingTeresaHideForNextGroup(mapObject);
    mapObject->mUnk_2d8 = 0;
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartKingTeresaHideThenCoinsFadeIn(mapObject);
    mapObject->mUnk_0a8 = 0;
    StartMapObjectSound(&mapObject->mUnk_000, 0x22c);
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = mapObject->mCollisionExtent.z =
        mapObject->mCollisionExtentTargetZ = mapObject->mPrm->mUnk_00c;
}

void KingTeresaHitReactionCallback(MissionRunMapObject *mapObject) {
    int isBelowFive;
    isBelowFive = IsStateNumberBelow(mapObject, 5);
    if (isBelowFive != 0) {
        StartKingTeresaHitReaction(mapObject);
    }
    mapObject->mUnk_2d8 = 0xd;
    SetKartCollisionCallback(mapObject, KingTeresaHitReactionCallback);
    if (mapObject->mTimer == 0) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x00000234u);
    }
}

void KingTeresaBossTransferCallback(MissionRunMapObject *mapObject, Kart *kart) {
    AddPendingBossTransferInMissionRun((u16) mapObject->mPrm->mUnk_110);
    mapObject->mUnk_000.mPosStep.x = 0;
    mapObject->mUnk_000.mPosStep.y = mapObject->mPrm->mUnk_114;
    mapObject->mUnk_000.mPosStep.z = 0;
    mapObject->mUnk_2d8 = 0xc;
    mapObject->mUnk_158 = AdvanceKingTeresaFollowForwardPoint;
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    StartKartHitReaction(kart);
    SetShadowOffsetYAndScale(mapObject, 0, 0x32000);
    mapObject->mUnk_0a8 = 1;
    if (!(gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0)) {
        StartFadeFog();
    }
}

void InitKingTeresaObjects(MapObjectList *mapObjectList) {
    s32 i;
    MissionRunMapObject *mapObject;
    MissionRunPrm *prm;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (GetRaceUseChainCameras() != 0) {
                StartKingTeresaZeroAlphaWait(mapObject);
            } else {
                StartKingTeresaFirstAnimation(mapObject);
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                prm = mapObject->mPrm;
                SetMissionRunTimerValues(prm->mUnk_1b8, prm->mUnk_1bc, prm->mUnk_1c0, prm->mUnk_1c4);
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
        if (mapObject->mUnk_0a8 != 0) {
            if (IsStateNumberBelow(mapObject, 5) != 0) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                if (kart->mState == KART_STATE_NORMAL && (kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0 &&
                    GetEntryKartInRange(mapObject, 0, mapObject->mPrm->mUnk_184) != NULL &&
                    GetEntryKartFacingObject(mapObject, 0, mapObject->mPrm->mUnk_180) != NULL &&
                    GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_188, 0) != NULL) {
                    StartKingTeresaStopForBossCoins(mapObject);
                }
            }
            if (IsStateNumberBelow(mapObject, 3) != 0) {
                if (IsPointInRange(mapObject, &GetCurrentGroupEntry(mapObject)->mPos, mapObject->mPrm->mUnk_138, 0) !=
                    0) {
                    IncrementEntryIndex(mapObject);
                }
                SetKartCollisionCallback(mapObject, KingTeresaHitReactionCallback);
                mapObject->mUnk_000.mFlags &= ~0x40;
                SetBossCoinShownCount(0);
                StartKingTeresaMoveToGroupEntry(mapObject);
            }
        } else {
            kart = GetKart((u16) gRaceSetup->mEntryIndex);
            if (kart->mUnk_48 & KART_48_OBJECTS_SKIP) {
                if (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunCount() : 0) {
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        SetMissionRunTimer((u16) mapObject->mPrm->mUnk_1bc);
                    }
                } else {
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        SetMissionRunTimer(0);
                    }
                }
                if ((mapObject->mUnk_000.mFlags & 1) == 0) {
                    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                    mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
                    HideKingTeresaWithoutEffects(mapObject);
                }
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) {
                if (IsStateNumberBelow(mapObject, 3) != 0) {
                    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunTimer() : 0) <
                        mapObject->mPrm->mUnk_1c8) {
                        if (mapObject->mUnk_000.mFlags & 1) {
                            SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                            mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
                            ShowKingTeresaNearKart(mapObject);
                        } else {
                            SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                            mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
                            StartKingTeresaWaitToApproach(mapObject);
                        }
                    } else if ((mapObject->mUnk_000.mFlags & 1) == 0) {
                        SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
                        mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
                        HideKingTeresaWithoutEffects(mapObject);
                    }
                }
            }
        }
        if (gKingTeresaState == 0) {
            StartKingTeresaAlphaSound(mapObject->mUnk_000.mSound);
        } else if (IsKingTeresaState0Or2Or5() != 0) {
            StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x22a);
        } else if (gKingTeresaState == 4) {
            StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x22b);
        }
    }
    AdvanceMissionRunMapObject(unused, mapObject);
}

void InitKingTeresa(MapObjectList *mapObjectList) {
    int i;
    MissionRunMapObject *mapObject;
    MissionRunPrm *prm;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(mapObject);
            }
            InitMissionRunMapObject(mapObjectList, mapObject, gKingTeresaNsbmdName, gKingTeresaNsbcaName,
                                    gKingTeresaPrmName);
            LoadMissionRunMapObjectShadow(mapObjectList, mapObject, data_ov001_021a7dd8);
            prm = mapObject->mPrm;
            SetCollisionOffsetAndExtent(mapObject, prm->mUnk_008, prm->mUnk_00c, prm->mUnk_240);
            SetShadowOffsetYAndScale(mapObject, 0, 0x19000);
            SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
            SetNodePositionSource(mapObject, 0);
            mapObject->mUnk_000.mFlags |= data_ov001_021a65b0;
            mapObject->mUnk_2b8 = 3;
        }
    }
}

void DrawKingTeresa(void *mapObjectList, MissionRunMapObject *mapObject) {
    DrawMissionRunMapObject(mapObjectList, mapObject);
    if (mapObject->mUnk_0a8 == 0) {
        DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 0);
        return;
    }
    DrawMissionRunMapObjectShadow(mapObjectList, mapObject, 1);
}

void CreateKingTeresaKindData(void) {
    void *kartCollision = &CollideKartWithMissionRunMapObject;
    void *itemCollision = &CollideItemWithMissionRunMapObject;
    void *sphereHit = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData =
        CreateMapObjectKindDataWithSoundIds(kartCollision, itemCollision, sphereHit, 0x2u, 0x0u, 0x0u, 0x0u);
}

void *CreateKingTeresaDrawList(void) {
    return CreateMapObjectDrawList1(InitKingTeresa, DrawKingTeresa, ToggleShadowScale);
}

void *CreateKingTeresaUpdateList(void) {
    return CreateMapObjectUpdateList(InitKingTeresaObjects, UpdateKingTeresa, NULL);
}
