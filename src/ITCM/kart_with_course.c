#include "ITCM/kart_with_course.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/sphere_collision.h"
#include "Main/Kart/kart_contact.h"
#include "Main/Course/course_color_blend.h"
#include "Main/MapObjects/rock.h"
#include "Main/Course/course_sound_slot.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_pool.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/System/backup_net_camera_work.h"
#include "fixed_vector_math.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_resources.h"

void CollideKartWithCourse(Kart *kart, Vec3 *groundNormal) {
    u16 headingDelta;
    u32 collisionFlags;
    u32 hitObjects;
    Vec3 pushOut;
    Vec3 secondNormal;
    Vec3 lowestOffset;
    Vec3 pointMotion;
    Vec3 normal;
    Vec3 pushVector;
    Vec3 landingPushVector;
    s32 bit100000WasSet;
    s32 bit200000WasSet;
    u32 collisionMask;
    s32 lowestOffsetLength;
    s32 pushStrength;
    s32 dot;
    s32 value;
    BOOL rotationExceeded;

    secondNormal = gKartVec3UnitY;
    bit100000WasSet = (kart->mMotionFlags & KART_MOTION_ATTRACTOR_PULL) ? 1 : 0;
    bit200000WasSet = (kart->mDriveFlags & KART_DRIVE_COURSE_SOUND_PLAYED) ? 1 : 0;
    *groundNormal = kart->mGroundNormal;
    if (StartKartRespawnWaitIfBelowZero(kart) != FALSE) {
        return;
    }
    if (CollideSphereWithCourse(&kart->mCollisionCenter, &kart->mPrevCollisionCenter, &kart->mTurnedForward,
                                kart->mRadius, 1, kart->mCollisionSlot, &pushOut, &normal, &secondNormal,
                                &collisionFlags, &lowestOffset, &pointMotion, &headingDelta, &hitObjects) != 0) {
        collisionMask = collisionFlags & 0x1e34ef;
        VEC_Add(&kart->mPos, &pushOut, &kart->mPos);
        AdvanceCourseColorBlend(&kart->mKartModelsEntry->mCourseColorBlend, (collisionFlags & 0x3c000000) >> 26,
                                kart->mVelocityLength);
        SetKartCourseHitAttributeBit(kart, collisionFlags);
        AdvanceKartPointMotion(kart, collisionFlags, &pointMotion, headingDelta);
        if (collisionFlags & 0x200300) {
            ApplyKartCourseContact(kart, collisionFlags, &secondNormal);
            if (collisionMask != 0) {
                dot = VEC_DotProduct(&normal, &kart->mHitVelocity);
                kart->mHitVelocity.x -= MUL_FIXED12_NO_ROUND(normal.x, dot);
                kart->mHitVelocity.y -= MUL_FIXED12_NO_ROUND(normal.y, dot);
                kart->mHitVelocity.z -= MUL_FIXED12_NO_ROUND(normal.z, dot);
                dot = VEC_DotProduct(&normal, &kart->mPrevHitVelocity);
                kart->mPrevHitVelocity.x -= MUL_FIXED12_NO_ROUND(normal.x, dot);
                kart->mPrevHitVelocity.y -= MUL_FIXED12_NO_ROUND(normal.y, dot);
                kart->mPrevHitVelocity.z -= MUL_FIXED12_NO_ROUND(normal.z, dot);
            }
            kart->mCourseHitTimer = KART_COURSE_HIT_TIMER_FRAMES;
            if (((s32(*)(Kart *, u32, Vec3 *)) gLowestOffsetFarCheck)(kart, collisionFlags, &lowestOffset) != 0 ||
                (kart->mMotionFlags & KART_MOTION_COURSE_PUSH_STRONG)) {
                lowestOffsetLength = 0;
                if (LENGTH_SQUARED(lowestOffset) >= 0x10) {
                    lowestOffsetLength = Vec3NormalizeAndGetLengthUnchecked(&lowestOffset, &pushVector);
                }
                if (lowestOffsetLength != 0) {
                    pushStrength = 0x802;
                    if (kart->mMotionFlags & KART_MOTION_COURSE_PUSH_STRONG) {
                        pushStrength *= 3;
                    }
                    pushVector.x = -pushVector.x;
                    pushVector.y = -pushVector.y;
                    pushVector.z = -pushVector.z;
                    pushVector.x = MUL_FIXED12_NO_ROUND(pushVector.x, pushStrength);
                    pushVector.y = MUL_FIXED12_NO_ROUND(pushVector.y, pushStrength);
                    pushVector.z = MUL_FIXED12_NO_ROUND(pushVector.z, pushStrength);
                    kart->mCollisionPushVelocity = pushVector;
                    kart->mCollisionPushVelocity.y = -0x19a;
                }
                kart->mMotionFlags |= KART_MOTION_COURSE_PUSH;
            } else {
                kart->mCollisionPushVelocity = gKartVec3Zero;
                kart->mMotionFlags &= ~KART_MOTION_COURSE_PUSH;
            }
        } else {
            kart->mMotionFlags &= ~KART_MOTION_COURSE_CONTACT;
            if (kart->mCourseHitTimer > 0) {
                kart->mCourseHitTimer--;
            }
        }
        if (collisionFlags & 0x8c10) {
            if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && (collisionFlags & 0x10)) {
                if (bit200000WasSet == 0) {
                    ApplyCourseSoundTableEntry((u16) ((PickCollisionHitValue(0x10) & 0xe0) >> 5));
                }
                kart->mDriveFlags |= KART_DRIVE_COURSE_SOUND_PLAYED;
            }
            if (collisionFlags & 0x8c00) {
                if (!(collisionFlags & 0x400) || !(kart->mMotionFlags & KART_MOTION_COURSE_CONTACT) ||
                    (collisionFlags & 0x800)) {
                    StartKartRespawnWait(kart, collisionFlags);
                }
            }
        }
        if (collisionFlags & 0x400000) {
            SetKartItemLinkFromHitValue(&(gKartItems)[kart->mIndex],
                                        (u16) ((PickCollisionHitValue(0x400000) & 0xe0) >> 5));
            if (kart->mEffectFlags & KART_EFFECT_KILLER) {
                ResetKartKillerCursorTo(&kart->mItemEffectData.mKillerCursor,
                                        (RacePointLink *) (gKartItems)[kart->mIndex].mItemLink.mLink);
            }
            if ((kart->mEntryFlags & KART_ENTRY_CPU) && (collisionFlags & 0x400000) &&
                kart->mState != KART_STATE_LAUNCH_DOUBLE_FLIP) {
                CallKartAiRequestLink(kart->mAi);
            }
        }
        if (collisionMask != 0) {
            *groundNormal = normal;
            if (LENGTH_SQUARED(*groundNormal) >= 0x10) {
                kart->mDriveFlags &= ~KART_DRIVE_JUMP_PAD;
                kart->mAirTiltAngleOffset = 0;
                RefreshKartSurface(kart);
                if ((collisionFlags & 0x20000) && !(kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) &&
                    !(kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED)) {
                    kart->mEffectFlags |= KART_EFFECT_ATTRACTOR;
                    kart->mAttractorIndex = (PickCollisionHitValue(0x20000) & 0xe0) >> 5;
                } else {
                    kart->mEffectFlags &= ~KART_EFFECT_ATTRACTOR;
                }
                AdvanceKartQuaternionBlendFactor(kart, groundNormal);
                if (kart->mVerticalSpeed < 0) {
                    kart->mVerticalSpeed = (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) ? -0x2b9 : -0xd9d;
                }
                ApplyKartLanding(kart, groundNormal);
                if (collisionFlags & 0x80000000) {
                    kart->mPointMotion.y = 0;
                }
                kart->mMotionFlags |= KART_MOTION_ON_GROUND;
                if (kart->mForwardSpeed != 0 || TryHoldKartStill(kart, collisionFlags, &hitObjects) == FALSE) {
                    StopKartStillHold(kart);
                    if (((s32(*)(Kart *, u32, Vec3 *)) gLowestOffsetFarCheck)(kart, collisionFlags, &lowestOffset) !=
                        0) {
                        lowestOffsetLength = 0;
                        if (LENGTH_SQUARED(lowestOffset) >= 0x10) {
                            lowestOffsetLength = Vec3NormalizeAndGetLengthUnchecked(&lowestOffset, &landingPushVector);
                        }
                        if (lowestOffsetLength != 0) {
                            pushStrength = 0x802;
                            if (kart->mMotionFlags & KART_MOTION_COURSE_PUSH_STRONG) {
                                pushStrength *= 3;
                            }
                            landingPushVector.x = -landingPushVector.x;
                            landingPushVector.y = -landingPushVector.y;
                            landingPushVector.z = -landingPushVector.z;
                            landingPushVector.x = MUL_FIXED12_NO_ROUND(landingPushVector.x, pushStrength);
                            landingPushVector.y = MUL_FIXED12_NO_ROUND(landingPushVector.y, pushStrength);
                            landingPushVector.z = MUL_FIXED12_NO_ROUND(landingPushVector.z, pushStrength);
                            kart->mCollisionPushVelocity = landingPushVector;
                            kart->mCollisionPushVelocity.y = -0x19a;
                        }
                        kart->mMotionFlags |= KART_MOTION_COURSE_PUSH;
                    } else {
                        kart->mCollisionPushVelocity = gKartVec3Zero;
                        kart->mMotionFlags &= ~KART_MOTION_COURSE_PUSH;
                    }
                }
            }
        } else {
            ClearKartGroundContact(kart, KART_MOTION_ON_GROUND);
        }
    } else {
        ClearKartGroundContact(kart, KART_MOTION_ON_GROUND | KART_MOTION_COURSE_CONTACT);
    }
    if (kart->mLandingTimer > 0) {
        kart->mLandingTimer--;
    }
    if (IsWaterHeightUsed()) {
        ApplyKartWaterDepth(kart);
    }
    if ((kart->mEffectFlags & KART_EFFECT_ATTRACTOR) && kart->mState == KART_STATE_NORMAL) {
        ApplyKartAttractorPull(kart, groundNormal, bit100000WasSet);
    }
    kart->mAttractorPullSpeed = MUL_FIXED12_NO_ROUND(kart->mAttractorPullSpeed, 0xf33);
    value = kart->mAttractorPullSpeed;
    if ((value > 0 ? value : -value) < 0x29) {
        kart->mAttractorPullSpeed = 0;
    }
    UpdateKartAirborne(kart);
    if (!(kart->mEffectFlags & KART_EFFECT_Y_SPIN)) {
        return;
    }
    kart->mYRotationAngleSum += kart->mYRotationAnglePerFrame;
    rotationExceeded = FALSE;
    value = kart->mYRotationAngleSum;
    if ((value > 0 ? value : -value) > kart->mYRotationCount * 0xffff) {
        kart->mYRotationAngle = 0;
        rotationExceeded = TRUE;
    } else {
        kart->mYRotationAngle += kart->mYRotationAnglePerFrame;
    }
    kart->mEffectFlags |= KART_EFFECT_GROUND_SOUND_STEP;
    if (rotationExceeded == FALSE) {
        return;
    }
    kart->mYRotationAngle = 0;
    kart->mEffectFlags &= ~KART_EFFECT_Y_SPIN;
}
