#include "ITCM/kart_velocity.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/kart_speed.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/kart_gravity.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/collision_slots.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/MapObjects/data_0206a000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/data_0206e000.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/code_02080cd0.h"
#include "Main/Kart/kart_effects.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"

void AdvanceKartByVelocity(Kart *kart) {
    s32 easeFactor;
    s32 scaledForwardSpeed;
    s32 velocityScale;
    Vec3 velocity;
    Vec3 forward;
    MtxFx33 turnMatrix;
    MtxFx33 boostMatrix;
    Vec3 tangentForward;
    Vec3 easeDelta;
    KartItemEffectState *itemEffectState;
    s32 dot;
    s32 hitVelocityDecay;
    u32 kartBits;

    velocityScale = kart->mVelocityScaleFactor;
    if (kart->mEffectFlags & KART_EFFECT_GESSO) {
        AdvanceKartGesso(kart);
    }
    kartBits = kart->mEffectFlags;
    if (kartBits & KART_EFFECT_KILLER) {
        AdvanceKartKiller(kart);
    } else {
        if (kartBits & KART_EFFECT_THUNDER_SHRINK) {
            AdvanceKartThunderShrink(kart);
        }
        if (kart->mEffectFlags & KART_EFFECT_SCALE_TABLE) {
            AdvanceKartScaleTableEffect(kart);
        }
        if (kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) {
            AdvanceKartTeresa(kart);
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        itemEffectState = &kart->mItemEffectData;
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            AddSoundRequest(gSoundRequestQueues, GetKartCameraDistanceSquared(kart->mIndex), RequestKartSound, kart,
                            0xa3);
        }
        itemEffectState->mAheadBoostFrames++;
        if (itemEffectState->mAheadBoostFrames > KART_AHEAD_BOOST_MAX_FRAMES &&
            (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST)) {
            kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
            kart->mAheadSpeedLimitFactor = TO_FIXED12(1);
            if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
                ResetKartModelsCourseColors(kart);
            }
            StopKartNearRankEffect(kart);
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_STAR) {
        itemEffectState = &kart->mItemEffectData;
        AdvanceKartStarEffects(kart->mIndex);
        if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) &&
            kart->mKartModelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
            SetKartCharacterAnimation(kart, 2, 1);
        }
        itemEffectState->mStarFrames++;
        if (itemEffectState->mStarFrames > KART_STAR_MAX_FRAMES) {
            kart->mEffectFlags &= ~KART_EFFECT_STAR;
            StopKartStarModels(kart);
            kart->mItemEffect = KART_ITEM_EFFECT_NONE;
            StopKartStarEffects(kart->mIndex);
            SetKartCharacterAnimation(kart, 0, 1);
            if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                StopKartStarSeq();
            }
            if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
                SetKartModelsGrayColors(kart);
            }
        }
    }
    if ((kart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT) && AdvanceKartRespawnWait(kart, &velocityScale) != 0) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_REMOVED) {
        return;
    }
    gKartStateFunctions[kart->mState](kart);
    ScaleKartForwardSpeed(kart);
    if (kart->mDriveFlags & KART_DRIVE_SINKING) {
        kart->mSinkFrames++;
        if (kart->mSinkFrames > KART_SINK_MAX_FRAMES) {
            kart->mDriveFlags &= ~(KART_DRIVE_SINKING | KART_DRIVE_OBJECTS_SKIP);
            if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                SetJgFollowKartCountdown();
            }
        } else {
            kart->mPos.y -= 0x19a;
        }
    } else {
        ApplyKartGravity(kart);
    }
    if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        GetKartForward(kart, &forward);
        if (!(kart->mDriveFlags & (KART_DRIVE_ACCEL_HELD | KART_DRIVE_BRAKE_HELD)) && kart->mGroundNormal.y > 0 &&
            (forward.y > 0 ? forward.y : -forward.y) > 0xcd && kart->mSpeedLimitHitFactor <= 0) {
            kart->mForwardSpeed += MUL_FIXED12_NO_ROUND(-forward.y, 0x19a);
        }
    }
    if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) || (kart->mEffectFlags & KART_EFFECT_KILLER)) {
        MTX_RotAxis33(&turnMatrix, &kart->mGroundNormal, FX_SinIdx((u16) kart->mTurnAngle),
                      FX_CosIdx((u16) kart->mTurnAngle));
        if (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
            MTX_RotAxis33(&boostMatrix, &kart->mRotationRow0, SIN_OF_ANGLE(0x5d0), COS_OF_ANGLE(0x5d0));
            MTX_Concat33(&boostMatrix, &turnMatrix, &turnMatrix);
        }
        MTX_MultVec33(&kart->mForward, &turnMatrix, &kart->mTurnedForward);
        dot = VEC_DotProduct(&kart->mGroundNormal, &kart->mTurnedForward);
        tangentForward.x = kart->mTurnedForward.x - MUL_FIXED12_NO_ROUND(kart->mGroundNormal.x, dot);
        tangentForward.y = kart->mTurnedForward.y - MUL_FIXED12_NO_ROUND(kart->mGroundNormal.y, dot);
        tangentForward.z = kart->mTurnedForward.z - MUL_FIXED12_NO_ROUND(kart->mGroundNormal.z, dot);
        kart->mSpeedLimitGroundFactor = VEC_Mag(&tangentForward);
    } else {
        dot = Vec3DotUnrounded(&kart->mForward, &kart->mGroundNormal);
        kart->mTurnedForward = kart->mForward;
        if (kart->mAirTiltAngleOffset > 0) {
            kart->mSpeedLimitGroundFactor = TO_FIXED12(1);
        } else if (dot < 0) {
            kart->mSpeedLimitGroundFactor = TO_FIXED12(1) - dot;
        } else {
            kart->mSpeedLimitGroundFactor = TO_FIXED12(1);
        }
    }
    scaledForwardSpeed = LimitKartForwardSpeedAndGetScaled(kart);
    ReduceKartSpeedByTurnRatio(&scaledForwardSpeed, kart);
    if ((kart->mMotionFlags & (KART_MOTION_ON_GROUND | KART_MOTION_COURSE_CONTACT)) ||
        (kart->mEffectFlags & KART_EFFECT_KILLER)) {
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
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND) && kart->mAirborneFrames > KART_AIRBORNE_LONG_FRAMES &&
        kart->mVelocity.y < -0x6000) {
        kart->mVelocity.y = -0x6000;
    }
    VEC_Add(&kart->mVelocity, &kart->mPrevPrevHitVelocity, &kart->mVelocity);
    VEC_Add(&kart->mVelocity, &kart->mPointMotion, &kart->mVelocity);
    AdvanceKartHop(kart);
    ScaleKartVelocityAndSetCappedLengthAndDirection(kart, velocityScale);
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        SetKartForwardSpeedRatio(Vec3DotUnrounded(&kart->mVelocity, &kart->mTurnedForward));
        if ((kart->mMotionFlags & KART_MOTION_START_DONE) && kart->mRevLevel != 0) {
            kart->mRevLevel = MUL_FIXED12_NO_ROUND(kart->mRevLevel, 0xfae);
            if (kart->mRevLevel < KART_REV_LEVEL_MIN) {
                kart->mRevLevel = 0;
            }
        }
    }
    if (!(kart->mEntryFlags & KART_ENTRY_REMOVED)) {
        VEC_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
        kart->mSpeedLimitHitFactor = TO_FIXED12(1);
    }
    hitVelocityDecay = (kart->mMotionFlags & KART_MOTION_ON_GROUND) ? 0xee1 : 0xfae;
    kart->mHitVelocity.x = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.x, hitVelocityDecay);
    kart->mHitVelocity.y = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.y, hitVelocityDecay);
    kart->mHitVelocity.z = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.z, hitVelocityDecay);
    if (SQUARE_SUM3(kart->mHitVelocity.x, kart->mHitVelocity.y, kart->mHitVelocity.z) >=
        0xa429) {
        kart->mMotionFlags |= KART_MOTION_HIT_VELOCITY;
    } else {
        kart->mHitVelocity = gKartVec3Zero;
        kart->mMotionFlags &= ~KART_MOTION_HIT_VELOCITY;
    }
    FindCollisionSlotsOverlappingSlot(kart->mCollisionSlot, 0xe800);
    CollideKartWithMapObjects(kart);
    if (kart->mEntryFlags & KART_ENTRY_SKIP_KART_HITS) {
        return;
    }
    ComputeKartPointAlongUp(&kart->mPointAlongUp, kart->mCollisionPosSource, kart->mPhysicalParam->mPointAlongUpExtra,
                            kart);
    ApplyItemObjectHitToKart(kart);
    CollideKartWithKarts(kart);
    UpdateKartAheadEffect(kart);
}
