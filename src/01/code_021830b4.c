#include "01/code_021830b4.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02184274.h"
#include "01/code_02184cc8.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_021000d0.h"

void StartDonketuWaterJumpState(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mUnk_238;
    StartMapObjectState(donketu, 8, UpdateDonketuWaterJumpSplash);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_224, donketu->mPrm->mUnk_228);
    SetVelocity(donketu, &velocity);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_230, donketu->mPrm->mUnk_234);
    SetCourseCollisionCallback(donketu, StartDonketuWaterLandState);
    donketu->mUnk_000.mFlags |= data_ov001_021a6578;
}

void StartDonketuWaterWalkState(Unk02188950 *donketu) {
    u32 targetAndPerCall;
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_210, donketu->mPrm->mUnk_214);
    targetAndPerCall = donketu->mPrm->mUnk_21c;
    TurnToPointMoveFollowsAngle(donketu, targetAndPerCall, targetAndPerCall);
    SetAnglePointAndMoveAnglePoint(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow);
    targetAndPerCall = donketu->mPrm->mUnk_218;
    SetSpeedTargetAndPerCall(donketu, targetAndPerCall, targetAndPerCall);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_220, &StartDonketuWaterJumpState);
}

void StartDonketuWaterSinkState(Unk02188950 *donketu) {
    Vec3 velocity;
    s32 scale;

    velocity.x = donketu->mUnk_000.mPos.x;
    velocity.y = 0;
    velocity.z = donketu->mUnk_000.mPos.z;
    if ((s64) velocity.z * velocity.z + ((s64) velocity.x * velocity.x + (s64) velocity.y * velocity.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&velocity, &velocity);
    }
    scale = donketu->mPrm->mUnk_204;
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, scale);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, scale);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, scale);
    velocity.y = -donketu->mPrm->mUnk_208;
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_1fc, donketu->mPrm->mUnk_200);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    SetVelocity(donketu, &velocity);
    DisableMissionRunMapObjectGravity(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_20c, StartDonketuWaterWalkState);
    StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
    StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    StartModelEffectAtWaterHeight(donketu, 4, 0);
    StartMapObjectSound(&donketu->mUnk_000, 0x244);
    donketu->mUnk_000.mFlags |= data_ov001_021a6578;
}

void StartDonketuKartNotEliminatedState(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_070, donketu->mPrm->mUnk_074);
    SetVelocity(donketu, &velocity);
    DisableMissionRunMapObjectGravity(donketu);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x423, 0);
        StartEffectAtWaterHeight(donketu, 0, 0, 0, 0x425, 0);
    }
    {
        SoundStartParams soundRequest = {0x212, 0, 0xc, 0};

        soundRequest.mPositionSource = &donketu->mUnk_000.mPos;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&donketu->mUnk_000.mPos);
        StartSndHandleSoundUnchecked(&soundRequest, GetSecondSndHandleSlot());
    }
    donketu->mUnk_000.mFlags |= data_ov001_021a6578;
}

void StartDonketuJumpLandState(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_160, donketu->mPrm->mUnk_164, NULL);
    SetSpeedAndClearTarget(donketu, 0);
}

u32 UpdateDonketuJumpSound(Unk02188950 *donketu) {
    StartMapObjectSoundWhileRequested(&donketu->mUnk_000, 0x00000243u);
    return 0;
}

void StartDonketuJumpState(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mUnk_154;
    StartMapObjectState(donketu, 5, (s32(*)(Unk02188950 *)) UpdateDonketuJumpSound);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_14c, donketu->mPrm->mUnk_150);
    SpinAngleStopMoveAngle(donketu, donketu->mPrm->mUnk_158, donketu->mPrm->mUnk_158);
    SetVelocity(donketu, &velocity);
    SetCourseCollisionCallback(donketu, StartDonketuJumpLandState);
}

void StartDonketuJumpWaitState(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_12c, donketu->mPrm->mUnk_130, NULL);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_134, &StartDonketuJumpState);
    SetSpeedAndClearTarget(donketu, 0);
}

s32 UpdateDonketuChaseStop(Unk02188950 *donketu) {
    SetAnglePointAndMoveAnglePoint(donketu, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    if (donketu->mSpeed < donketu->mPrm->mUnk_108) {
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
        SetDonketuStepSoundCallbacks(donketu);
    }
    return 0;
}

void StartDonketuChaseStopState(Unk02188950 *donketu) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(donketu, 2, UpdateDonketuChaseStop);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_10c, donketu->mPrm->mUnk_110);
    TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_118, donketu->mPrm->mUnk_118);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    StopMoveAngleTurning(donketu);
    SetSpeedTargetAndPerCall(donketu, 0, donketu->mPrm->mUnk_114);
    SetStoppedCallback(donketu, StartDonketuRepeatJumps);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    if (donketu->mSpeed < donketu->mPrm->mUnk_114) {
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    }
    SetDonketuStepEffectCallbacks((u16 *) donketu);
}

void StartDonketuChaseRunState(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_0f4, donketu->mPrm->mUnk_0f8);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_0fc, donketu->mPrm->mUnk_100);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_104, &StartDonketuChaseStopState);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    SetDonketuStepEffectCallbacks((u16 *) donketu);
}

void StartDonketuChaseWaitState(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_0e8, donketu->mPrm->mUnk_0ec);
    StopTurningMoveFollowsAngle(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_0f0, &StartDonketuChaseRunState);
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuChaseRunAtStart(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_080, donketu->mPrm->mUnk_084);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_088, donketu->mPrm->mUnk_08c);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_090, &StartDonketuChaseStopState);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    SetDonketuStepEffectCallbacks((u16 *) donketu);
}

void StartDonketuChaseKartState(Unk02188950 *donketu) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    StartMapObjectState(donketu, 3, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_0cc, donketu->mPrm->mUnk_0d0);
    TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_0d8, donketu->mPrm->mUnk_0d8);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    SetSpeedAndClearTarget(donketu, donketu->mPrm->mUnk_0d4);
    SetPointInRangeCallback(donketu, 0, donketu->mPrm->mUnk_0e4, &kart->mPos, StartDonketuChaseWaitState);
    if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        StartMapObjectSound(&donketu->mUnk_000, 0x214);
    } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartMapObjectSound(&donketu->mUnk_000, 0x245);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWalkToCourseMapRow(Unk02188950 *donketu) {
    if (IsPointInRange(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow, (donketu->mPrm->mUnk_180 + 0x28), 0)) {
        StartMapObjectState(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_168, donketu->mPrm->mUnk_16c);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mUnk_000.mCourseMapRow->mUnk_00);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_174, donketu->mPrm->mUnk_170);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_17c, NULL);
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    } else {
        StartMapObjectState(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_168, donketu->mPrm->mUnk_16c << 2);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mUnk_000.mCourseMapRow->mUnk_00);
        SetSpeedTargetAndPerCall(donketu, -donketu->mPrm->mUnk_174, donketu->mPrm->mUnk_170);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_17c, NULL);
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWalkState(Unk02188950 *donketu) {
    MissionRunPrm *prm;

    prm = donketu->mPrm;
    if (IsPointInRange(donketu, &GetCurrentGroupEntry(donketu)->mPos, prm->mUnk_0ac, prm->mUnk_0b0)) {
        StartMapObjectState(donketu, 1, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_0b8, donketu->mPrm->mUnk_0bc);
        TurnSidewaysMoveFollowsAngle(donketu, donketu->mPrm->mUnk_0c4, donketu->mPrm->mUnk_0c4, 0);
        SetAnglePointAndMoveAnglePoint(donketu, &GetCurrentGroupEntry(donketu)->mPos);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_0c0, donketu->mPrm->mUnk_0c0);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_0c8, NULL);
    } else {
        IncrementEntryIndex(donketu);
        StartMapObjectState(donketu, 1, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_09c, donketu->mPrm->mUnk_0a0);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_0a8, donketu->mPrm->mUnk_0a8);
        SetAnglePointAndMoveAnglePoint(donketu, &GetCurrentGroupEntry(donketu)->mPos);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_0a4, donketu->mPrm->mUnk_0a4);
        prm = donketu->mPrm;
        SetPointInRangeCallback(donketu, prm->mUnk_0ac, prm->mUnk_0b0, &GetCurrentGroupEntry(donketu)->mPos, NULL);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWaterFallState(Unk02188950 *donketu) {
    StartDonketuWaterSinkState(donketu);
    func_ov001_02188260(donketu);
}

void StartDonketuKartEliminatedState(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_078, donketu->mPrm->mUnk_07c);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
}

void DonketuStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

int UpdateDonketuWaitForRaceStart(Unk02188950 *donketu) {
    if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 2 ||
            GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 3) {
            ReleaseEffects(donketu);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&donketu->mUnk_000, 0x240);
        }
    }
    if (IsRaceStarted() == 1) {
        StartDonketuChaseRunAtStart(donketu);
    }
    return 0;
}

int UpdateDonketuStartupEffects(Unk02188950 *donketu) {
    if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 2) {
            ReleaseEffects(donketu);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            StartEffectWithRotatedDirection(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&donketu->mUnk_000, 0x240);
        }
    } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 0x2b ||
            GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 0x48) {
            ReleaseEffects(donketu);
            StartEffectAtRowHeight(donketu, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}

s32 UpdateDonketuKingIceEffects(Unk02188950 *donketu) {
    int nsbcaFrameIndex;
    if ((donketu->mUnk_000.mKind == 0x000001f6u) &&
        (nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd), nsbcaFrameIndex == 2)) {
        ReleaseEffects(donketu);
        StartEffectWithRotatedDirection(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000428u, 0);
        StartEffectWithRotatedDirection(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000429u, 0);
        StartEffectWithRotatedDirection(donketu, 0x00001000u, 0, 0, 0, 0x00000800u, 0xfffff000u, 0x0000042au, 0);
        StartMapObjectSound(&donketu->mUnk_000, 0x00000240u);
    }
    return 0;
}

void StartDonketuWaitForRaceStart(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 8, &UpdateDonketuWaitForRaceStart);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_064, donketu->mPrm->mUnk_068);
}

void StartDonketuStartupSecond(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 8, &UpdateDonketuStartupEffects);
    if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_058, donketu->mPrm->mUnk_05c);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_060, &StartDonketuWaitForRaceStart);
        return;
    }
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_058, donketu->mPrm->mUnk_05c,
                                  &StartDonketuWaitForRaceStart);
}

void StartDonketuStartupFirst(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_04c, donketu->mPrm->mUnk_050);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_054, &StartDonketuStartupSecond);
}

void StartDonketuChainStartupSecond(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_040, donketu->mPrm->mUnk_044);
}

void StartDonketuChainStartupFirst(Unk02188950 *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_034, donketu->mPrm->mUnk_038);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_03c, &StartDonketuChainStartupSecond);
}

void InitDonketuObjects(MapObjectList *list) {
    s32 objectIndex;
    Unk02188950 *donketu;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            DecrementEntryIndexSkipZero(donketu);
            donketu->mUnk_000.mCourseMapRow->mUnk_00.x = 0;
            donketu->mUnk_000.mCourseMapRow->mUnk_00.z = 0;
            if (GetRaceUseChainCameras() != 0) {
                StartDonketuChainStartupFirst(donketu);
            } else {
                StartDonketuStartupFirst(donketu);
            }
            func_ov001_02188da4(donketu, StartDonketuChaseRunAtStart);
        }
    }
    SetStandingsEndCallback((void (*)(void)) DonketuStandingsEndCallback);
}

void UpdateDonketu(u32 mapObjectList, Unk02188950 *donketu) {
    MissionRunPrm *prm;
    Kart *kart;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (IsStateNumberBelow(donketu, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                StartDonketuKartEliminatedState(donketu);
            } else {
                StartDonketuKartNotEliminatedState(donketu);
            }
        }
    } else {
        if (IsStateNumberBelow(donketu, 8) != 0) {
            if (func_ov001_021871d0(donketu) != FALSE) {
                StartDonketuWaterFallState(donketu);
            }
        }
        if (IsStateNumberBelow(donketu, 5) != 0) {
            prm = donketu->mPrm;
            if (GetAbsoluteCounter(donketu) >= prm->mUnk_148) {
                prm = donketu->mPrm;
                if (GetEntryKartInRange(donketu, prm->mUnk_138, prm->mUnk_13c) != NULL) {
                    prm = donketu->mPrm;
                    kart = GetEntryKartFacingObject(donketu, prm->mUnk_140, prm->mUnk_144);
                    if (kart != NULL) {
                        if ((GetKart(kart->mIndex)->mUnk_48 & 0x100000) != 0 && kart->mBoostTimer > 0) {
                            StartDonketuJumpWaitState(donketu);
                        }
                    }
                }
            }
        }
        if (IsStateNumberBelow(donketu, 3) != 0) {
            if (IsPointInRange(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow, donketu->mPrm->mUnk_180, 0) ==
                FALSE) {
                StartDonketuWalkToCourseMapRow(donketu);
            }
        }
        if (IsStateNumberBelow(donketu, 2) != 0) {
            prm = donketu->mPrm;
            if (GetEntryKartInRange(donketu, prm->mUnk_0dc, prm->mUnk_0e0) != NULL) {
                StartDonketuChaseKartState(donketu);
            }
        }
        if (IsStateNumberBelow(donketu, 1) != 0) {
            StartDonketuWalkState(donketu);
        }
    }
    AdvanceMissionRunMapObject(mapObjectList, donketu);
}

void InitDonketuSoundSource(Unk02188950 *donketu) {
    donketu->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) donketu->mUnk_000.mSound, 0xc, &donketu->mUnk_000.mPos);
    donketu->mUnk_000.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void InitBossDonketu(MapObjectList *list) {
    Unk02188950 *donketu;
    s32 objectIndex;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            InitMissionRunMapObject(list, donketu, gBossDonketuNsbmdName, gBossDonketuNsbcaName, gBossDonketuPrmName);
            LoadMissionRunMapObjectShadow(list, donketu, data_ov001_021a79e4);
            SetCollisionOffsetAndExtent(donketu, donketu->mPrm->mUnk_008, donketu->mPrm->mUnk_00c, 0);
            SetShadowOffsetYAndScale(donketu, 0, 0x11000);
            SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
            donketu->mUnk_2b8 = 2;
        }
    }
}

void InitKingIceDonketu(MapObjectList *list) {
    Unk02188950 *donketu;
    s32 objectIndex;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            InitMissionRunMapObject(list, donketu, gKingIceDonketuNsbmdName, gKingIceDonketuNsbcaName,
                                    gKingIceDonketuPrmName);
            LoadMissionRunMapObjectShadow(list, donketu, data_ov001_021a7998);
            SetCollisionOffsetAndExtent(donketu, donketu->mPrm->mUnk_008, donketu->mPrm->mUnk_00c, 0);
            SetShadowOffsetYAndScale(donketu, 0, 0x21000);
            SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
        }
    }
}

void DrawDonketu(void *mapObjectList, Unk02188950 *donketu) {
    DrawMissionRunMapObject(mapObjectList, donketu);
    DrawMissionRunMapObjectShadow(mapObjectList, donketu, 0);
}

void CreateDonketuKindData(void) {
    u32 v4 = 0x23eu;
    void *kartCollisionCallback = &CollideKartWithMissionRunMapObject;
    void *itemCollisionCallback = &CollideItemWithMissionRunMapObject;
    void *sphereHitCallback = &ComputeSphereHitOnMissionRunMapObject;
    void *kindData = CreateMapObjectKindDataWithSoundIds(kartCollisionCallback, itemCollisionCallback,
                                                         sphereHitCallback, 0x2u, 0x1u, v4, 0x0u);
}

void *CreateBossDonketuDrawList(void) {
    return CreateMapObjectDrawList1(InitBossDonketu, DrawDonketu, ToggleShadowScale);
}

void *CreateKingIceDonketuDrawList(void) {
    return CreateMapObjectDrawList1(InitKingIceDonketu, DrawDonketu, ToggleShadowScale);
}

void *CreateDonketuUpdateList(void) {
    return CreateMapObjectUpdateList(InitDonketuObjects, UpdateDonketu, NULL);
}
