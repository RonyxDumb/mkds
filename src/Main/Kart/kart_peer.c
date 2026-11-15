#include "Main/Kart/kart_peer.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/kart_with_course.h"
#include "ITCM/kart_speed.h"
#include "ITCM/kart_velocity.h"
#include "ITCM/kart_motion.h"
#include "ITCM/collision_slots.h"
#include "ITCM/sphere_collision.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/kart_surface_effects.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_draw_state.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_start_placement.h"
#include "Main/Kart/kart_sound_distance.h"
#include "Main/Kart/kart_motion_slot.h"
#include "Main/Kart/kart_chain_camera_nop.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/Kart/kart_models_entry.h"
#include "Main/Item/item_in_use.h"
#include "model_draw_state.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "fixed_vector_math.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Kart/kart_draw.h"
#include "Main/Kart/course_models.h"

void AdvancePeerKartMotion(Kart *kart) {
    ParticipantKartRecordState *recordState;
    s32 tableIndex;
    u32 kartBits;

    kartBits = kart->mEntryFlags;
    if ((kartBits & (KART_ENTRY_REMOVED | KART_ENTRY_SCALING_IN)) != 0) {
        if ((kartBits & KART_ENTRY_REMOVED) != 0) {
            AdvanceKartRemovalShrink(kart);
            return;
        }
        kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
        tableIndex = kart->mFramesSinceRemovalOrReset;
        if (tableIndex >= 0x19) {
            kart->mEntryFlags = kart->mEntryFlags & ~KART_ENTRY_SCALING_IN;
            return;
        }
        kart->mScaleFactor.x = gKartScaleFactorXTable[tableIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[tableIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[tableIndex];
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        return;
    }
    recordState = kart->mParticipantRecordData;
    Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mCombinedQuaternion);
    AdvanceParticipantKartRecords(kart);
    if (kart->mForwardSpeed > KART_PEER_OFFSET_CLEAR_SPEED) {
        recordState->mPosOffset = gKartVec3Zero;
    }
    ResetKartTurnAndRadius(kart);
    UpdateKartSpeedLimitGoal(kart);
    UpdateKartSpeedLimit(kart);
    UpdateKartForwardAndLengthRatio(kart);
    AdvanceKartInputAndTurn(kart);
    AdvanceKartBoosts(kart);
    recordState = kart->mParticipantRecordData;
    recordState->mHopSpeed = recordState->mHopSpeed + kart->mGravity;
    recordState->mHopHeight = recordState->mHopHeight + recordState->mHopSpeed;
    if (recordState->mHopHeight < 0) {
        recordState->mHopHeight = 0;
        recordState->mHopSpeed = 0;
    }
    if (IsRaceStarted() == 1) {
        kart->mAdvanceOffsetCycle = AdvanceKartOffsetCycleIndex;
    }
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_ON_BOOST_SURFACE) != 0) {
        kart->mVerticalSpeed = 0;
    }
    AdvanceKartByVelocity(kart);
}

// The peer version of AdvanceKartCollision; it also moves the shown position and rotation toward the simulated kart.
void AdvancePeerKartCollision(Kart *kart) {
    ParticipantKartRecordState *recordState;
    s32 blendFactor;
    Vec3 groundNormal;
    Vec3 groundedPos;
    Vec3 pushOut;
    Vec3 downOffset;
    Vec3 probePos;
    Vec3 posStep;
    u32 hitAttributes;
    Vec3 *upAxis;

    recordState = kart->mParticipantRecordData;
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED) != 0) {
        return;
    }
    if ((kart->mMotionFlags & KART_MOTION_NEAR_KART) != 0) {
        kart->mMotionFlags = kart->mMotionFlags | KART_MOTION_NEAR_KART_HELD;
    } else {
        kart->mMotionFlags = kart->mMotionFlags & ~KART_MOTION_NEAR_KART_HELD;
    }
    ComputeKartPointAlongUp(&kart->mCollisionCenter, &kart->mPos, 0x400, kart);
    CollideKartWithCourse(kart, &groundNormal);
    AdvancePeerKartOrientation(kart, &groundNormal);
    kart->mGroundNormal = groundNormal;
    kart->mCollisionStepFrames = kart->mCollisionStepFrames + 1;
    UpdateKartSoundWrapper(kart);
    AdvanceKartCollisionTimer(kart);
    if ((kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) != 0) {
        ComputeKartSidePoints(kart);
    }
    if ((kart->mEffectFlags & KART_EFFECT_MODEL_SCALE_ANIM) != 0) {
        AdvanceKartModelScaleAnimation(kart);
    }
    kart->mAdvanceOffsetCycle(kart);
    groundedPos = kart->mPos;
    groundedPos.y = groundedPos.y - recordState->mHopHeight;
    blendFactor = recordState->mPosBlendFactor;
    VEC_Subtract(&groundedPos, &recordState->mSmoothedPos, &posStep);
    posStep.x = MUL_FIXED12_NO_ROUND(posStep.x, blendFactor);
    posStep.y = MUL_FIXED12_NO_ROUND(posStep.y, blendFactor);
    posStep.z = MUL_FIXED12_NO_ROUND(posStep.z, blendFactor);
    VEC_Add(&recordState->mSmoothedPos, &posStep, &recordState->mSmoothedPos);
    if ((kart->mParticipantRecordData->mRecordBits & KART_DRIVE_ON_BOOST_SURFACE) != 0) {
        ComputeKartPointAlongUp(&probePos, &recordState->mSmoothedPos, 0x400, kart);
        upAxis = &kart->mRotationRow1;
        downOffset.x = MUL_FIXED12_NO_ROUND(upAxis->x, -0x7000);
        downOffset.y = MUL_FIXED12_NO_ROUND(upAxis->y, -0x7000);
        downOffset.z = MUL_FIXED12_NO_ROUND(upAxis->z, -0x7000);
        VEC_Add(&probePos, &downOffset, &probePos);
        if (CollideSphereWithCourse(&probePos, NULL, 0, kart->mRadius, 1, kart->mCollisionSlot, &pushOut, NULL, NULL,
                                    &hitAttributes, NULL, NULL, NULL, NULL) != 0) {
            VEC_Add(&pushOut, &downOffset, &pushOut);
            VEC_Add(&recordState->mSmoothedPos, &pushOut, &recordState->mSmoothedPos);
        }
    }
    recordState->mSmoothedDrawPos = recordState->mSmoothedPos;
    recordState->mSmoothedDrawPos.y = recordState->mSmoothedDrawPos.y + recordState->mHopHeight;
    QuaternionBlend(&recordState->mSmoothedRotation, &kart->mCombinedQuaternion, &recordState->mSmoothedRotation,
                    0x333);
}

void AdvancePeerKartOrientation(Kart *kart, Vec3 *groundNormal) {
    ParticipantKartRecordState *recordState;
    Vec4 hopTiltQuaternion;
    s32 headingDifference;
    s32 hopHeightTilt;

    recordState = kart->mParticipantRecordData;
    kart->mVelocityScaleFactor = TO_FIXED12(1);
    if (kart->mAirborneFrames > KART_PEER_AIR_TILT_AIRBORNE_FRAMES &&
        (kart->mParticipantRecordData->mRecordBits & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        kart->mQuaternionBlendFactor = FIXED12_RATIO(6, 100);
        ComputeKartAirTiltQuaternion(kart, &kart->mAirTiltQuaternion);
    } else {
        AdvanceKartQuaternionFromVector(kart, groundNormal);
    }
    QuaternionBlend(&kart->mTiltQuaternion, &kart->mAirTiltQuaternion, &kart->mTiltQuaternion,
                    kart->mQuaternionBlendFactor);
    headingDifference = kart->mHeadingAngle - recordState->mSmoothedHeadingAngle;
    if ((headingDifference > 0 ? headingDifference : -headingDifference) > 0x7fff) {
        if (headingDifference > 0) {
            headingDifference = -(0xffff - headingDifference);
        } else {
            headingDifference = headingDifference + 0xffff;
        }
    }
    recordState->mSmoothedHeadingAngle =
        recordState->mSmoothedHeadingAngle + MUL_FIXED12_NO_ROUND(headingDifference, 0x19a);
    QuaternionFromAxisAngle(&gKartVec3UnitY, (u16) (kart->mHeadingAngle + kart->mHeadingAngleOffset),
                            &kart->mHeadingQuaternion);
    QuaternionMultiply(&kart->mTiltQuaternion, &kart->mHeadingQuaternion, &kart->mCombinedQuaternion);
    if ((kart->mMotionFlags & KART_MOTION_HOPPING) != 0) {
        if (kart->mHopSpeed > 0) {
            hopHeightTilt = (u16) MUL_FIXED12_NO_ROUND(kart->mHopHeight, 0x1f4);
            kart->mHopTiltAngle = KART_HOP_TILT_START - hopHeightTilt;
            if (kart->mHopTiltAngle > KART_HOP_TILT_LIMIT) {
                kart->mHopTiltAngle = KART_HOP_TILT_RESET;
            }
        } else {
            kart->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&gKartVec3UnitX, -kart->mHopTiltAngle, &hopTiltQuaternion);
        QuaternionMultiply(&kart->mCombinedQuaternion, &hopTiltQuaternion, &kart->mCombinedQuaternion);
    } else {
        kart->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&kart->mCombinedQuaternion, &kart->mCombinedQuaternion);
}

void SetKartPrevCollisionCenterFromPrevPos(Kart *kart) {
    ComputeKartPointAlongUp(&kart->mPrevCollisionCenter, &kart->mPrevPos, 0x400, kart);
}

void InitKart(Kart *kart, void (**slotFunctions)(Kart *)) {
    u32 isPeer;
    u16 slotIndex;
    ModelAnimation *characterAnimation;

    GetHeap(GetCurrentHeapCall());
    isPeer = gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_PEER;
    kart->mKartModelsEntry = GetKartModelsEntry(kart->mIndex);
    InitCourseColorBlend(&kart->mKartModelsEntry->mCourseColorBlend, 1);
    if (gRaceSetup->mMode == MODE_WIFI) {
        for (slotIndex = 0; slotIndex < 9; slotIndex++) {
            if (slotIndex == 3) {
                kart->mSlotFunctions[slotIndex] = isPeer != 0 ? AdvancePeerKartMotionSlot : AdvanceLocalKartMotionSlot;
            } else if (slotIndex == 4) {
                kart->mSlotFunctions[slotIndex] =
                    isPeer != 0 ? AdvancePeerKartCollisionSlot : AdvanceLocalKartCollisionSlot;
            } else if (slotIndex == 5) {
                kart->mSlotFunctions[slotIndex] =
                    isPeer != 0 ? SetKartPrevCollisionCenterFromPrevPos : SetKartPrevCollisionCenter;
            } else {
                kart->mSlotFunctions[slotIndex] = *slotFunctions;
            }
            slotFunctions++;
        }
    } else {
        for (slotIndex = 0; slotIndex < 9; slotIndex++) {
            if (slotIndex == 3) {
                kart->mSlotFunctions[slotIndex] = AdvanceKartMotionSlot;
            } else if (slotIndex == 4) {
                kart->mSlotFunctions[slotIndex] = AdvanceKartCollisionSlot;
            } else if (slotIndex == 5) {
                kart->mSlotFunctions[slotIndex] = SetKartPrevCollisionCenter;
            } else {
                kart->mSlotFunctions[slotIndex] = *slotFunctions;
            }
            slotFunctions++;
        }
    }
    kart->mParticipantRecordData = NULL;
    if (kart->mSlotFunctions[1] != 0) {
        kart->mSlotFunctions[1](kart);
    }
    kart->mPosSource = &kart->mPos;
    kart->mRotationSource = &kart->mCombinedQuaternion;
    kart->mCollisionPosSource = &kart->mPos;
    if (kart->mSlotFunctions[0] != 0) {
        kart->mSlotFunctions[0](kart);
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_REPLAY || (kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        kart->mSlotFunctions[2] = SetKartSoundDistanceSquaredAndChange;
    } else {
        kart->mSlotFunctions[2] = SetKartSoundDistanceSquared;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        if (isPeer != 0) {
            kart->mPosSource = &kart->mParticipantRecordData->mSmoothedDrawPos;
            kart->mRotationSource = &kart->mParticipantRecordData->mSmoothedRotation;
            kart->mCollisionPosSource = &kart->mParticipantRecordData->mSmoothedPos;
        } else {
            kart->mPosSource = &kart->mPos;
            kart->mRotationSource = &kart->mCombinedQuaternion;
            kart->mCollisionPosSource = &kart->mPos;
        }
    } else {
        kart->mPosSource = &kart->mPos;
        kart->mRotationSource = &kart->mCombinedQuaternion;
        kart->mCollisionPosSource = &kart->mPos;
    }
    kart->mPosSourceCopy = kart->mPosSource;
    PlaceKartAtStartPlacement(kart, 0);
    if (GetRaceUseChainCameras() != 0 && gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        kart->mSlotFunctions[3] = KartChainCameraNop;
        kart->mSlotFunctions[4] = KartChainCameraNop;
        kart->mDrawMatrixPos = kart->mDrawBaseRow3;
        kart->mDrawBaseRow3.x = kart->mDrawBaseRow3.x >> 4;
        kart->mDrawBaseRow3.y = kart->mDrawBaseRow3.y >> 4;
        kart->mDrawBaseRow3.z = kart->mDrawBaseRow3.z >> 4;
        if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
            AdvanceKartCharacterAnimation(kart);
            characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
            characterAnimation->mAnmObjs[characterAnimation->mCurrentIndex]->mFrame =
                characterAnimation->mHead.mFrameIndex;
        }
    }
    ResetParticipantKartRecordPos(kart);
    if ((kart->mEntryFlags & KART_ENTRY_CPU) != 0) {
        CallKartAiSetup(kart->mAi, kart->mIndex);
    }
}
