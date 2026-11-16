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
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Kart/KartAiCallbacks.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_02062ed8.h"

void StructMQRacerEntry_SomeFn_90(Kart *kart) {
    ParticipantKartRecordState *b;
    s32 tableIndex;
    u32 f;

    f = kart->field7C;
    if ((f & 0xa0) != 0) {
        if ((f & 0x20) != 0) {
            StructMQRacerEntry_SomeFn_53(kart);
            return;
        }
        kart->field3C8 = kart->field3C8 + 1;
        tableIndex = kart->field3C8;
        if (tableIndex >= 0x19) {
            kart->field7C = kart->field7C & ~0x80;
            return;
        }
        kart->mScaleFactor.x = gKartScaleFactorXTable[tableIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[tableIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[tableIndex];
        kart->mScale.x = (s64) kart->mScaleBase.x * kart->mScaleFactor.x >> 12;
        kart->mScale.y = (s64) kart->mScaleBase.y * kart->mScaleFactor.y >> 12;
        kart->mScale.z = (s64) kart->mScaleBase.z * kart->mScaleFactor.z >> 12;
        kart->mScale.y = (s64) kart->mScaleYFactor * kart->mScale.y >> 12;
        return;
    }
    b = kart->field514;
    qrtn_toMtx43(&kart->field120, &kart->mUnk_110_q);
    StructMQRacerEntry_SomeFn_78(kart);
    if (kart->mForwardSpeed > 0x3000) {
        b->fieldA8 = driverCore_sZeroVec;
    }
    driver_1FFCA50(kart);
    UpdateKartSpeedLimitGoal(kart);
    driver_1FFBE04(kart);
    driver_1FFBD9C(kart);
    driver_1FFC6C0(kart);
    driver_handleSpecialBoosts(kart);
    b = kart->field514;
    b->field64 = b->field64 + kart->mGravity;
    b->field60 = b->field60 + b->field64;
    if (b->field60 < 0) {
        b->field60 = 0;
        b->field64 = 0;
    }
    if (race_getState() == 1) {
        kart->field230 = driver_1FFB0CC;
    }
    if ((kart->field514->field44 & 1) != 0) {
        kart->mVerticalSpeed = 0;
    }
    driver_handleRegularDriving(kart);
}

void sub_2064F50(Kart *kart) {
    ParticipantKartRecordState *b;
    s32 c;
    Vec3 groundNormal;
    Vec3 e;
    Vec3 i;
    Vec3 h;
    Vec3 g;
    Vec3 f;
    u32 j;
    Vec3 *k;

    b = kart->field514;
    if ((kart->field7C & 0x20) != 0) {
        return;
    }
    if ((kart->field44 & KART_44_NEAR_KART) != 0) {
        kart->field44 = kart->field44 | 0x80000;
    } else {
        kart->field44 = kart->field44 & ~0x80000;
    }
    ComputeKartPointAlongUp(&kart->mCollisionCenter, &kart->mPos, 0x400, kart);
    driver_handleCollision(kart, &groundNormal);
    StructMQRacerEntry_SomeFn_84(kart, &groundNormal);
    kart->mGroundNormal = groundNormal;
    kart->field4D0 = kart->field4D0 + 1;
    func_01ffc920(kart);
    AdvanceKartCollisionTimer(kart);
    if ((kart->field4C & KART_4C_NEAR_PLAYER_RANK) != 0) {
        rptc_updateDriverEffects(kart);
    }
    if ((kart->field4C & 8) != 0) {
        AdvanceKartModelScaleAnimation(kart);
    }
    kart->field230(kart);
    e = kart->mPos;
    e.y = e.y - b->field60;
    c = b->field24;
    VEC_Subtract(&e, &b->field0, &f);
    f.x = (s64) f.x * c >> 12;
    f.y = (s64) f.y * c >> 12;
    f.z = (s64) f.z * c >> 12;
    VEC_Add(&b->field0, &f, &b->field0);
    if ((kart->field514->field44 & 1) != 0) {
        ComputeKartPointAlongUp(&g, &b->field0, 0x400, kart);
        k = &kart->field12C;
        h.x = (s64) k->x * -0x7000 >> 12;
        h.y = (s64) k->y * -0x7000 >> 12;
        h.z = (s64) k->z * -0x7000 >> 12;
        VEC_Add(&g, &h, &g);
        if (col_collide(&g, NULL, 0, kart->mRadius, 1, kart->mCollisionSlot, &i, NULL, NULL, &j, NULL, NULL, NULL,
                          NULL) != 0) {
            VEC_Add(&i, &h, &i);
            VEC_Add(&b->field0, &i, &b->field0);
        }
    }
    b->field10 = b->field0;
    b->field10.y = b->field10.y + b->field60;
    qrtn_lerp(&b->field4C, &kart->mUnk_110_q, &b->field4C, 0x333);
}

void StructMQRacerEntry_SomeFn_84(Kart *kart, Vec3 *groundNormal) {
    ParticipantKartRecordState *c;
    Vec4 hopTiltQuaternion;
    s32 headingDifference;
    s32 f;

    c = kart->field514;
    kart->field3F8 = 0x1000;
    if (kart->mAirborneFrames > 5 && (kart->field514->field44 & 1) == 0) {
        kart->mQuaternionBlendFactor = 0xf6;
        StructMQRacerEntry_SomeFn_88(kart, &kart->mUnk_100_q);
    } else {
        driver_1FFAD14(kart, groundNormal);
    }
    qrtn_lerp(&kart->mUnk_f0_q, &kart->mUnk_100_q, &kart->mUnk_f0_q, kart->mQuaternionBlendFactor);
    headingDifference = kart->mHeadingAngle - c->fieldE;
    if ((headingDifference > 0 ? headingDifference : -headingDifference) > 0x7fff) {
        if (headingDifference > 0) {
            headingDifference = -(0xffff - headingDifference);
        } else {
            headingDifference = headingDifference + 0xffff;
        }
    }
    c->fieldE = c->fieldE + (s32) ((s64) headingDifference * 0x19a >> 12);
    qrtn_fromAxisAngle(&driverCore_sUpVec, (u16) (kart->mHeadingAngle + kart->mHeadingAngleOffset), &kart->mUnk_e0_m);
    qrtn_mult(&kart->mUnk_f0_q, &kart->mUnk_e0_m, &kart->mUnk_110_q);
    if ((kart->field44 & 2) != 0) {
        if (kart->mHopSpeed > 0) {
            f = (u16) ((s64) kart->mHopHeight * 0x1f4 >> 12);
            kart->mHopTiltAngle = 0x9c4 - f;
            if (kart->mHopTiltAngle > 0x6a4) {
                kart->mHopTiltAngle = 0x352;
            }
        } else {
            kart->mHopTiltAngle = 0;
        }
        qrtn_fromAxisAngle(&driverCore_sRightVec, (u16) -kart->mHopTiltAngle, &hopTiltQuaternion);
        qrtn_mult(&kart->mUnk_110_q, &hopTiltQuaternion, &kart->mUnk_110_q);
    } else {
        kart->mHopTiltAngle = 0;
    }
    qrtn_normalize(&kart->mUnk_110_q, &kart->mUnk_110_q);
}

void SetKartPrevCollisionCenterFromPrevPos(Kart *kart) {
    ComputeKartPointAlongUp(&kart->mPrevCollisionCenter, &kart->mPrevPos, 0x400, kart);
}

void InitKart(Kart *kart, void (**slotFunctions)(Kart *)) {
    u32 isPeer;
    u16 i;
    KartModelAnimationView *characterAnimation;

    proc_getHeap(proc_getCurrent());
    isPeer = gRaceMultiConfig->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_PEER;
    kart->mKartModelsEntry = chkrt_getCharKart(kart->mIndex);
    light_init(&kart->mKartModelsEntry->field40, 1);
    if (gRaceMultiConfig->mMode == 5) {
        for (i = 0; i < 9; i++) {
            if (i == 3) {
                kart->mSlotFunctions[i] = isPeer != 0 ? MQ_FnPtr3_Net_3 : MQ_FnPtr3_Net_Not3;
            } else if (i == 4) {
                kart->mSlotFunctions[i] = isPeer != 0 ? MQ_FnPtr4_Net_3 : MQ_FnPtr4_Net_Not3;
            } else if (i == 5) {
                kart->mSlotFunctions[i] =
                    isPeer != 0 ? SetKartPrevCollisionCenterFromPrevPos : SetKartPrevCollisionCenter;
            } else {
                kart->mSlotFunctions[i] = *slotFunctions;
            }
            slotFunctions++;
        }
    } else {
        for (i = 0; i < 9; i++) {
            if (i == 3) {
                kart->mSlotFunctions[i] = sub_20646C0;
            } else if (i == 4) {
                kart->mSlotFunctions[i] = sub_20641D4;
            } else if (i == 5) {
                kart->mSlotFunctions[i] = SetKartPrevCollisionCenter;
            } else {
                kart->mSlotFunctions[i] = *slotFunctions;
            }
            slotFunctions++;
        }
    }
    kart->field514 = NULL;
    if (kart->mSlotFunctions[1] != 0) {
        kart->mSlotFunctions[1](kart);
    }
    kart->mPosSource = &kart->mPos;
    kart->field50C = &kart->mUnk_110_q;
    kart->field510 = &kart->mPos;
    if (kart->mSlotFunctions[0] != 0) {
        kart->mSlotFunctions[0](kart);
    }
    if (gRaceMultiConfig->mRaceKind == 2 || (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        kart->mSlotFunctions[2] = SetKartSoundDistanceSquaredAndChange;
    } else {
        kart->mSlotFunctions[2] = SetKartSoundDistanceSquared;
    }
    if (gRaceMultiConfig->mMode == 5) {
        if (isPeer != 0) {
            kart->mPosSource = &kart->field514->field10;
            kart->field50C = &kart->field514->field4C;
            kart->field510 = &kart->field514->field0;
        } else {
            kart->mPosSource = &kart->mPos;
            kart->field50C = &kart->mUnk_110_q;
            kart->field510 = &kart->mPos;
        }
    } else {
        kart->mPosSource = &kart->mPos;
        kart->field50C = &kart->mUnk_110_q;
        kart->field510 = &kart->mPos;
    }
    kart->mPosSourceCopy = kart->mPosSource;
    driver_initToNkmPos(kart, 0);
    if (race_isCamAnimMode() != 0 && gRaceMultiConfig->mRaceKind != RACE_KIND_AWARD) {
        kart->mSlotFunctions[3] = func_020649e8;
        kart->mSlotFunctions[4] = func_020649e8;
        kart->mDrawMatrixPos = kart->field174;
        kart->field174.x = kart->field174.x >> 4;
        kart->field174.y = kart->field174.y >> 4;
        kart->field174.z = kart->field174.z >> 4;
        if ((kart->field7C & KART_7C_MODELS_ENTRY_008_SET) != 0) {
            AdvanceKartCharacterAnimation(kart);
            characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
            *characterAnimation->field1C[characterAnimation->field1A] = characterAnimation->fieldC;
        }
    }
    StructMQRacerEntry_SomeFn_48(kart);
    if ((kart->field7C & 2) != 0) {
        enmy_init(kart->mAi, kart->mIndex);
    }
}
