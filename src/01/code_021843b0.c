#include "01/code_021843b0.h"

#include "01/code_02184cc8.h"
#include "01/code_02188950.h"
#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188158.h"
#include "01/code_02184000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_021000d0.h"

void DonketuKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    s32 scale;

    if ((GetKart(kart->mIndex)->mUnk_48 & KART_48_BOOST) && kart->mBoostTimer > 0) {
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

    if ((GetKart(kart->mIndex)->mUnk_48 & KART_48_BOOST) && kart->mBoostTimer > 0) {
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
