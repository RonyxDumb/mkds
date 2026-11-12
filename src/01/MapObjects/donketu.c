#include "01/MapObjects/donketu.h"
#include "01/code_02184e18.h"
#include "01/MapObjects/lld.h"
#include "01/code_02184cc8.h"
#include "01/code_02188218.h"
#include "01/code_0218820c.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "01/code_021843b0.h"
#include "01/code_02188950.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02184000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/effects.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Sound/sound_start.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "01/code_02184390.h"
#include "01/code_021842ec.h"
#include "01/code_021842b4.h"
#include "01/code_02184274.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Unknown/code_0210b000.h"

void StartBossDonketuStepEffectFirst(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0x000008cdu, 0, 0x0000119au, 0x00000413u, 0);
}

void StartBossDonketuStepEffectSecond(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0xfffff733u, 0, 0x0000119au, 0x00000413u, 0);
}

void StartKingIceDonketuStepEffectFirst(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0xfffff000u, 0, 0x00001333u, 0x00000444u, 0);
}

void StartKingIceDonketuStepEffectSecond(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0x00001000u, 0, 0x00001333u, 0x00000444u, 0);
}

void SetDonketuStepSoundCallbacks(MissionRunMapObject *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0x19, StartDonketuStepSoundFirst, 0x36, StartDonketuStepSoundSecond);
}

void SetDonketuStepEffectCallbacks(u16 *mapObject) {
    if (*mapObject == (0x000001f5u)) {
        SetTwoAnimationFrameCallbacks((MissionRunMapObject *) mapObject, 0x19, StartBossDonketuStepEffectFirst, 0x36,
                                      StartBossDonketuStepEffectSecond);
        return;
    }
    if (*mapObject == (0x000001f6u)) {
        SetTwoAnimationFrameCallbacks((MissionRunMapObject *) mapObject, 9, StartKingIceDonketuStepEffectFirst, 0x26,
                                      StartKingIceDonketuStepEffectSecond);
    }
}

void StartDonketuRepeatJumpAfterHitState(MissionRunMapObject *mapObject) {
    if (GetRepeatsRemaining(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mUnk_1f4;
        StartMapObjectState(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1ec, mapObject->mPrm->mUnk_1f0);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, StartDonketuRepeatJumpAfterHitState);
    } else {
        StartMapObjectState(mapObject, 0, NULL);
    }
}

void StartDonketuRepeatJumpsAfterHit(MissionRunMapObject *mapObject) {
    SetRepeatsRemaining(mapObject, (u16) mapObject->mPrm->mUnk_1f8);
    StopTurningMoveFollowsAngle(mapObject);
    StartDonketuRepeatJumpAfterHitState(mapObject);
}

void StartDonketuRepeatJumpState(MissionRunMapObject *mapObject) {
    if (GetRepeatsRemaining(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mUnk_124;
        StartMapObjectState(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, StartDonketuRepeatJumpState);
    } else {
        StartMapObjectState(mapObject, 0, NULL);
    }
}

void StartDonketuRepeatJumps(MissionRunMapObject *mapObject) {
    SetRepeatsRemaining(mapObject, (u16) mapObject->mPrm->mUnk_128);
    StopTurningMoveFollowsAngle(mapObject);
    StartDonketuRepeatJumpState(mapObject);
}

void DonketuKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    s32 scale;

    if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_BOOST) && kart->mBoostTimer > 0) {
        if (IsStateNumberBelow(donketu, 8)) {
            if (donketu->mPrm->mUnk_1dc > 0 || donketu->mPrm->mUnk_1e0 > 0) {
                Vec3 velocityWhenBoosted = {0, 0, 0};
                velocityWhenBoosted.x = kart->mVelocity.x;
                velocityWhenBoosted.z = kart->mVelocity.z;
                if ((s64) velocityWhenBoosted.z * velocityWhenBoosted.z +
                        ((s64) velocityWhenBoosted.x * velocityWhenBoosted.x +
                         (s64) velocityWhenBoosted.y * velocityWhenBoosted.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&velocityWhenBoosted, &velocityWhenBoosted);
                }
                scale = donketu->mPrm->mUnk_1e0;
                velocityWhenBoosted.x = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.x, scale);
                velocityWhenBoosted.y = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.y, scale);
                velocityWhenBoosted.z = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.z, scale);
                velocityWhenBoosted.y = donketu->mPrm->mUnk_1dc;
                StartMapObjectState(donketu, 7, NULL);
                StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_1d4, donketu->mPrm->mUnk_1d8);
                SpinAngleStopMoveAngle(donketu, donketu->mPrm->mUnk_1e4, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                SetStoppedCallback(donketu, StartDonketuRepeatJumpsAfterHit);
                SetSpeedAndClearTarget(donketu, 0);
            }
            {
                Vec3 effectPosition;

                VEC_Subtract(&donketu->mUnk_000.mPos, &kart->mCollisionCenter, &effectPosition);
                if ((s64) effectPosition.z * effectPosition.z +
                        ((s64) effectPosition.x * effectPosition.x + (s64) effectPosition.y * effectPosition.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
                }
                VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
                if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                    donketu->mUnk_000.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                    StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x214);
                    StartMapObjectSound(&donketu->mUnk_000, 0x211);
                    StartEffect(0x3e9, &effectPosition);
                    StartEffect(0x3e8, &effectPosition);
                    StartEffect(0x3ea, &effectPosition);
                    StartEffectAtRowHeight(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                    StartEffectAtRowHeight(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                    donketu->mUnk_000.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                    StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x245);
                    StartMapObjectSound(&donketu->mUnk_000, 0x23f);
                    StartEffect(0x3fa, &effectPosition);
                    StartEffect(0x3fb, &effectPosition);
                    StartEffect(0x3fc, &effectPosition);
                    StartEffectAtRowHeight(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                    StartEffectAtRowHeight(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (IsStateNumberBelow(donketu, 7)) {
        if (donketu->mPrm->mUnk_1c4 > 0 || donketu->mPrm->mUnk_1c8 > 0) {
            Vec3 velocityWhenNotBoosted = {0, 0, 0};
            velocityWhenNotBoosted.x = kart->mVelocity.x;
            velocityWhenNotBoosted.z = kart->mVelocity.z;
            if ((s64) velocityWhenNotBoosted.z * velocityWhenNotBoosted.z +
                    ((s64) velocityWhenNotBoosted.x * velocityWhenNotBoosted.x +
                     (s64) velocityWhenNotBoosted.y * velocityWhenNotBoosted.y) >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&velocityWhenNotBoosted, &velocityWhenNotBoosted);
            }
            scale = donketu->mPrm->mUnk_1c8;
            velocityWhenNotBoosted.x = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.x, scale);
            velocityWhenNotBoosted.y = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.y, scale);
            velocityWhenNotBoosted.z = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.z, scale);
            velocityWhenNotBoosted.y = donketu->mPrm->mUnk_1c4;
            StartMapObjectState(donketu, 7, NULL);
            StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_1bc, donketu->mPrm->mUnk_1c0);
            SpinAngleStopMoveAngle(donketu, donketu->mPrm->mUnk_1cc, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            SetStoppedCallback(donketu, NULL);
            SetSpeedAndClearTarget(donketu, 0);
        }
    }
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mUnk_2d8 = 13;
}

void DonketuChaseKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    Vec3 velocityWhenBoosted;
    Vec3 effectPosition;
    Vec3 velocityWhenNotBoosted;

    if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_BOOST) && kart->mBoostTimer > 0) {
        if (IsStateNumberBelow(donketu, 8)) {
            if (donketu->mPrm->mUnk_1a8 > 0 || donketu->mPrm->mUnk_1ac > 0) {
                velocityWhenBoosted.x =
                    MUL_FIXED12_NO_ROUND(-donketu->mPrm->mUnk_1ac, FX_SinIdx((u16) donketu->mMoveAngle));
                velocityWhenBoosted.y = donketu->mPrm->mUnk_1a8;
                velocityWhenBoosted.z =
                    MUL_FIXED12_NO_ROUND(-donketu->mPrm->mUnk_1ac, FX_CosIdx((u16) donketu->mMoveAngle));
                StartMapObjectState(donketu, 7, NULL);
                StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_1a0, donketu->mPrm->mUnk_1a4);
                SpinAngleStopMoveAngle(donketu, donketu->mPrm->mUnk_1b0, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                SetStoppedCallback(donketu, StartDonketuRepeatJumpsAfterHit);
                SetSpeedAndClearTarget(donketu, 0);
            }
            VEC_Subtract(&donketu->mUnk_000.mPos, &kart->mCollisionCenter, &effectPosition);
            if ((s64) effectPosition.x * effectPosition.x + (s64) effectPosition.y * effectPosition.y +
                    (s64) effectPosition.z * effectPosition.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
            }
            VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
            if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                donketu->mUnk_000.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x214);
                StartMapObjectSound(&donketu->mUnk_000, 0x211);
                StartEffect(0x3e9, &effectPosition);
                StartEffect(0x3e8, &effectPosition);
                StartEffect(0x3ea, &effectPosition);
                StartEffectAtRowHeight(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                StartEffectAtRowHeight(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
            } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                donketu->mUnk_000.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x245);
                StartMapObjectSound(&donketu->mUnk_000, 0x23f);
                StartEffect(0x3fa, &effectPosition);
                StartEffect(0x3fb, &effectPosition);
                StartEffect(0x3fc, &effectPosition);
                StartEffectAtRowHeight(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                StartEffectAtRowHeight(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
            }
            donketu->mUnk_000.mPosStep.x =
                MUL_FIXED12_NO_ROUND(donketu->mPrm->mUnk_1b8, FX_SinIdx((u16) donketu->mMoveAngle));
            donketu->mUnk_000.mPosStep.y = 0;
            donketu->mUnk_000.mPosStep.z =
                MUL_FIXED12_NO_ROUND(donketu->mPrm->mUnk_1b8, FX_CosIdx((u16) donketu->mMoveAngle));
            donketu->mUnk_000.mPos.x -= donketu->mUnk_000.mPosStep.x;
            donketu->mUnk_000.mPos.y -= donketu->mUnk_000.mPosStep.y;
            donketu->mUnk_000.mPos.z -= donketu->mUnk_000.mPosStep.z;
        }
    } else if (IsStateNumberBelow(donketu, 7)) {
        if (donketu->mPrm->mUnk_18c > 0 || donketu->mPrm->mUnk_190 > 0) {
            velocityWhenNotBoosted.x =
                MUL_FIXED12_NO_ROUND(-donketu->mPrm->mUnk_190, FX_SinIdx((u16) donketu->mMoveAngle));
            velocityWhenNotBoosted.y = donketu->mPrm->mUnk_18c;
            velocityWhenNotBoosted.z =
                MUL_FIXED12_NO_ROUND(-donketu->mPrm->mUnk_190, FX_CosIdx((u16) donketu->mMoveAngle));
            StartMapObjectState(donketu, 7, NULL);
            StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_184, donketu->mPrm->mUnk_188);
            SpinAngleStopMoveAngle(donketu, donketu->mPrm->mUnk_194, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            SetStoppedCallback(donketu, StartDonketuRepeatJumps);
            SetSpeedAndClearTarget(donketu, 0);
        }
        donketu->mUnk_000.mPosStep.x =
            MUL_FIXED12_NO_ROUND(donketu->mPrm->mUnk_19c, FX_SinIdx((u16) donketu->mMoveAngle));
        donketu->mUnk_000.mPosStep.y = 0;
        donketu->mUnk_000.mPosStep.z =
            MUL_FIXED12_NO_ROUND(donketu->mPrm->mUnk_19c, FX_CosIdx((u16) donketu->mMoveAngle));
        donketu->mUnk_000.mPos.x -= donketu->mUnk_000.mPosStep.x;
        donketu->mUnk_000.mPos.y -= donketu->mUnk_000.mPosStep.y;
        donketu->mUnk_000.mPos.z -= donketu->mUnk_000.mPosStep.z;
        donketu->mUnk_000.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
        StartMapObjectSound(&donketu->mUnk_000, 0x213);
    }
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mUnk_2d8 = 0xd;
    StartCameraWobbleAtDistance(donketu->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
}

void DonketuFallKartCollisionCallback(MissionRunMapObject *donketu) {
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mUnk_2d8 = 0xb;
}

void StartDonketuWaterLandState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 7, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_23c, donketu->mPrm->mUnk_240, NULL);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x412, 0);
    StartMapObjectSound(&donketu->mUnk_000, 0x242);
    StartCameraWobbleAtDistance(donketu->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mUnk_000.mFlags &= ~0x20;
}

s32 UpdateDonketuFall(MissionRunMapObject *donketu) {
    if (donketu->mVelocity.y < 0) {
        SetKartCollisionCallback(donketu, DonketuFallKartCollisionCallback);
        donketu->mUnk_150 = 7;
        donketu->mUnk_158 = NULL;
    }
    return 0;
}

s32 UpdateDonketuWaterJumpSplash(MissionRunMapObject *donketu) {
    if (donketu->mUnk_000.mPos.y >= -GetHeightAboveWaterOrEfct(0)) {
        StartModelEffectAtWaterHeight(donketu, 4, 0);
        StartMapObjectSound(&donketu->mUnk_000, 0x241);
        donketu->mUnk_158 = UpdateDonketuFall;
    }
    return 0;
}

void StartDonketuWaterJumpState(MissionRunMapObject *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mUnk_238;
    StartMapObjectState(donketu, 8, UpdateDonketuWaterJumpSplash);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_224, donketu->mPrm->mUnk_228);
    SetVelocity(donketu, &velocity);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_230, donketu->mPrm->mUnk_234);
    SetCourseCollisionCallback(donketu, StartDonketuWaterLandState);
    donketu->mUnk_000.mFlags |= gDonketuWaterFlag;
}

void StartDonketuWaterWalkState(MissionRunMapObject *donketu) {
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

void StartDonketuWaterSinkState(MissionRunMapObject *donketu) {
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
    donketu->mUnk_000.mFlags |= gDonketuWaterFlag;
}

void StartDonketuKartNotEliminatedState(MissionRunMapObject *donketu) {
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
    donketu->mUnk_000.mFlags |= gDonketuWaterFlag;
}

void StartDonketuJumpLandState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_160, donketu->mPrm->mUnk_164, NULL);
    SetSpeedAndClearTarget(donketu, 0);
}

u32 UpdateDonketuJumpSound(MissionRunMapObject *donketu) {
    StartMapObjectSoundWhileRequested(&donketu->mUnk_000, 0x00000243u);
    return 0;
}

void StartDonketuJumpState(MissionRunMapObject *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mUnk_154;
    StartMapObjectState(donketu, 5, (s32(*)(MissionRunMapObject *)) UpdateDonketuJumpSound);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_14c, donketu->mPrm->mUnk_150);
    SpinAngleStopMoveAngle(donketu, donketu->mPrm->mUnk_158, donketu->mPrm->mUnk_158);
    SetVelocity(donketu, &velocity);
    SetCourseCollisionCallback(donketu, StartDonketuJumpLandState);
}

void StartDonketuJumpWaitState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 5, NULL);
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_12c, donketu->mPrm->mUnk_130, NULL);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_134, &StartDonketuJumpState);
    SetSpeedAndClearTarget(donketu, 0);
}

s32 UpdateDonketuChaseStop(MissionRunMapObject *donketu) {
    SetAnglePointAndMoveAnglePoint(donketu, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    if (donketu->mSpeed < donketu->mPrm->mUnk_108) {
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
        SetDonketuStepSoundCallbacks(donketu);
    }
    return 0;
}

void StartDonketuChaseStopState(MissionRunMapObject *donketu) {
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

void StartDonketuChaseRunState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_0f4, donketu->mPrm->mUnk_0f8);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_0fc, donketu->mPrm->mUnk_100);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_104, &StartDonketuChaseStopState);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    SetDonketuStepEffectCallbacks((u16 *) donketu);
}

void StartDonketuChaseWaitState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_0e8, donketu->mPrm->mUnk_0ec);
    StopTurningMoveFollowsAngle(donketu);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_0f0, &StartDonketuChaseRunState);
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuChaseRunAtStart(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 2, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_080, donketu->mPrm->mUnk_084);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_088, donketu->mPrm->mUnk_08c);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_090, &StartDonketuChaseStopState);
    SetKartCollisionCallback(donketu, DonketuChaseKartCollisionCallback);
    SetDonketuStepEffectCallbacks((u16 *) donketu);
}

void StartDonketuChaseKartState(MissionRunMapObject *donketu) {
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

void StartDonketuWalkToCourseMapRow(MissionRunMapObject *donketu) {
    if (IsPointInRange(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow, (donketu->mPrm->mUnk_180 + 0x28), 0)) {
        StartMapObjectState(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_168, donketu->mPrm->mUnk_16c);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mUnk_000.mCourseMapRow->mPosition);
        SetSpeedTargetAndPerCall(donketu, donketu->mPrm->mUnk_174, donketu->mPrm->mUnk_170);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_17c, NULL);
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    } else {
        StartMapObjectState(donketu, 3, NULL);
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_168, donketu->mPrm->mUnk_16c << 2);
        TurnToPointMoveFollowsAngle(donketu, donketu->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mUnk_000.mCourseMapRow->mPosition);
        SetSpeedTargetAndPerCall(donketu, -donketu->mPrm->mUnk_174, donketu->mPrm->mUnk_170);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_17c, NULL);
        SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    }
    SetDonketuStepSoundCallbacks(donketu);
}

void StartDonketuWalkState(MissionRunMapObject *donketu) {
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

void StartDonketuWaterFallState(MissionRunMapObject *donketu) {
    StartDonketuWaterSinkState(donketu);
    IncrementHitCountAndCheckLimit(donketu);
}

void StartDonketuKartEliminatedState(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, NULL);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_078, donketu->mPrm->mUnk_07c);
    StopTurningMoveFollowsAngle(donketu);
    SetSpeedAndClearTarget(donketu, 0);
}

void DonketuStandingsEndCallback(void) {
    ResetMissionRunMapObjects();
}

int UpdateDonketuWaitForRaceStart(MissionRunMapObject *donketu) {
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

int UpdateDonketuStartupEffects(MissionRunMapObject *donketu) {
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

s32 UpdateDonketuKingIceEffects(MissionRunMapObject *donketu) {
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

void StartDonketuWaitForRaceStart(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, &UpdateDonketuWaitForRaceStart);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_064, donketu->mPrm->mUnk_068);
}

void StartDonketuStartupSecond(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, &UpdateDonketuStartupEffects);
    if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
        StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_058, donketu->mPrm->mUnk_05c);
        StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_060, &StartDonketuWaitForRaceStart);
        return;
    }
    StartAnimationWithEndCallback(donketu, donketu->mPrm->mUnk_058, donketu->mPrm->mUnk_05c,
                                  &StartDonketuWaitForRaceStart);
}

void StartDonketuStartupFirst(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_04c, donketu->mPrm->mUnk_050);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_054, &StartDonketuStartupSecond);
}

void StartDonketuChainStartupSecond(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_040, donketu->mPrm->mUnk_044);
}

void StartDonketuChainStartupFirst(MissionRunMapObject *donketu) {
    StartMapObjectState(donketu, 8, UpdateDonketuKingIceEffects);
    StartAnimationNoEndCallback(donketu, donketu->mPrm->mUnk_034, donketu->mPrm->mUnk_038);
    StartStateFrameCountCallback(donketu, donketu->mPrm->mUnk_03c, &StartDonketuChainStartupSecond);
}

void InitDonketuObjects(MapObjectList *list) {
    s32 objectIndex;
    MissionRunMapObject *donketu;

    if (list != NULL) {
        for (objectIndex = 0; objectIndex < list->mMapObjectCount && (donketu = list->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            DecrementEntryIndexSkipZero(donketu);
            donketu->mUnk_000.mCourseMapRow->mPosition.x = 0;
            donketu->mUnk_000.mCourseMapRow->mPosition.z = 0;
            if (GetRaceUseChainCameras() != 0) {
                StartDonketuChainStartupFirst(donketu);
            } else {
                StartDonketuStartupFirst(donketu);
            }
            SetUnusedCallback(donketu, StartDonketuChaseRunAtStart);
        }
    }
    SetStandingsEndCallback((void (*)(void)) DonketuStandingsEndCallback);
}

void UpdateDonketu(u32 mapObjectList, MissionRunMapObject *donketu) {
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
            if (IsNotRisingWithBelowZeroBit(donketu) != FALSE) {
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
                        if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_KINOKO_BOOST) != 0 &&
                            kart->mBoostTimer > 0) {
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

void InitDonketuSoundSource(MissionRunMapObject *donketu) {
    donketu->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) donketu->mUnk_000.mSound, 0xc, &donketu->mUnk_000.mPos);
    donketu->mUnk_000.mFarDistanceSquared = gSoundFalloffs[12].mFarDistanceSquared;
}

void InitBossDonketu(MapObjectList *list) {
    MissionRunMapObject *donketu;
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
    MissionRunMapObject *donketu;
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

void DrawDonketu(void *mapObjectList, MissionRunMapObject *donketu) {
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
