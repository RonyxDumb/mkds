#include "Main/Unknown/code_020649ec.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffb130.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_020641b8.h"
#include "Main/Unknown/code_020646c0.h"
#include "Main/Unknown/code_020649e8.h"
#include "Main/Unknown/code_02066000.h"
#include "Main/Unknown/code_02068000.h"
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
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02010c84.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_0208c188.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_02062ed8.h"

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
    Matrix4x3FromQuaternion(&kart->mUnk_120_m, &kart->mUnk_110_q);
    AdvanceParticipantKartRecords(kart);
    if (kart->mForwardSpeed > 0x3000) {
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
    if ((kart->mParticipantRecordData->mRecordBits & 1) != 0) {
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
    if ((kart->mParticipantRecordData->mRecordBits & 1) != 0) {
        ComputeKartPointAlongUp(&probePos, &recordState->mSmoothedPos, 0x400, kart);
        upAxis = &kart->mUnk_12c;
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
    QuaternionBlend(&recordState->mSmoothedRotation, &kart->mUnk_110_q, &recordState->mSmoothedRotation, 0x333);
}

void AdvancePeerKartOrientation(Kart *kart, Vec3 *groundNormal) {
    ParticipantKartRecordState *recordState;
    Vec4 hopTiltQuaternion;
    s32 headingDifference;
    s32 hopHeightTilt;

    recordState = kart->mParticipantRecordData;
    kart->mVelocityScaleFactor = 0x1000;
    if (kart->mAirborneFrames > 5 && (kart->mParticipantRecordData->mRecordBits & 1) == 0) {
        kart->mQuaternionBlendFactor = 0xf6;
        ComputeKartAirTiltQuaternion(kart, &kart->mUnk_100_q);
    } else {
        AdvanceKartQuaternionFromVector(kart, groundNormal);
    }
    QuaternionBlend(&kart->mUnk_f0_q, &kart->mUnk_100_q, &kart->mUnk_f0_q, kart->mQuaternionBlendFactor);
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
    QuaternionFromAxisAngle(&gKartVec3UnitY, (u16) (kart->mHeadingAngle + kart->mHeadingAngleOffset), &kart->mUnk_e0_m);
    QuaternionMultiply(&kart->mUnk_f0_q, &kart->mUnk_e0_m, &kart->mUnk_110_q);
    if ((kart->mMotionFlags & KART_MOTION_HOPPING) != 0) {
        if (kart->mHopSpeed > 0) {
            hopHeightTilt = (u16) MUL_FIXED12_NO_ROUND(kart->mHopHeight, 0x1f4);
            kart->mHopTiltAngle = 0x9c4 - hopHeightTilt;
            if (kart->mHopTiltAngle > 0x6a4) {
                kart->mHopTiltAngle = 0x352;
            }
        } else {
            kart->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&gKartVec3UnitX, (u16) -kart->mHopTiltAngle, &hopTiltQuaternion);
        QuaternionMultiply(&kart->mUnk_110_q, &hopTiltQuaternion, &kart->mUnk_110_q);
    } else {
        kart->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&kart->mUnk_110_q, &kart->mUnk_110_q);
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
    kart->mRotationSource = &kart->mUnk_110_q;
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
            kart->mRotationSource = &kart->mUnk_110_q;
            kart->mCollisionPosSource = &kart->mPos;
        }
    } else {
        kart->mPosSource = &kart->mPos;
        kart->mRotationSource = &kart->mUnk_110_q;
        kart->mCollisionPosSource = &kart->mPos;
    }
    kart->mPosSourceCopy = kart->mPosSource;
    PlaceKartAtStartPlacement(kart, 0);
    if (GetRaceUseChainCameras() != 0 && gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        kart->mSlotFunctions[3] = KartChainCameraNop;
        kart->mSlotFunctions[4] = KartChainCameraNop;
        kart->mDrawMatrixPos = kart->mUnk_174;
        kart->mUnk_174.x = kart->mUnk_174.x >> 4;
        kart->mUnk_174.y = kart->mUnk_174.y >> 4;
        kart->mUnk_174.z = kart->mUnk_174.z >> 4;
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
