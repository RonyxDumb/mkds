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
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_02077bc0.h"

static inline void func_020653d0_inline(Kart *entryKart, Kart *sourceKart, Vec3 *direction) {
    Vec3 offset;
    Vec3 crossProduct;

    *direction = *(Vec3 *) &sourceKart->field120;
    VEC_Subtract(&entryKart->mPos, &sourceKart->mPos, &offset);
    VEC_CrossProduct(&sourceKart->field138, &offset, &crossProduct);
    if (VEC_DotProduct(&crossProduct, &sourceKart->field12C) < 0) {
        direction->x = -direction->x;
        direction->y = -direction->y;
        direction->z = -direction->z;
    }
}

void func_020653d0(Kart *kart, ParticipantKartRecord *record, s32 stepCount) {
    Vec3 newPos;
    Vec3 moveStep;
    Vec3 headingAxis;
    Vec3 axisOffset;
    Vec3 collisionOffset;
    Vec3 prevPos;
    MtxFx33 turnMatrix;
    MtxFx33 fixedAngleMatrix;
    u32 w;
    u32 recordFlags;
    ParticipantKartRecordState *state;
    s32 wasOnGround;
    u16 i;
    u16 s;
    ParticipantKartRecordState *stateAgain;
    s32 k;
    s32 startedState;
    Kart *o;
    Kart *sourceKart;
    s32 e;
    u8 byte;
    Vec3 *axis;

    recordFlags = record->mFlags;
    wasOnGround = (kart->field44 & KART_44_ON_GROUND) != 0;
    state = kart->field514;
    newPos.x = record->mPosX << 10;
    newPos.y = record->mPosY << 10;
    newPos.z = record->mPosZ << 10;
    kart->mForwardSpeed = record->mForwardSpeed << 2;
    kart->mHeadingAngle = record->mHeadingAngle;
    state->field44 = record->field14;
    state->field48 = record->field10;
    byte = state->field48 >> 24;
    state->mPushDirection.x = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->field48 >> 16;
    state->mPushDirection.y = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->field48 >> 8;
    state->mPushDirection.z = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    state->field48 = state->field48 & 0xff;
    state->mTargetTurnAngle = record->mTurnAngle;
    kart->mTurnAngle = record->mTurnAngle;
    if (wasOnGround) {
        kart->field44 |= KART_44_ON_GROUND;
    } else {
        kart->field44 &= ~KART_44_ON_GROUND;
    }
    if (kart->field514->field48 & 2) {
        kart->field44 |= 2;
    } else {
        kart->field44 &= ~2;
    }
    if (kart->field514->field48 & 8) {
        kart->field44 |= KART_44_DRIFTING;
    } else {
        kart->field44 &= ~KART_44_DRIFTING;
    }
    if (((kart->field514->mAppliedFlags & 0x10000) != 0) != ((recordFlags & 0x10000) != 0)) {
        s = kart->mHeadingAngle;
        driver_2072B94(kart, &newPos, 0, 0);
        kart->mHeadingAngle = s;
        headingAxis = data_02165530;
        qrtn_fromAxisAngle(&headingAxis, kart->mHeadingAngle, (Vec4 *) &kart->fieldE0);
        *(Vec4 *) &kart->field108.z = *(Vec4 *) &kart->fieldE0;
        if (kart->field7C & 0x400) {
            stateAgain = kart->field514;
            stateAgain->field0 = kart->mPos;
            stateAgain->field10 = stateAgain->field0;
            stateAgain->field4C = *(Vec4 *) &kart->field108.z;
            stateAgain->fieldA8 = driverCore_sZeroVec;
            stateAgain->fieldB4 = 0;
        }
    }
    if ((s64) (kart->mPos.x - newPos.x) * (kart->mPos.x - newPos.x) +
            (s64) (kart->mPos.y - newPos.y) * (kart->mPos.y - newPos.y) +
            (s64) (kart->mPos.z - newPos.z) * (kart->mPos.z - newPos.z) >=
        0x15f90000000LL) {
        switch (state->fieldB4) {
            case 0:
                axis = &kart->field138;
                axisOffset.x = ((s64) axis->x * -0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * -0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * -0x7000) >> 12;
                break;
            case 1:
                axis = &kart->field138;
                axisOffset.x = ((s64) axis->x * 0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * 0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * 0x7000) >> 12;
                break;
            case 2:
                axis = &kart->field120;
                axisOffset.x = ((s64) axis->x * 0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * 0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * 0x7000) >> 12;
                break;
            case 3:
            default:
                axis = &kart->field120;
                axisOffset.x = ((s64) axis->x * -0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * -0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * -0x7000) >> 12;
                break;
        }
        state->fieldA8 = axisOffset;
        newPos.y += 0x14000;
        VEC_Add(&newPos, &axisOffset, &newPos);
        kart->mPos = newPos;
        kart->mPrevPos = kart->mPos;
        kart->mDrawMatrixPos = kart->mPrevPos;
        state->field0 = kart->mDrawMatrixPos;
        *(Vec3 *) &kart->field25C = driverCore_sZeroVec;
        ComputeKartPointAlongUp(&kart->mCollisionCenter, &newPos, 0x400, kart);
        SetKartPrevCollisionCenter(kart);
        state->fieldB4++;
        if (state->fieldB4 > 3) {
            state->fieldB4 = 0;
        }
    } else if (!(kart->field48 & 0x20000)) {
        prevPos = kart->mPrevPos;
        VEC_Add(&newPos, &state->fieldA8, &newPos);
        col_queryBySphere(&newPos, stepCount * 0xd000 + kart->mRadius, 0x8000);
        for (i = 0; i < stepCount; i++) {
            if (kart->field48 & 0x40) {
                kart->mPos.y -= 0x19a;
            } else {
                if (i < 3 && i < stepCount / 2) {
                    driver_updateYRot(kart, driver_handleSteering(kart, 0));
                }
                qrtn_fromAxisAngle(&driverCore_sUpVec, kart->mHeadingAngle, (Vec4 *) &kart->fieldE0);
                qrtn_mult((Vec4 *) &kart->fieldF0, (Vec4 *) &kart->fieldE0, (Vec4 *) &kart->field108.z);
                qrtn_toMtx43(&kart->field120, (Vec4 *) &kart->field108.z);
                stateAgain = kart->field514;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    (s32) (((s64) (stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle) * 0x333 + 0x800) >> 12);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
                MTX_RotAxis33((MtxFx43 *) &turnMatrix, &kart->field12C,
                              FX_SinCosTable_[((u16) kart->mTurnAngle >> 4) * 2],
                              FX_SinCosTable_[((u16) kart->mTurnAngle >> 4) * 2 + 1]);
                if (kart->field48 & 1) {
                    MTX_RotAxis33((MtxFx43 *) &fixedAngleMatrix, &kart->field120, FX_SinCosTable_[0xba],
                                  FX_SinCosTable_[0xbb]);
                    MTX_Concat33(fixedAngleMatrix.field0, turnMatrix.field0, turnMatrix.field0);
                }
                MTX_MultVec33(&kart->mForward, turnMatrix.field0, &kart->mTurnedForward);
                k = kart->mForwardSpeed;
                moveStep.x = ((s64) kart->mTurnedForward.x * k) >> 12;
                moveStep.y = ((s64) kart->mTurnedForward.y * k) >> 12;
                moveStep.z = ((s64) kart->mTurnedForward.z * k) >> 12;
                VEC_Add(&newPos, &moveStep, &newPos);
                VEC_Add(&newPos, &kart->mHitVelocity, &newPos);
                VEC_Add(&kart->mVelocity, &kart->mHitVelocity, &kart->mVelocity);
                if (kart->field514->field44 & 1) {
                    kart->mVerticalSpeed = 0;
                }
                k = (kart->field44 & KART_44_ON_GROUND) ? 0xee1 : 0xfae;
                kart->mHitVelocity.x = ((s64) kart->mHitVelocity.x * k) >> 12;
                kart->mHitVelocity.y = ((s64) kart->mHitVelocity.y * k) >> 12;
                kart->mHitVelocity.z = ((s64) kart->mHitVelocity.z * k) >> 12;
                if ((s64) kart->mHitVelocity.x * kart->mHitVelocity.x +
                        (s64) kart->mHitVelocity.y * kart->mHitVelocity.y +
                        (s64) kart->mHitVelocity.z * kart->mHitVelocity.z >=
                    0xa429) {
                    kart->field44 |= 0x2000;
                } else {
                    kart->mHitVelocity = driverCore_sZeroVec;
                    kart->field44 &= ~0x2000;
                }
            }
            if (col_collide(&newPos, (u32 *) &prevPos, 0, kart->mRadius, 1, kart->mCollisionSlot, &collisionOffset, 0,
                              0, &w, 0, 0, 0, 0)) {
                VEC_Add(&newPos, &collisionOffset, &newPos);
            }
            prevPos = newPos;
        }
    }
    if (kart->field48 & 0x40) {
        goto l0;
    }
    kart->mPos.x = newPos.x;
    kart->mPos.z = newPos.z;
    startedState = 0;
    if (((kart->field514->mAppliedFlags & 1) != 0) != ((recordFlags & 1) != 0) && (kart->field44 & KART_44_ON_GROUND)) {
        stateAgain = ((volatile Kart *) kart)->field514;
        stateAgain->field64 = 0x1405;
        stateAgain->field60 = 0;
        kart->mVerticalSpeed += 0x21a2;
    }
    if (((kart->field514->mAppliedFlags & 0x20000) != 0) != ((recordFlags & 0x20000) != 0)) {
        driver_throwUp(kart);
        startedState = 1;
    }
    if (((kart->field514->mAppliedFlags & 4) != 0) != ((recordFlags & 4) != 0)) {
        driver_startSpinOut(kart, 1, 0);
        startedState = 1;
    }
    if (((kart->field514->mAppliedFlags & 8) != 0) != ((recordFlags & 8) != 0)) {
        driver_startSpinOut(kart, 2, 0);
        startedState = 1;
    }
    if (((kart->field514->mAppliedFlags & 0x10) != 0) != ((recordFlags & 0x10) != 0)) {
        driver_startForwardFlip(kart);
        startedState = 1;
    }
    if (((kart->field514->mAppliedFlags & 0x2000) != 0) != ((recordFlags & 0x2000) != 0)) {
        driver_startStarInvincibility(kart);
    }
    if (((kart->field514->mAppliedFlags & 0x4000) != 0) != ((recordFlags & 0x4000) != 0)) {
        i = 0;
        race_startDarkening();
        StartEffectsAtOtherKarts(kart->mIndex);
        e = kart->field7C & 0x200;
        if (e) {
            if (e) {
                kart->field514->field2C ^= 0x4000;
            }
        } else {
            for (; i < (u32) gRaceMultiConfig->mKartCount; i++) {
                if (i != kart->mIndex) {
                    driver_startThunderShrinkEffect(driver_getById(i));
                }
            }
        }
    }
    if (((kart->field514->mAppliedFlags & 0x8000) != 0) != ((recordFlags & 0x8000) != 0)) {
        driver_startThunderShrinkEffect(kart);
    }
    if (((kart->field514->mAppliedFlags & 0x100000) != 0) != ((recordFlags & 0x100000) != 0)) {
        driver_startKillerMode(kart);
    }
    if (((kart->field514->mAppliedFlags & 0x200000) != 0) != ((recordFlags & 0x200000) != 0)) {
        kart->field538.mKillerEnding = TRUE;
    }
    if (((kart->field514->mAppliedFlags & 0x4000000) != 0) != ((recordFlags & 0x4000000) != 0)) {
        driver_startTeresaEffect(kart);
    }
    if (((kart->field514->mAppliedFlags & 0x40) != 0) != ((recordFlags & 0x40) != 0)) {
        if (kart->field7C & 0x200) {
            if ((kart->field4C & 0x10000040) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto l1;
            }
        } else if (kart->mState == KART_STATE_PUSH_DOUBLE_FLIP) {
            goto l1;
        }
        sfx_21090C4(&kart->mSoundSource, 0xe8, 0x7f, 0);
        driver_startDoubleBackwardFlip(kart, &state->mPushDirection, 0);
    l1:
        if (((kart->field514->mAppliedFlags & 0x80) != 0) != ((recordFlags & 0x80) != 0)) {
            sfx_21090C4(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    } else if (((kart->field514->mAppliedFlags & 0x20) != 0) != ((recordFlags & 0x20) != 0)) {
        if (kart->field7C & 0x200) {
            if ((kart->field4C & 0x10000040) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto l2;
            }
        } else if (kart->mState == KART_STATE_PUSH_FLIP) {
            goto l2;
        }
        driver_startBackwardFlip(kart, &state->mPushDirection, 0);
    l2:
        if (((kart->field514->mAppliedFlags & 0x80) != 0) != ((recordFlags & 0x80) != 0)) {
            sfx_21090C4(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    }
    if (((kart->field514->mAppliedFlags & 0x40000) != 0) != ((recordFlags & 0x40000) != 0)) {
        driver_startSlipstream(kart);
    }
    if (((kart->field514->mAppliedFlags & 0x80000) != 0) != ((recordFlags & 0x80000) != 0)) {
        kart->field538.field1C = 0;
        kart->field4C |= 0x8000000;
        kart->field4C &= ~0x20000;
        if (kart->field4C & 0x2000) {
            driver_disableSlipStreamToonMode(kart);
        }
        chkrt_setTargetColors(kart->mKartModelsEntry, 0, 0x1084, 0);
        if (kart->field7C & KART_7C_MODELS_ENTRY_008_SET) {
            driver_setAnimation(kart, 1, 0);
            driver_setFaceExpression(kart->mKartModelsEntry, 1);
        }
        if (!(kart->field48 & 0x840)) {
            sfx_emitDriverVoice(kart, kart->mSoundIndex, 0);
        }
        cspl_emitGessoSplash(kart->mIndex, 0);
    }
    if (startedState) {
        o = driver_getById((u16) ((recordFlags & 0x60000000) >> 29));
        if (o != kart) {
            o->field4C |= 0x1000;
        }
    }
    o = driver_getById(gRaceMultiConfig->mEntryIndex);
    e = 0;
    if (((kart->field514->mAppliedFlags & 0x400000) != 0) != ((recordFlags & 0x400000) != 0) && o->mIndex == 0) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l3;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l3;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startDoubleBackwardFlip(o, &direction, 0);
    l3:
        e = 1;
    }
    if (((kart->field514->mAppliedFlags & 0x800000) != 0) != ((recordFlags & 0x800000) != 0) && o->mIndex == 1) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l4;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l4;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startDoubleBackwardFlip(o, &direction, 0);
    l4:
        e = 1;
    }
    if (((kart->field514->mAppliedFlags & 0x1000000) != 0) != ((recordFlags & 0x1000000) != 0) && o->mIndex == 2) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l5;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l5;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startDoubleBackwardFlip(o, &direction, 0);
    l5:
        e = 1;
    }
    if (((kart->field514->mAppliedFlags & 0x2000000) != 0) != ((recordFlags & 0x2000000) != 0) && o->mIndex == 3) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l6;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l6;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startDoubleBackwardFlip(o, &direction, 0);
    l6:
        e = 1;
    }
    if (e) {
        goto l0;
    }
    if (((kart->field514->mAppliedFlags & 0x200) != 0) != ((recordFlags & 0x200) != 0) && o->mIndex == 0) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l7;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l7;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            vec_normalize(&direction, &direction);
        }
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startBackwardFlip(o, &direction, 0);
    l7:
    }
    if (((kart->field514->mAppliedFlags & 0x400) != 0) != ((recordFlags & 0x400) != 0) && o->mIndex == 1) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l8;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l8;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            vec_normalize(&direction, &direction);
        }
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startBackwardFlip(o, &direction, 0);
    l8:
    }
    if (((kart->field514->mAppliedFlags & 0x800) != 0) != ((recordFlags & 0x800) != 0) && o->mIndex == 2) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l9;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l9;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            vec_normalize(&direction, &direction);
        }
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startBackwardFlip(o, &direction, 0);
    l9:
    }
    if (((kart->field514->mAppliedFlags & 0x1000) != 0) != ((recordFlags & 0x1000) != 0) && o->mIndex == 3) {
        Vec3 direction;

        s = kart->mIndex;
        direction = driverCore_sRightVec;
        sourceKart = driver_getById(s);
        if (o->field7C & 0x200) {
            if ((o->field4C & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l10;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l10;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            vec_normalize(&direction, &direction);
        }
        sfx_21090C4(&o->mSoundSource, 0xe8, 0x7f, 0);
        driver_startBackwardFlip(o, &direction, 0);
    l10:
    }
l0:
    kart->field514->mAppliedFlags = recordFlags;
}
