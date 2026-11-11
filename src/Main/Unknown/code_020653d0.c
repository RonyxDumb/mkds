#include "Main/Unknown/code_020653d0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206b000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02082000.h"
#include "Main/Unknown/code_0210a000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"

static inline void SetSideSignedDirection(Kart *entryKart, Kart *sourceKart, Vec3 *direction) {
    Vec3 offset;
    Vec3 crossProduct;

    *direction = sourceKart->mUnk_120;
    VEC_Subtract(&entryKart->mPos, &sourceKart->mPos, &offset);
    VEC_CrossProduct(&sourceKart->mUnk_138, &offset, &crossProduct);
    if (VEC_DotProduct(&crossProduct, &sourceKart->mUnk_12c) < 0) {
        direction->x = -direction->x;
        direction->y = -direction->y;
        direction->z = -direction->z;
    }
}

void ApplyParticipantKartRecord(Kart *kart, ParticipantKartRecord *record, s32 stepCount) {
    Vec3 newPos;
    Vec3 moveStep;
    Vec3 headingAxis;
    Vec3 axisOffset;
    Vec3 collisionOffset;
    Vec3 prevPos;
    MtxFx33 turnMatrix;
    MtxFx33 fixedAngleMatrix;
    u32 hitAttributes;
    u32 recordFlags;
    ParticipantKartRecordState *state;
    s32 wasOnGround;
    u16 index;
    u16 value;
    ParticipantKartRecordState *stateAgain;
    s32 scale;
    s32 startedState;
    Kart *otherKart;
    Kart *sourceKart;
    s32 flag;
    u8 byte;
    Vec3 *axis;

    recordFlags = record->mFlags;
    wasOnGround = (kart->mMotionFlags & KART_MOTION_ON_GROUND) != 0;
    state = kart->mParticipantRecordData;
    newPos.x = record->mPosX << 10;
    newPos.y = record->mPosY << 10;
    newPos.z = record->mPosZ << 10;
    kart->mForwardSpeed = record->mForwardSpeed << 2;
    kart->mHeadingAngle = record->mHeadingAngle;
    state->mRecordBits = record->mUnk_14;
    state->mRecordKartBits = record->mUnk_10;
    byte = state->mRecordKartBits >> 24;
    state->mPushDirection.x = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->mRecordKartBits >> 16;
    state->mPushDirection.y = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->mRecordKartBits >> 8;
    state->mPushDirection.z = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    state->mRecordKartBits = state->mRecordKartBits & 0xff;
    state->mTargetTurnAngle = record->mTurnAngle;
    kart->mTurnAngle = record->mTurnAngle;
    if (wasOnGround) {
        kart->mMotionFlags |= KART_MOTION_ON_GROUND;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_ON_GROUND;
    }
    if (kart->mParticipantRecordData->mRecordKartBits & 2) {
        kart->mMotionFlags |= KART_MOTION_HOPPING;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_HOPPING;
    }
    if (kart->mParticipantRecordData->mRecordKartBits & 8) {
        kart->mMotionFlags |= KART_MOTION_DRIFTING;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_DRIFTING;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x10000) != 0) != ((recordFlags & 0x10000) != 0)) {
        value = kart->mHeadingAngle;
        ResetKartAndSetPos(kart, &newPos, 0, 0);
        kart->mHeadingAngle = value;
        headingAxis = data_02165530;
        QuaternionFromAxisAngle(&headingAxis, kart->mHeadingAngle, &kart->mUnk_e0_m);
        kart->mUnk_110_q = kart->mUnk_e0_m;
        if (kart->mEntryFlags & KART_ENTRY_WIFI_PEER) {
            stateAgain = kart->mParticipantRecordData;
            stateAgain->mSmoothedPos = kart->mPos;
            stateAgain->mSmoothedDrawPos = stateAgain->mSmoothedPos;
            stateAgain->mSmoothedRotation = kart->mUnk_110_q;
            stateAgain->mPosOffset = gKartVec3Zero;
            stateAgain->mPosOffsetIndex = 0;
        }
    }
    if ((s64) (kart->mPos.x - newPos.x) * (kart->mPos.x - newPos.x) +
            (s64) (kart->mPos.y - newPos.y) * (kart->mPos.y - newPos.y) +
            (s64) (kart->mPos.z - newPos.z) * (kart->mPos.z - newPos.z) >=
        0x15f90000000LL) {
        switch (state->mPosOffsetIndex) {
            case 0:
                axis = &kart->mUnk_138;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, -0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, -0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, -0x7000);
                break;
            case 1:
                axis = &kart->mUnk_138;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, 0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, 0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, 0x7000);
                break;
            case 2:
                axis = &kart->mUnk_120;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, 0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, 0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, 0x7000);
                break;
            case 3:
            default:
                axis = &kart->mUnk_120;
                axisOffset.x = MUL_FIXED12_NO_ROUND(axis->x, -0x7000);
                axisOffset.y = MUL_FIXED12_NO_ROUND(axis->y, -0x7000);
                axisOffset.z = MUL_FIXED12_NO_ROUND(axis->z, -0x7000);
                break;
        }
        state->mPosOffset = axisOffset;
        newPos.y += 0x14000;
        VEC_Add(&newPos, &axisOffset, &newPos);
        kart->mPos = newPos;
        kart->mPrevPos = kart->mPos;
        kart->mDrawMatrixPos = kart->mPrevPos;
        state->mSmoothedPos = kart->mDrawMatrixPos;
        kart->mUnk_25c = gKartVec3Zero;
        ComputeKartPointAlongUp(&kart->mCollisionCenter, &newPos, 0x400, kart);
        SetKartPrevCollisionCenter(kart);
        state->mPosOffsetIndex++;
        if (state->mPosOffsetIndex > 3) {
            state->mPosOffsetIndex = 0;
        }
    } else if (!(kart->mDriveFlags & KART_DRIVE_HIT_STATE)) {
        prevPos = kart->mPrevPos;
        VEC_Add(&newPos, &state->mPosOffset, &newPos);
        FindCollisionSlotsAroundPos(&newPos, stepCount * 0xd000 + kart->mRadius, 0x8000);
        for (index = 0; index < stepCount; index++) {
            if (kart->mDriveFlags & KART_DRIVE_SINKING) {
                kart->mPos.y -= 0x19a;
            } else {
                if (index < 3 && index < stepCount / 2) {
                    AdvanceKartTurnHeading(kart, ApplyKartTurnInput(kart, 0));
                }
                QuaternionFromAxisAngle(&gKartVec3UnitY, kart->mHeadingAngle, &kart->mUnk_e0_m);
                QuaternionMultiply(&kart->mUnk_f0_q, &kart->mUnk_e0_m, &kart->mUnk_110_q);
                Matrix4x3FromQuaternion(&kart->mUnk_120_m, &kart->mUnk_110_q);
                stateAgain = kart->mParticipantRecordData;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    MUL_FIXED12_ROUNDED(stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle, 0x333);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
                MTX_RotAxis33(&turnMatrix, &kart->mUnk_12c, FX_SinIdx((u16) kart->mTurnAngle),
                              FX_CosIdx((u16) kart->mTurnAngle));
                if (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
                    MTX_RotAxis33(&fixedAngleMatrix, &kart->mUnk_120, SIN_OF_ANGLE(0x5d0), COS_OF_ANGLE(0x5d0));
                    MTX_Concat33(&fixedAngleMatrix, &turnMatrix, &turnMatrix);
                }
                MTX_MultVec33(&kart->mForward, &turnMatrix, &kart->mTurnedForward);
                scale = kart->mForwardSpeed;
                moveStep.x = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.x, scale);
                moveStep.y = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.y, scale);
                moveStep.z = MUL_FIXED12_NO_ROUND(kart->mTurnedForward.z, scale);
                VEC_Add(&newPos, &moveStep, &newPos);
                VEC_Add(&newPos, &kart->mHitVelocity, &newPos);
                VEC_Add(&kart->mVelocity, &kart->mHitVelocity, &kart->mVelocity);
                if (kart->mParticipantRecordData->mRecordBits & 1) {
                    kart->mVerticalSpeed = 0;
                }
                scale = (kart->mMotionFlags & KART_MOTION_ON_GROUND) ? 0xee1 : 0xfae;
                kart->mHitVelocity.x = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.x, scale);
                kart->mHitVelocity.y = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.y, scale);
                kart->mHitVelocity.z = MUL_FIXED12_NO_ROUND(kart->mHitVelocity.z, scale);
                if ((s64) kart->mHitVelocity.x * kart->mHitVelocity.x +
                        (s64) kart->mHitVelocity.y * kart->mHitVelocity.y +
                        (s64) kart->mHitVelocity.z * kart->mHitVelocity.z >=
                    0xa429) {
                    kart->mMotionFlags |= KART_MOTION_HIT_VELOCITY;
                } else {
                    kart->mHitVelocity = gKartVec3Zero;
                    kart->mMotionFlags &= ~KART_MOTION_HIT_VELOCITY;
                }
            }
            if (CollideSphereWithCourse(&newPos, &prevPos, 0, kart->mRadius, 1, kart->mCollisionSlot, &collisionOffset,
                                        0, 0, &hitAttributes, 0, 0, 0, 0)) {
                VEC_Add(&newPos, &collisionOffset, &newPos);
            }
            prevPos = newPos;
        }
    }
    if (kart->mDriveFlags & KART_DRIVE_SINKING) {
        goto l0;
    }
    kart->mPos.x = newPos.x;
    kart->mPos.z = newPos.z;
    startedState = 0;
    if (((kart->mParticipantRecordData->mAppliedFlags & 1) != 0) != ((recordFlags & 1) != 0) &&
        (kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        stateAgain = ((volatile Kart *) kart)->mParticipantRecordData;
        stateAgain->mHopSpeed = 0x1405;
        stateAgain->mHopHeight = 0;
        kart->mVerticalSpeed += 0x21a2;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x20000) != 0) != ((recordFlags & 0x20000) != 0)) {
        StartKartState6(kart);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 4) != 0) != ((recordFlags & 4) != 0)) {
        StartKartState2(kart, 1, 0);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 8) != 0) != ((recordFlags & 8) != 0)) {
        StartKartState2(kart, 2, 0);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x10) != 0) != ((recordFlags & 0x10) != 0)) {
        StartKartState3(kart);
        startedState = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x2000) != 0) != ((recordFlags & 0x2000) != 0)) {
        StartKartStar(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x4000) != 0) != ((recordFlags & 0x4000) != 0)) {
        index = 0;
        StartFadeFog();
        StartEffectsAtOtherKarts(kart->mIndex);
        flag = kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL;
        if (flag) {
            if (flag) {
                kart->mParticipantRecordData->mEventToggleFlags ^= 0x4000;
            }
        } else {
            for (; index < (u32) gRaceSetup->mKartCount; index++) {
                if (index != kart->mIndex) {
                    StartKartThunderShrink(GetKart(index));
                }
            }
        }
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x8000) != 0) != ((recordFlags & 0x8000) != 0)) {
        StartKartThunderShrink(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x100000) != 0) != ((recordFlags & 0x100000) != 0)) {
        StartKartKiller(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x200000) != 0) != ((recordFlags & 0x200000) != 0)) {
        kart->mItemEffectData.mKillerEnding = TRUE;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x4000000) != 0) != ((recordFlags & 0x4000000) != 0)) {
        StartKartTeresa(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x40) != 0) != ((recordFlags & 0x40) != 0)) {
        if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto l1;
            }
        } else if (kart->mState == KART_STATE_PUSH_DOUBLE_FLIP) {
            goto l1;
        }
        StartSound(&kart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(kart, &state->mPushDirection, 0);
    l1:
        if (((kart->mParticipantRecordData->mAppliedFlags & 0x80) != 0) != ((recordFlags & 0x80) != 0)) {
            StartSound(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    } else if (((kart->mParticipantRecordData->mAppliedFlags & 0x20) != 0) != ((recordFlags & 0x20) != 0)) {
        if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto l2;
            }
        } else if (kart->mState == KART_STATE_PUSH_FLIP) {
            goto l2;
        }
        StartKartState4(kart, &state->mPushDirection, 0);
    l2:
        if (((kart->mParticipantRecordData->mAppliedFlags & 0x80) != 0) != ((recordFlags & 0x80) != 0)) {
            StartSound(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x40000) != 0) != ((recordFlags & 0x40000) != 0)) {
        StartKartAheadBoost(kart);
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x80000) != 0) != ((recordFlags & 0x80000) != 0)) {
        kart->mItemEffectData.mGessoFrames = 0;
        kart->mEffectFlags |= KART_EFFECT_GESSO;
        kart->mEffectFlags &= ~KART_EFFECT_COURSE_COLORED;
        if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
            ResetKartModelsCourseColors(kart);
        }
        StartKartModelColorBlend(kart->mKartModelsEntry, 0, 0x1084, 0);
        if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
            StartKartCharacterAnimationOnce(kart, 1, 0);
            SetCharacterFaceFrameIndex(kart->mKartModelsEntry, 1);
        }
        if (!(kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT))) {
            StartKartSeqArcSound(kart, kart->mSoundIndex, 0);
        }
        StartOrthoQuadsGesoSumi(kart->mIndex, 0);
    }
    if (startedState) {
        otherKart = GetKart((u16) ((recordFlags & 0x60000000) >> 29));
        if (otherKart != kart) {
            otherKart->mEffectFlags |= KART_EFFECT_START_SOUND_PENDING;
        }
    }
    otherKart = GetKart(gRaceSetup->mEntryIndex);
    flag = 0;
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x400000) != 0) != ((recordFlags & 0x400000) != 0) &&
        otherKart->mIndex == 0) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l3;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l3;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(otherKart, &direction, 0);
    l3:
        flag = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x800000) != 0) != ((recordFlags & 0x800000) != 0) &&
        otherKart->mIndex == 1) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l4;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l4;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(otherKart, &direction, 0);
    l4:
        flag = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x1000000) != 0) != ((recordFlags & 0x1000000) != 0) &&
        otherKart->mIndex == 2) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l5;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l5;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(otherKart, &direction, 0);
    l5:
        flag = 1;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x2000000) != 0) != ((recordFlags & 0x2000000) != 0) &&
        otherKart->mIndex == 3) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l6;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l6;
        }
        SetSideSignedDirection(otherKart, sourceKart, &direction);
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(otherKart, &direction, 0);
    l6:
        flag = 1;
    }
    if (flag) {
        goto l0;
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x200) != 0) != ((recordFlags & 0x200) != 0) &&
        otherKart->mIndex == 0) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l7;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l7;
        }
        VEC_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(otherKart, &direction, 0);
    l7:
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x400) != 0) != ((recordFlags & 0x400) != 0) &&
        otherKart->mIndex == 1) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l8;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l8;
        }
        VEC_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(otherKart, &direction, 0);
    l8:
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x800) != 0) != ((recordFlags & 0x800) != 0) &&
        otherKart->mIndex == 2) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l9;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l9;
        }
        VEC_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(otherKart, &direction, 0);
    l9:
    }
    if (((kart->mParticipantRecordData->mAppliedFlags & 0x1000) != 0) != ((recordFlags & 0x1000) != 0) &&
        otherKart->mIndex == 3) {
        Vec3 direction;

        value = kart->mIndex;
        direction = gKartVec3UnitX;
        sourceKart = GetKart(value);
        if (otherKart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
            if ((otherKart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || otherKart->mState == KART_STATE_PUSH_FLIP) {
                goto l10;
            }
        } else if (otherKart->mState == KART_STATE_PUSH_FLIP) {
            goto l10;
        }
        VEC_Subtract(&otherKart->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if (LENGTH_SQUARED(direction) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&otherKart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(otherKart, &direction, 0);
    l10:
    }
l0:
    kart->mParticipantRecordData->mAppliedFlags = recordFlags;
}
