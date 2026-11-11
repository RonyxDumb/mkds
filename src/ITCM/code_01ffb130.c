#include "ITCM/code_01ffb130.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffb930.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206dfd0.h"
#include "Main/Unknown/code_0206e000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206e874.h"
#include "Main/Unknown/code_020681f0.h"

void AdvanceKartByVelocity(Kart *kart) {
    s32 easeFactor;
    s32 scaledForwardSpeed;
    s32 velocityScale;
    Vec3 velocity;
    Vec3 forward;
    MtxFx33 turnMatrix;
    MtxFx33 m2;
    Vec3 v3;
    Vec3 easeDelta;
    KartItemEffectState *itemEffectState;
    s32 d;
    s32 hitVelocityDecay;
    u32 w;

    velocityScale = kart->mVelocityScaleFactor;
    if (kart->mUnk_4c & 0x8000000) {
        AdvanceKartGesso(kart);
    }
    w = kart->mUnk_4c;
    if (w & 0x10000000) {
        AdvanceKartKiller(kart);
    } else {
        if (w & KART_4C_THUNDER_SHRINK) {
            AdvanceKartThunderShrink(kart);
        }
        if (kart->mUnk_4c & 0x10000) {
            AdvanceKartScaleTableEffect(kart);
        }
        if (kart->mUnk_7c & 0x402000) {
            AdvanceKartTeresa(kart);
        }
    }
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        itemEffectState = &kart->mItemEffectData;
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            AddSoundRequest(gSoundRequestQueues, GetKartCameraDistanceSquared(kart->mIndex), RequestKartSound, kart,
                            0xa3);
        }
        itemEffectState->mAheadBoostFrames++;
        if (itemEffectState->mAheadBoostFrames > 0xb4 && (kart->mUnk_4c & KART_4C_AHEAD_BOOST)) {
            kart->mUnk_4c &= ~KART_4C_AHEAD_BOOST;
            kart->mAheadSpeedLimitFactor = 0x1000;
            if (!(kart->mUnk_4c & 0x8000000)) {
                ResetKartModelsCourseColors(kart);
            }
            StopKartNearRankEffect(kart);
        }
    }
    if (kart->mUnk_4c & 0x40) {
        itemEffectState = &kart->mItemEffectData;
        AdvanceKartStarEffects(kart->mIndex);
        if ((kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) &&
            kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
            SetKartCharacterAnimation(kart, 2, 1);
        }
        itemEffectState->mStarFrames++;
        if (itemEffectState->mStarFrames > 0x1c2) {
            kart->mUnk_4c &= ~0x40;
            StopKartStarModels(kart);
            kart->mItemEffect = 0;
            StopKartStarEffects(kart->mIndex);
            SetKartCharacterAnimation(kart, 0, 1);
            if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                StopKartStarSeq();
            }
            if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
                SetKartModelsGrayColors(kart);
            }
        }
    }
    if ((kart->mUnk_48 & KART_48_RESPAWN_WAIT) && AdvanceKartRespawnWait(kart, &velocityScale) != 0) {
        return;
    }
    if (kart->mUnk_7c & KART_7C_REMOVED) {
        return;
    }
    gKartStateFunctions[kart->mState](kart);
    ScaleKartForwardSpeed(kart);
    if (kart->mUnk_48 & KART_48_SINKING) {
        kart->mSinkFrames++;
        if (kart->mSinkFrames > 0x41) {
            kart->mUnk_48 &= ~(KART_48_SINKING | KART_48_OBJECTS_SKIP);
            if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                SetJgState4Countdown();
            }
        } else {
            kart->mPos.y -= 0x19a;
        }
    } else {
        ApplyKartGravity(kart);
    }
    if (kart->mUnk_44 & KART_44_ON_GROUND) {
        GetKartForward(kart, &forward);
        if (!(kart->mUnk_48 & 6) && kart->mGroundNormal.y > 0 && (forward.y > 0 ? forward.y : -forward.y) > 0xcd &&
            kart->mSpeedLimitHitFactor <= 0) {
            kart->mForwardSpeed += MUL_FIXED12_NO_ROUND(-forward.y, 0x19a);
        }
    }
    if ((kart->mUnk_44 & KART_44_ON_GROUND) || (kart->mUnk_4c & 0x10000000)) {
        MTX_RotAxis33(&turnMatrix, &kart->mGroundNormal, FX_SinIdx((u16) kart->mTurnAngle),
                      FX_CosIdx((u16) kart->mTurnAngle));
        if (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE) {
            MTX_RotAxis33(&m2, &kart->mUnk_120, SIN_OF_ANGLE(0x5d0), COS_OF_ANGLE(0x5d0));
            MTX_Concat33(&m2, &turnMatrix, &turnMatrix);
        }
        MTX_MultVec33(&kart->mForward, &turnMatrix, &kart->mTurnedForward);
        d = VEC_DotProduct(&kart->mGroundNormal, &kart->mTurnedForward);
        v3.x = kart->mTurnedForward.x - MUL_FIXED12_NO_ROUND(kart->mGroundNormal.x, d);
        v3.y = kart->mTurnedForward.y - MUL_FIXED12_NO_ROUND(kart->mGroundNormal.y, d);
        v3.z = kart->mTurnedForward.z - MUL_FIXED12_NO_ROUND(kart->mGroundNormal.z, d);
        kart->mSpeedLimitGroundFactor = VEC_Mag(&v3);
    } else {
        d = Vec3DotUnrounded(&kart->mForward, &kart->mGroundNormal);
        kart->mTurnedForward = kart->mForward;
        if (kart->mAirTiltAngleOffset > 0) {
            kart->mSpeedLimitGroundFactor = 0x1000;
        } else if (d < 0) {
            kart->mSpeedLimitGroundFactor = 0x1000 - d;
        } else {
            kart->mSpeedLimitGroundFactor = 0x1000;
        }
    }
    scaledForwardSpeed = LimitKartForwardSpeedAndGetScaled(kart);
    ReduceKartSpeedByTurnRatio(&scaledForwardSpeed, kart);
    if ((kart->mUnk_44 & 0x90) || (kart->mUnk_4c & 0x10000000)) {
        easeFactor = kart->mTurnedForwardEaseFactor;
        VEC_Subtract(&kart->mTurnedForward, &kart->mEasedTurnedForward, &easeDelta);
        easeDelta.x = MUL_FIXED12_NO_ROUND(easeDelta.x, easeFactor);
        easeDelta.y = MUL_FIXED12_NO_ROUND(easeDelta.y, easeFactor);
        easeDelta.z = MUL_FIXED12_NO_ROUND(easeDelta.z, easeFactor);
        VEC_Add(&kart->mEasedTurnedForward, &easeDelta, &kart->mEasedTurnedForward);
        kart->mEasedTurnedForward.y = kart->mTurnedForward.y;
    }
    velocity.x = MUL_FIXED12_NO_ROUND(kart->mEasedTurnedForward.x, scaledForwardSpeed);
    velocity.y = MUL_FIXED12_NO_ROUND(kart->mEasedTurnedForward.y, scaledForwardSpeed);
    velocity.z = MUL_FIXED12_NO_ROUND(kart->mEasedTurnedForward.z, scaledForwardSpeed);
    if (scaledForwardSpeed >= 0) {
        kart->mSignedTurnedForward = kart->mTurnedForward;
    } else {
        kart->mSignedTurnedForward.x = -kart->mTurnedForward.x;
        kart->mSignedTurnedForward.y = -kart->mTurnedForward.y;
        kart->mSignedTurnedForward.z = -kart->mTurnedForward.z;
    }
    if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        velocity.y = 0;
    }
    kart->mVelocity = velocity;
    VEC_Add(&kart->mVelocity, &kart->mCollisionPushVelocity, &kart->mVelocity);
    kart->mVelocity.y += kart->mVerticalSpeed;
    VEC_MultAdd(kart->mAttractorPullSpeed, &kart->mAttractorPullDirection, &kart->mVelocity, &kart->mVelocity);
    if (!(kart->mUnk_44 & KART_44_ON_GROUND) && kart->mAirborneFrames > 5 && kart->mVelocity.y < -0x6000) {
        kart->mVelocity.y = -0x6000;
    }
    VEC_Add(&kart->mVelocity, &kart->mPrevPrevHitVelocity, &kart->mVelocity);
    VEC_Add(&kart->mVelocity, &kart->mPointMotion, &kart->mVelocity);
    AdvanceKartHop(kart);
    ScaleKartVelocityAndSetCappedLengthAndDirection(kart, velocityScale);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetKartForwardSpeedRatio(Vec3DotUnrounded(&kart->mVelocity, &kart->mTurnedForward));
        if ((kart->mUnk_44 & 0x1000000) && kart->mKeyALevel != 0) {
            kart->mKeyALevel = MUL_FIXED12_NO_ROUND(kart->mKeyALevel, 0xfae);
            if (kart->mKeyALevel < 0xcd) {
                kart->mKeyALevel = 0;
            }
        }
    }
    if (!(kart->mUnk_7c & KART_7C_REMOVED)) {
        VEC_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
        kart->mSpeedLimitHitFactor = 0x1000;
    }
    hitVelocityDecay = (kart->mUnk_44 & KART_44_ON_GROUND) ? 0xee1 : 0xfae;
    kart->mHitVelocity.x = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.x, hitVelocityDecay);
    kart->mHitVelocity.y = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.y, hitVelocityDecay);
    kart->mHitVelocity.z = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.z, hitVelocityDecay);
    if ((s64) kart->mHitVelocity.x * kart->mHitVelocity.x + (s64) kart->mHitVelocity.y * kart->mHitVelocity.y +
            (s64) kart->mHitVelocity.z * kart->mHitVelocity.z >=
        0xa429) {
        kart->mUnk_44 |= 0x2000;
    } else {
        kart->mHitVelocity = data_02154f94;
        kart->mUnk_44 &= ~0x2000;
    }
    FindCollisionSlotsOverlappingSlot(kart->mCollisionSlot, 0xe800);
    CollideKartWithMapObjects(kart);
    if (kart->mUnk_7c & 0x8000000) {
        return;
    }
    ComputeKartPointAlongUp(&kart->mPointAlongUp, kart->mCollisionPosSource, kart->mPhysicalParam->mUnk_04, kart);
    ApplyItemObjectHitToKart(kart);
    CollideKartWithKarts(kart);
    UpdateKartAheadEffect(kart);
}
